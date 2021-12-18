import math

lines = [eval(l.rstrip()) for l in open("../input.in", "r+").readlines()]

class node:
    def __init__(self, pairs, parent, layer): # Layer 1 indexed
        self.parent = parent
        self.layer = layer

        if isinstance(pairs, list):
            self.ispair = True
            if isinstance(pairs[0], node):
                self.left = pairs[0]
                self.left.incr_layer()
                self.left.parent = self
            else:
                self.left = node(pairs[0], self, layer + 1)
            
            if isinstance(pairs[1], node):
                self.right = pairs[1]
                self.right.incr_layer()
                self.right.parent = self
            else:
                self.right = node(pairs[1], self, layer + 1)
        else:
            self.ispair = False
            self.dat = pairs
    
    def __str__(self) -> str:
        if not self.ispair:
            return str(self.dat)
        return "[" + str(self.left) + ", " + str(self.right) + "]"

    def incr_layer(self, num=1):
        self.layer += num
        if self.ispair:
            self.left.incr_layer(num)
            self.right.incr_layer(num)

    def find_leftleaf(self):
        if not self.ispair:
            return self
        return self.left.find_leftleaf()

    def find_rightleaf(self):
        if not self.ispair:
            return self
        return self.right.find_rightleaf()

    # Keep on going up the tree until you find that you can traverse down a left/right side
    def find_explode_lnode(self):
        if self.parent == None:
            return None
        if self.parent.left == self:
            return self.parent.find_explode_lnode()
        return self.parent.left.find_rightleaf()

    def find_explode_rnode(self):
        if self.parent == None:
            return None
        if self.parent.right == self:
            return self.parent.find_explode_rnode()
        return self.parent.right.find_leftleaf()

    def explode(self):
        result = None
        lexn = self.find_explode_lnode()
        rexn = self.find_explode_rnode()
        if lexn:
            lexn.dat += self.left.dat
        if rexn:
            rexn.dat += self.right.dat

        if self.parent.left == self:
            self.parent.left = node(0, self.parent, self.layer)
            result = self.parent.left
        if self.parent.right == self:
            self.parent.right = node(0, self.parent, self.layer)
            result = self.parent.right

        return result

    def split(self):
        if self.parent.left == self:
            self.parent.left = node([math.floor(self.dat / 2), math.ceil(self.dat / 2)], self.parent, self.layer)
            if self.layer >= 5:
                return self.parent.left.explode()
            return self.parent.left

        if self.parent.right == self:
            self.parent.right = node([math.floor(self.dat / 2), math.ceil(self.dat / 2)], self.parent, self.layer)
            if self.layer >= 5:
                return self.parent.right.explode()
            return self.parent.right
    
    def magnitude(self):
        if not self.ispair:
            return self.dat
        return 3 * self.left.magnitude() + 2 * self.right.magnitude()

def explodeall(n):
    if n.ispair and n.layer >= 5:
        n = n.explode()
    if n.ispair:
        explodeall(n.left)
        explodeall(n.right)

def splitall(n):
    if not n.ispair:
        if n.dat >= 10:
            n = n.split()
            return True
        return False
    return splitall(n.left) or splitall(n.right)
    
def simplify(n):
    explodeall(n)
    while splitall(n):
        explodeall(n)
    
tree = node([lines[0], lines[1]], None, 1)
simplify(tree)

for i in range(2, len(lines)):
    tree = node([tree, lines[i]], None, 1)
    simplify(tree)
    
print(tree)
print(tree.magnitude())

        