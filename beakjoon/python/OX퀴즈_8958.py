num = int(input())

for i in range(num):
    score = 0
    li = input().split('X')
    for j in li:
        if len(j) != 0:
            score += sum(range(1, len(j) + 1))
    print(score)