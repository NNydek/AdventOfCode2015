import unittest
import re

class tests(unittest.TestCase):
    def test_part1(self):
        instructions = ["turn on 0,0 through 999,999","toggle 0,0 through 999,0","turn off 499,499 through 500,500"]
        self.assertEqual(part1([instructions[0]]), 1000000)
        self.assertEqual(part1([instructions[1]]), 1000)
        self.assertEqual(part1([instructions[2]]), 0)
    
    def test_part2(self):
        instructions = ["turn on 0,0 through 0,0", "toggle 0,0 through 999,999"]
        self.assertEqual(part2([instructions[0]]), 1)
        self.assertEqual(part2([instructions[1]]), 2000000)

def read_input(filename='input.txt'):
    with open(filename, 'r') as file:
        return file.read().strip().splitlines()

def parse_instruction(instruction):
    #Captures action, starting x1, y1 coordinates and ending x2, y2 coordinates
    match = re.match(r"(turn on|turn off|toggle) (\d+),(\d+) through (\d+),(\d+)", instruction)
    if match:
        action, x1, y1, x2, y2 = match.groups()
        return action, int(x1), int(y1), int(x2), int(y2)
    return None

def part1(instructions):
    grid = [[0] * 1000 for _ in range(1000)]
    for instruction in instructions:
        action, x1, y1, x2, y2 = parse_instruction(instruction)
        for x in range(x1, x2 + 1):
            for y in range(y1, y2 + 1):
                match action:
                    case "turn on": grid[x][y] = 1
                    case "turn off": grid[x][y] = 0
                    case "toggle": grid[x][y] = not grid[x][y]
    return sum(row.count(1) for row in grid)

def part2(instructions):
    grid = [[0] * 1000 for _ in range(1000)]
    for instruction in instructions:
        action, x1, y1, x2, y2 = parse_instruction(instruction)
        for x in range(x1, x2 + 1):
            for y in range(y1, y2 + 1):
                match action:
                    case "turn on": grid[x][y] += 1
                    case "turn off": grid[x][y] = max(0, grid[x][y] - 1)
                    case "toggle": grid[x][y] += 2
    return sum(sum(row) for row in grid)

def main():
    #unittest.main()
    input = read_input()
    print(part1(input))
    print(part2(input))
    
if __name__ == "__main__":
    main()
