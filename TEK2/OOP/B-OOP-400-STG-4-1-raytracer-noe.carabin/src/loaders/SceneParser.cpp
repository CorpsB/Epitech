/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** SceneParser
*/

/**
 * @file SceneParser.cpp
 * @brief Implements the scene loading system using libconfig for the raytracer engine.
 * @author Noé Carabin
 * @version 1.0
 * @date 2025-05
 *
 * @details
 * This file provides functions for parsing `.cfg` scene files using the libconfig library.
 * The scene description may contain camera settings, materials, primitives (spheres, boxes, cones, torus, etc.),
 * lights, skyboxes, and transformations (shear, rotation, custom matrix).
 * 
 * Features:
 * - Recursive scene inclusion through the `includes` key.
 * - Material resolution with support for checker, texture, and noise maps.
 * - Parsing of geometric primitives and their transformation wrappers.
 * - Support for advanced fractals and meshes like Menger sponge, Sierpinski tetrahedron, and TangleCube.
 * - Robust error handling with clear diagnostics for missing or malformed settings.
 * 
 * Entry points:
 * - `RayTracer::loadScene(const std::string&, Scene&, bool)` loads a single scene file.
 */


#include <libconfig.h++>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <string>
#include <memory>

#include "../../include/core/Raytracer.hpp"
#include "loaders/SceneParser.hpp"
#include "rendering/Scene.hpp"
#include "rendering/Camera.hpp"
#include "rendering/AmbientLight.hpp"
#include "rendering/PointLight.hpp"
#include "rendering/DirectionalLight.hpp"
#include "rendering/Material.hpp"
#include "rendering/Texture.hpp"
#include "rendering/CheckerTexture.hpp"
#include "rendering/ImageTexture.hpp"
#include "primitives/Sphere.hpp"
#include "primitives/Plane.hpp"
#include "primitives/Box.hpp"
#include "primitives/Cylinder.hpp"
#include "primitives/Cone.hpp"
#include "primitives/Triangle.hpp"
#include "primitives/Torus.hpp"
#include "primitives/Sierpinski.hpp"
#include "primitives/Menger.hpp"
#include "primitives/TangleCube.hpp"
#include "geoTransf/Shear.hpp" 
#include "geoTransf/Rotation.hpp"
#include "geoTransf/Matrix.hpp"
#include "rendering/NoiseTexture.hpp"
#include "rendering/PerlinNoise.hpp"

#include "loaders/STLLoader.hpp"

//All transformation
static std::shared_ptr<RayTracer::APrimitive> ParseShear(const libconfig::Setting &node, std::shared_ptr<RayTracer::APrimitive> prim,
    bool debug = false) {
    if (!node.exists("shear"))
        return prim;

    const libconfig::Setting &sh = node.lookup("shear");
    double sXY = 0, sXZ = 0, sYX = 0, sYZ = 0, sZX = 0, sZY = 0;

    sh.lookupValue("xy", sXY);
    sh.lookupValue("xz", sXZ);
    sh.lookupValue("yx", sYX);
    sh.lookupValue("yz", sYZ);
    sh.lookupValue("zx", sZX);
    sh.lookupValue("zy", sZY);

    if (debug) {
        std::cerr << "[Debug] shear " << "xy=" << sXY << " xz=" << sXZ << " " << "yx=" << sYX << " yz=" << sYZ << " "
            << "zx=" << sZX << " zy=" << sZY << "\n";
    }
    return std::make_shared<RayTracer::Shear>(prim, sXY, sXZ, sYX, sYZ, sZX, sZY);
}

static std::shared_ptr<RayTracer::APrimitive> ParseRotation(const libconfig::Setting &node, std::shared_ptr<RayTracer::APrimitive> prim,
    bool debug = false) {
    if (!node.exists("rotation"))
        return prim;

    const libconfig::Setting &rot = node.lookup("rotation");
    double rx = 0;
    double ry = 0;
    double rz = 0;

    rot.lookupValue("x", rx);
    rot.lookupValue("y", ry);
    rot.lookupValue("z", rz);

    const double deg2rad = M_PI / 180.0;
    rx *= deg2rad;
    ry *= deg2rad;
    rz *= deg2rad;

    if (debug) {
        std::cerr << "[Debug] rotation x=" << rx << " y=" << ry << " z=" << rz << " (radians)\n";
    }

    return std::make_shared<RayTracer::Rotation>(prim, rx, ry, rz);
}

