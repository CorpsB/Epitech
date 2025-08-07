/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Skybox
*/

#include "rendering/ShadowShading.hpp"
#include "../../include/rendering/Skybox.hpp"
#include <cmath>
#include <fstream>
#include <iostream>
#include <cctype>
#include <algorithm>


/** @return *true* if width, height and data array are all valid. */
bool Skybox::PPMImage::isLoaded() const {
    return width > 0 && height > 0 && !data.empty();
}

/**
 * @brief  Fetch the colour of an exact texel.
 * @param x Pixel column (0 … width-1).
 * @param y Pixel row    (0 … height-1).
 * @return  Linear-space RGB in **[0,1]³**.
*/
Math::Vector3D Skybox::PPMImage::getColorAtTexel(int x, int y) const {
    x = std::clamp(x, 0, width - 1);
    y = std::clamp(y, 0, height - 1);

    size_t idx = (static_cast<size_t>(y) * width + x) * 3;

    if (idx + 2 >= data.size()) {
        std::cerr << "SKYBOX GET_COLOR_AT_TEXEL ERROR: idx=" << idx
                  << " for x=" << x << ", y=" << y << " out of range (size: " << data.size() << ")\n";
        return {1.0, 0.0, 1.0};
    }
    return {
        data[idx]     / 255.0,
        data[idx + 1] / 255.0,
        data[idx + 2] / 255.0
    };
}

/**
 * @brief  Bilinear sample in normalised texture coordinates.
 * @param u Horizontal coordinate (0 = left, 1 = right, wraps outside).
 * @param v Vertical   coordinate (0 = bottom, 1 = top,  wraps outside).
 * @return  Linear-space RGB colour.
*/
Math::Vector3D Skybox::PPMImage::sample(double u, double v) const {
    if (!isLoaded()) {
        return {0.1, 0.1, 0.2};
    }

    u = u - std::floor(u);
    v = std::clamp(v, 0.0, 1.0);

    double fx = u * (width - 1.0);
    double fy = v * (height - 1.0);

    int x1 = static_cast<int>(std::floor(fx));
    int y1 = static_cast<int>(std::floor(fy));

    double u_ratio = fx - x1;
    double v_ratio = fy - y1;

    Math::Vector3D c00 = getColorAtTexel(x1, y1);
    Math::Vector3D c10 = getColorAtTexel(x1 + 1, y1);
    Math::Vector3D c01 = getColorAtTexel(x1, y1 + 1);
    Math::Vector3D c11 = getColorAtTexel(x1 + 1, y1 + 1);

    Math::Vector3D top_interp = c00 * (1.0 - u_ratio) + c10 * u_ratio;
    Math::Vector3D bottom_interp = c01 * (1.0 - u_ratio) + c11 * u_ratio;

    return top_interp * (1.0 - v_ratio) + bottom_interp * v_ratio;
}

Skybox::PPMImage Skybox::detail::globalSkyboxTexture;

/**
 * @brief  Load a binary or ASCII PPM file from disk.
 * @param  filepath Absolute or relative path to the *.ppm* file.
 * @param  image    [out] Destination @ref PPMImage struct.
 * @return *true* if the file was read successfully.
*/
bool Skybox::loadPPMFile(const std::string& filepath, PPMImage& image) {
    std::ifstream ifs(filepath, std::ios::binary);
    if (!ifs.is_open()) {
        std::cerr << "SKYBOX ERROR: Could not open PPM file: " << filepath << std::endl;
        return false;
    }
    std::string magic;
    ifs >> magic;
    if (!ifs) return false;

    bool isP3 = (magic == "P3");
    if (!isP3 && magic != "P6") return false;

    auto skip_ws_comments = [&]() {
        while (true) {
            int c = ifs.peek();
            if (c == EOF) return false;
            if (std::isspace(static_cast<unsigned char>(c))) { ifs.get(); }
            else if (c == '#') { std::string comment; std::getline(ifs, comment); }
            else break;
        }
        return ifs.good();
    };

    if (!skip_ws_comments()) return false;
    int w, h, maxv;
    ifs >> w; if (!ifs || !skip_ws_comments()) return false;
    ifs >> h; if (!ifs || !skip_ws_comments()) return false;
    ifs >> maxv; if (!ifs || maxv != 255) return false;

    image.width = w;
    image.height = h;
    image.data.resize(static_cast<size_t>(w) * h * 3);

    if (isP3) {
        for (size_t i = 0; i < image.data.size(); ++i) {
            int v_int;
            ifs >> v_int;
            if (!ifs) return false;
            image.data[i] = static_cast<unsigned char>(std::clamp(v_int, 0, 255));
        }
    } else {
        char single_whitespace;
        ifs.get(single_whitespace);
        if (!std::isspace(static_cast<unsigned char>(single_whitespace))) return false;
        ifs.read(reinterpret_cast<char*>(image.data.data()), image.data.size());
        if (static_cast<size_t>(ifs.gcount()) != image.data.size()) return false;
    }
    return true;
}


