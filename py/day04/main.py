import hashlib

def part1(secret_key, prefix='00000'):
    num = 1

    while True:
        hash_input = secret_key + str(num)
        hash_result = hashlib.md5(hash_input.encode()).hexdigest()
        if hash_result.startswith(prefix):
            return num
        num += 1

def part2(secret_key, prefix='000000'):
    num = 1

    while True:
        hash_input = secret_key + str(num)
        hash_result = hashlib.md5(hash_input.encode()).hexdigest()
        if hash_result.startswith(prefix):
            return num
        num += 1

def main():
    input = 'bgvyzdsv'
    print(part1(input))
    print(part2(input))
    
if __name__ == "__main__":
    main()
