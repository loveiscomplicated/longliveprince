lst = []

for i in range(9):
    lst.append(int(input()))


for i in range(1,9):
        for j in range(0,8):
            if (sum(lst) - lst[i] - lst[j]) == 100:
                a = i
                b = j

del lst[a]
del lst[b]

lst.sort()

for i in lst:
    print(i)