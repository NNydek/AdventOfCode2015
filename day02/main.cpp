#include <algorithm>
#include <fstream>
#include <initializer_list>
#include <iostream>
#include <string>
#include <vector>

std::string readFile(std::string filename) {
  std::string line;
  std::string contents;
  std::ifstream fs(filename);
  while (std::getline(fs, line)) {
    contents += line + 'x';
  }
  return contents;
}

int part1(std::string fileInput) {
  std::string input = fileInput;

  int length, width, height;
  std::string ch = "x";
  std::size_t pos = 0;

  int flag = 0;
  int surfaceArea = 0;
  int temp = 0;
  int result = 0;

  while ((pos = input.find(ch)) != std::string::npos) {
    if (flag == 0) {
      length = stoi(input.substr(0, pos));
      input.erase(0, pos + ch.length());
      flag = 1;
    } else if (flag == 1) {
      width = stoi(input.substr(0, pos));
      input.erase(0, pos + ch.length());
      flag = 2;
    } else if (flag == 2) {
      height = stoi(input.substr(0, pos));
      input.erase(0, pos + ch.length());
      flag = 0;

      surfaceArea += 2 * (length * width + width * height + height * length);
      temp = std::max({length, width, height});

      if (length == temp)
        length = 1;
      else if (width == temp)
        width = 1;
      else if (height == temp)
        height = 1;
      result += length * width * height;
    }
  }
  result += surfaceArea;
  return result;
}

int part2(std::string fileInput) {
  std::string input = fileInput;

  int length, width, height;
  std::string ch = "x";
  std::size_t pos = 0;

  int flag = 0;
  int surfaceArea = 0;
  int temp = 0;
  int result = 0;

  while ((pos = input.find(ch)) != std::string::npos) {
    if (flag == 0) {
      length = stoi(input.substr(0, pos));
      input.erase(0, pos + ch.length());
      flag = 1;
    } else if (flag == 1) {
      width = stoi(input.substr(0, pos));
      input.erase(0, pos + ch.length());
      flag = 2;
    } else if (flag == 2) {
      height = stoi(input.substr(0, pos));
      input.erase(0, pos + ch.length());
      flag = 0;

      surfaceArea += length * width * height;
      temp = std::max({length, width, height});

      if (length == temp)
        length = 0;
      else if (width == temp)
        width = 0;
      else if (height == temp)
        height = 0;
      result += 2 * (length + width + height);
    }
  }
  result += surfaceArea;
  return result;
}

int main() {
  std::string filename("input.txt");
  std::string input;
  input = readFile(filename);

  std::cout << "Part 1 answer: " << part1(input)
            << "\nPart 2 answer: " << part2(input) << "\n";
}
