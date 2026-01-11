// prng.cpp
// Created by Mason Antram on 1/10/2026.
// Creates a pseudo-random number

#include<iostream>
#include<ctime>
#include<unistd.h>
#include<fstream>


int prng () {

    std::string text;
    int random = 0;

    sleep(1);
    srand(time(0));
    std::ifstream prngfile("prng-service.txt");
    prngfile >> text;

    if (text == "default") {
        random = rand();
    }

    return random;

}

int main()
{

    std::cout << "random number is " << prng() << std::endl;

    return 0;
}
