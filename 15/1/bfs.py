from collections import *
from heapq import *
lines = [l.rstrip() for l in open("../input.in", "r+").readlines()]

dr = [-1, 0, 1, 0]
dc = [0, -1, 0, 1]

graph = [[int(c) for c in line] for line in lines]

lowest = [[10000000 for ele in row] for row in graph]

def in_bounds(r, c):
    return r >= 0 and r < len(graph) and c >= 0 and c < len(graph[0])

bfs = []
heappush(bfs, (0, 0, 0))
lowest[0][0] = 0

while len(bfs) > 0:
    ele = heappop(bfs)
    
    if ele[1:] == (len(graph) - 1, len(graph[0]) - 1):
        continue

    for dR, dC in zip(dr, dc):
        nr, nc = ele[1] + dR, ele[2] + dC
        if not in_bounds(nr, nc):
            continue

        nrisk = graph[nr][nc] + ele[0]
        if lowest[nr][nc] > nrisk:
            
            heappush(bfs, (nrisk, nr, nc))
            lowest[nr][nc] = nrisk

print(lowest[-1][-1])