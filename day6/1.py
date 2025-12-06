nums = []
with open("input.txt") as file:
    for line in file:
        num = line.strip().split(" ")
        row = []
        for nu in num:
            nu = nu.strip()
            if nu:
                row.append(nu)
        nums.append(row)

total = 0
for col in range(len(nums[0])):
    op = nums[-1][col]
    sum = 0
    if op == '*':
        sum = 1
    for i in range(len(nums) - 1):
        if (op == '*'):
            sum *= int(nums[i][col])
        elif (op == '+'):
            sum += int(nums[i][col])
    total += sum

print(total) 