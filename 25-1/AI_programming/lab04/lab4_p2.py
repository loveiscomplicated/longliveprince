H = int(input("Display height?: "))
numbers_to_print = int(input("Up to which number to print?: "))

lst = []

# initial status of the program
for i in range(H):
    lst.append([])

lst[0].append(1)
ptr = 0 # indicates the current row
step = 2 # indicates the current step 
count = 1

while numbers_to_print != count:
    count += 1
    if step == 2:
        lst[ptr].append(count)
        
    continue

