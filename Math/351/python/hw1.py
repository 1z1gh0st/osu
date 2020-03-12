#import math

for n in range(1000):
    if (((3/2)**(n+2))*((1/3)**(n+1)) < 10**(-4)):
        print("N must be at least : ", n)
        break;
