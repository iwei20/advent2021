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
    result = defaultdict(list)
    if oxr[0] < xr[0]:
        result["x"].append(0)
    if oxr[1] > xr[1]:
        result["x"].append(1)
    if oyr[0] < yr[0]:
        result["y"].append(0)
    if oyr[1] > yr[1]:
        result["y"].append(1)
    if ozr[0] < zr[0]:
        result["z"].append(0)
    if ozr[1] > zr[1]:
        result["z"].append(1)
    return result

idx = {"x":0, "y":1, "z":2}
# Eliminate a region and split the rest into prisms
def splitall(xr, yr, zr, oxr, oyr, ozr):
    # Bound xr, yr, zr to the edges of the cube
    xr[0] = max(xr[0], oxr[0])
    xr[1] = min(xr[1], oxr[1])

    yr[0] = max(yr[0], oyr[0])
    yr[1] = min(yr[1], oyr[1])

    zr[0] = max(zr[0], ozr[0])
    zr[1] = min(zr[1], ozr[1])

    result = [(oxr, oyr, ozr)]
    within = delinquents(xr, yr, zr, oxr, oyr, ozr)
    for dir in within:
        newresult = []
        for cube in result:
            # Both boundaries are inside
            if len(within[dir]) == 2:
                if dir == "x":
                    newresult.append(((cube[0][0], xr[0]), oyr, ozr))
                    newresult.append(((xr[0], xr[1]), oyr, ozr))
                    newresult.append(((xr[1], cube[0][1]), oyr, ozr))
                if dir == "y":
                    newresult.append((oxr, (cube[1][0], yr[0]), ozr))
                    newresult.append((oxr, (yr[0], yr[1]), ozr))
                    newresult.append((oxr, (yr[1], cube[1][1]), ozr))
                if dir == "z":
                    newresult.append((oxr, oyr, (cube[2][0], zr[0])))
                    newresult.append((oxr, oyr, (zr[0], zr[1])))
                    newresult.append((oxr, oyr, (zr[1], cube[2][1])))

            if len(within[dir]) == 1:
                if dir == "x":
                    newresult.append(((cube[0][0], xr[within[dir][0]]), oyr, ozr))
                    newresult.append(((xr[within[dir][0]], cube[0][1]), oyr, ozr))
                if dir == "y":
                    newresult.append((oxr, (cube[1][0], yr[within[dir][0]]), ozr))
                    newresult.append((oxr, (yr[within[dir][0]], cube[1][1]), ozr))
                if dir == "z":
                    newresult.append((oxr, oyr, (cube[2][0], zr[within[dir][0]])))
                    newresult.append((oxr, oyr, (zr[within[dir][0]], cube[2][1])))
            
        result = newresult
    # Remove the split part that 
    result.remove((xr, yr, zr))
    return result

cubes_on = []
for line in lines:
    
    state, xr, yr, zr = process(line)
    if state:
        to_add = [(xr, yr, zr)]
        for cube in cubes_on:
            new_toadd = []
            new_toadd
            to_add = new_toadd
    else:
        nextcubes_on = []
        for oxr, oyr, ozr in cubes_on:
            nextcubes_on += splitall(xr, yr, zr, oxr, oyr, ozr)
        cubes_on = nextcubes_on