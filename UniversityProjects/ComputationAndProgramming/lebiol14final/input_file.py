#Ficheiro de input

from functools import reduce
import random


"""
Função de geração do professor Paulo Mateus de uma sequência aleatória de DNA e uma lista de fragmentos
a partir desta, com n nucleótidos, pelo menos c fragmentos (continua até haver pelo menos um fragmento que
cubra cada posição da sequência) e com comprimento dos fragmentos no intervalo [dmin, dmax]
"""
def generate(n,c,dmin,dmax):
    #r: Sequência de DNA
    #w: lista de fragmentos
    r=[]
    for i in range(n):
        r+=[random.randint(0,3)]
    w=[]
   
    cov=[]
    for i in range(n):
        cov+=[False]
    for i in range(c):
        pos=random.randint(0,n-dmin-1)
        dim=random.randint(dmin,dmax)
        w+=[r[pos:min(pos+dim,n)]]
        for j in range(pos,min(pos+dim,n)):
            cov[j]=True
    while not all(cov):
        pos=random.randint(0,n-dmin-1)
        dim=random.randint(dmin,dmax)
        w+=[r[pos:min(pos+dim,n)]]
        for j in range(pos,min(pos+dim,n)):
            cov[j]=True
    return r, w


#Geração aleatória de sequências de DNA
DNA, fragments = generate(200, 100, 15, 25)

