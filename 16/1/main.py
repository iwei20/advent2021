from math import prod, log2

lines = [l.rstrip() for l in open("../input.in", "r+").readlines()]
bstring = bin(int(lines[0], 16))[2:].zfill(int(len(lines[0]) * log2(16)))

class literal_packet:
    def __init__(self, version, subseq_data):
        self.version = int(version, 2)
        self.subseq_data = ""
        i = 0
        while i < len(subseq_data):
            self.subseq_data += subseq_data[i + 1:i + 5]
            i += 5
        self.num = int(self.subseq_data, 2)
    
    def eval(self):
        return self.num

class op_packet:
    def __init__(self, version, type, subpackets):
        self.version = int(version, 2)
        self.type = type
        self.operands = subpackets

    def eval(self):
        if self.type == 0:
            return sum(child.eval() for child in self.operands)
        if self.type == 1:
            return prod(child.eval() for child in self.operands)
        if self.type == 2:
            return min(child.eval() for child in self.operands)
        if self.type == 3:
            return max(child.eval() for child in self.operands)
        if self.type == 5:
            return 1 if self.operands[0].eval() > self.operands[1].eval() else 0
        if self.type == 6:
            return 1 if self.operands[0].eval() < self.operands[1].eval() else 0
        if self.type == 7:
            return 1 if self.operands[0].eval() == self.operands[1].eval() else 0

iptr = 0
total_v = 0

def advance(n):
    global bstring, iptr
    result = bstring[:n]
    bstring = bstring[n:]
    iptr += n
    return result

def take_packet():
    global bstring, iptr, total_v

    v = advance(3)
    total_v += int(v, 2) # For part 1

    type = advance(3)

    if int(type, 2) == 4: # Literal
        fourbdat = ""
        while bstring[0] != "0":
            fourbdat += advance(5)
        fourbdat += advance(5) # Last group of 5 starts with 0

        return literal_packet(v, fourbdat)

    else: # Operator
        lid = advance(1)
        subpackets = []
        
        if int(lid, 2) == 0: # Raw length counting
            blen = int(advance(15), 2)

            curr_iptr = iptr
            while(iptr < curr_iptr + blen):
                subpackets.append(take_packet())

        if int(lid, 2) == 1: # Full packet counting
            blen = int(advance(11), 2)

            for _ in range(blen):
                subpackets.append(take_packet())

        result = op_packet(v, int(type, 2), subpackets)

    return result

res = take_packet()
print("Part 1:", total_v)
print("Part 2:", res.eval())