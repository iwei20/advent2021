lines = [l.rstrip() for l in open("../input.in", "r+").readlines()]

dr = [-1, -1, 0, 1, 1, 1, 0, -1]
dc = [0, 1, 1, 1, 0, -1, -1, -1]

def in_bounds(r, c, rs, cs):
    return r < rs and r >= 0 and c < cs and c >= 0 



steps = 100000

graf = [[int(c) for c in line] for line in lines]
visited = [[False for i in line] for line in lines]
total_count = [0]

def flash(i, j):
    if not in_bounds(i, j, len(graf), len(graf[0])) or visited[i][j]:
        return

    # Flash
    if graf[i][j] > 9:
        visited[i][j] = True
        total_count[0] += 1
        graf[i][j] = 0

        for d, _ in enumerate(dr):
            if in_bounds(i + dr[d], j + dc[d], len(graf), len(graf[0])) and not visited[i + dr[d]][j + dc[d]]:
                graf[i + dr[d]][j + dc[d]] += 1
            flash(i + dr[d], j + dc[d])

def all_zero():
    return all([all([e == 0 for e in row]) for row in graf])

for _ in range(steps):
    for i, row in enumerate(graf):
        for j, ele in enumerate(row):
            graf[i][j] += 1
    for i, row in enumerate(graf):
        for j, ele in enumerate(row):
            flash(i, j)        
    for i, row in enumerate(graf):
        for j, ele in enumerate(row):
            print(ele, end=' ')    
        print()
    visited = [[False for i in line] for line in lines]
    if(all_zero()):
        print(_)
        break
    print()

print(total_count[0])