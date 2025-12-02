
def invalid(i):
    num = str(i)

    for i in range(1, len(num)):
        if (len(num) % i): continue
        flag = True
        j = 0
        while (j < len(num)):
            if (num[:i] != num[j:j+i]):
                flag = False
            j += i
        if flag:
            return True
    return False

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
