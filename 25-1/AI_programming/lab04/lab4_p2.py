
class status:
    def status(self, H, N, coordinate, num):
        status.H = H
        status.N = N
        status.coordinate = coordinate # 지금 값을 넣어야 할 자리를 뜻함
        status.num = num # 이제 넣을 값

def validate(coordinate):
    x = coordinate[0]
    y = coordinate[1]
    if x < 0 or y >= H:
        return False
    return True

def bottom_left(MyStatus, lst):
    if not validate(MyStatus.coordinate):
        return "Wall Hit"
    
    x = MyStatus.coordinate[0]
    lst[x].append(MyStatus.num)

    MyStatus.num += 1
    MyStatus.coordinate[0] -= 1
    MyStatus.coordinate[1] += 1
    
    bottom_left(MyStatus, lst)


H = int(input("Display height?: "))
N = int(input("Up to which number to print?: "))

lst = []

for i in range(H):
    lst.append([])
    
# step 1 excecuting...
lst[0].append(1)
coordinate = [1, 0] # 앞으로 넣어야 할 위치
Mystatus = status(H, N, coordinate, 2) # 앞으로 넣어야 할 값

# making step 2 function



# making step 3 function

    

# looping step 2 and 3

