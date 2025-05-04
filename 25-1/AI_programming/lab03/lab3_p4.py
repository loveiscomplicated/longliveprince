def FindGoldbachCombination(N):
    """
    this function finds the Goldbach Combination
    param: N(integer value that is bigger than 2)
    returns: the Goldbach Combination 
    """
    def isPrime(num): # first, find the prime number
        if num == 1:
            return False
        if num == 2:
            return True 
        for i in range(2, num):
            if num % i == 0:
                return False
        return True
            
    prime_lst = []
    for i in range(1, 100_001): # 100001 == 100_001, just for convenience
        if isPrime(i):
            prime_lst.append(i)

    
    final_list = []
    for i in range(len(prime_lst)):
        for j in range(len(prime_lst)):
            if prime_lst[i] + prime_lst[j] == N:
                if prime_lst[i] <= prime_lst[j]:
                    final_list.append([prime_lst[i] , prime_lst[j]])

    return final_list