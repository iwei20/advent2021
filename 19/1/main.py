from math import *
from collections import *
from itertools import *
lines = [l.rstrip() for l in open("../input.in", "r+").readlines()]

REQ_MATCH = 12
SHARED_BEACONS = 0

allbeacons = set()
class scanner:
    def __init__(self, beacons):
        self.beacons = beacons
        self.correctarrangement = None
        self.location = None

    def possible_rel_beacon_arranges(self):
        return list(zip(*([(x, y, z), (y, x, -z), (-y, z, -x), (z, y, -x), (z, x, y), (-z, x, -y), (-y, x, z), (x, -z, y), (-z, -x, y), (x, -y, -z), (y, -x, z), (z, -x, -y), (y, -z, -x), (-y, -x, -z), (-x, -y, z), (-z, -y, -x), (-x, z, y), (-x, -z, -y), (x, z, -y), (-x, y, -z), (z, -y, x), (y, z, x), (-y, -z, x), (-z, y, x)] for x, y, z in self.beacons)))

    def match(self, other):
        global SHARED_BEACONS
        if not self.location:
            return
        if other.location:
            return
        for arrangement in other.possible_rel_beacon_arranges():
            possibles = defaultdict(lambda: 0)
            for selfcoord in self.correctarrangement:
                for othercoord in arrangement:
                    possibles[sum_tuple(selfcoord, tuple(-j for j in othercoord))] += 1

            for possiblecenter in possibles:
                if possibles[possiblecenter] >= REQ_MATCH:
                    other.correctarrangement = arrangement
                    other.location = sum_tuple(self.location, possiblecenter)
                    return
                

def sum_tuple(a, b):
    return tuple((a[i] + b[i] for i in range(len(a))))

i = 1
scanners = []
nextbeacons = []
while i < len(lines):
    if not lines[i]:
        i += 1
        scanners.append(scanner(nextbeacons))
        nextbeacons = []
    else:
        nextbeacons.append(eval("(" + lines[i] + ")"))
    i += 1
if nextbeacons:
    scanners.append(scanner(nextbeacons))

scanners[0].location = (0, 0, 0)
scanners[0].correctarrangement = scanners[0].possible_rel_beacon_arranges()[0]

itr = 0
while None in (s.location for s in scanners):
    for i in range(len(scanners)):
        for j in range(i + 1, len(scanners)):
            scanners[i].match(scanners[j])
            scanners[j].match(scanners[i])
    for s in scanners:
        print(s.location)
    print("Iteration",itr,"complete")
    itr += 1

for s in scanners:
    for relbeacon in s.correctarrangement:
        allbeacons.add(sum_tuple(relbeacon, s.location))

print("Part 1:", len(allbeacons))

maxdist = 0
for i in range(len(scanners)):
    for j in range(i + 1, len(scanners)):
        maxdist = max(maxdist, sum(abs(scanners[i].location[k] - scanners[j].location[k]) for k in range(3)))
print("Part 2:", maxdist)
