class Fraction(object):
    """Class to represent a number as a fraction with arithmetic and comparison operations."""

    def __init__(self, n, d):
        """
        Initialize a Fraction object with numerator and denominator.
        Raises errors if input types are invalid or denominator is non-positive.
        """
        if type(n) != int or type(d) != int:  # Ensure both inputs are integers
            raise ValueError('requires type int')
        if d <= 0:
            raise ZeroDivisionError('requires positive integer denominator')
        self.num = n
        self.denom = d
        self.reduce()

    def reduce(self):
        """
        Reduces self to simplest form and ensures positive denominator.
        This is done by dividing numerator and denominator by their GCD.
        """
        gcd = self.__gcd(self.num, self.denom)
        if gcd == 1 or self.num == 0 or self.denom <= 1:
            return
        self.num = int(self.num / gcd)
        self.denom = int(self.denom / gcd)

        # Ensure the denominator is always positive
        if self.denom < 0:
            self.num *= -1
            self.denom *= -1

    def __str__(self):
        """
        Returns a string representation of the fraction.
        If denominator is 1, return as integer string.
        If numerator is 0, return '0'.
        """
        if self.num == 0:
            return '0'
        if self.denom == 1:
            return str(self.num)
        return str(self.num) + '/' + str(self.denom)

    def __add__(self, other):
        """
        Adds another Fraction or int to self and returns the result as a new Fraction.
        """
        # Convert int to Fraction for addition
        if isinstance(other, int):
            other = Fraction(other, 1)
        # Cross-multiply to compute new numerator and denominator
        new_num = self.num * other.denom + other.num * self.denom
        new_denom = self.denom * other.denom
        return Fraction(new_num, new_denom)

    def __mul__(self, other):
        """
        Multiplies another Fraction or int with self and returns the result as a new Fraction.
        """
        # Convert int to Fraction for multiplication
        if isinstance(other, int):
            other = Fraction(other, 1)
        # Multiply numerators and denominators
        new_num = self.num * other.num
        new_denom = self.denom * other.denom
        return Fraction(new_num, new_denom)

    def __sub__(self, other):
        """
        Subtracts another Fraction or int from self and returns the result as a new Fraction.
        """
        # If other is int, convert to Fraction and negate
        if isinstance(other, int):
            other = Fraction(-other, 1)
            result = self.__add__(other)
            return result

        # Negate the Fraction and use __add__
        other = other.__neg__()
        result = self.__add__(other)
        return result

    def __truediv__(self, other):
        """
        Divides self by another Fraction or int and returns the result as a new Fraction.
        """
        if other == 0:
            raise ZeroDivisionError('requires positive integer denominator')
        if isinstance(other, int):
            other = Fraction(other, 1)
        # Multiply by reciprocal of other
        result = self.__mul__(Fraction(other.denom, other.num))
        return result

    def __lt__(self, other):
        """
        Returns True if self is less than other (Fraction or int).
        Comparison is done by converting to float.
        """
        a = self.num / self.denom
        if isinstance(other, int):
            b = other
        elif isinstance(other, Fraction):
            b = other.num / other.denom
        else:
            raise ValueError("requires int")
        # Return result of comparison
        return a < b

    def __le__(self, other):
        """
        Returns True if self is less than or equal to other (Fraction or int).
        """
        a = self.num / self.denom
        if isinstance(other, int):
            b = other
        elif isinstance(other, Fraction):
            b = other.num / other.denom
        else:
            raise ValueError("requires int")
        return a <= b

    def __gt__(self, other):
        """
        Returns True if self is greater than other (Fraction or int).
        """
        a = self.num / self.denom
        if isinstance(other, int):
            b = other
        elif isinstance(other, Fraction):
            b = other.num / other.denom
        else:
            raise ValueError("requires int")
        return a > b

    def __ge__(self, other):
        """
        Returns True if self is greater than or equal to other (Fraction or int).
        """
        a = self.num / self.denom
        if isinstance(other, int):
            b = other
        elif isinstance(other, Fraction):
            b = other.num / other.denom
        else:
            raise ValueError("requires int")
        return a >= b

    def __eq__(self, other):
        """
        Returns True if self is equal to other (Fraction or int).
        """
        a = self.num / self.denom
        if isinstance(other, int):
            b = other
        elif isinstance(other, Fraction):
            b = other.num / other.denom
        else:
            raise ValueError("requires int")
        return a == b

    # ----- You don't have to modify below
    def __gcd(self, _a, _b):
        """
        Computes the greatest common divisor (GCD) of two integers.
        Used internally for fraction reduction.
        """
        a, b = abs(_a), abs(_b)
        if b > a:
            a, b = b, a
        while b != 0:
            [a, b] = [b, a % b]
        if a == 0:
            a = 1
        return a

    def __neg__(self):
        """
        Returns the negation of the current fraction (i.e., -self).
        """
        # Flip the sign of numerator
        return Fraction(-self.num, self.denom)

    __radd__ = __add__
    __rmul__ = __mul__

    def __rsub__(self, other):
        """
        Right-side subtraction (int or Fraction - self).
        """
        if isinstance(other, int):
            return Fraction(other, 1).__sub__(self)
        elif isinstance(other, Fraction):
            return other.__sub__(self)
        else:
            raise ValueError('requires type int or Fraction')

    def __rtruediv__(self, other):
        """
        Right-side division (int or Fraction / self).
        """
        if isinstance(other, int):
            return Fraction(other, 1).__truediv__(self)
        elif isinstance(other, Fraction):
            return other.__truediv__(self)
        else:
            raise ValueError('requires type int or Fraction')

    def __pow__(self, other):
        """
        Raises self to the power of an integer and returns the result as a new Fraction.
        """
        if isinstance(other, int):
            if other == 0:
                return Fraction(1, 1)
            else:
                ret = self
                # Multiply repeatedly for positive power
                for _ in range(abs(other) - 1):
                    ret = ret.__mul__(self)
                # Handle negative power
                if other < 0:
                    ret = ret.__rtruediv__(1)
            return ret
        else:
            raise ValueError('requires type int')
