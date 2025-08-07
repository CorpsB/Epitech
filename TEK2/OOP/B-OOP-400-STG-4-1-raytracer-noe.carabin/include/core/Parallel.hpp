/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-raytracer-noe.carabin
** File description:
** Parallel
*/

/**
 * @file Parallel.hpp
 * @brief Utilities for parallel computation using OpenMP.
 * @author Noé Carabin
 * @version 1.0
 * @date 2025-05
 *
 * @details
 * This header provides a minimal interface for parallel loops and thread queries
 * using OpenMP. It abstracts parallelism behind a namespace and provides a
 * functional interface for readability and portability.
 */

#pragma once

#include <omp.h>
#include <functional>

namespace Utils::Parallel {

    /**
     * @brief Get the thread number of the current OpenMP thread.
     *
     * @return Index of the current thread (0-based).
     */
    int getThreadNum();

    /**
     * @brief Get the total number of OpenMP threads in the current parallel region.
     *
     * @return Number of threads used in parallel regions.
     */
    int getNumThreads();

    /**
     * @brief Execute a parallel for loop from `start` to `end - 1`.
     *
     * Wraps OpenMP's `#pragma omp parallel for` and accepts a lambda
     * or callable object to be executed in parallel.
     *
     * @param start Beginning index (inclusive).
     * @param end Ending index (exclusive).
     * @param func Function to execute for each index.
     */
    void forLoop(int start, int end, const std::function<void(int)>& func);
} // namespace Utils::Parallel

