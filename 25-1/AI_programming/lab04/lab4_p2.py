
class status:
    def status(self, H, N, coordinate, num):
        status.H = H
        status.N = N
        status.coordinate = coordinate # 지금 값을 넣어야 할 자리를 뜻함
        status.num = num # 이제 넣을 값

def validate_wall(MyStatus):
    x = MyStatus.coordinate[0]
    y = MyStatus.coordinate[1]
    if x < 0 or y >= H:
        return False
    return True

def validate_num(MyStatus):
    if MyStatus.num > MyStatus.N:
        return False
    return True

# making step 2 function
def bottom_left(MyStatus : status, lst : list):
    if not validate_num(MyStatus):
        return MyStatus, lst, "Over"
    if not validate_wall(MyStatus):
        MyStatus.coordinate[0] += 1
        MyStatus.coordinate[1] -= 1
        return MyStatus, lst, "Wall Hit"
    
    x = MyStatus.coordinate[0]
    lst[x].append(MyStatus.num)

    MyStatus.num += 1
    MyStatus.coordinate[0] -= 1
    MyStatus.coordinate[1] += 1
    
    bottom_left(MyStatus, lst)

def step_2(MyStatus : status, lst : list):
    # go right once
    if not validate_num(MyStatus):
        return "Over"
    MyStatus.coordinate[0] += 1
    return bottom_left(MyStatus, lst)


# making step 3 function
def upper_right(MyStatus : status, lst : list):
    if not validate_num(MyStatus):
        return "Over"
    if not validate_wall(MyStatus):
        MyStatus.coordinate[0] -= 1
        MyStatus.coordinate[1] += 1
        return "Wall Hit"
    
    x = MyStatus.coordinate[0]
    lst[x].append(MyStatus.num)

    MyStatus.num += 1
    MyStatus.coordinate[0] += 1
    MyStatus.coordinate[1] -= 1
    
    upper_right(MyStatus, lst)

def step_3(MyStatus : status, lst : list):
    # If bottom direction is available, go bottom once
    bottom = status(MyStatus.H, MyStatus.N, MyStatus.coordinate, MyStatus.num)
    bottom.coordinate[1] += 1
    if MyStatus.coordinate[1] += 


H = int(input("Display height?: "))
N = int(input("Up to which number to print?: "))

lst = []

for i in range(H):
    lst.append([])
    
# step 1 excecuting...
lst[0].append(1)
coordinate = [1, 0] # 앞으로 넣어야 할 위치
MyStatus = status(H, N, coordinate, 2) # 2 == 앞으로 넣어야 할 값


# step 2 excecuting...

# looping step 2 and 3

