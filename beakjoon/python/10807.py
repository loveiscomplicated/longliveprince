num_repeat = int(input())
num_str = input()
lst = [int(i) for i in num_str.split(' ')]
q = int(input())
ans = 0

for i in lst:
    if i == q:
        ans += 1
        
print(ans)