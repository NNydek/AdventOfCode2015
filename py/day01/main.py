def read_input(filename='input.txt'):
    with open(filename, 'r') as file:
        return file.read().strip()

def find_floor(instructions):
    floor = 0
    for char in instructions:
        if char == '(':
            floor += 1
        elif char == ')':
            floor -= 1
    return floor

def main():
    instructions = read_input()
    print(find_floor(instructions))

if __name__ == "__main__":
    main()
