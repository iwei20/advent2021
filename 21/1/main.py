from math import *
from collections import *
from itertools import *

ITERATIONS = 2

lines = [l.rstrip() for l in open("../input.in", "r+").readlines()]

starts = [2, 3]
die = deque(range(1, 100+1))

points = [0, 0]

which = 0
rolls = 0
while max(points) < 1000:
    moves = 0
    for i in range(3):
        roll = die.popleft()
        moves += roll
        die.append(roll)
        rolls += 1
    starts[which] += moves
    starts[which] %= 10
    points[which] += starts[which] + 1
    which ^= 1

print(min(points) * rolls)