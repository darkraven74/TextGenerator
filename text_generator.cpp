//
// Created by darkraven on 01.12.15.
//

#include "text_generator.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>


text_generator::text_generator(std::string input_file)
    : words_number(0)
{
    std::ifstream input_stream(input_file.c_str());
    std::string line;
    const char space_delimeter = ' ';
    while (getline(input_stream, line)) {
        std::istringstream line_stream(line);
        std::string word;
        while (getline(line_stream, word, space_delimeter)) {
            word.erase(std::remove_if(word.begin(), word.end(),
                                      [](char c)
                                      { return std::ispunct(c) || !std::isprint(c); }),
                       word.end());
            if (word.length()) {
                std::map<std::string, long long>::iterator it = words_frequency.find(word);
                if (it != words_frequency.end()) {
                    it->second++;
                }
                else {
                    words_frequency.insert(std::pair<std::string, long long>(word, 1));
                }
                words_number++;
            }
        }
    }
    double cur_border = 0;
    for (auto &map_entry : words_frequency) {
        std::string word = map_entry.first;
        long long frequency = map_entry.second;
        double probability = ((double) frequency) / words_number;
        words_probability.insert(std::pair<double, std::string>(cur_border + probability, word));
        cur_border += probability;
    }
}
std::vector<std::string> text_generator::generate(int output_size)
{
    std::vector<std::string> answer;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<> distribution(0.0, 1.0);
    for (int i = 0; i < output_size; i++) {
        double random_value = distribution(generator);
        auto iter = words_probability.lower_bound(random_value);
        answer.push_back(iter->second);
    }
    return answer;
}
