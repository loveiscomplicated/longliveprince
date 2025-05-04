def FindLongestWord(file_name):
    """
    finding the longest word in the given test file(.txt)
    param: 
        file_name: name of the file
    returns:
        the longest word
    """
    with open(file_name, 'r') as f:
        content = f.read()
    
    lst = content.split()
    L_idx = len(lst[0]) # largest index

    for i in range(len(lst)):
        if len(lst[L_idx]) < len(lst[i]):
            L_idx = i

    return lst[L_idx].lower()
