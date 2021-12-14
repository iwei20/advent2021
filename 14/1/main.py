from collections import *
lines = [l.rstrip() for l in open("../input.in", "r+").readlines()]

template = lines[0]

p2i = dict()
for line in lines[2:]:
    pair, _, insert = line.split()
    p2i[pair] = insert

steps = 40
pairs = defaultdict(lambda:0)
for i in range(len(template) - 1):
    pairs[template[i:i+2]] += 1

for _ in range(steps):
    new_pairs = defaultdict(lambda:0)

    for pair in pairs:
        new_pairs[pair[0] + p2i[pair]] += pairs[pair]
        new_pairs[p2i[pair] + pair[1]] += pairs[pair]
    pairs = new_pairs
    # print(result)

charcount = Counter()
for pair in pairs:
    charcount[pair[0]] += pairs[pair]
    charcount[pair[1]] += pairs[pair]

charcount[template[0]] += 1
charcount[template[-1]] += 1
for ele in charcount:
    charcount[ele] /= 2

print(charcount.most_common()[0][1] - charcount.most_common()[-1][1])