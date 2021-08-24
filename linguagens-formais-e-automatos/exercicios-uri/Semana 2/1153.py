# -*- coding: utf-8 -*-

def factorial(n):
    if n == 1:
        return n
    
    else:
        return n * factorial(n-1)

n = int(input())

ans = factorial(n)
print(ans)
