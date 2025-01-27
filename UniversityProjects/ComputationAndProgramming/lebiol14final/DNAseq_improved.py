#Classe DNAseq - implementação alternativa (teoricamente mais eficiente)
#Sequências de DNA

class DNAseq():
    
    def __init__(self):
        self._dna_seq=[]

    def add(self, c):
        self._dna_seq.append(c)

    def len(self):
        return len(self._dna_seq)

    def pos(self, i):
        return self._dna_seq[i]
    
    """
    Função overlay: procura a maior sobreposição entre um sufixo de um fragmento e um prefixo de w
    Podemos observar que concatenando a sequência w com a self, com um separador no meio (número/caracter
    que não possa aparecer em nenhuma das sequências), obtendo-se a sequência a, a resposta é o maior sufixo
    (que não seja a sequência inteira) da sequência resultante que também é prefixo da própria sequência,
    ou seja, a._prefix_function()[-1].
    """ 
    def overlay(self, w): 
        sep = -1
        a = w._copy()
        a.add(sep)
        a.conc(self)
        return a._prefix_function()[-1]

    """
    Função occursQ: Vê se a sequência (self) ocorre dentro da sequência w
    Podemos observar que concatenando a sequência self com a w, com um separador no meio (número/caracter
    que não possa aparecer em nenhuma das sequências), obtendo-se a sequência a, se self aparece em w, então,
    considerando os sufixos que acabam em cada posição j de a correspondente à sequência w, algum deles será
    igual ao prefixo de a (que é self), logo terá função prefixo igual a self.len() 
    """ 
    def occursQ(self, w):
        if self.len() > w.len():
            return False
        sep = -1
        a = self._copy()
        a.add(sep)
        a.conc(w)
        prefix_find = a._prefix_function()
        for i in range(self.len()+1, len(prefix_find)):
            if prefix_find[i] == self.len():
                return True
        return False

    def prefix(self, n):
        pref = DNAseq() 
        pref._dna_seq = self._dna_seq[:n]
        return pref
    
    def suffix(self, n):
        suf = DNAseq()
        suf._dna_seq = self._dna_seq[-n:]
        return suf
        
    #Função conc: adiciona uma sequência w à primeira (self)
    def conc(self, w):
        self._dna_seq += w._dna_seq

    def __str__(self):
        return str(self._dna_seq)
    
    def _copy(self):
        cop = DNAseq()
        for i in self._dna_seq:
            cop.add(i)
        return cop

    """
    Função pi (prefixo)
    Esta função recebe uma sting s devolve uma lista f em que, na i-ésima posição, encontra-se o comprimento do maior
    sufixo que termina na posição i (que não seja a sequência inteira) e que também é prefixo da string 
    A função baseia-se na observação de que, se a resposta para a (i-1)-ésima posição é m, então para a i-ésima posição é 
    m+1 se s[i] == s[m]. Caso contrário, podemos aproveitar o facto de s[:m] ser igual a s[i-m:i] e sabemos que a resposta
    é no máximo f[m-1]. Em cada iteração do for, adicionamos no máximo 1 ao m, portanto, mesmo que diminuamos várias vezes
    o m, nunca o vamos fazer no total mais de len(s) vezes.
    Logo, a função funciona em tempo linear no comprimento da string.
    """
    def _prefix_function(self):
        f = [0] 
        m = 0
        for i in range(1,self.len()):
            while self.pos(i) != self.pos(m) and m > 0:
                m = f[m-1]
            if self.pos(m)==self.pos(i):
                m+=1
            f.append(m)
        return f
