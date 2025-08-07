/*
** EPITECH PROJECT, 2025
** Nanotekspice
** File description:
** main
*/

#include "Nts.hpp"
#include <iostream>
#include <fstream>

int help_func(void)
{
    std::ifstream help("README");
    std::string line;

    while(std::getline(help, line)) {
        std::cout << line << std::endl;
    }
    help.close();
    return 0;
}

int main(int ac, char **av)
{
    nts::Nts nano;

    if (ac != 2)
        return 84;
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        return help_func();
    try {
        nano.parsing(av[1]);
        nano.launch();
    } catch (const nts::Nts::Error &error) {
        std::cerr << "ERROR - " << error.what() << std::endl;
        return 84;
    }
    return 0;
}
