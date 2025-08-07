/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Parallel
*/

#include "../../include/core/Parallel.hpp"

/**
 * @file Parallel.cpp
 * @brief Implements utilities for parallel execution using OpenMP.
 * @author Noé Carabin
 * @version 1.0
 * @date 2025-05
 *
 * @details
 * This file contains the implementation of lightweight wrappers around OpenMP
 * functionality. These wrappers allow other parts of the project to query thread
 * information and execute parallel for-loops in a clean and functional style.
 */

int Utils::Parallel::getThreadNum() {
    return omp_get_thread_num();
}

int Utils::Parallel::getNumThreads() {
    return omp_get_num_threads();
}

void Utils::Parallel::forLoop(int start, int end, const std::function<void(int)>& func) {
#pragma omp parallel for schedule(dynamic)
    for (int i = start; i < end; ++i) {
        func(i);
    }
}
