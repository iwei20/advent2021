


from collections import deque
import itertools

lines = [l.rstrip() for l in open("../input.in", "r+").readlines()]
class ALU:
    def __init__(self):
        self.vars = {"w":0, "x":0, "y":0, "z":0}
        self.inpq = deque()

    def queue_inputs(self, ilist):
        self.inpq.extend(ilist)

    def inp(self, var):
        self.vars[var] = self.inpq.popleft()

    def add(self, vara, varb):
        if not varb.lstrip("-").isdigit():
            self.vars[vara] += self.vars[varb]
        else:
            self.vars[vara] += int(varb)

    def mul(self, vara, varb):
        if not varb.lstrip("-").isdigit():
            self.vars[vara] *= self.vars[varb]
        else:
            self.vars[vara] *= int(varb)

    def div(self, vara, varb):
        if not varb.lstrip("-").isdigit():
            self.vars[vara] = int(self.vars[vara]/self.vars[varb])
        else:
            self.vars[vara] = int(self.vars[vara]/int(varb))

    def mod(self, vara, varb):
        if not varb.lstrip("-").isdigit():
            self.vars[vara] %= self.vars[varb]
        else:
            self.vars[vara] %= int(varb)

    def eql(self, vara, varb):
        if not varb.lstrip("-").isdigit():
            self.vars[vara] = 1 if self.vars[vara] == self.vars[varb] else 0 
        else:
            self.vars[vara] += 1 if self.vars[vara] == int(varb) else 0 

    def get(self, varname):
        return self.vars[varname]

    def __str__(self):
        result = ""
        for var in self.vars:
            result += str(var)
            result += ":"
            result += str(self.vars[var])
            result += " "
        return result

maxans = 0
for i_1, i_2, i_3, i_5, i_6, i_8, i_10 in itertools.product(range(1, 10), repeat=7):
    machine = ALU()
    candidate_model = [i_1, i_2, i_3, 9, i_5, i_6, i_6 + 6, i_8, i_8 - 5, i_10, i_10 - 1, 9, 9, 1]
    machine.queue_inputs(candidate_model)

    for line in lines:
        if line:
            #print(line)
            words = line.split()
            cmd = words[0]
            if cmd == "inp":
                machine.inp(words[1])
            if cmd == "add":
                machine.add(words[1], words[2])
            if cmd == "mul":
                machine.mul(words[1], words[2])
            if cmd == "div":
                machine.div(words[1], words[2])
            if cmd == "mod":
                machine.mod(words[1], words[2])
            if cmd == "eql":
                machine.eql(words[1], words[2])

    print(machine)
    if machine.get("z") == 0:
        maxans = max(maxans, int(''.join(str(digit) for digit in candidate_model)))
        print(maxans)

print(maxans)
