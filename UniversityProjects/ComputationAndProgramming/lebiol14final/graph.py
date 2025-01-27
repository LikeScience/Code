#Classe Graph
#Grafo de sobreposições

class Graph:
    
    def __init__(self, n):
        self._matrix=[[0 for i in range(n)] for j in range(n)] 
            
    def add(self,i,j,w):
        self._matrix[i][j]=w  

    #Função adjQ: indica se há uma aresta de i para j
    def adjQ(self, i,j):    
        return self._matrix[i][j]>0 

    #Função adj: retorna a lista de adjacências de um nó i (que tem 2 listas: os índices e os pesos dos nós adjacentes a i)
    def adj(self,i):
        adjs = []
        pesos = []
        for k in range(self.nnodes()):
            if self.adjQ(i,k):
                adjs.append(k)
                pesos.append(self._matrix[i][k]) 
        return ([adjs, pesos])

    #Função indegree: compara os pesos das arestas que vão para i e retorna o maior
    def indegree(self, i):
        maximo = 0 
        for k in range(self.nnodes()): 
            if self._matrix[k][i]>maximo:   
                maximo = self._matrix[k][i] 
        return maximo
                
    def nnodes(self):
        return len(self._matrix)