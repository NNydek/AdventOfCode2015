#include <fstream>
#include <iostream>
#include <string>

std::string readFile(std::string fileName) {
    std::string line;
    std::string contents;
    std::ifstream fs(fileName);
    while (std::getline(fs, line)) {
        contents += line + '\n';
    }
    return contents;
}

int part1(std::string fileInput) {
    std::string input = fileInput;

    std::size_t pos = 0;
    std::string word;

    int result = 0;
    int vowel = 0;
    int req = 1;

    while ((pos = input.find('\n')) != std::string::npos) {
        word = input.substr(0, pos);

        // 3rd requirement
        if (word.find("ab") != std::string::npos ||
            word.find("cd") != std::string::npos ||
            word.find("pq") != std::string::npos ||
            word.find("xy") != std::string::npos) {
            req = 0;
        }
        // 2nd requirement
        if (req == 1) {
            for (size_t i = 0; i < word.size(); ++i) {
                if (word[i] == word[i + 1]) {
                    req = 2;
                    break;
                }
            }
        }
        // 1st requirement
        if (req == 2) {
            for (size_t i = 0; i < word.size(); ++i) {
                if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
                    word[i] == 'o' || word[i] == 'u') {
                    vowel++;
                }
                if (vowel == 3) {
                    result++;
                    break;
                }
            }
        }
        req = 1;
        vowel = 0;
        input.erase(0, pos + 1);
    }
    return result;
}

int part2(std::string fileInput) {
    std::string input = fileInput;

    std::size_t pos = 0;
    std::string word;

    int result = 0;
    int req = 1;

    while ((pos = input.find('\n')) != std::string::npos) {
        word = input.substr(0, pos);

        // 2nd requirement
        if (req == 1) {
            for (size_t i = 0; i < (word.size() - 2); ++i) {
                if (word[i] == word[i + 2]) {
                    req = 2;
                    break;
                }
            }
        }
        // 1st requirement
        if (req == 2) {
            for (size_t i = 0; i < (word.size() - 2); ++i) {
                for (size_t j = 0; j < (word.size() - (3 + i)); ++j) {
                    if (word.substr(i, 2) == word.substr(i + j + 2, 2)) {
                        result++;
                        std::cout << result << ' ' << word << std::endl;
                        goto end;
                    }
                }
            }
        }
    end:
        req = 1;
        input.erase(0, pos + 1);
    }
    return result;
}

int main() {
    std::string fileName = "input.txt";
    std::string input;
    input = readFile(fileName);

    std::cout << "Part 1 answer: " << part1(input)
              << "\nPart 2 answer: " << part2(input) << '\n';
}
