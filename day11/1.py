from collections import defaultdict

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
print(dfs("you"))