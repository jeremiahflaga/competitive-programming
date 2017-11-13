
def getEntriesBefore42(numbers):
    lst = []
    for n in numbers:
        if n == 42:
            break
        else:
            lst.append(n)

    return lst


def run():
    numbers = []
    while True:
        try:            
            line = input()
        except EOFError:
            break
        
        if line.strip() == '':
            break
        else:
            numbers.append(int(line))

    for n in getEntriesBefore42(numbers):
        print(n)


if __name__ == '__main__':
    run()