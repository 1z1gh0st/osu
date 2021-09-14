# --- This is not proper code, only for trying things out --- #
import random

n = 3

A = []
for i in range(0, n):
    row = []
    for j in range(0, n):
        row.append(random.random())
    A.append(row)

print(A)
