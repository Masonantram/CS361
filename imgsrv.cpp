// imgsrv.cpp
// Created by Mason Antram 1/10/2026.
// Takes pseudo random number from image-service.txt to determine which photo in the dataset to display.

#include<iostream>
#include<fstream>
#include<filesystem>
#include<unistd.h>

int main()
{

    std::filesystem::path images = "C:\\Users\\mason\\Desktop\\School\\OSU\\CS361\\Week1\\program1\\gen1testset";
    std::ifstream filein("prng-service.txt");
    int size = std::distance(std::filesystem::directory_iterator(images), std::filesystem::directory_iterator{});
    int index = 0;
    int text;

    while(true)
    {
        std::filesystem::path newpath = images;
        if (filein >> text)
        {
            sleep(1);
            filein >> text;
            filein.close();
            index = text % size;
            newpath += "\\";
            newpath += std::to_string(index);
            newpath += ".png";
            std::ofstream fileout("image-service.txt");
            fileout << newpath;
            fileout.close();
            //test string
            std::cout << "file path = " << newpath << std::endl;

        }
    }

    return 0;
};