# Nolan Groves
# Lab 11 - Recursion, but this time with python

def fact(n):
    if n == 1:
        return n
    return n*fact(n-1)

def fib(n):
    if n == 1 or n == 0:
        return n
    return fib(n-1) + fib(n-2)

n = input("> ")
print "Factorial: ", fact(n)
print "Fibo: " , fib(n)
    
