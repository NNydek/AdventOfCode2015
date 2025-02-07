def read_input(filename='input.txt'):
    with open(filename, 'r') as file:
        return file.read().strip().splitlines()

#Part One
def calculate_wrapping_paper(dimensions):
    total_paper = 0
    for dim in dimensions:
        length, width, height = map(int, dim.split('x'))

        surface_area = 2 * (length*width + width*height + height*length)
        smallest_side = min(length*width, width*height, height*length)
        
        total_paper += surface_area + smallest_side
    return total_paper

#Part Two
def calculate_ribbon(dimensions):
    total_ribbon = 0
    for dim in dimensions:
        length, width, height = map(int, dim.split('x'))
        smallest, second_smallest = sorted([length, width, height])[:2]
        ribbon_wrap = 2 * (smallest + second_smallest)
        ribbon_bow = length * width * height

        total_ribbon += ribbon_wrap + ribbon_bow
    return total_ribbon

def main():
    dimensions = read_input()
    #Part One
    print(calculate_wrapping_paper(dimensions))

    #Part Two
    print(calculate_ribbon(dimensions))

if __name__ == "__main__":
    main()
