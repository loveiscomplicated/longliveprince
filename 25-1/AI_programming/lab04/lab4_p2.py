def makeCoordList(H, k):
    """
    H : height
    k : x + y 
        where x and y is the index of 2 dimensional array
    
    this function makes the list of coordinates

    returns : coordinate_list
    """
    coordinate_list = []
    x = k
    y = 0

    while y < H:
        coordinate_list.append((x, y))
        x -= 1
        y += 1

        if x < 0:
            break

    if k % 2 == 0:
        coordinate_list = coordinate_list[::-1]

    return coordinate_list

def putValue(H, N):
    """
    H : height
    N : integer values from 1 to N
    
    puts the values to the coordinate_list

    returns : result (list)
    """
    lst = []
    k = 0
    while len(lst) < N:
        if len(lst) + len(makeCoordList(H, k)) <= N:
            lst.extend(makeCoordList(H, k))
        elif len(lst) < N and len(lst) + len(makeCoordList(H, k)) > N:
            rightEnd = N - len(lst)
            lst.extend(makeCoordList(H, k)[:rightEnd])
        k += 1
    
    for i in range(len(lst)):
        lst[i] = (lst[i], i + 1)

    result = []
    for i in range(H):
        result.append([])
    
    for i in lst:
        result[i[0][1]].append(i[1])
    
    return result

            
# initializing the program, H and N are required
H = int(input("Display height?: "))
N = int(input("Up to which number to print?: "))

resultList = putValue(H, N)

# making resultList into string so that the program can print within given conditions
for i in resultList:
    resultstr = ""
    for j in i:
        strJ = str(j)
        if len(strJ) < 3:
            space = 3 - len(strJ)
            strJ = ' ' * space + strJ
        resultstr += strJ
    print(resultstr)



