from collections import *
from heapq import *
lines = [l.rstrip() for l in open("../input.in", "r+").readlines()]

dr = [-1, 0, 1, 0]
dc = [0, -1, 0, 1]
dRC = zip(dr, dc)

graph = [[int(c) for c in line] for line in lines]
newgraph = [[0 for i in range(5 * len(lines[0]))] for j in range(5 * len(lines))]

for i in range(5):
    for j in range(5):
        for r in range(i * len(lines), (i + 1) * len(lines)):
            
            for c in range(j * len(lines[0]), (j + 1) * len(lines[0])):
                
                newgraph[r][c] = graph[r - i * len(lines)][c - j * len(lines[0])] + i + j
                if newgraph[r][c] > 9:
                    newgraph[r][c] -= 9


lowest = [[10000000 for ele in row] for row in newgraph]

def in_bounds(r, c):
    return r >= 0 and r < len(newgraph) and c >= 0 and c < len(newgraph[0])

bfs = []
heappush(bfs, (0, 0, 0))
lowest[0][0] = 0

while len(bfs) > 0:
    ele = heappop(bfs)
    
    if ele[1:] == (len(newgraph) - 1, len(newgraph[0]) - 1):
        continue

    for dR, dC in zip(dr, dc):
        nr, nc = ele[1] + dR, ele[2] + dC
        if not in_bounds(nr, nc):
            continue

        nrisk = newgraph[nr][nc] + ele[0]
        if lowest[nr][nc] > nrisk:
            
            heappush(bfs, (nrisk, nr, nc))
            lowest[nr][nc] = nrisk

print(lowest[-1][-1])