import numpy as np

veccy_weccy = np.array([[0],[1],[2],[3],[4]])

def shmigmoid(x):
    return 1 / (1 + np.exp(-1 * x))

print(shmigmoid(veccy_weccy))