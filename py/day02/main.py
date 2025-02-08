def read_input(filename='input.txt'):
    with open(filename, 'r') as file:
        return file.read().strip().splitlines()

def part1(dimensions):
    total_paper = 0
    for dim in dimensions:
        length, width, height = map(int, dim.split('x'))

        surface_area = 2 * (length*width + width*height + height*length)
        smallest_side = min(length*width, width*height, height*length)
        
        total_paper += surface_area + smallest_side
    return total_paper

def part2(dimensions):
    total_ribbon = 0
    for dim in dimensions:
        length, width, height = map(int, dim.split('x'))
        smallest, second_smallest = sorted([length, width, height])[:2]
        ribbon_wrap = 2 * (smallest + second_smallest)
        ribbon_bow = length * width * height

        total_ribbon += ribbon_wrap + ribbon_bow
    return total_ribbon

def main():
    input = read_input()
    print(part1(input))
    print(part2(input))

if __name__ == "__main__":
    main()
