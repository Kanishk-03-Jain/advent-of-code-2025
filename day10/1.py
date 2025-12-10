cnt = 0
with open("input.txt") as file:
    for line in file:
        parts = line.strip().split()
        diagram = list(parts[0].rstrip(']').lstrip('['))
        buttons = []
        for i in range(1, len(parts) - 1):
            button = parts[i].rstrip(')').lstrip('(').split(',')
            buttons.append(list(int(b) for b in button))
        joltage = parts[-1]
        init_config = ['.'] * len(diagram)
        def dfs(i, curr_config):
            if curr_config == diagram:
                return 0
            if i == len(buttons):
                return float('inf')
            toggle = curr_config.copy()
            for b in buttons[i]:
                if toggle[b] == '.':
                    toggle[b] = '#'
                else:
                    toggle[b] = '.'
            return min(1 + dfs(i + 1, toggle), dfs(i + 1, curr_config))
            
        cnt += dfs(0, init_config)
print(cnt)




