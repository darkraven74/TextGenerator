#include <iostream>
#include "text_generator.h"

void print_usage()
{
    std::cout << "usage: text_generator --input_file <text file to analyze> --output_size <number of words>"
        << std::endl;
}

int main(int argc, char *argv[])
{
    std::string input_file;
    int output_size;
    for (int i = 1; i < argc; i++) {
        std::string sarg = argv[i];
        if (sarg == "--input_file") {
            i++;
            input_file = argv[i];
        }
        else if (sarg == "--output_size") {
            i++;
            output_size = atoi(argv[i]);
        }
        if (sarg == "--help") {
            print_usage();
            exit(0);
        }
    }

    text_generator generator(input_file);
    std::vector<std::string> answer = generator.generate(output_size);
    for (auto str : answer) {
        std::cout << str << std::endl;
    }

    return 0;
}