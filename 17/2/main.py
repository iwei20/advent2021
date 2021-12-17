from math import *
from collections import *
from itertools import *

lines = [l.rstrip() for l in open("../input.in", "r+").readlines()]
_, __, xin, yin = lines[0].split()
xleft, xright = xin[2:].split("..")
xleft, xright = int(xleft), int(xright[:-1])
ybot, ytop = yin[2:].split("..")
ybot, ytop = int(ybot), int(ytop)

vels = set()
for vxi in range(300):
    for vyi in range(-300, 300):
        vxc = vxi
        vyc = vyi
        lastposx = 0
        lastposy = 0
        posx = 0
        posy = 0

        while posy >= ybot and posx <= xright:
            lastposx = posx
            lastposy = posy
            posx += vxc
            posy += vyc
            vxc -= 1
            vyc -= 1
            vxc = max(0, vxc)
            
        if lastposy <= ytop and lastposx >= xleft:
            vels.add((vxi, vyi))

print(len(vels))