static std::shared_ptr<RayTracer::APrimitive> ParseMatrix(const libconfig::Setting &node, std::shared_ptr<RayTracer::APrimitive> prim,
    bool debug = false) {
    if (!node.exists("matrix"))
        return prim;

    const libconfig::Setting &matNode = node.lookup("matrix");

    if (matNode.getLength() != 3 || matNode.getType() != libconfig::Setting::TypeList) {
        std::cerr << "[Error] matrix must be a list of 3 lists.\n";
        return prim;
    }

    double mat[3][3];

    for (int i = 0; i < 3; ++i) {
        const libconfig::Setting &row = matNode[i];
        if (row.getLength() != 3 || row.getType() != libconfig::Setting::TypeList) {
            std::cerr << "[Error] each matrix row must be a list of 3 numbers.\n";
            return prim;
        }
        for (int j = 0; j < 3; ++j) {
            const libconfig::Setting &val = row[j];
            mat[i][j] = (val.getType() == libconfig::Setting::TypeInt) ? (double)(int)val : (double)val;
        }        
    }

    if (debug) {
        std::cerr << "[Debug] matrix = [\n";
        for (int i = 0; i < 3; ++i)
            std::cerr << "  [" << mat[i][0] << ", " << mat[i][1] << ", " << mat[i][2] << "]\n";
        std::cerr << "]\n";
    }

    return std::make_shared<RayTracer::Matrix>(prim, mat);
}

static std::shared_ptr<RayTracer::APrimitive> ApplyTransforms(const libconfig::Setting &s, std::shared_ptr<RayTracer::APrimitive> p, bool debug) {
    p = ParseShear(s, p, debug);
    p = ParseRotation(s, p, debug);
    p = ParseMatrix(s, p, debug);
    return p;
}

// Helpers
static Math::Vector3D parseVec3(const libconfig::Setting &s, const char* kx="x", const char* ky="y", const char* kz="z") {
    auto get = [&](const char* k)->double {
        if (!s.exists(k)) return 0.0;
        const libconfig::Setting &v = s.lookup(k);
        return v.getType()== libconfig::Setting::TypeInt ? (double)(int)v : (double)v;
    };
    return { get(kx), get(ky), get(kz) };
}
static Math::Vector3D parseColor(const libconfig::Setting &s) {
    Math::Vector3D c = parseVec3(s, "r","g","b");
    return { c.x/255.0, c.y/255.0, c.z/255.0 };
}

static RayTracer::Material parseMaterialDef(const libconfig::Setting &m, bool debug) {
    RayTracer::Material mat;
    m.lookupValue("name",        mat.name);
    mat.albedo      = parseColor(m.lookup("albedo"));
    m.lookupValue("roughness",   mat.roughness);
    m.lookupValue("metallic",    mat.metallic);
    if (m.exists("specular")) {
        const libconfig::Setting &sp = m.lookup("specular");
        if (sp.getType() == libconfig::Setting::TypeGroup)
            mat.specular = parseVec3(sp, "r", "g", "b");
        else {
            double sVal = 0.0;
            m.lookupValue("specular", sVal);
            mat.specular = Math::Vector3D{ sVal, sVal, sVal };
        }
    }
    m.lookupValue("transparency", mat.transparency);
    m.lookupValue("ior",          mat.ior);
    if (m.exists("emission")) {
        mat.emission = parseColor(m.lookup("emission"));
    }
    m.lookupValue("emissionStrength", mat.emissionStrength);

    if (m.exists("checker")) {
        const libconfig::Setting &ch = m.lookup("checker");
        auto c1 = parseColor(ch.lookup("color1"));
        auto c2 = parseColor(ch.lookup("color2"));
        float scale = 1.0f;
        ch.lookupValue("scale", scale);
        mat.diffuseMap = std::make_shared<RayTracer::CheckerTexture>(c1, c2, scale);
    }
    else if (m.exists("texture")) {
        std::string file;
        m.lookupValue("texture", file);
        mat.diffuseMap = std::make_shared<RayTracer::ImageTexture>(file);
    }

    if (m.exists("noise") && mat.diffuseMap) {
        const libconfig::Setting &ns = m.lookup("noise");
        float noiseScale = 10.0f;
        float noiseStrength = 0.1f;
        ns.lookupValue("scale", noiseScale);
        ns.lookupValue("strength", noiseStrength);
        mat.diffuseMap = std::make_shared<RayTracer::NoiseTexture>(mat.diffuseMap,
                                                         noiseScale,
                                                         noiseStrength);
    }

    if (debug) {
        std::cerr << "[Debug] Material '"<<mat.name<<"' albedo=("<<mat.albedo.x<<","<<mat.albedo.y<<","<<mat.albedo.z<<") "
                  <<"roughness="<<mat.roughness<<" metallic="<<mat.metallic
                  <<" specular=("<<mat.specular.x<<","<<mat.specular.y<<","<<mat.specular.z<<") "
                  <<"transparency="<<mat.transparency<<" ior="<<mat.ior
                  <<" emission=("<<mat.emission.x<<","<<mat.emission.y<<","<<mat.emission.z<<")"
                  <<" strength="<<mat.emissionStrength<<"\n";
    }
    return mat;
}

