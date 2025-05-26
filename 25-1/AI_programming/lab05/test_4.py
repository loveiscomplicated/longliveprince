from lab5_p3 import Polynomial

p1 = Polynomial([1, 2, 1])
print(f"p1: {p1}\n")

print(f"p1 (x=0): {p1.evaluate(0)}")
print(f"p1 (x=3): {p1.evaluate(3)}")
p1_der = p1.derivative()
p1_int = p1.integral(C=0)
print(f"p1 derivative: {p1_der}")
print(f"p1 integral (C=0): {p1_int}\n")

p2 = Polynomial([0, 1, -1, 2])
print(f"p2: {p2}\n")

print(f"p1 + p2: {p1 + p2}")
print(f"p1 - p2: {p1 - p2}")
print(f"p1 * p2: {p1 * p2}")
