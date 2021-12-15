from collections import *
lines = [l.rstrip() for l in open("../input.in", "r+").readlines()]

graph = [[int(c) for c in line] for line in lines]
visited = [[False for c in line] for line in lines]

risks = [[0] + [0 for c in lines[0]]] + [[0] + [int(c) for c in line] for line in lines]
for i in range(2, len(lines) + 1):
    risks[i][1] += risks[i - 1][1]

for i in range(2, len(lines[0]) + 1):
    risks[1][i] += risks[1][i - 1]    

for i in range(2, len(lines) + 1):
    for j in range(2, len(lines[0]) + 1):
        risks[i][j] += min(risks[i - 1][j], risks[i][j - 1])

for row in risks:
    print(row)

print(risks[-1][-1] - risks[1][1])
"""
bfs = deque()
bfs.append((0, 0, 0))
visited[0][0]
while len(bfs) > 0:
"""