static RayTracer::Material resolveMaterial(const libconfig::Setting &s,
                                const std::map<std::string, RayTracer::Material> &mats,
                                const Math::Vector3D &fallback) {
    RayTracer::Material mat;
    std::string name;
    if (s.lookupValue("material", name) && mats.count(name)) {
        mat = mats.at(name);
    } else {
        mat = RayTracer::Material{"default", fallback, 0.0f, 0.0f, {0,0,0}, 0.0f, 1.0f};
    }
    if (s.exists("checker")) {
        const libconfig::Setting &ch = s.lookup("checker");
        auto c1 = parseColor(ch.lookup("color1"));
        auto c2 = parseColor(ch.lookup("color2"));
        float scale = 1.0f; ch.lookupValue("scale", scale);
        mat.diffuseMap = std::make_shared<RayTracer::CheckerTexture>(c1, c2, scale);
    } else if (s.exists("texture")) {
        std::string file; s.lookupValue("texture", file);
        mat.diffuseMap = std::make_shared<RayTracer::ImageTexture>(file);
    }
    if (s.exists("emission")) {
        mat.emission = parseColor(s.lookup("emission"));
    }
    if (s.exists("emissionStrength")) {
        s.lookupValue("emissionStrength", mat.emissionStrength);
    }
    return mat;
}

static void ParseCamera(const libconfig::Setting &cam, RayTracer::Scene &scene, bool debug) {
    auto pos = parseVec3(cam.lookup("position"));
    auto rot = cam.exists("rotation") ? parseVec3(cam.lookup("rotation")) : Math::Vector3D{0,0,0};
    double fov = 45.0; cam.lookupValue("fieldOfView", fov);

    int w = 800, h = 600;
    if (cam.exists("resolution")) {
        const libconfig::Setting &r = cam.lookup("resolution");
        r.lookupValue("width", w);
        r.lookupValue("height", h);
    }

    double aperture = 0.0;
    cam.lookupValue("aperture", aperture);
    double focusDist = 1.0;
    cam.lookupValue("focusDistance", focusDist);

    Math::Vector3D fwd{0,0,-1};
    fwd = fwd.rotateX(rot.x).rotateY(rot.y).rotateZ(rot.z);
    Math::Vector3D up{0,1,0};
    Math::Vector3D right = fwd.cross(up) / fwd.cross(up).length();
    Math::Vector3D realUp = right.cross(fwd) / right.cross(fwd).length();

    scene = RayTracer::Scene(RayTracer::Camera(
            Math::Point3D{pos.x, pos.y, pos.z},
            Math::Point3D{pos.x + fwd.x * focusDist,
                    pos.y + fwd.y * focusDist,
                    pos.z + fwd.z * focusDist},
            realUp,
            fov,
            double(w) / h,
            aperture,
            focusDist,
            h,
            w
    ));
    if (debug) {
        std::cerr << "[Debug] Camera pos=(" << pos.x << "," << pos.y << "," << pos.z << ")"
                << " rot=(" << rot.x << "," << rot.y << "," << rot.z << ")"
                << " fov=" << fov
                << " res=" << w << "x" << h
                << " aperture=" << aperture
                << " focusDist=" << focusDist << "\n";
    }
}

