def read_input(filename='input.txt'):
    with open(filename, 'r') as file:
        return file.read().strip()

#Part One
def find_floor(instructions):
    floor = 0
    for char in instructions:
        if char == '(':
            floor += 1
        elif char == ')':
            floor -= 1
    return floor

#Part Two
def find_basement_position(instructions):
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
    instructions = read_input()
    #Part One
    print(find_floor(instructions))
    
    #Part Two
    print(find_basement_position(instructions))


if __name__ == "__main__":
    main()
