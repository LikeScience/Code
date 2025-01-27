nCen = int(input())

if (1 <= nCen and nCen <= 100): 
    for i in range(nCen):
        intC, intS = input().split(" "), input().split(" ")

        if (intS[0] == intS[1] or intC[0] == intC[1]): print("Sem alibi")  
        elif (int(intC[0]) <= int(intS[0]) or int(intC[1]) <= int(intS[1])):
            print("Com alibi")
        else: print("Sem alibi")   