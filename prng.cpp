// prng.cpp
// Created by Mason Antram on 1/10/2026.
// Creates a pseudo-random number

#include<iostream>
#include<ctime>
#include<unistd.h>
#include<fstream>

int main()
{
    std::string text;
    int random = 0;

    while (true)
    {
        sleep(1);
        srand(time(0));
        std::ifstream prngfilein("prng-service.txt");
        prngfilein >> text;
        prngfilein.close();
        std::cout << "text = " << text << std::endl;

        if (text == "run") {
            random = rand();
            std::ofstream prngfileout("prng-service.txt");
            prngfileout << random;
            prngfileout.close();

        }

        std::cout << "random is " << random << std::endl;
    }

    return 0;
}
