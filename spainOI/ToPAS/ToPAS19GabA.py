inp = input().split(" ")

def calc(inp1, inp2, tp, d, ptd, min):
    o = int(inp1)*tp + int(inp2)*d + ptd
    if (o < min): return min
    else: return o

if (int(inp[0])): print(calc(inp[1], inp[2], 10, 80, 100, 250))
else: print(calc(inp[1], inp[2], 15, 120, 150, 350))