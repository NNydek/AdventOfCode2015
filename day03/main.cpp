#include <iostream>
#include <fstream>
#include <string>

std::string readFile(std::string filename) {
    std::string contents;
    char ch;
    std::fstream fin(filename, std::fstream::in);
    while (fin >> ch)
        contents += ch;
    return contents;
}

int part1(std::string fileInput) {
    std::string input = fileInput;
    const auto columns = 1000, rows = 1000;
    auto santaArray = new int[rows][columns];
    auto santaX = columns / 2, santaY = rows / 2;

    int result = 1;
    santaArray[santaX][santaY] = 1;

    for (char& ch : input) {
        if (santaArray[santaX][santaY] != 1) {
            santaArray[santaX][santaY] = 1;
            result += 1;
        }
        switch (ch) {
        case '^':
            santaY--;
            break;
        case 'v':
            santaY++;
            break;
        case '>':
            santaX++;
            break;
        case '<':
            santaX--;
            break;
        default:
            break;
        }
    }
    return result;
}

int main() {
    std::string filename("input.txt");
    std::string input;
    input = readFile(filename);

    std::cout << "Part 1 answer: " << part1(input) << '\n';
}