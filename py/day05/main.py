import re

def read_input(filename='input.txt'):
    with open(filename, 'r') as file:
        return file.read().strip().splitlines()

def has_naughty_substring(word, substrings = ['ab','cd','pq','xy']):
    return any(sub in word for sub in substrings)

def has_consecutive_letters(word):
    for i in range(len(word) - 1):
        if word[i] == word[i + 1]:
            return True
    return False

def has_3vowels(word):
    vowels = "aeiouAEIOU"
    vowel_count = sum(1 for letter in word if letter in vowels)
    return vowel_count >= 3

def part1(strings):
    nice_strings = 0
    for string in strings:
        if has_naughty_substring(string):
            continue
        if has_consecutive_letters(string) and has_3vowels(string):
            nice_strings += 1
    return nice_strings

def part2(strings):
    nice_strings = 0
    for string in strings:
        #if has pair of two letters and has repeated spaced pair
        if bool(re.search(r'(..).*\1', string)) and bool(re.search(r'(.).\1', string)):
            nice_strings += 1
    return nice_strings

def main():
    input = read_input()
    print(part1(input))
    print(part2(input))
    
if __name__ == "__main__":
    main()
