import math


def function(x):
    function = eval(function_string)
    return function


function_string = input("Enter the function in python format: ")
a, b = map(float, input("Enter the initial and final limit: ").split())
exact = float(input("Enter the exact solution: "))
n = int(input("Give the total number of segment: "))

odd_sum = even_sum = 0.0
h = (b-a)/n
for i in range(1, n):
    if i % 2:
        odd_sum += function(a+i*h)
    else:
        even_sum += function(a+i*h)
ans = (b-a)/(3*n)*(function(a)+4*odd_sum + 2*even_sum+function(b))

print("\nThe result of the integration is: ", ans)
print("The true error is: ", exact - ans)
print("The absolute relative error is: ",
      abs(exact-ans)/exact*100, "%\n\n", sep="")


print('N\t\tValue\t\t\tE(t)\t\t\t|et|%%')
print('------------------------------------------------------------------------')
for i in range(2, 11, 2):
    odd_sum = even_sum = 0.0
    h = (b-a)/i
    for j in range(1, i):
        if j % 2:
            odd_sum += function(a+j*h)
        else:
            even_sum += function(a+j*h)
    ans = (b-a)/(3*i)*(function(a)+4*odd_sum + 2*even_sum+function(b))
    print('%d\t\t%f\t\t%f\t\t%f' %
          (i, ans, exact-ans, abs(exact-ans)/exact*100))
