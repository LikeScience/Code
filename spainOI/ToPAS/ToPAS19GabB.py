nGav, dGav, nInc = int(input()), [], 0

for i in range(nGav): dGav.append(input())
if (dGav[0] == "#"): nInc = nInc+1

for i in range(1, len(dGav), 1):
    if (dGav[i] == "#" and dGav[i-1] == "#"):
        nInc = nInc+1

print(nInc)