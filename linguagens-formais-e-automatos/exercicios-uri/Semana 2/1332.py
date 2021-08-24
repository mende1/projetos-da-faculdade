# -*- coding: utf-8 -*-

n = int(input())

# 3
# owe       1
# too       2
# theee     3

for i in range(n):
    a = input()

    if len(a) == 5:
        print(3)
    
    else:
        count1 = 0
        count2 = 0

        one = "one"
        two = "two"

        for j in range(3):
            if a[j] == one[j]:
                count1 += 1
            if a[j] == two[j]:
                count2 += 1

        if count1 > count2:
            print(1)
        else:
            print(2)
