
result = set()
coord = (1, 2, 3)
bruh = list(coord)
for i in range(4):
    bruh[0], bruh[1] = bruh[1], -bruh[0]
    for j in range(4):
        bruh[0], bruh[2] = bruh[2], -bruh[0]
        for k in range(4):
            bruh[1], bruh[2] = bruh[2], -bruh[1]
            result.add(tuple(bruh))

print(len(result))
print (result)
