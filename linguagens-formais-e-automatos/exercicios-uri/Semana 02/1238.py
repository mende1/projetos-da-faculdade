# -*- coding: utf-8 -*-

n = int(input())

# 2
# Tpo oCder     TopCoder
# aa bb         abab

for i in range(n):
    a, b = input().split()
    ans = ""

    minimo = min(len(a), len(b))
    for j in range(minimo):
        ans += a[j]
        ans += b[j]

    for j in range(minimo, len(a)):
        ans += a[j]

    for j in range(minimo, len(b)):
        ans += b[j]

    print(ans)