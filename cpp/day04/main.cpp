#include "md5.h"
#include <string>

int part1(std::string input) {
  int result = 0;

  while (md5(input + std::to_string(++result)).compare(0, 5, "00000") != 0)
    ;

  return result;
}

int part2(std::string input) {
  int result = 0;

  while (md5(input + std::to_string(++result)).compare(0, 6, "000000") != 0)
    ;

  return result;
}

int main() {
  std::string input = "bgvyzdsv";

  std::cout << "Part 1 answer: " << part1(input)
            << "\nPart 2 answer: " << part2(input) << '\n';
}
