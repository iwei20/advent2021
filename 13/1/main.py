from collections import *
lines = [l.rstrip() for l in open("../input.in", "r+").readlines()]

size = 2000
grid = [[False for _ in range(size)] for __ in range(size)]

start_fold = 0
for i, line in enumerate(lines):
    if not line:
        start_fold = i + 1
        break

    a, b = line.split(",")
    grid[int(a)][int(b)] = True

for line in lines[start_fold:]:
    axis, intercept = line.split()[-1].split("=")
    intercept = int(intercept)

    for i in range(intercept + 1, size):
        if intercept - (i - intercept) >= 0:
            for j in range(size):
                if axis == "x":
                    if grid[i][j]:
                        grid[intercept - (i - intercept)][j] = True
                        grid[i][j] = False    
                if axis == "y":
                    if grid[j][i]:
                        grid[j][intercept - (i - intercept)] = True
                        grid[j][i] = False   

with open("out.out", "w+") as fout:
    count = 0
    for i in range(size):
        for j in range(size):
            fout.write("#" if grid[j][i] else ".")
            if grid[j][i]:
                count += 1
        fout.write("\n")


print(count)

