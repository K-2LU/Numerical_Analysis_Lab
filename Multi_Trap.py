import math

def f(x):
    f = eval(func)
    return f

func = input("Enter the function in python format: ")
a, b  = map(float, input("Enter the values of a(lower limit) and b(upper limit): ").split())

ex = float(input("Enter the exact solution: "))
n = int(input("Enter the number of segments: "))

print("The area under the function from a to b: ", end="")

temp = 0
h = (b-a)/n

for i in range(1, n):
    temp += f(a + i*h)

ans = h*0.5*(f(a)+2*temp+f(b))
print("%.4f" %ans)

print("True error: %.4f" %(ex - ans))
print("The absolute relative error: %.4f" %((abs(ex-ans)*100)/ex))

print("\n")
print("     n    \t    Value \t    Et \t\t   |εt|% \t   |εa|%")
for i in range(74):
    print("-", end="")
print("")

for i in range(1, 9):
    n = i
    temp = 0
    h = (b-a)/n

    for j in range(1, n):
        temp += f(a + j*h)  
    ans = h*0.5*(f(a)+2*temp+f(b))

    if i == 1:
        print("    %d    \t %.4f  \t %.4f  \t %.4f \t   ---" %(n, ans, (ex - ans), ((ex - ans)*100)/ex))
    else :
        print("    %d    \t %.4f  \t %.4f  \t %.4f \t %.4f" %(n, ans, (ex - ans), ((ex - ans)*100)/ex, (((ans - prev_ans)*100)/ans)))

    prev_ans = ans