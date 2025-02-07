#include <fstream>
#include <iostream>
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

  for (char &ch : input) {
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

int part2(std::string fileInput) {
  std::string input = fileInput;
  const auto columns = 1000, rows = 1000;
  auto santaArray = new int[rows][columns];
  auto roboSantaArray = new int[rows][columns];
  auto santaX = columns / 2, santaY = rows / 2;
  auto roboSantaX = columns / 2, roboSantaY = rows / 2;

  int turn = 0;
  int result = 1;

  santaArray[santaX][santaY] = 1;
  roboSantaArray[roboSantaX][roboSantaY] = 1;

  for (char &ch : input) {
    if (santaArray[santaX][santaY] != 1) {
      santaArray[santaX][santaY] = 1;
      roboSantaArray[santaX][santaY] = 1;

      result += 1;
    }
    if (roboSantaArray[roboSantaX][roboSantaY] != 1) {
      roboSantaArray[roboSantaX][roboSantaY] = 1;
      santaArray[roboSantaX][roboSantaY] = 1;

      result += 1;
    }

    switch (ch) {
    case '^':
      if (turn % 2 == 0)
        santaY--;
      else
        roboSantaY--;
      break;
    case 'v':
      if (turn % 2 == 0)
        santaY++;
      else
        roboSantaY++;
      break;
    case '>':
      if (turn % 2 == 0)
        santaX++;
      else
        roboSantaX++;
      break;
    case '<':
      if (turn % 2 == 0)
        santaX--;
      else
        roboSantaX--;
      break;
    default:
      break;
    }
    turn += 1;
  }
  return result;
}

int main() {
  std::string filename("input.txt");
  std::string input;
  input = readFile(filename);

  std::cout << "Part 1 answer: " << part1(input)
            << "\nPart 2 answer: " << part2(input) << '\n';
}