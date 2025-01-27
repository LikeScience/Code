#Classe Fraglist
#Listas de Fragmentos

class Fraglist():

    def __init__(self):
        self._frag_list = []

    def add(self, w):
        self._frag_list.append(w)

    #Função purge: Remove todos os fragmentos que ocorrem dentro de outros
    def purge(self): 
        new_self = [] #Lista dos fragmentos que não ocorrem em nenhum dos outros
        removed = [False]*self.len() #Lista que indica se cada fragmento já foi removido
        
        for i in range(self.len()):
            j = 0
            while j < self.len() and (j == i or removed[j] or not(self.pos(i).occursQ(self.pos(j)))):
                j+=1
            if j==self.len():                   
                new_self.append(self.pos(i)) 
            else:
                removed[i]=True 
        self._frag_list = new_self

    def len(self):
        return len(self._frag_list)

    def pos(self, i):
        return self._frag_list[i]
