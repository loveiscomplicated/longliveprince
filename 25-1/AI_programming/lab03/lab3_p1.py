def CarSimulation(N, M):
    """
    Car simulation
    param: 
        N: Number of rows
        M: Number of columns
    returns:
        k, x, y
    """
    k = -1
    x = 1
    count = 0
    y = 1
    Nc = N - 1 # copy of N in order not to directly modify the value
    Mc = M - 1 # copy of M in order not to directly modify the value

    status = 'R'
    
    while True:
        if status == 'R' and count == 0:
            if Nc == 0:
                return k, x, y
            x += Nc
            count += 1
            k += 1
            status = 'D'

        elif status == 'R' and count != 0:
            if Nc == 0:
                return k, x, y
            x += Nc
            Nc -= 1
            k += 1
            status = 'D'

        elif status == 'D':
            if Mc == 0:
                return k, x, y
            y += Mc
            Mc -= 1
            k += 1
            status = 'L'

        elif status == 'L':
            if Nc == 0:
                return k, x, y
            x -= Nc
            Nc -= 1
            k += 1
            status = 'U'

        elif status == 'U':
            if Mc == 0:
                return  k, x, y
            y -= Mc
            Mc -= 1
            k += 1
            status = 'R'
