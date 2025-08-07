/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** main
*/

/**
 * @file main.cpp
 * @brief Entry point of the raytracer application. Initializes and runs the Raytracer engine.
 * @author Noé Carabin
 * @version 1.0
 * @date 2025-05
 *
 * @details
 * This file contains the `main` function, which instantiates the `Raytracer` object,
 * executes the rendering process, and handles any runtime exceptions raised by the engine.
 */

#include "../../include/core/Raytracer.hpp"

/// Raimond is a good Raytracer. Logic, it's Raimond.

/**
 * @brief Program entry point.
 *
 * Initializes the Raytracer application and triggers rendering via the `run()` method.
 * Any errors thrown during initialization or execution are caught and reported to stderr.
 *
 * @param argc Argument count
 * @param argv Argument values
 * @return 0 on success, 84 on failure
 */
int main(int argc, char* argv[])
{
    Raytracer raimond(argc, argv);

    try {
        raimond.run();
        return 0;
    }
    catch(const Raytracer::Error &error)
    {
        std::cerr << "[ERROR] - " << error.what() << std::endl;
        return 84;
    }    
}
