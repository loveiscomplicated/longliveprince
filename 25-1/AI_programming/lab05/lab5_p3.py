import math
try:
    from lab5_p1 import Fraction
except ImportError:
    pass

class Polynomial:
    """
    Polynomial class that supports operations such as addition, 
    subtraction, multiplication, derivative, and integral.
    """

    def __init__(self, coefficients: list):
        """
        Initialize a Polynomial object with a list of coefficients.

        Parameters:
        coefficients (list): A list containing integers or Fractions 
                             representing the polynomial coefficients.

        Returns:
        None
        """
        self.coefficients = []
        for c in coefficients:
            if isinstance(c, int):  # Convert int to Fraction
                self.coefficients.append(Fraction(c, 1))
            elif isinstance(c, Fraction):  # Keep Fraction as-is
                self.coefficients.append(c)

    def __add__(self, other):
        """
        Add two Polynomial objects and return a new Polynomial.

        Parameters:
        other (Polynomial): The Polynomial to add.

        Returns:
        Polynomial: Sum of self and other.
        """
        small = other
        big = self
        if len(self.coefficients) < len(other.coefficients):
            small = self
            big = other

        lst = []

        # Add overlapping coefficients
        for i in range(len(small.coefficients)):
            lst.append(small.coefficients[i] + big.coefficients[i])
        # Append remaining terms from the larger polynomial
        for i in range(len(big.coefficients) - len(small.coefficients)):
            lst.append(big.coefficients[len(small.coefficients) + i])

        result = Polynomial(lst)

        return result

    def __sub__(self, other):
        """
        Subtract another Polynomial from self.

        Parameters:
        other (Polynomial): The Polynomial to subtract.

        Returns:
        Polynomial: Result of self - other.
        """
        negated_lst = [-1 * i for i in other.coefficients]
        negated_other = Polynomial(negated_lst)

        return self.__add__(negated_other)

    def __mul__(self, other):
        """
        Multiply two Polynomial objects and return a new Polynomial.

        Parameters:
        other (Polynomial): The Polynomial to multiply with.

        Returns:
        Polynomial: Product of self and other.
        """
        lst = self.coefficients
        other_lst = other.coefficients

        # Result length is m + n - 1 for multiplication
        result_lst = [Fraction(0, 1)] * (len(lst) + len(other_lst) - 1)
        for i in range(len(lst)):
            for j in range(len(other_lst)):
                result_lst[i + j] += lst[i] * other_lst[j]

        return Polynomial(result_lst)

    def derivative(self):
        """
        Compute the derivative of the Polynomial.

        Returns:
        Polynomial: The derivative as a new Polynomial.
        """
        lst = []
        for i in range(1, len(self.coefficients)):
            lst.append(self.coefficients[i] * i)

        return Polynomial(lst)

    def integral(self, C=0):
        """
        Compute the integral of the Polynomial.

        Parameters:
        C (int): Constant of integration (default is 0).

        Returns:
        Polynomial: The integral as a new Polynomial.
        """
        lst = [Fraction(C, 1)]
        for i in range(len(self.coefficients)):
            lst.append(self.coefficients[i] * Fraction(1, i + 1))
        return Polynomial(lst)

    def evaluate(self, x: int):
        """
        Evaluate the Polynomial at a specific x value.

        Parameters:
        x (int): The input value.

        Returns:
        result (Fraction): Computed result of the polynomial.
        """
        result = 0
        for i, coeff in enumerate(self.coefficients):
            result += coeff * (x ** i)
        return result

    def __str__(self):
        """
        Generate a human-readable string representation of the polynomial.

        Returns:
        str: A string showing the polynomial expression.
        """
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
