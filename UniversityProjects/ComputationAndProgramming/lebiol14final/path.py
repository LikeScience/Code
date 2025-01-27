#Classe Path
#Caminhos

from DNAseq import DNAseq
from fraglist import Fraglist
from graph import Graph


class Path():

    def __init__(self, g, i):
        self._path = [i]
        self._graph = g
        self._node_count = [0] * self._graph.nnodes()  #Número de vezes que cada fragmento aparece no caminho
        self._node_count[i] = 1
        self._repeated = False  #Esta variável indica se existem fragmentos repetidos

    def add(self, j):
        if self._graph.adjQ(self._path[-1], j): #Adiciona-se apenas o nó j ao caminho se j é adjacente ao último elemento do caminho que já tenho 
            self._path.append(j)
            self._node_count[j] += 1 
            if self._node_count[j] > 1:
                self._repeated = True

    #Função last: retorna o último nó do caminho
    def last(self): 
        return self._path[-1]

    #Função copy: cria e retorna uma cópia do caminho para a podermos modificar sem alterar o orignal
    def copy(self):    
        new_path = Path(self._graph, self._path[0])
        new_path._path = self._path[:]
        new_path._node_count = self._node_count[:]
        new_path._repeated = self._repeated
        return new_path                      

    def loopQ(self):
        return self._node_count[self._path[-1]] > 1 #O último nó do caminho está num ciclo só se já apareceu antes 

    def hamiltonianQ(self):    #Um caminho é hamiltoniano se passamos por todos os nós e uma única vez por cada nó
        return (len(self._path) == self._graph.nnodes() and not self._repeated)

    #Função extandableQ: podemos adicionar mais um nó sem criar um ciclo
    def extendableQ(self):     
        adj_last = self._graph.adj(self._path[-1]) 
        if (self.loopQ()):      
            return False     
        return any(self._node_count[i] == 0 for i in adj_last[0])  #Retorna true sse houver pelo menos um nó adjacente que não está no caminho
        
    #Função seq: junta os fragmentos excluindo as partes que se sobrepõem e retorna a sequência reconstruída
    def seq(self, f):  
        output = DNAseq()
        for i in self._path:  
            next_seq = f.pos(i)
            output.conc(next_seq.suffix(next_seq.len() - output.overlay(next_seq))) 
        return output
