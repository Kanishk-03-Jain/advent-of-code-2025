from collections import defaultdict
import time

adj = defaultdict(list)
with open("input.txt") as file:
    for line in file:
        parts = line.split()
        for i in range(1, len(parts)):
            adj[parts[0][:-1]].append(parts[i])

def dfs(curr):
    if curr == "out":
        return 1
    ans = 0
    for child in adj[curr]:
        ans += dfs(child)
    return ans

start = time.perf_counter()
print(dfs("you"))
end = time.perf_counter()
print(f"Time taken: {end - start:.6f} seconds")