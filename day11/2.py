from collections import defaultdict
from functools import cache

adj = defaultdict(list)
with open("input.txt") as file:
    for line in file:
        parts = line.split()
        for i in range(1, len(parts)):
            adj[parts[0][:-1]].append(parts[i])

@cache
def dfs(curr, fft, dac):
    if curr == "out":
        return fft and dac
    ans = 0
    for child in adj[curr]:
        if child == "fft":
            ans += dfs(child, True, dac)
        elif child == "dac":
            ans += dfs(child, fft, True)
        else:
            ans += dfs(child, fft, dac)
    return ans

print(dfs("svr", False, False))