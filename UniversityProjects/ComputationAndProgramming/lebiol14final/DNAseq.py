#Classe DNAseq
#Sequências de DNA

class DNAseq():

    def __init__(self):
        self._dna_seq = []

    def add(self, c):
        self._dna_seq.append(c)

    def len(self):
        return len(self._dna_seq)

    def pos(self, i):
        return self._dna_seq[i]

    #Função overlay: procura a maior sobreposição entre um sufixo de um fragmento e um prefixo de w
    def overlay(self, w):
        i = min(self.len(), w.len())

        #Começamos com a maior sobreposição hipotética e paramos quando encontrarmos uma sobreposição válida (que vai ser a maior)
        while i > 0 and w.prefix(i)._dna_seq != self.suffix(i)._dna_seq:
            i -= 1

        return i

    #Função occursQ: Vê se a sequência (self) ocorre dentro da sequência w
    def occursQ(self, w):
        i = 0
        r = False

        #Enquanto não encontrámos nenhuma ocorrência, vamos procurando porções de w que correspondam à sequência (self)
        while i <= w.len() - self.len() and not r:
            if w._dna_seq[i:i + self.len()] == self._dna_seq:
                r = True
            i += 1

        return r

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