static void ParseSpheres(const libconfig::Setting &ss, RayTracer::Scene &scene, const std::map<std::string, RayTracer::Material> &mats, bool debug) {
    for (int i=0;i<ss.getLength();++i){
        auto &s=ss[i]; auto c=parseVec3(s);
        double r=1; s.lookupValue("r",r);
        Math::Vector3D col=s.exists("color")?parseColor(s.lookup("color")):Math::Vector3D{1,1,1};
        RayTracer::Material mat=resolveMaterial(s,mats,col);

        std::shared_ptr<RayTracer::APrimitive> sphere = std::make_shared<RayTracer::Sphere>(Math::Point3D{c.x, c.y, c.z}, r, mat);
        sphere = ApplyTransforms(s, sphere, debug);
        scene.addObject(sphere);
        if (debug) {
            std::cerr<<"[Debug] Sphere center=("<<c.x<<","<<c.y<<","<<c.z<<") r="<<r
                    <<" mat='"<<mat.name<<"'\n";
        }
    }
}

static void ParseBoxes(const libconfig::Setting &bs, RayTracer::Scene &scene, const std::map<std::string, RayTracer::Material> &mats, bool debug) {
    for(int i=0;i<bs.getLength();++i){
        auto &b=bs[i]; auto mn=parseVec3(b.lookup("min")); auto mx=parseVec3(b.lookup("max"));
        Math::Vector3D col=b.exists("color")?parseColor(b.lookup("color")):Math::Vector3D{1,1,1};
        RayTracer::Material mat=resolveMaterial(b,mats,col);

        std::shared_ptr<RayTracer::APrimitive> box = std::make_shared<RayTracer::Box>(Math::Point3D{mn.x,mn.y,mn.z},Math::Point3D{mx.x,mx.y,mx.z},mat);
        box = ApplyTransforms(b, box, debug);
        scene.addObject(box);
        if (debug) {
            std::cerr<<"[Debug] Box min=("<<mn.x<<","<<mn.y<<","<<mn.z<<") max=("<<mx.x<<","<<mx.y<<","<<mx.z<<") "
                    <<"mat='"<<mat.name<<"'\n";
        }
    }
}

static void ParseCylinders(const libconfig::Setting &cs, RayTracer::Scene &scene, const std::map<std::string, RayTracer::Material> &mats, bool debug) {
    for(int i=0;i<cs.getLength();++i){
        auto &c=cs[i]; auto base=parseVec3(c);
        double r=1,h=1; c.lookupValue("r",r); c.lookupValue("h",h);
        Math::Vector3D col=c.exists("color")?parseColor(c.lookup("color")):Math::Vector3D{1,1,1};
        RayTracer::Material mat=resolveMaterial(c,mats,col);

        std::shared_ptr<RayTracer::APrimitive> cylinder = std::make_shared<RayTracer::Cylinder>(Math::Point3D{base.x,base.y,base.z}, 
            Math::Vector3D{0,1,0},r,h,mat);
        cylinder = ApplyTransforms(c, cylinder, debug);
        scene.addObject(cylinder);
        if (debug) {
            std::cerr<<"[Debug] Cylinder base=("<<base.x<<","<<base.y<<","<<base.z<<") r="<<r<<" h="<<h
                    <<" mat='"<<mat.name<<"'\n";
        }
    }
}

static void ParseCones(const libconfig::Setting &cs, RayTracer::Scene &scene, const std::map<std::string, RayTracer::Material> &mats, bool debug) {
    for(int i=0;i<cs.getLength();++i){
        auto &c=cs[i]; auto base=parseVec3(c);
        double r1=0,r2=0,h=1; c.lookupValue("r1",r1); c.lookupValue("r2",r2); c.lookupValue("h",h);
        if(r1>0&&r2>0) continue;
        Math::Point3D apex; Math::Vector3D axis; double angle=0;
        if(r1==0){ apex=Math::Point3D{base.x,base.y,base.z}; axis={0,1,0}; angle=atan2(r2,h)*180/M_PI; }
        else       { apex=Math::Point3D{base.x,base.y+h,base.z}; axis={0,-1,0}; angle=atan2(r1,h)*180/M_PI; }
        Math::Vector3D col=c.exists("color")?parseColor(c.lookup("color")):Math::Vector3D{1,1,1};
        RayTracer::Material mat=resolveMaterial(c,mats,col);

        std::shared_ptr<RayTracer::APrimitive> cone = std::make_shared<RayTracer::Cone>(apex,axis,angle,h,mat);
        cone = ApplyTransforms(c, cone, debug);
        scene.addObject(cone);
        if (debug) {
            std::cerr<<"[Debug] Cone apex=("<<apex.x<<","<<apex.y<<","<<apex.z<<") axis=("<<axis.x<<","<<axis.y<<","<<axis.z<<") "
                    <<"angle="<<angle<<" h="<<h<<" mat='"<<mat.name<<"'\n";
        }
    }
}