/**
 * @brief  Initialise the global skybox texture.
 * @param  filepath Path to a lat-long panoramic PPM image.
 * @return *true* if the image was loaded and stored in
 *         @ref detail::globalSkyboxTexture.
 *
 * If the function returns *false*, the renderer will fall back to the
 * procedural gradient in @ref skyGradient.
*/
bool Skybox::initializeSkybox(const std::string& filepath) {
    return loadPPMFile(filepath, detail::globalSkyboxTexture);
}

/**
 * @brief  Procedural horizon-to-zenith gradient.
 * @param  unitDir Normalised ray direction.
 * @return Linear-space RGB sky colour.
 *
 * The current implementation blends from light-blue at the horizon
 * *(y = 0)* to deep-blue at the zenith *(y = 1)* using a smooth-step.
*/
Math::Vector3D Skybox::skyGradient(const Math::Vector3D& unitDir) {
    if (!detail::globalSkyboxTexture.isLoaded()) {
        double t = 0.5 * (unitDir.y + 1.0);
        t = std::clamp(t, 0.0, 1.0);
        t = t * t * (3.0 - 2.0 * t);

        Math::Vector3D bottomColor{0.7, 0.8, 1.0};
        Math::Vector3D topColor{0.2, 0.3, 0.8};
        Math::Vector3D col = bottomColor * (1.0 - t) + topColor * t;

        double sunIntensity = std::pow(std::max(0.0, unitDir.y), 8.0);
        Math::Vector3D sunColor{0.3, 0.25, 0.2};
        col = col + sunColor * sunIntensity;
        col.x = std::min(col.x, 1.0);
        col.y = std::min(col.y, 1.0);
        col.z = std::min(col.z, 1.0);
        return col;
    }

    double y_clamped = std::clamp(unitDir.y, -1.0, 1.0);

    double phi    = std::atan2(unitDir.z, unitDir.x);
    double lat    = std::asin(y_clamped);

    double u_raw  = (phi + M_PI) / (2.0 * M_PI);
    double v_temp  = (lat + M_PI_2) / M_PI;
    double u_final = u_raw;
    double v_final  = 1.0 - v_temp;

    return detail::globalSkyboxTexture.sample(u_final, v_final);
}

