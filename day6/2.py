total = 0
with open("input.txt") as file:
    lines = file.readlines()
    op = ''
    sum = -1
    for col in range(len(lines[0]) - 1):
        num = ""
        for line in lines:
            # print(line)
            if line[col] == '*' or line[col] == '+':
                op = line[col]
                continue
            if line[col]:
                num += line[col]
                
        num = num.strip()
        if num == "":
            total += sum
            print(sum)
            sum = -1
            continue
        if sum == -1:
            if op == '+':
                sum = 0
            elif op == '*':
                sum = 1
        
        if op == '+':
            sum += int(num)
        elif op == '*':
            sum *= int(num)
        # print(sum)
        # print(total)
    
print(total + sum)

