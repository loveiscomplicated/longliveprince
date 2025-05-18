def lookAndSaySequence(n ,l):
    """
    n : initial integer
    l : the length of sequence

    returns the list (sequence) of integers 
    and whether the sequence includes a cycle as a boolean flag 
    for the given initial integer n and the length of sequence l
    """
    def dictToListElem(dic : dict):
        """
        dic : dictionary used in the process

        makes dict to string that is appropriate to output list element
        
        returns : list element
        """
        sorted_dict = sorted(dic.items()) # sorting by keys in order to make it to element of result list
        result = ''
        for i in sorted_dict:
            result += str(i[1])
            result += i[0]
        return int(result)
    
    def makeDict(prevN : int):
        """
        prevN : previous integer that has to be computed

        calculates how many given numbers has appeared and stores as dict
        
        returns a dictionary that stores the number of occurance
        """
        resultDict  = dict()
        numStr = str(prevN) # numbers that converted into string (all keys are string)
        for i in range(len(numStr)):
            if numStr[i] in resultDict.keys():
                resultDict[numStr[i]] += 1
            else:
                resultDict[numStr[i]] = 1
            
        return resultDict

    def flag(lst : list):
        """
        lst : list that has to be checked

        checks whether given list has a cycle
        
        returns : True if the list is valid
        """
        maxCycle = len(lst) // 2
        cycleSize = 1
        while cycleSize <= maxCycle:
            if lst[-cycleSize:] == lst[-2 * cycleSize : -cycleSize]:
                return True
            cycleSize += 1
        return False
    
    # repeat makeDict and dictToListElem for l(alphabet) times
    lst = [n]
    prevN = n
    for i in range(l - 1):
        dic = makeDict(prevN)
        lst.append(dictToListElem(dic))
        prevN = dictToListElem(dic)

    return lst, flag(lst)