def myPiCalculator(tol):
    """
    [parameters]
    tol : tolerance parameter tol tells you when to stop the computation
    
    [returns]
    the approximated value of pi
    """

    def termCalculator(temp):
        """
        calculating the value of some part of each terms
        
        [parameters]
        temp : indicating the n-th term
        
        [returns]
        the denominator of the term
        """
        if temp == 1:
            return 2**0.5
        else:
            return (2 + termCalculator(temp - 1))**0.5 # recursion is used. not really wanted to show off.
    
    pi = 2
    temp = 1
    new_pi = pi * (2 / termCalculator(temp))    

    while True:
        temp += 1
        (pi, new_pi) = (new_pi, new_pi*(2/termCalculator(temp))) # updating the variables by using tuple
        diff = abs(pi - new_pi)
        if diff < tol:
            break
        else:
            continue
            
    return new_pi
        
