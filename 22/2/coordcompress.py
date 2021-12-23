from math import *
from collections import *
from itertools import *

lines = [l.rstrip() for l in open("../input.in", "r+").readlines()]

def process(line):
    result = []
    state, coordinates = line.split(" ")
    result.append(1 if state == "on" else 0)
    for coord in coordinates.split(","):
        nums = coord[2:].split("..")
        nums[0] = int(nums[0])
        nums[1] = int(nums[1]) + 1
        result.append(tuple(nums))
    return result

xlist = []
ylist = []
zlist = []
for line in lines:
    state, xr, yr, zr = process(line)
    xlist.append(xr[0])
    xlist.append(xr[1])
    ylist.append(yr[0])
    ylist.append(yr[1])
    zlist.append(zr[0])
    zlist.append(zr[1])

xlist = sorted(xlist)
ylist = sorted(ylist)
zlist = sorted(zlist)
compressx = {ele:i for i,ele in enumerate(xlist)}
compressy = {ele:i for i,ele in enumerate(ylist)}
compressz = {ele:i for i,ele in enumerate(zlist)}

ongrid = [[[False for k in zlist] for j in ylist] for i in xlist]
for line in lines:
    state, xr, yr, zr = process(line)
    for i in range(compressx[xr[0]], compressx[xr[1]]):
        for j in range(compressy[yr[0]], compressy[yr[1]]):
            for k in range(compressz[zr[0]], compressz[zr[1]]):
                ongrid[i][j][k] = state
ans = 0
for i in range(len(ongrid) - 1):
    for j in range(len(ongrid[0]) - 1):
        for k in range(len(ongrid[0][0]) - 1):
            if ongrid[i][j][k]:
                ans += (xlist[i + 1] - xlist[i]) * (ylist[j + 1] - ylist[j]) * (zlist[k + 1] - zlist[k])
print(ans)