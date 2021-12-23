from math import *
from collections import *
from itertools import *
from functools import *

@lru_cache(None)
def solve(posa, posb, scorea, scoreb, which):
    if scorea >= 21:
        return (1, 0)
    if scoreb >= 21:
        return (0, 1)
    
    totala, totalb = 0, 0
    for rolla in range(1, 4):
        for rollb in range(1, 4):
            for rollc in range(1, 4):
                newpos = [posa, posb]
                newscore = [scorea, scoreb]

                newpos[which] += rolla + rollb + rollc
                newpos[which] %= 10
                newscore[which] += newpos[which] + 1

                ares, bres = solve(newpos[0], newpos[1], newscore[0], newscore[1], which ^ 1)
                totala += ares
                totalb += bres
    return totala, totalb

print(solve(3, 7, 0, 0, 0))
