from math import *
from collections import *
from itertools import *

ITERATIONS = 2

lines = [l.rstrip() for l in open("../input.in", "r+").readlines()]

algo = lines[0]

coords = defaultdict(int)

for i, row in enumerate(lines[2:]):
    for j, ele in enumerate(row):
        if ele == "#":
            coords[(i, j)] = 1
        else:
            coords[(i, j)] = 0
        #coords.append((i - int(len(lines) / 2), j - int(len(lines[0]) / 2)))

def sim(itr):
    global coords

    nextcoords = defaultdict(lambda:1-itr%2)

    minr = min(pair[0] for pair in coords) - 1
    maxr = max(pair[0] for pair in coords) + 2
    minc = min(pair[1] for pair in coords) - 1
    maxc = max(pair[1] for pair in coords) + 2

    for potox in range(minr, maxr):
        for potoy in range(minc, maxc):
            algo_index = 0

            for dr in range(-1, 2):
                for dc in range(-1, 2):
                    algo_index *= 2

                    if coords[(potox + dr, potoy + dc)] == 1:
                        algo_index += 1
            #print(int(algo_index, 2))
            if algo[algo_index] == "#":
                nextcoords[(potox, potoy)] = 1
            else:
                nextcoords[(potox, potoy)] = 0

    print(len(nextcoords))
    print(len([nextcoord for nextcoord in nextcoords if nextcoords[nextcoord] == 1]))
    print()
    return nextcoords

for i in range(ITERATIONS):
    tempcoords = sim(i)
print(len([tempcoord for tempcoord in tempcoords if tempcoords[tempcoord] == 1]))
print(len([coord for coord in coords if coords[coord] == 1]))