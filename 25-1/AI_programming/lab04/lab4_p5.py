def SmoothingMethod(l, k):
    """
    l : one-dimensional array
    k : window size

    computes : a sliding window of size k

    returns:
    array smoothed (smoothed_list) by . 
    """
    lst = []
    expansion = int((k - 1) / 2)
    for i in range(len(l)):
        if i == 0:
            # expansion + initial number in order to make the expansion appropriate
            for j in range(expansion + 1): 
                lst.append(l[0])
        elif i == len(l) - 1:
            for j in range(expansion + 1):
                lst.append(l[-1])
        else:
            lst.append(l[i])

    # initialize the result list and then use sliding window
    resultList = []

    for i in range(len(lst) - k + 1):
        slidingWindow = []
        for j in range(k):
            slidingWindow.append(lst[i + j])
            
        resultList.append(round(sum(slidingWindow)/k, 1))

    return resultList
