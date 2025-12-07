splits = 0
with open("input.txt") as file:
    lines = [line.rstrip("\n") for line in file]

    for row in range(1, len(lines)):
        for col in range(len(lines[row])):
            if lines[row - 1][col] == 'S':
                if lines[row][col] == '^':
                    lines[row] = lines[row][:col - 1] + "S.S" + lines[row][col + 2:]
                    splits += 1
                else:
                    lines[row] = lines[row][:col] + "S" + lines[row][col + 1:]

    print(splits)
    print(lines[-1].count('S'))