static void ParsePlanes(const libconfig::Setting &ps, RayTracer::Scene &scene, const std::map<std::string, RayTracer::Material> &mats, bool debug) {
    for(int i=0;i<ps.getLength();++i){
        auto &p=ps[i]; std::string ax; p.lookupValue("axis",ax); double pos=0; p.lookupValue("position",pos);
        Math::Point3D point; Math::Vector3D normal;
        if(ax=="X"){ normal={1,0,0}; point={pos,0,0}; }
        else if(ax=="Y"){ normal={0,1,0}; point={0,pos,0}; }
        else             { normal={0,0,1}; point={0,0,pos}; }
        Math::Vector3D col=p.exists("color")?parseColor(p.lookup("color")):Math::Vector3D{1,1,1};
        RayTracer::Material mat=resolveMaterial(p,mats,col);

        std::shared_ptr<RayTracer::APrimitive> plane = std::make_shared<RayTracer::Plane>(point,normal,mat);
        plane = ApplyTransforms(p, plane, debug);
        scene.addObject(plane);
        if (debug) {
            std::cerr<<"[Debug] Plane axis="<<ax<<" pos="<<pos<<" mat='"<<mat.name<<"'\n";
        }
    }
}

static void ParseTorus(const libconfig::Setting &ts, RayTracer::Scene &scene, const std::map<std::string, RayTracer::Material> &mats, bool debug) {
    for(int i=0;i<ts.getLength();++i){
        auto &t=ts[i]; auto c=parseVec3(t.lookup("center")); double R=1,r=0.5;
        t.lookupValue("majorRadius",R); t.lookupValue("minorRadius",r);
        Math::Vector3D col=t.exists("color")?parseColor(t.lookup("color")):Math::Vector3D{1,1,1};
        RayTracer::Material mat=resolveMaterial(t,mats,col);

        std::shared_ptr<RayTracer::APrimitive> torus = std::make_shared<RayTracer::Torus>(Math::Point3D{c.x,c.y,c.z},R,r,mat);
        torus = ApplyTransforms(t, torus, debug);
        scene.addObject(torus);
        if (debug) {
            std::cerr<<"[Debug] Torus center=("<<c.x<<","<<c.y<<","<<c.z<<") R="<<R<<" r="<<r
                    <<" mat='"<<mat.name<<"'\n";
        }
    }
}

static void ParseMeshes(const libconfig::Setting &ms, RayTracer::Scene &scene, const std::map<std::string, RayTracer::Material> &mats, bool debug) {
    for(int i=0;i<ms.getLength();++i){
        auto &m=ms[i]; std::string file; m.lookupValue("file",file);
        auto tr=parseVec3(m.exists("translate")?m.lookup("translate"):m);
        double sc=1; m.lookupValue("scale",sc);
        Math::Vector3D col=m.exists("color")?parseColor(m.lookup("color")):Math::Vector3D{1,1,1};
        RayTracer::Material mat=resolveMaterial(m,mats,col);
        auto mesh= RayTracer::STLLoader::load(file); mesh.transform(tr,sc);

        for(auto &tri:mesh.triangles) {
            std::shared_ptr<RayTracer::APrimitive> meshe = std::make_shared<RayTracer::Triangle>(tri.v0,tri.v1,tri.v2,mat);
            meshe = ApplyTransforms(m, meshe, debug);
            scene.addObject(meshe);
        }
        if (debug) {
            std::cerr<<"[Debug] Mesh '"<<file<<"' translate=("<<tr.x<<","<<tr.y<<","<<tr.z<<") "
                    <<"scale="<<sc<<" tris="<<mesh.triangles.size()<<" mat='"<<mat.name<<"'\n";
        }
    }
}

