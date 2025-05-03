def FindMaxValue(D1,D2,D3):
    """asdfasdfasdf"""
    def find_opp(index):
        if index == 0:
            opp = 4
        elif index == 1:
            opp = 3
        elif index == 2:
            opp = 5
        elif index == 3:
            opp = 1
        elif index == 4:
            opp = 0
        elif index == 5:
            opp = 2 
        return opp
    
    sum1 = []
        
    for i in range(6):
        for j in range(6):
            if D1[i] == D2[j]:
                opp_1 = find_opp(j) # opposite side of index j
                for k in range(6):
                    if D2[opp_1] == D3[k]:
                        opp_2 = find_opp(k) # opposite side of index k
                        partial_sum_d1 = sum(D1) - D1[i]
                        partial_sum_d2 = sum(D2) - D2[j] - D2[opp_1]
                        partial_sum_d3 = sum(D3) - D3[k] - D3[opp_2]
                        temp_sum = partial_sum_d1 + partial_sum_d2 + partial_sum_d3
                        sum1.append(temp_sum)
    if len(sum1) == 0:
        Max_value = -1
        return Max_value
    else:
        Max_value = sum1[0]

        for i in range(len(sum1)):
            if Max_value < sum1[i]:
                Max_value = sum1[i]

        
        return Max_value
            
    
