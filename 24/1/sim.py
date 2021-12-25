import itertools

diffs = [4, 16, 14, -13, 11, 13, -7, 7, -12, 15, -16, -9, -8, -8]
maxans = 0

def sim(i_1, i_2, i_3, i_5, i_6, i_8, i_10):
    instructions = [i_1, i_2, i_3, "pop", i_5, i_6, "pop", i_8, "pop", i_10, "pop", "pop", "pop", "pop"]
    stack = []

    for i, pair in enumerate(zip(instructions, diffs)):
        instr, diff = pair
        if not instr == "pop":
            stack.append(instr + diff)
        else:
            instructions[i] = stack.pop() + diff
            if instructions[i] >= 10 or instructions[i] <= 0:
                return 0

    return int(''.join(str(instr) for instr in instructions))

maxans = 0
for i_1, i_2, i_3, i_5, i_6, i_8, i_10 in itertools.product(range(1, 10), repeat=7):
    maxans = max(maxans, sim(i_1, i_2, i_3, i_5, i_6, i_8, i_10))

print(maxans)
