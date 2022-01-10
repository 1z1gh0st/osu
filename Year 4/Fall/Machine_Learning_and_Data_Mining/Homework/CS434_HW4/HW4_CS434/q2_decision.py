import numpy as np
import matplotlib.pyplot as plt
import matplotlib

def H(Y):
        sum = 0
        for y_i in Y:
                Pyi = np.count_nonzero(Y == y_i)
                sum -= Pyi * np.log2(Pyi)
        return sum

def H_(X, Y):
        sum = 0
        k = len(Y)
        for j in range(0, 2):
                Pxj = np.count_nonzero(X == X[j])
                int_sum = 0
                for i in range(0, k):
                        Pyi_xj = np.count_nonzero((Y == Y[i]) and (X == X[j]))
                        int_sum += Pyi_xj * np.log2(Pyi)     
                sum -= Pxj * int_sum
        return sum

def IG(X):
        return H(Y) - H_(Y,X)

X_train = [
        [0,1,1],
        [1,1,1],
        [0,0,0],
        [1,1,0],
        [0,1,0],
        [1,0,1]
        ]
y_train = [0,0,0,1,1,1]

print(H(y_train))


