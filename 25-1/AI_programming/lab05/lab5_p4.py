import math

class Point:
    """
    A class to represent a 2D point on a Euclidean plane.
    Supports operations like translation, scaling, reflection, and rotation.
    """

    def __init__(self, x, y):
        """
        Initialize a Point object with rounded x and y coordinates.

        Parameters:
        x (float): x-coordinate.
        y (float): y-coordinate.
        """
        self.x = round(x, 2)
        self.y = round(y, 2)

    def __str__(self):
        """
        Return a string representation of the point in (x.xx, y.yy) format.

        Returns:
        str: Formatted coordinate string.
        """
        return f"({self.x:.2f}, {self.y:.2f})"
    
    def __add__(self, other):
        """
        Add two points component-wise.

        Parameters:
        other (Point): The other point to add.

        Returns:
        Point: Resulting point after addition.
        """
        return Point(self.x + other.x, self.y + other.y)

    def __neg__(self):
        """
        Return a new Point with both coordinates negated.

        Returns:
        Point: The negated point.
        """
        return Point(-self.x, -self.y)

    def __sub__(self, other):
        """
        Subtract another point from the current point.

        Parameters:
        other (Point): The point to subtract.

        Returns:
        Point: Result of subtraction.
        """
        return Point(self.x - other.x, self.y - other.y)
    
    def __mul__(self, other):
        """
        Multiply the point by a scalar.

        Parameters:
        other (float or int): The scalar value.

        Returns:
        Point: Scaled point.

        Raises:
        ValueError: If other is not float or int.
        """
        if isinstance(other, float) or isinstance(other, int):
            return Point(other * self.x, other * self.y)
        else:
            raise ValueError("other should be type float or int")
    
    def __rmul__(self, other):
        """
        Multiply when scalar is on the left (commutative).

        Parameters:
        other (float or int): The scalar value.

        Returns:
        Point: Scaled point.
        """
        return self.__mul__(other)
    
    def __truediv__(self, other):
        """
        Divide the point by a scalar.

        Parameters:
        other (float or int): The scalar value.

        Returns:
        Point: Scaled down point.

        Raises:
        ZeroDivisionError: If other is zero.
        ValueError: If other is not float or int.
        """
        if isinstance(other, float) or isinstance(other, int):
            if other != 0:
                return Point(self.x / other, self.y / other)
            else:
                raise ZeroDivisionError("other should be non-zero")
        else:
            raise ValueError("other should be type float or int")

    def symmetric(self, reference_point):
        """
        Return a point symmetric to self with respect to the given reference point.

        Parameters:
        reference_point (Point): The point to reflect about.

        Returns:
        Point: The symmetric point.
        """
        # Reflect the point over the reference point
        x_dot = 2 * reference_point.x - self.x
        y_dot = 2 * reference_point.y - self.y
        return Point(x_dot, y_dot)
    
    def rotate(self, reference_point, angle):
        """
        Rotate the point counterclockwise about a reference point.

        Parameters:
        reference_point (Point): Center of rotation.
        angle (float): Angle in radians.

        Returns:
        Point: The rotated point.
        """
        # Apply translation, rotation, and inverse translation
        cos = math.cos(angle)
        sin = math.sin(angle)

        x_dot1 = self.x - reference_point.x
        y_dot1 = self.y - reference_point.y

        x_dot2 = x_dot1 * cos - y_dot1 * sin
        y_dot2 = x_dot1 * sin + y_dot1 * cos

        x_dot = reference_point.x + x_dot2
        y_dot = reference_point.y + y_dot2

        return Point(x_dot, y_dot)
