def Philip(n):
    Q = [0] * n
    R = [0] * n
    Q[0] = 1
    R[0] = 2
    for i in range(1,n):
        Q[i] = R[i-1]
        R[i] = 2 * (Q[i-1] + R[i-1])
    return Q[n-1] + R[n-1]

def Jacob(n):
    if n == 1:
        return 3
    elif n == 2:
        return 8
    else:
        return (2 * Jacob(n-1)) + Jacob(n-2)

def Brandon(n):
    if n == 1:
        return 3
    elif n == 2:
        return 8
    else:
        return Brandon(n-1) + Brandon(n-1)

def BruteForce(n):
    if n == 1:
        return ["0", "1", "2"]
    else:
        TotalStrings = []
        PreviousStrings = BruteForce(n-1)
        for string in PreviousStrings:
            for i in range(0, 3):
                TotalStrings.append(string + str(i))
        return TotalStrings

def RemoveBadStrings(array):
    GoodStrings = []
    for string in array:
        if string.find("00") == -1:
            GoodStrings.append(string)
    return GoodStrings
'''
n = 10
for i in range(1,n):
    print("\n\nPHILIP: ", Philip(i), "\nJACOB: ", Jacob(i), "\nBRANDON: ", Brandon(i), "\nBRUTE FORCE: ", len(RemoveBadStrings(BruteForce(i))))
'''

for i in range(1,100):
    print(Philip(i))