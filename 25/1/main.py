from collections import deque
import itertools

lines = [l.rstrip() for l in open("../input.in", "r+").readlines()]

easts = []
souths = []
for i, line in enumerate(lines):
    for j, space in enumerate(line):
        if space == "v":
            souths.append((i, j))
        if space == ">":
            easts.append((i, j))

steps = 0
changed = True
while changed:
    nexteasts = []
    nextsouths = []
    # if steps <= 3:
    #     for i in range(len(lines)):
    #         for j in range(len(lines[0])):
    #             if [i, j] in easts:
    #                 print(">", end="")
    #             if [i, j] in souths:
    #                 print("v", end="")
    #             if [i, j] not in souths and [i, j] not in easts:
    #                 print(".", end="")
    #         print()
    #     print()
    changed = False
    for coord in easts:
        newcoord = (coord[0], (coord[1] + 1) % len(lines[0]))
        if newcoord not in souths and newcoord not in easts:
            nexteasts.append(newcoord)
            changed = True
        else:
            nexteasts.append(coord)
    for coord in souths:
        newcoord = ((coord[0] + 1) % len(lines), coord[1])
        if newcoord not in souths and newcoord not in nexteasts:
            nextsouths.append(newcoord)
            changed = True
        else:
            nextsouths.append(coord)

    steps += 1
    souths = nextsouths
    easts = nexteasts

# for i in range(len(lines)):
#     for j in range(len(lines[0])):
#         if [i, j] in easts:
#             print(">", end="")
#         if [i, j] in souths:
#             print("v", end="")
#         if [i, j] not in souths and [i, j] not in easts:
#             print(".", end="")
#     print()

print(steps)
        