def num_to_string(num):
    """
    [purpose]
    in order to make the spaces properly
    [parameter]
    num : integer which has to be converted into proper form of string
    
    [returns]
    3 character long string
    """
    if len(str(num)) < 3:
        return ' '*(3 - len(str(num))) + str(num)
    elif len(str(num)) == 3:
        return str(num)
    


# getting the user input
n = int(input("Up to which number to print?: "))

# initializing the list
lst = [list(), list(), list(), list(), list(), list(), list(), list(), list(), list()]

# adding values to the list
temp = 1
while temp <= n:
    for inner_lst in lst:
        if temp > n:
            break
        inner_lst.append(temp)
        temp += 1
    
# checking if the inner list is empty. if it does, then discard it.
new_lst = [i for i in lst if len(i) != 0]

# converting integers into string by using num_to_string function
for inner_lst in new_lst:
    for i in range(len(inner_lst)):
        inner_lst[i] = num_to_string(inner_lst[i])
        
# printing line by line
for inner_lst in new_lst:
    print(''.join(inner_lst))
