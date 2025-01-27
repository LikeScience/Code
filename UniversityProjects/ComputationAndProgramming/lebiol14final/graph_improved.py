#Classe Graph - implementação alternativa (teoricamente mais eficiente)
#Grafo de sobreposições

from math import inf
class Graph():

    def __init__(self, n):
        self._matrix=[[0 for i in range(n)] for j in range(n)] 

        self._adj_list = [[[], []] for i in range(n)]     
        self._sup_weight = [-inf]*n

    def add(self, i, j, w):
        self._matrix[i][j]=w

        #Precalculamos a lista de adjacências e o indegree ao atualizarmos quando adicionamos cada aresta
        self._adj_list[i][0].append(j)
        self._adj_list[i][1].append(w)
        self._sup_weight[j] = max(self._sup_weight[j], w)

    #Função adjQ: indica se há uma aresta de i para j
    def adjQ(self, i, j):
        return self._matrix[i][j]>0
        
    #Função adj: retorna a lista de adjacências de um nó i 
    def adj(self, i):
        return self._adj_list[i]

    #Função indegree: compara os pesos das arestas que vão para i e retorna o maior
    def indegree(self, i):
        return self._sup_weight[i]

    def nnodes(self):
        return len(self._matrix)
    