def CarSimulation(N, M):
    """asdfasdfasdf"""
    k = -1
    x = 1
    count = 0
    y = 1
    Nc = N - 1 # copy of N
    Mc = M - 1 # copy of M

    status = 'R'
    
    while True:
        print(x, y, status, Nc, Mc)
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