static void ParseLights(const libconfig::Setting &ls, RayTracer::Scene &scene, bool debug) {
    double amb=0.1,dif=1.0; ls.lookupValue("ambient",amb); ls.lookupValue("diffuse",dif);
    scene.addLight(std::make_shared<RayTracer::AmbientLight>(amb));
    if (debug)
        std::cerr<<"[Debug] Light ambient="<<amb<<" diffuse="<<dif<<"\n";
    if(ls.exists("point")) for(int i=0;i<ls.lookup("point").getLength();++i){
            auto &pt=ls.lookup("point")[i]; auto p=parseVec3(pt);
            double inten=dif; pt.lookupValue("intensity",inten);
            scene.addLight(std::make_shared<RayTracer::PointLight>(Math::Point3D{p.x, p.y, p.z}, inten));
            if (debug)
                std::cerr<<"[Debug] PointLight @("<<p.x<<","<<p.y<<","<<p.z<<") inten="<<inten<<"\n";
        }
    if(ls.exists("directional")) for(int i=0;i<ls.lookup("directional").getLength();++i){
            auto &d=ls.lookup("directional")[i]; auto dir=parseVec3(d);
            double inten=dif; d.lookupValue("intensity",inten);
            scene.addLight(std::make_shared<RayTracer::DirectionalLight>(Math::Vector3D{dir.x, dir.y, dir.z}, inten));
            if (debug)
                std::cerr<<"[Debug] DirLight dir=("<<dir.x<<","<<dir.y<<","<<dir.z<<") inten="<<inten<<"\n";
        }
}

static void ParseSierpinski(const libconfig::Setting &ss, RayTracer::Scene &scene, const std::map<std::string, RayTracer::Material> &mats, bool debug) {
    for (int i = 0; i < ss.getLength(); ++i) {
        const libconfig::Setting &s = ss[i];
        auto c = parseVec3(s.lookup("center"));
        double size = 1.0; s.lookupValue("size", size);
        int depth = 2;     s.lookupValue("depth", depth);
        Math::Vector3D col = s.exists("color") ? parseColor(s.lookup("color")) : Math::Vector3D{1,1,1};
        RayTracer::Material mat = resolveMaterial(s, mats, col);

        std::shared_ptr<RayTracer::APrimitive> sierpinski = std::make_shared<RayTracer::Sierpinski>(Math::Point3D{c.x, c.y, c.z}, size, depth, mat);
        sierpinski = ApplyTransforms(s, sierpinski, debug);
        scene.addObject(sierpinski);
        if (debug) {
            std::cerr << "[Debug] Sierpinski center=(" << c.x << "," << c.y << "," << c.z
                    << ") size=" << size << " depth=" << depth
                    << " mat='" << mat.name << "'\n";
        }
    }
}

static void ParseMenger(const libconfig::Setting &ss, RayTracer::Scene &scene, const std::map<std::string, RayTracer::Material> &mats, bool debug) {
    for (int i = 0; i < ss.getLength(); ++i) {
        const libconfig::Setting &s = ss[i];
        auto c = parseVec3(s.lookup("center"));
        double size = 1.0; s.lookupValue("size", size);
        int depth = 2;     s.lookupValue("depth", depth);
        Math::Vector3D col = s.exists("color") ? parseColor(s.lookup("color")) : Math::Vector3D{1,1,1};
        RayTracer::Material mat = resolveMaterial(s, mats, col);

        std::shared_ptr<RayTracer::APrimitive> menger = std::make_shared<RayTracer::Menger>(Math::Point3D{c.x, c.y, c.z}, size, depth, mat);
        menger = ApplyTransforms(s, menger, debug);
        scene.addObject(menger);
        if (debug) {
            std::cerr << "[Debug] Menger center=(" << c.x << "," << c.y << "," << c.z
                    << ") size=" << size << " depth=" << depth
                    << " mat='" << mat.name << "'\n";
        }
    }
}

