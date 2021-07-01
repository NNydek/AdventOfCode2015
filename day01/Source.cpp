#include <iostream>
#include <fstream>

std::string readFile(std::string filename) {
    std::string contents;
    char ch;
    std::fstream fin(filename, std::fstream::in);
    while (fin >> ch)
        contents += ch;
    return contents;
}

void part1() {
    std::string filename("input.txt");
    std::string input;
    input = readFile(filename);
    int result = 0;

    for (char& ch : input) {
        if (ch == '(') {
            result += 1;
        }
        else {
            result -= 1;
        }
    }
    std::cout << result;
}

void part2() {
    std::string filename("input.txt");
    std::string input;
    input = readFile(filename);
    int result = 0;
    int charPosition = 0;

    for (char& ch : input) {
        if (ch == '(' && result >= 0) {
            result += 1;
            charPosition += 1;
        }
        else if (ch == ')' && result >= 0) {
            result -= 1;
            charPosition += 1;
        }
        else
            break;
    }
    std::cout << charPosition;
}

int main() {
    part1();
    std::cout << "\n";
    part2();
}

