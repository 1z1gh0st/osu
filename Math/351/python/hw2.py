import math
for n in range(0, 20):
    if ((math.exp(0)*(2**(n+1)-1))/((math.factorial(n+1))*(n+1))) < (10**(-5)):
        print(n)
        break
