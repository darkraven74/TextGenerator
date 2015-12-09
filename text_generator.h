//
// Created by darkraven on 01.12.15.
//

#ifndef TEXTGENERATOR_TEXT_GENERATOR_H
#define TEXTGENERATOR_TEXT_GENERATOR_H

#include <string>
#include <vector>
#include <map>

class text_generator
{
public:
    text_generator(std::string input_file);
    std::vector<std::string> generate(int output_size);

private:
    std::map<std::string, long long> words_frequency;
    std::map<double, std::string> words_probability;
    long long words_number;
};


#endif //TEXTGENERATOR_TEXT_GENERATOR_H
