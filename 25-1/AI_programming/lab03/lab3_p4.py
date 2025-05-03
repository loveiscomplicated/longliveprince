def FindGoldbachCombination(N):
    """asdfasdfasdfa"""
    def isPrime(num):
        if num == 1:
            return False
        if num == 2:
            return True 
        for i in range(2, num):
            if num % i == 0:
                return False
        return True
            
    prime_lst = []
    for i in range(1, 100_001):
        if isPrime(i):
            prime_lst.append(i)

    
    final_list = []
    for i in range(len(prime_lst)):
        for j in range(len(prime_lst)):
            if prime_lst[i] + prime_lst[j] == N:
                final_list.append([prime_lst[i] , prime_lst[j]])

    for i in range(len(final_list)):
        for j in range(len(final_list)):
            if i != j:
                if (final_list[i][::-1] == final_list[j]):
                    del final_list[j]

    
    
    return final_list