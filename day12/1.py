shapes = []
cnt = 0
with open("input.txt") as file:
    lines = [line.rstrip("\n") for line in file]
    i = 0
    while i < len(lines):
        if "x" in lines[i]:
            parts = lines[i].split()
            width, length = parts[0][:-1].split("x")
            grid = [['.' for _ in range(int(length))] for _ in range(int(width))]
            
            total_area = 0
            for index in range(1, len(parts)):
                total_area += int(parts[index]) * sum(g.count("#") for g in shapes[index - 1])
                # print(total_area)

            if total_area <= int(width) * int(length):
                cnt += 1
            i += 1
        elif ":" in lines[i]:
            i += 1
            shape = []
            while lines[i] != "":
                shape.append(lines[i])
                i += 1
            shapes.append(shape)
            i += 1
print(cnt)