from math import *
from collections import *
from itertools import *

ITERATIONS = 2

lines = [l.rstrip() for l in open("../input.in", "r+").readlines()]

die = [1, 2, 3]
dp = [[defaultdict(int) for i in range(21)] for j in range(21)]

dp[0][0][(2, 3)] += 1