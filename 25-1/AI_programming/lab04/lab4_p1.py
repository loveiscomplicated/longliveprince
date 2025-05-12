import operator

# initial status of program
running = True
lst = []

while running:
    user_input1 = input("Enter a fruit type (q to quit): ")
    if user_input1 == 'q': # terminating condition
        break
    else:
        user_input2 = int(input("Enter a weight in kg: "))
        idx = -1
        for i in range(len(lst)):
            if user_input1 == lst[i][0]:
                idx = i
                break
        if idx == -1:
            lst.append([user_input1, user_input2])
        else:
            lst[idx][1] += user_input2
        continue

lst.sort(key=operator.itemgetter(0))
for i in lst:
    print(f'{i[0]}, {i[1]}kg.')

            