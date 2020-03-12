import math
for n in range(0, 1000):
    R_bound = (4.0**((2.0*n)+2.0))/float(math.factorial(n+1))
    if (R_bound < float(10**(-3))):
            print(n)
            break
