def num_to_string(num):
    """
    parameter 
    - num : integer which has to be converted into proper form of string
    
    returns
    - 3 character long string
    """
    if len(str(num)) < 3:
        return ' '*(3 - len(str(num))) + str(num)
    else:
        return str(num)
    



n = int(input("Up to which number to print?: "))

lst = [list(), list(), list(), list(), list(), list(), list(), list(), list(), list()]

temp = 1

while temp <= n:
    for inner_lst in lst:
        if temp > n:
            break
        inner_lst.append(temp)
        temp += 1
    
# checking if the inner list is empty. if it does, then discard it.
for i in range(len(lst)):
    if len(lst[i]) == 0:
        del lst[i]
    