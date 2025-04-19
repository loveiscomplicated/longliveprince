from lab2_p3 import resetValues

# L, t
testcases = [
    ([i for i in range(7)], 2.5),
    ([2*i+1 for i in range(10)], 7),
    ([i**2 for i in range(5)], 100)
]

for (L, t) in testcases:
    print(f"L={L}, t={t}, your output={resetValues(L, t)}, L after function call={L}")
