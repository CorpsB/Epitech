/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Raytracer
*/

/**
 * @file Raytracer.hpp
 * @brief Declares the main Raytracer application class for program execution and argument handling.
 * @author Noé Carabin
 * @version 1.0
 * @date 2025-05
 *
 * @details
 * The Raytracer class is the main entry point of the application. It handles
 * program arguments, initializes the scene, and launches the rendering process.
 * It also provides an internal Error exception class to report initialization or
 * runtime errors in a consistent way.
 */

#ifndef RAYTRACER_HPP_
#define RAYTRACER_HPP_

#include "../rendering/Scene.hpp"
#include "../rendering/PostFX.hpp"
#include "Utils.hpp"

/**
 * @class Raytracer
 * @brief Main application class that manages the raytracing pipeline.
 */
class Raytracer {
    public:
        /**
         * @brief Construct the Raytracer with command-line arguments.
         * @param ac Argument count (argc)
         * @param av Argument values (argv)
         */
        Raytracer(int ac, char **av);
        /**
         * @brief Destructor.
         */
        ~Raytracer();

        /**
         * @class Error
         * @brief Custom exception type for errors occurring during raytracer initialization or execution.
         */
        class Error : public std::exception {
            public:
                /**
                 * @brief Construct an error with a message.
                 * @param msg Description of the error
                 */
                Error(const std::string &msg = "") : _msg(msg) {};
                /**
                 * @brief Retrieve the error message.
                 * @return C-style string with error description
                 */
                const char *what() const noexcept
                {
                    return this->_msg.c_str();
                }
            private:
                std::string _msg; ///< Error message
        };

        /**
         * @brief Launch the raytracing process.
         *
         * Parses arguments, loads the scene, and triggers rendering and display.
         */
        void run();
    protected:
    private:
        int _ac; ///< Argument count (from main)
        char **_av; ///< Argument values (from main)
};

#endif /* !RAYTRACER_HPP_ */
