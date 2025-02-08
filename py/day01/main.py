def read_input(filename='input.txt'):
    with open(filename, 'r') as file:
        return file.read().strip()

def part1(instructions):
    floor = 0
    for char in instructions:
        if char == '(':
            floor += 1
        elif char == ')':
            floor -= 1
    return floor

def part2(instructions):
    floor = 0
    charPosition = 0
    for char in instructions:
        if char == '(':
            floor += 1
        elif char == ')':
            floor -= 1
        
        charPosition += 1
        if floor == -1:
            return charPosition
    return 0

def main():
    input = read_input()
    print(part1(input))
    print(part2(input))

if __name__ == "__main__":
    main()
