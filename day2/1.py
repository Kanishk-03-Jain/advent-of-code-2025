
def invalid(i):
    num = str(i)
    reqlen = len(num)//2
    return (num[:reqlen] == num[reqlen:])

cnt = 0
with open('day2/input.txt', 'r') as file:
    for line in file:
        ranges = line.strip().split(",")
        for ran in ranges:
            st, end = map(int, ran.split("-"))
            for i in range(st, end + 1):
                if (invalid(i)):
                    print(i)
                    cnt += i

print(cnt)
