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
}
std::vector<std::string> text_generator::generate(int output_size)
{
    std::vector<std::string> answer;
    for (auto &map_entry : words_frequency) {
        std::string word = map_entry.first;
        long long frequency = map_entry.second;
        long long answer_frequency = (long long) floor(1.0 * frequency / words_number * output_size);
        for (int i = 0; i < answer_frequency; i++) {
            answer.push_back(word);
        }
    }
    std::random_shuffle(answer.begin(), answer.end());
    return answer;
}
