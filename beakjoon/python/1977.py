m = int(input())
n = int(input())


li = []

for i in range(m, n+1):
    if (i**(0.5)) == int(i**(0.5)):
        li.append(i)

if len(li) == 0:
    print(-1)

else:
    print(sum(li))
    print(li[0])


