#mathssp
#problemas de otimizaçao
#algoritmo genético - algoritmo de otimização estocástico - aleatório
#simular os mais fortes
#temos dados; temos de deduzir a fórmula
#1 - criar uma população (fírmulas aleatorias; juntar tordas)
#2 - certo nº de gerações, vemos quão boas são; as piores morrem, 
#3 -as melhores misturam.se e "reproduzem-se" duas formas  criam uma terceira
#4 - possibilidade de pequenas mutações aleatórias
#após alugmas gerações fica boa
#formula representada numa arvore
#algoritmos genéticos - formas de antenas - muito boa
#fitness function - importante!!
import operator
import random 


operators = [
    operator.add,
    operator.sub,
    operator.mul,
    operator.truediv,
]

operands = [
    "t",
    "a",
    "v",
    "x",
     1,

]

class Formula:
    """Base class to represent formulas."""

    def eval(self,data):
        raise NotImplementedError()

    def copy(self):
        raise NotImplementedError()

    

    @classmethod
    def new_formula(cls, prob_operator = 0.5):
        if (random.random() < prob_operator):
            return Operator.new_operator(prob_operator/2)
        else: 
            return Operand.new_operand()

    def fitness(self, data_list):
        errors = sum(
            (self.eval(data)-data["result"])**2
            for data in data_list
        )
        return errors
        

class Operand(Formula):
    """class to represent operands"""

    def eval(self, data):
        if isinstance(self.value,str):
            return data[self.value]
        else:
            return self.value

    def copy(self):
        return Operand(self.value)
   
    def __init__(self, value):
        self.value = value
        
    def __repr__(self):
        return str(self.value)

    @classmethod
    def new_operand(cls):
        operand = random.choice(operands)
        return cls(operand)

class Operator(Formula):
    """class to represent operators"""

    def eval(self, data):
        left = self.left.eval(data)
        right = self.right.eval(data)
        if (self.op == operator.truediv and right == 0):
            return float("inf")
        return self.op(left, right)
        

    def copy(self):
        return Operator(
            self.op,
            self.left.copy(),
            self.right.copy(),    
        )


    def __init__(self, op, left, right):
        self.op = op
        self.left = left
        self.right = right

    def __repr__(self):
        return f"({self.left} {self.op.__name__} {self.right})" 
    @classmethod
    def new_operator(cls, prob_operator):
        op = random.choice(operators)
        left = Formula.new_formula(prob_operator)
        right = Formula.new_formula(prob_operator)
        return cls(op,left,right)


def reproduce(f1, f2):
    if isinstance(f1, Operand) and isinstance(f2, Operand):
        op = random.choice(operators)
        return Operator(op,f1.copy(),f2.copy())
    elif isinstance(f1,Operand):
        operator = f2.copy()
        if (random.random() < 0.5): 
            operator.left = f1.copy()
        else:
            operator.right = f1.copy() 
        return operator
        
    elif isinstance(f2,Operand):
        operator = f1.copy()
        if (random.random() < 0.5): 
            operator.left = f2.copy()
        else:
            operator.right = f2.copy() 
        return operator
    else: 
        child = f1.copy()
        into = random.choice(["left","right"])
        from_ = random.choice(["left", "right"])
        setattr(child,into,getattr(f2,from_).copy())
        return child

def make_fake_data():
    data = {}
    data["a"] = random.uniform(-10,10)
    data["v"] = random.uniform(-10,10)
    data["x"] = random.uniform(-10,10)
    data["t"] = random.uniform(-10,10)
    data["result"] = (
        0.5*data["a"]*data["t"]**2 + data["v"] * data["t"] + data["x"]
    )
    return data
            
A = Formula.new_formula()
B = Formula.new_formula()
print(A)
#print(B)
#print (reproduce(A,B))


data = make_fake_data()
print (A.eval(data))

from itertools import pairwise

population = [Formula.new_formula() for _ in range(1000)]
data_list = [make_fake_data() for _ in range(200)]

"""for _ in range(100):
    population = sorted(population, key = lambda p: p.fitness(data_list))[:500]
    #top = population[:20  ] - only for mutations
    random.shuffle(population)
    next_generation = [reproduce(f1,f2) for f1,f2 in pairwise(population)]
    population = population + next_generation

print(min(population, key=lambda p: p.fitness(data_list)))"""

for gen in range(100):
    print(gen, min(population, key=lambda p: p.fitness(data_list)))
    population = sorted(population, key = lambda p: p.fitness(data_list))[:500]
    #top = population[:20  ] - only for mutations
    random.shuffle(population)
    next_generation = [reproduce(f1,f2) for f1,f2 in pairwise(population)]
    population = population + next_generation



