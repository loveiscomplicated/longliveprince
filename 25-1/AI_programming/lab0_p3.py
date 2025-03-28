num_lst = []

while True:
    user_input = int(input('Your number: '))
    if user_input == 0:
        break
    else:
        num_lst.append(user_input)
        

lst_pos = []
lst_neg = []

for i in num_lst:
    if abs(i) <= 100:
        if i > 0:
            lst_pos.append(i)
        elif i < 0:
            lst_neg.append(i)
    else:
        continue

if len(lst_pos) == 0:
    print('No positive integer entered')
else:
    print(f'There are {len(lst_pos)} positive integer(s) and the sum is {sum(lst_pos)}')
    
if len(lst_neg) == 0:
    print('No negative integer entered')
else:
    print(f'There are {len(lst_neg)} positive integer(s) and the sum is {sum(lst_neg)}')

