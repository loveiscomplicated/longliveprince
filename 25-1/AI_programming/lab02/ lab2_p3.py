def resetValues(L, t):
    """
    [parameters]
    L : list that only contains integer or float
    t : threshold value
    
    [returns]
    all values in list L that are above(>) t are removed
    """
    # using List Comprehension to make the code shorter.
    # this can create lists with simple, concise code without explicitly writing loops.
    Result = [i for i in L if i <= t]
    return Result

