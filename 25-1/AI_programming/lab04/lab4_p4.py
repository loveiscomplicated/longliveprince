def lookAndSaySequence(n ,l):
    """
    returns the list (sequence) of integers 
    and whether the sequence includes a cycle as a boolean flag 
    for the given initial integer n and the length of sequence l
    """
    
    def gen(n):
        lst = []
        for i in range(10):
            lst.append([0])
        
        num = str(n)
        for i in range(len(num)):
            lst[ord(i) - 48] += 1
        
        
        
    