static void ParseTangleCube(const libconfig::Setting &tc, RayTracer::Scene &scene, const std::map<std::string, RayTracer::Material> &mats, bool debug)
{
    for (int i = 0; i < tc.getLength(); ++i) {
        const libconfig::Setting &t = tc[i];
        Math::Vector3D vc = parseVec3(t.lookup("center"));
        Math::Point3D center{ vc.x, vc.y, vc.z };
        double scale = 1.0;
        t.lookupValue("scale", scale);
        Math::Vector3D defaultCol = t.exists("color") ? parseColor(t.lookup("color")) : Math::Vector3D{1,1,1};
        RayTracer::Material mat = resolveMaterial(t, mats, defaultCol);

        std::shared_ptr<RayTracer::APrimitive> tangleC = std::make_shared<RayTracer::TangleCube>(center, scale, mat);
        tangleC = ApplyTransforms(t, tangleC, debug);
        scene.addObject(tangleC);
        if (debug) {
            std::cerr << "[Debug] TangleCube center(" << center.x << "," << center.y << "," << center.z
            << ") scale=" << scale << " mat='" << mat.name << "'\n";
        }
    }
}

bool RayTracer::loadScene(const std::string &file, Scene &scene, bool debug) {
    libconfig::Config cfg;

    try { 
        cfg.readFile(file.c_str());

        // Camera
        ParseCamera(cfg.lookup("camera"), scene, debug);

        // Skybox (optional)
        if (cfg.exists("skybox")) {
            std::string skyboxFile;
            cfg.lookupValue("skybox", skyboxFile);
            if (!skyboxFile.empty()) {
                if (!Skybox::initializeSkybox(skyboxFile)) {
                    std::cerr << skyboxFile << std::endl;
                    return false;
                }
            }
        }

        // Materials|
        std::map<std::string,Material> mats;
        if(cfg.exists("materials")) {
            for(int i=0;i<cfg.lookup("materials").getLength();++i){
                Material m = parseMaterialDef(cfg.lookup("materials")[i], debug);
                mats[m.name] = m;
            }
        }
    
        // Primitives
        if(cfg.exists("primitives")){
            auto &pr = cfg.lookup("primitives");
    
            if(pr.exists("spheres"))
                ParseSpheres(pr.lookup("spheres"),    scene,mats, debug);
            if(pr.exists("boxes"))
                ParseBoxes(pr.lookup("boxes"),      scene,mats, debug);
            if(pr.exists("cylinders"))
                ParseCylinders(pr.lookup("cylinders"),scene,mats, debug);
            if(pr.exists("cones"))
                ParseCones(pr.lookup("cones"),      scene,mats, debug);
            if(pr.exists("torus"))
                ParseTorus(pr.lookup("torus"),      scene,mats, debug);
            if(pr.exists("meshes"))
                ParseMeshes(pr.lookup("meshes"),     scene,mats, debug);
            if(pr.exists("sierpinski"))
                ParseSierpinski(pr.lookup("sierpinski"),     scene,mats, debug);
            if(pr.exists("menger"))
                ParseMenger(pr.lookup("menger"),     scene,mats, debug);
            if(pr.exists("tangleCube"))
                ParseTangleCube(pr.lookup("tangleCube"),     scene,mats, debug);
        }
    
        // Planes (top-level)
        if(cfg.exists("planes"))
            ParsePlanes(cfg.lookup("planes"), scene, mats, debug);
    
        // Lights
        if(cfg.exists("lights")) ParseLights(cfg.lookup("lights"), scene, debug);
    
        return true;
    } catch(const libconfig::FileIOException &e) {
        std::string error_mesage("I/O error reading " + file);
        throw Raytracer::Error(error_mesage);
    } catch(const libconfig::ParseException &e) {
        std::string msg = "Parse error in file " + std::string(e.getFile()) +
                          " at line " + std::to_string(e.getLine()) +
                          ": " + e.getError();
        throw Raytracer::Error(msg);
    } catch(const libconfig::SettingNotFoundException &e) {
        throw Raytracer::Error("Missing setting: " + std::string(e.what()));
    } catch (const libconfig::SettingTypeException &e) {
        throw Raytracer::Error("Wrong type for setting: " + std::string(e.what()));
    } catch (const std::exception &e) {
        throw Raytracer::Error("Unexpected error while loading scene: " + std::string(e.what()));
    }
}
