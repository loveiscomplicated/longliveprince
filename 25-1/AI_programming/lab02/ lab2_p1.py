size = int(input("Enter a size: "))
direction = input("Enter a direction: ")

if direction == 'l':
    # star_arr is the list of number of stars that has to be printed in each line.
    # ex) if (direnction == 'l') and (size == 3), then star_arr == [1, 2, 3, 2, 1]
    star_arr = list(range(1, size + 1))
    star_arr.extend(list(range(size - 1, 0, -1)))
    
    for num_star in star_arr:
        line = ' ' * (size - num_star) + '*' * num_star
        print(line)

elif direction == 'r':
    star_arr = list(range(1, size + 1))
    star_arr.extend(list(range(size - 1, 0, -1)))
    
    # the only difference between direction == 'l' is the order of space and star
    for num_star in star_arr:
        print('*' * num_star)
        
elif direction == 'u':
    star_arr = range(1, 2*size, 2)
    space_arr = range(size - 1, -1, -1)
    
    for index in range(size):
        line = ' ' * space_arr[index] + '*' * star_arr[index]
        print(line)

elif direction == 'd':
    star_arr = range(size*2 - 1, 0, -2)
    
    for index in range(size): # not necessary to make space_arr since it's same as range(size)
        line = ' ' * index + '*' * star_arr # so we use index instead
        print(line)