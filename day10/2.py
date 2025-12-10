from z3 import *

cnt = 0

with open("input.txt") as file:
    for line in file:
        parts = line.strip().split()

        buttons = []
        for i in range(1, len(parts) - 1):
            b = parts[i].strip("()").split(",")
            buttons.append([int(x) for x in b])

        counters = list(int(x) for x in parts[-1].strip("{}").split(","))

        # z3 optimize
        opt = Optimize()
        
        x = [Int(f'x_{i}') for i in range(len(buttons))]

        for var in x:
            opt.add(var >= 0)

        # For each counter j, the sum of presses must equal target[j]
        for j in range(len(counters)):
            # Find which buttons affect counter j
            relevant_buttons = [x[i] for i in range(len(buttons)) if j in buttons[i]]
            # Sum should be equal to counters
            opt.add(Sum(relevant_buttons) == counters[j])

        # Objective: Minimize total button presses
        opt.minimize(Sum(x))

        # Solve
        if opt.check() == sat:
            model = opt.model()
            # Calculate sum of values in the solution
            cnt += sum(model[v].as_long() for v in x)
        else:
            print(f"No solution")

print(cnt)
