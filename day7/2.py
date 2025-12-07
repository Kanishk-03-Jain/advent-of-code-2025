with open("input.txt") as file:
    lines = [line.rstrip("\n") for line in file]
    beams = [0] * len(lines[0])
    for i, col in enumerate(lines[0]):
        if col == 'S':
            beams[i] = 1

    for row in range(1, len(lines)):
        new_beams = [0] * len(lines[row])
        for col in range(len(lines[row])):
            if lines[row - 1][col] == 'S':
                if lines[row][col] == '^':
                    lines[row] = lines[row][:col - 1] + "S.S" + lines[row][col + 2:]
                    new_beams[col - 1] += beams[col]
                    new_beams[col + 1] += beams[col]
                    splits += 1
                else:
                    new_beams[col] += beams[col]
                    lines[row] = lines[row][:col] + "S" + lines[row][col + 1:]
        beams = new_beams
    print(sum(new_beams))



