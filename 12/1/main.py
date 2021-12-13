from collections import *
lines = [l.rstrip().split("-") for l in open("../input.in", "r+").readlines()]

adj = defaultdict(list)

for a, b in lines:
    adj[a] += [b]
    adj[b] += [a]

# print(adj)
single_good = [False]
vis = {node:0 for node in adj}

def traverse(root : str):
    if root == "end":
        return [["end"]]

    if vis[root] >= 1 and root == "start":
        return

    if vis[root] >= 1 and root.islower() and single_good[0]:
        return

    vis[root] += 1
    this_layer_set = False
    if vis[root] >= 2 and root.islower():
        single_good[0] = True
        this_layer_set = True
    this_result = []
    # print(root)
    # print(adj[root])
    for neighbor in adj[root]:
        results = traverse(neighbor)
        if results:
            for path in results:
                if path:
                    this_result.append([root] + path)
    vis[root] -= 1
    
    if this_layer_set:
        single_good[0] = False
    return this_result
    
# print(traverse("start"))
print(len(traverse("start")))