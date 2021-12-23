from math import *
from collections import *
from itertools import *

lines = [l.rstrip() for l in open("../input.in", "r+").readlines()]

def solve():
    pass

def process(line):
    result = []
    state, coordinates = line.split(" ")
    result.append(1 if state == "on" else 0)
    for coord in coordinates.split(","):
        nums = coord[2:].split("..")
        result.append(tuple(int(num) for num in nums))
    return result

# Returns which bounds are within the cube
def delinquents(xr, yr, zr, oxr, oyr, ozr):
    result = []
    if oxr[0] < xr[0]:
        result.append(("x", 0))
    if oxr[1] > xr[1]:
        result.append(("x", 1))
    if oyr[0] < yr[0]:
        result.append(("y", 0))
    if oyr[1] > yr[1]:
        result.append(("y", 1))
    if ozr[0] < zr[0]:
        result.append(("z", 0))
    if ozr[1] > zr[1]:
        result.append(("z", 1))
    return result

#cubes_on = []
cubes = [[[False for i in range(101)] for j in range(101)] for k in range(101)]
for line in lines:
    # nextcubes_on = []
    state, xr, yr, zr = process(line)
    for i in range(max(0, xr[0] + 50), min(101, xr[1] + 51)):
        for j in range(max(0, yr[0] + 50), min(101, yr[1] + 51)):
            for k in range(max(0, zr[0] + 50), min(101, zr[1] + 51)):
                cubes[i][j][k] = state
        
        #cubes_on.append((xr, yr, zr))
    #else:
        #for oxr, oyr, ozr in cubes_on:
            # Cases:
            #within = delinquents(xr, yr, zr, oxr, oyr, ozr)
            # Cube encompasses the cube
            #if len(within) == 0:
               # continue
            # Cube chops through the cube in half
           # if len(within) == 1
            # Cube chops through a cube in fourth
            # Cube chops through a cube in eighths
            # Cube does not intersect

countc = 0
for square in cubes:
    for row in square:
        for ele in row:
            if ele:
                countc += 1
print(countc)