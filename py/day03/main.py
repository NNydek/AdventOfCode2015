def read_input(filename='input.txt'):
    with open(filename, 'r') as file:
        return file.read().strip()

def part1(directions):
    unique_visited_positions = {(0,0)}
    santa = [0, 0]
    for dir in directions:
        match dir:
            case '>': santa[0] += 1
            case '<': santa[0] -= 1
            case '^': santa[1] += 1
            case 'v': santa[1] -= 1
        unique_visited_positions.add(tuple(santa))
    return len(unique_visited_positions)

def part2(directions):
    santa_unique_positions = {(0,0)}
    robosanta_unique_positions = {(0,0)}
    santa, robosanta = [0, 0], [0, 0]
    turn = 1 #1 for santa, 0 for robosanta
    for dir in directions:
        if turn == 1:
            match dir:
                case '>': santa[0] += 1
                case '<': santa[0] -= 1
                case '^': santa[1] += 1
                case 'v': santa[1] -= 1
            santa_unique_positions.add(tuple(santa))
        if turn == 0:
            match dir:
                case '>': robosanta[0] += 1
                case '<': robosanta[0] -= 1
                case '^': robosanta[1] += 1
                case 'v': robosanta[1] -= 1
            robosanta_unique_positions.add(tuple(robosanta))
        turn = 1 - turn

    combined_unique_positions = santa_unique_positions.union(robosanta_unique_positions)
    return len(combined_unique_positions)

def main():
    input = read_input()
    print(part1(input))
    print(part2(input))

if __name__ == "__main__":
    main()
