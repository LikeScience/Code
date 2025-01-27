#Ficheiro principal
#Algoritmo de reconsrução da sequência de DNA a partir dos fragmentos

from DNAseq import DNAseq
from fraglist import Fraglist
from graph import Graph
from path import Path
from input_file import *
#from DNAseq_improved import DNAseq
#from graph_improved import Graph

from math import inf
import time 
from functools import reduce
import random

#Função sample_create: divide o intervalo de 0 a 1 em tantas partes como elementos da lista w, sendo o tamanho das partes dependente de cada elemento da lista w e do expoente x. (Expoentes positivos levam a tamanhos diretamente proporcionais aos originais e negativos inversamente)  
def sample_create(w, x):          
    nw = list(map((lambda y: y**x), w))
    sum = reduce((lambda x, y: x + y), nw, 0)
    nw = list(map((lambda y: y / sum), nw))
    for i in range(1, len(nw)):
        nw[i] = nw[i - 1] + nw[i]     
    return nw

#Função sample_eval: escolhe um número aleatório x entre 0 e 1 e procura o índice do menor elemento de w que é maior que x por pesquisa binária
def sample_eval(w):
    x = random.random()
    l, r = 0, len(w) - 1
    while l < r:
        m = (l + r) // 2
        if x < w[m]:
            r = m
        else:
            l = m + 1
    return l

#Algoritmo: recebe uma fraglist e um número k e procura reconstruir a sequência original de DNA a partir da fraglist (favorecendo sequências menores), repetindo a procura k vezes
def algorithm(f, k):

    #Excluir os fragmentos irrelevantes (os que occorrem dentro de outros)
    f.purge()
   

    #Cria o grafo das sobreposições dos fragmentos: adiciona uma aresta de i para j com peso que corresponde à sobreposição entre o fragmento i e o j
    g = Graph(f.len())  
    for i in range(f.len()):   
        for j in range(f.len()): 
            if i != j:
                overlay_ij = f.pos(i).overlay(f.pos(j))
                if overlay_ij != 0:
                    g.add(i, j, overlay_ij)
                    

    #Reconstrução da sequência: cria um caminho e escolhe um nó inicial, tentando estender o caminho com maior probabilidade pelos vizinhos com mais sobreposição 
    initial_prob_cutoff = sample_create([max(g.indegree(i), 0.001) for i in range(g.nnodes())], -2)
    #A função max garante que não haja divisões por 0 se o indegree for 0 (usa-se um valor próximo de 0)
    r = DNAseq()
    shortest_len = inf
    for _ in range(k):  

        #Criação de um caminho e escolha do nó inicial (mais probabilidade se tiver menor indegree)
        initial = sample_eval(initial_prob_cutoff)
        p = Path(g, initial)

        #Estendemos o caminho enquanto este não for obrigado a entrar num ciclo e até ficar hamiltoniano. Exclui-se os vizinhos do último nó que levam a um ciclo.
        while not (p.hamiltonianQ()) and p.extendableQ():
            neighbours = g.adj(p.last())
            is_extendable = []
            for i in range(len(neighbours[0])):
                temp_p = p.copy()
                temp_p.add(neighbours[0][i])
                is_extendable.append(0 if temp_p.loopQ() else 1)
            
            next_prob_cutoff = sample_create([is_extendable[i] * neighbours[1][i] for i in range(len(neighbours[0]))], 100)
            p.add(neighbours[0][sample_eval(next_prob_cutoff)])

        #Se o caminho for hamiltoniano, vamos atualizando a menor sequência até agora reconstruída            
        if p.hamiltonianQ():
            this_seq = p.seq(f)
            if this_seq.len() < shortest_len:
                shortest_len = this_seq.len()
                r = this_seq
    return r

#Função que transforma a lista (l) numa DNAseq
def to_dnaseq(l):
    s = DNAseq()
    for b in l:
        s.add(b)
    return s

#Função que transforma uma lista de listas (ll) numa Fraglist
def to_fraglist(ll):  
    f = Fraglist()
    for i in ll:
        f.add(to_dnaseq(i))
    return f

#Importar os fragmentos e a sequência original do ficheiro input_file e transformá-los para Fraglist e DNAseq
fl = to_fraglist(fragments)
dna = to_dnaseq(DNA)

#Executar o algoritmo e medir o tempo
start_time = time.time()

r = algorithm(fl, 500)

end_time = time.time()

#Print do output
print("Original Sequence:", dna)
print("Reconstructed Sequence:", r)
print("Length:", dna.len(), "(original),", r.len(),"(reconstructed)")  
print("Contained in Original:", dna.occursQ(r)) #Ver se a original ocorre na reconstruída
print("Algorithm time:", end_time - start_time)
