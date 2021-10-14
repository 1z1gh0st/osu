import numpy as np

array_x = np.array([[1,2,3,4],[5,6,7,8],[8,9,10,11],[12,13,14,15],[16,17,18,19],[20,21,22,23]])

print(array_x)

train_x = np.array([])

for i in range(0,3):
    if i != 2:
        if train_x.size == 0:
            train_x = np.vsplit(array_x, 3)[i]
        else:
            train_x = np.append(train_x, np.vsplit(array_x, 3)[i], axis=0)
        
print(train_x)