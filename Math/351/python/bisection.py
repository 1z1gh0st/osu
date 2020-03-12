def f(x):
    return (x**3)-(x**2)-1

def root_find_bisection(a0, b0, n):
    a = a0
    b = b0
    if (a > b):
        swap = b
        b = a
        a = swap
    for i in range(0,n):
        c = (0.5)*(a+b)
        if (f(c) < 0):
            a = c
        else:
            b = c
        if (i == n-1):
            return (0.5)*(a+b)

print(root_find_bisection(0,2,7))
