#include <fstream>
#include <iostream>

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
  int result = 0;

  for (char &ch : input) {
    if (ch == '(') {
      result += 1;
    } else {
      result -= 1;
    }
  }
  return result;
}

int part2(std::string fileInput) {
  std::string input = fileInput;
  int result = 0;
  int charPosition = 0;

  for (char &ch : input) {
    if (ch == '(' && result >= 0) {
      result += 1;
      charPosition += 1;
    } else if (ch == ')' && result >= 0) {
      result -= 1;
      charPosition += 1;
    } else
      break;
  }
  return charPosition;
}

int main() {
  std::string filename("input.txt");
  std::string input;
  input = readFile(filename);

  std::cout << "Part 1 answer: " << part1(input)
            << "\nPart 2 answer: " << part2(input) << "\n";
}
