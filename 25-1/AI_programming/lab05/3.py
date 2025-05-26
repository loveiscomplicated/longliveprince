import math
try:
    from lab5_p1 import Fraction
except ImportError:
    pass

class Polynomial:
    def __init__(self, coefficients: list):
        """Initializes the polynomial with a list of integer or Fraction coefficients."""
        ### Solution version below
        self.coefficients = []
        for c in coefficients:
            if isinstance(c, int):
                self.coefficients.append(Fraction(c, 1))
            elif isinstance(c, Fraction):
                self.coefficients.append(c)

    def __add__(self, other):
        small = other
        big = self
        if len(self.coefficients) < len(other.coefficients):
            small = self
            big = other
            
        lst = []

        for i in range(len(small.coefficients)):
            lst.append(small.coefficients[i] + big.coefficients[i])
        for i in range(len(big.coefficients) - len(small.coefficients)):
            lst.append(big.coefficients[len(small.coefficients) + i])
        
        result = Polynomial(lst)
        
        return result
    

    def __sub__(self, other):
        """Subtracts another Polynomial from self and returns a new Polynomial."""
        negated_lst = [-1 * i for i in other.coefficients]
        negated_other = Polynomial(negated_lst)
        
        return self.__add__(negated_other)

    def __mul__(self, other):
        lst = self.coefficients
        other_lst = other.coefficients
        
        result_lst = [Fraction(0, 1)] * (len(lst) + len(other_lst) - 1)
        for i in range(len(lst)):
            for j in range(len(other_lst)):
                result_lst[i + j] += lst[i] * other_lst[j]
        
        return Polynomial(result_lst)
                

    def derivative(self):
        lst = []
        for i in range(1, len(self.coefficients)):
            lst.append(self.coefficients[i] * i)
        
        return Polynomial(lst)

    def integral(self, C=0):
        lst = [Fraction(C, 1)]
        for i in range(len(self.coefficients)):
            lst.append(self.coefficients[i] * Fraction(1, i + 1))
        return Polynomial(lst)

    def evaluate(self, x: int):
        """Return f(x) where f is self polynomial"""
        result = 0
        for i, coeff in enumerate(self.coefficients):
            result += coeff * (x ** i)
        return result

    def __str__(self):
        """String representation of polynomial equation"""
        terms = []
        for i, coeff in enumerate(self.coefficients):
            if coeff != 0:
                if i == 0:
                    terms.append(f"{coeff}")
                elif i == 1:
                    terms.append(f"{coeff}*x")
                else:
                    terms.append(f"{coeff}*x^{i}")
        return " + ".join(terms).replace('+ -', '- ') if terms else "0"

