import math

def f(x):
    f = eval(func)
    return f

func = input("Enter the function in python format: ")
a, b  = map(float, input("Enter the values of a(lower limit) and b(upper limit): ").split())

ex = float(input("Enter the exact solution: "))

print("The area under the function from a to b: ", end="")
h = (b-a)/2
ans = h*(f(a)+f(b))
print("%.4f" %ans)

print("True error: %.4f" %(ex - ans))
print("The absolute relative error: %.4f" %((abs(ex-ans)*100)/ex))