#Exemplo de sequência de DNA
#DNA=[3, 3, 3, 2, 2, 3, 3, 2, 0, 3, 3, 1, 3, 2, 0, 1, 2, 0, 0, 2, 0, 3, 2, 1, 0, 3, 1, 1, 1, 0, 2, 2, 0, 3, 3, 0, 0, 0, 3, 3, 2, 0, 3, 2, 1, 1, 2, 3, 1, 1, 3, 3, 1, 2, 3, 1, 2, 2, 0, 2, 3, 1, 3, 1, 0, 2, 0, 2, 0, 0]
#fragments=[[0, 0, 3, 3, 2, 0, 3, 2, 1, 1, 2, 3, 1, 1], [3, 3, 1, 2, 3, 1, 2, 2, 0, 2, 3, 1, 3, 1, 0, 2], [2, 0, 3, 3, 0, 0, 0, 3, 3, 2, 0, 3, 2, 1, 1, 2], [3, 2, 0, 1, 2, 0, 0, 2, 0, 3, 2, 1, 0, 3, 1, 1, 1, 0, 2, 2], [2, 2, 3, 3, 2, 0, 3, 3, 1, 3, 2, 0, 1, 2, 0, 0, 2, 0, 3, 2], [0, 0, 2, 0, 3, 2, 1, 0, 3, 1, 1, 1, 0], [3, 1, 3, 2, 0, 1, 2, 0, 0, 2, 0, 3, 2, 1, 0, 3, 1, 1, 1, 0], [0, 0, 2, 0, 3, 2, 1, 0, 3, 1, 1, 1, 0, 2, 2, 0], [1, 3, 2, 0, 1, 2, 0, 0, 2, 0, 3, 2, 1, 0, 3], [3, 1, 2, 3, 1, 2, 2, 0, 2, 3, 1, 3, 1], [1, 2, 3, 1, 2, 2, 0, 2, 3, 1, 3, 1, 0, 2, 0, 2], [1, 3, 2, 0, 1, 2, 0, 0, 2, 0, 3, 2, 1, 0, 3], [3, 3, 2, 2, 3, 3, 2, 0, 3, 3, 1, 3, 2, 0, 1], [0, 3, 2, 1, 0, 3, 1, 1, 1, 0, 2, 2], [1, 1, 0, 2, 2, 0, 3, 3, 0, 0, 0, 3, 3, 2, 0, 3, 2, 1], [1, 1, 0, 2, 2, 0, 3, 3, 0, 0, 0, 3, 3, 2, 0, 3, 2, 1], [2, 0, 3, 2, 1, 0, 3, 1, 1, 1, 0, 2], [3, 1, 1, 3, 3, 1, 2, 3, 1, 2, 2, 0, 2], [1, 2, 3, 1, 2, 2, 0, 2, 3, 1, 3, 1, 0, 2, 0, 2, 0], [3, 3, 0, 0, 0, 3, 3, 2, 0, 3, 2, 1, 1, 2, 3, 1, 1, 3, 3, 1], [3, 1, 2, 2, 0, 2, 3, 1, 3, 1, 0, 2, 0], [3, 3, 2, 0, 3, 3, 1, 3, 2, 0, 1, 2, 0, 0, 2, 0], [2, 3, 1, 2, 2, 0, 2, 3, 1, 3, 1, 0, 2, 0, 2, 0], [0, 0, 2, 0, 3, 2, 1, 0, 3, 1, 1, 1, 0, 2], [3, 1, 2, 3, 1, 2, 2, 0, 2, 3, 1, 3, 1, 0, 2], [2, 1, 0, 3, 1, 1, 1, 0, 2, 2, 0, 3, 3, 0, 0, 0, 3, 3], [0, 3, 2, 1, 1, 2, 3, 1, 1, 3, 3, 1, 2, 3, 1, 2, 2], [0, 2, 0, 3, 2, 1, 0, 3, 1, 1, 1, 0, 2, 2, 0, 3, 3, 0], [3, 1, 2, 3, 1, 2, 2, 0, 2, 3, 1, 3, 1, 0, 2], [1, 1, 3, 3, 1, 2, 3, 1, 2, 2, 0, 2, 3, 1, 3, 1, 0, 2, 0], [3, 1, 1, 3, 3, 1, 2, 3, 1, 2, 2, 0, 2, 3, 1, 3, 1, 0, 2], [1, 3, 2, 0, 1, 2, 0, 0, 2, 0, 3, 2], [1, 3, 3, 1, 2, 3, 1, 2, 2, 0, 2, 3, 1, 3, 1, 0, 2], [3, 2, 0, 1, 2, 0, 0, 2, 0, 3, 2, 1, 0, 3, 1, 1], [2, 3, 3, 2, 0, 3, 3, 1, 3, 2, 0, 1, 2, 0, 0, 2, 0, 3, 2], [2, 0, 3, 3, 1, 3, 2, 0, 1, 2, 0, 0, 2, 0, 3, 2, 1], [3, 1, 1, 1, 0, 2, 2, 0, 3, 3, 0, 0, 0, 3, 3, 2, 0, 3, 2], [0, 1, 2, 0, 0, 2, 0, 3, 2, 1, 0, 3, 1, 1, 1, 0], [2, 0, 3, 2, 1, 1, 2, 3, 1, 1, 3, 3, 1], [2, 1, 0, 3, 1, 1, 1, 0, 2, 2, 0, 3, 3, 0, 0, 0, 3, 3, 2], [3, 3, 3, 2, 2, 3, 3, 2, 0, 3, 3, 1], [3, 0, 0, 0, 3, 3, 2, 0, 3, 2, 1, 1, 2, 3, 1, 1, 3, 3], [1, 1, 0, 2, 2, 0, 3, 3, 0, 0, 0, 3], [0, 2, 2, 0, 3, 3, 0, 0, 0, 3, 3, 2, 0, 3, 2, 1, 1, 2, 3, 1], [3, 3, 1, 2, 3, 1, 2, 2, 0, 2, 3, 1, 3], [0, 0, 3, 3, 2, 0, 3, 2, 1, 1, 2, 3, 1, 1, 3, 3], [2, 0, 3, 3, 1, 3, 2, 0, 1, 2, 0, 0, 2, 0, 3, 2], [3, 2, 1, 1, 2, 3, 1, 1, 3, 3, 1, 2, 3, 1, 2, 2, 0, 2, 3, 1], [1, 0, 2, 2, 0, 3, 3, 0, 0, 0, 3, 3, 2, 0, 3, 2, 1, 1], [1, 1, 2, 3, 1, 1, 3, 3, 1, 2, 3, 1, 2, 2, 0, 2, 3, 1, 3, 1], [0, 0, 2, 0, 3, 2, 1, 0, 3, 1, 1, 1], [1, 0, 3, 1, 1, 1, 0, 2, 2, 0, 3, 3, 0, 0, 0, 3, 3, 2, 0, 3], [3, 2, 0, 3, 2, 1, 1, 2, 3, 1, 1, 3, 3], [1, 3, 3, 1, 2, 3, 1, 2, 2, 0, 2, 3, 1, 3, 1, 0, 2, 0, 2], [3, 3, 1, 3, 2, 0, 1, 2, 0, 0, 2, 0, 3, 2, 1, 0, 3, 1, 1, 1], [3, 1, 2, 2, 0, 2, 3, 1, 3, 1, 0, 2, 0, 2, 0, 0], [0, 2, 2, 0, 3, 3, 0, 0, 0, 3, 3, 2, 0], [3, 3, 2, 0, 3, 3, 1, 3, 2, 0, 1, 2], [1, 1, 2, 3, 1, 1, 3, 3, 1, 2, 3, 1, 2, 2], [1, 1, 0, 2, 2, 0, 3, 3, 0, 0, 0, 3, 3, 2], [2, 2, 0, 3, 3, 0, 0, 0, 3, 3, 2, 0, 3, 2], [0, 2, 2, 0, 3, 3, 0, 0, 0, 3, 3, 2, 0, 3, 2, 1, 1], [3, 2, 2, 3, 3, 2, 0, 3, 3, 1, 3, 2, 0, 1, 2, 0], [1, 2, 3, 1, 1, 3, 3, 1, 2, 3, 1, 2, 2, 0, 2, 3, 1], [2, 1, 0, 3, 1, 1, 1, 0, 2, 2, 0, 3], [2, 2, 0, 3, 3, 0, 0, 0, 3, 3, 2, 0, 3, 2, 1, 1], [0, 0, 0, 3, 3, 2, 0, 3, 2, 1, 1, 2, 3, 1], [2, 0, 1, 2, 0, 0, 2, 0, 3, 2, 1, 0, 3, 1, 1, 1], [1, 0, 2, 2, 0, 3, 3, 0, 0, 0, 3, 3, 2, 0, 3, 2, 1, 1], [3, 1, 1, 3, 3, 1, 2, 3, 1, 2, 2, 0, 2, 3, 1]]