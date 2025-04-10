def evalPolynomial(x, L):
    """
    [parameters]
    x : integer
    L : coefficient list
    
    [returns]
    the value of a polynomial computation
    """
    if len(L) == 0:
        return 0
    
    # this is a list that contains the values of exponentiation
    lst = [x ** i for i in range(len(L))]
    
    # result list contains the values if each terms
    result = []
    for i in range(len(L)):
        result.append(lst[i]*L[i])
    
    # summing up to return the result of computation
    return sum(result)    
    
        
