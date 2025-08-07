/*
** EPITECH PROJECT, 2025
** B-OOP-400-STG-4-1-tekspice-noe.carabin
** File description:
** logger
*/

#include "LoggerComponent.hpp"
#include <fstream>
#include <iostream>
#include <cmath>

void nts::LoggerComponent::execute()
{
    int table[8];
    int clock = getLink(9);
    int inhibit = getLink(10);
    char result;

    for (int i = 0; i <= 7; i++) {
        table[i] = getLink(i + 1);
        // printf("Table de [%i]: %i\n", i, table[i]);
        if (table[i] == -1)
            return;
    }
    // printf("Clock: %i\n", clock);
    // printf("\n\n");
    if (clock == 1 && (inhibit == 0)) {
        std::ofstream file("log.bin", std::ios::app | std::ios::binary);

        if (!file) {
            std::cerr << "Erreur : Impossible d'ouvrir log.bin" << std::endl;
            return;
        }
        result = table[7] * static_cast<int>(std::pow(2, 7)) +
            table[6] * static_cast<int>(std::pow(2, 6)) +
            table[5] * static_cast<int>(std::pow(2, 5)) +
            table[4] * static_cast<int>(std::pow(2, 4)) +
            table[3] * static_cast<int>(std::pow(2, 3)) +
            table[2] * static_cast<int>(std::pow(2, 2)) +
            table[1] * 2 + table[0];
        file << (result);
        file.close();
    }
}

int nts::LoggerComponent::getBounds()
{
    return 10;
}
