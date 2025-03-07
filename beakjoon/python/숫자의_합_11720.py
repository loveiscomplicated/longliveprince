from collections import Counter

num = int(input())

str_list = []

for a in range(num):
    str_list.append(input())

for i in str_list:
    count = Counter(i).most_common(2)
    if count[0][1] == count[1][1]:
        print("?")
    else:
        print(count[0][0]) 
        
        
import sys
sys.stdin.readline()
    