/**
 * @brief Recursive path-tracing integrator.
 *
 * Shoots a primary or secondary ray, finds the nearest intersection in
 * the @p scene, then:
 *  1. adds emitted radiance (area lights or emissive materials);  
 *  2. samples the BSDF to spawn a bounce ray;  
 *  3. accumulates reflected radiance scaled by the BRDF and cosine;  
 *  4. terminates at @p maxDepth or via Russian-roulette.
 *
 * @param ray      Current ray in world space.
 * @param scene    Scene containing geometry, lights, BVH and skybox.
 * @param depth    Current recursion depth (0 for primary bounce).
 * @param maxDepth Maximum recursion depth allowed.
 * @return         Linear-space RGB radiance for this ray.
 *
 * The function is **not** thread-safe if it relies on global RNG; wrap
 * per-thread RNGs when doing multi-threaded rendering.
*/
Math::Vector3D RayTracer::shade(const Ray& ray,
                     const Scene& scene,
                     int depth,
                     int maxDepth)
{
    constexpr double EPS = 1e-4;
    if (depth >= maxDepth)
        return {0,0,0};

    double tHit = std::numeric_limits<double>::infinity();
    HitRecord rec;
    if (!scene.hit(ray, tHit, rec)) {
        auto dir = ray.direction.normalized();
        return Skybox::skyGradient(dir);
    }

    const Material& M = rec.material;
    Math::Vector3D direct_emission = M.emission * M.emissionStrength;

    Math::Vector3D albedo = M.diffuseMap
        ? M.diffuseMap->sample(rec.uv.x, rec.uv.y)
        : M.albedo;
    if (albedo.x > 1.01 || albedo.y > 1.01 || albedo.z > 1.01)
        albedo *= (1.0/255.0);

    Math::Vector3D N_geom    = rec.normal;
    Math::Vector3D N_shading = N_geom;

    const double roughness_th    = 0.05;
    const double metallic_th     = 0.5;
    const double transparency_th = 0.01;
    const double ior_th          = 1.0001;

    bool mat_is_smooth_dielectric =
        M.metallic   < metallic_th &&
        M.roughness  < roughness_th &&
        M.transparency > transparency_th &&
        M.ior        > ior_th;

    bool mat_is_metal        = M.metallic >= metallic_th;
    bool mat_is_smooth_metal = mat_is_metal && M.roughness < roughness_th;

    Math::Vector3D direct_lighting{0,0,0};
    for (auto const& lightPtr : scene.lights) {
        const ILight& light = *lightPtr;
        Math::Vector3D contrib{0,0,0};

        if (light.type() == LightType::Ambient) {
            contrib = albedo
                    * light.intensity()
                    * (1.0 - M.metallic);
            direct_lighting += contrib;
            continue;
        }

        Math::Vector3D Ld = light.direction(rec.point);
        double lightDist = std::numeric_limits<double>::infinity();
        if (light.type() == LightType::Point) {
            auto pos   = light.position(rec.point);
            auto delta = pos - rec.point;
            lightDist  = delta.length();
            if (lightDist < EPS) continue;
            Ld = delta * (1.0 / lightDist);
        }

        double NdotL = std::max(0.0, N_shading.dot(Ld));
        if (NdotL <= 0.0) continue;

        Ray shadowRay{ rec.point + N_shading * EPS, Ld };
        double shadow_transparency = 1.0;
        for (auto const& objPtr : scene.objects) {
            double tS; HitRecord hr;
            if (objPtr->hits(shadowRay, tS, hr)
             && tS < lightDist && tS > EPS)
            {
                shadow_transparency *= hr.material.transparency;
                if (shadow_transparency < 1e-3) break;
            }
        }
        if (shadow_transparency < 1e-3) continue;

        Math::Vector3D brdf_direct{0,0,0};
        if (!mat_is_smooth_dielectric && !mat_is_smooth_metal)
            brdf_direct = albedo * (1.0 / M_PI);

        double attenuation = (light.type() == LightType::Directional)
            ? 1.0
            : 1.0 / (lightDist * lightDist + 1e-8);

        if (brdf_direct.x > 0 || brdf_direct.y > 0 || brdf_direct.z > 0) {
            contrib = brdf_direct
                    * light.intensity()
                    * NdotL
                    * attenuation
                    * shadow_transparency;
            direct_lighting += contrib;
        }
    }
    direct_lighting += direct_emission;

    double max_alb = std::max(std::max(albedo.x, albedo.y), albedo.z);
    double rr_basis = mat_is_smooth_dielectric
        ? std::max(static_cast<double>(M.transparency), 0.75)
        : max_alb;
    double p_cont = std::clamp(rr_basis, 0.05, 0.95);
    if (depth > 1 && rand01() > p_cont)
        return direct_lighting;

    Math::Vector3D indirect_lighting{0,0,0};
    bool entering = ray.direction.dot(N_geom) < 0;
    Math::Vector3D n_interface = entering
        ? N_shading
        : N_shading * -1.0;

    Ray scattered;
    Math::Vector3D bsdf_att{1,1,1};
    double bsdf_pdf = 1.0;

    if (mat_is_smooth_dielectric) {
        double cosi = ray.direction.dot(n_interface);
        double etai = entering ? 1.0 : M.ior;
        double etat = entering ? M.ior : 1.0;
        double eta  = etai / etat;
        double k    = 1.0 - eta*eta*(1.0 - cosi*cosi);

        double F;
        if (k < 0.0) {
            F = 1.0;
        } else {
            double c1 = std::abs(cosi), c2 = std::sqrt(k);
            double Rs = (etai*c1 - etat*c2)/(etai*c1 + etat*c2);
            double Rp = (etat*c1 - etai*c2)/(etat*c1 + etai*c2);
            F = 0.5*(Rs*Rs + Rp*Rp);
        }
        F = std::clamp(F, 0.0, 1.0);

        if (rand01() < F) {
            Math::Vector3D R = ray.direction
                             - n_interface * 2.0 * ray.direction.dot(n_interface);
            scattered = Ray{ rec.point + n_interface*EPS, R.normalized() };
            bsdf_att = {1,1,1};
            bsdf_pdf = F;
        } else {
            Math::Vector3D T = ray.direction*eta
                             + n_interface*(eta*cosi - std::sqrt(std::max(0.0, k)));
            scattered = Ray{ rec.point - n_interface*EPS, T.normalized() };
            bsdf_att = albedo;
            bsdf_pdf = 1.0 - F;
        }

    } else if (mat_is_metal) {
        Math::Vector3D R = ray.direction
                         - N_shading * 2.0 * ray.direction.dot(N_shading);
        scattered = Ray{ rec.point + N_shading*EPS, R.normalized() };
        bsdf_att = M.specular;

    } else {
        double hemi_pdf;
        Math::Vector3D D = sampleHemisphere(N_shading, hemi_pdf);
        scattered = Ray{ rec.point + N_shading*EPS, D };
        bsdf_att = albedo;
        bsdf_pdf = hemi_pdf;
    }
    Math::Vector3D Li = shade(scattered, scene, depth+1, maxDepth);
    if (mat_is_smooth_dielectric || mat_is_metal) {
        if (bsdf_pdf > 1e-7)
            indirect_lighting = bsdf_att * Li / (bsdf_pdf * p_cont + 1e-8);
    } else {
        indirect_lighting = bsdf_att * Li / (p_cont + 1e-8);
    }
    Math::Vector3D result = direct_lighting + indirect_lighting;
    result.x = clamp01(result.x);
    result.y = clamp01(result.y);
    result.z = clamp01(result.z);
    return result;
}