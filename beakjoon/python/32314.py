a = int(input())
temp = input()
w = int(temp.split()[0])
v = int(temp.split()[1])

if a*v <= w:
    print(1)
else:
    print(0)