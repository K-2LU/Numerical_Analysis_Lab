import math

def f(x, y):
    f = eval(func)
    return f

print("")
func = input("Enter the function: ")
# print(f(3, 4))

print("Enter the values of x0, y0: ")
x0, y0 = map(float, input().split())
h = float(input("Enter step size: "))
xf = float(input("Enter the final value of x: "))
exct = float(input("Enter the exact solution: "))

print("\nIteration \t x \t       y")

itr, stp = 1, 1
tx, ty = x0, y0

while(x0 < xf):
    k1 = f(x0, y0)
    k2 = f(x0 + 0.75*h, y0 + (0.75*k1*h))

    y0 = y0 + (((1/3)*k1) + ((2/3)*k2))*h
    x0 += h
    print("%d \t %12.4f \t %10.4f" %(itr,y0,y0))
    itr += 1

print("")
print("\n Step, h \t      y(%d) \t    Et \t\t  |εt|%%" %(xf))
for i in range(58):
    print("-", end="")
print("")

itr = 1
for i in range(5):
    while(x0 < xf):
        k1 = f(x0, y0)
        k2 = f(x0 + 0.75*h, y0 + (0.75*k1*h))

        y0 = y0 + (((1/3)*k1) + ((2/3)*k2))*h
        x0 += h
        # print("%d \t %12.4f \t %10.4f" %(itr,y0,y0))
        itr += 1

    print("%5.4f \t %12.4f \t %5.4f \t %5.4f" %(h,y0,exct - y0, ((exct - y0)/ exct)*100))
    x0, y0 = tx, ty
    h = h / 2
    itr += 1