# -*- coding: utf-8 -*-

n = int(input())

for i in range(1, n+1):
    divisao = n/i
    if(str(divisao)[-1] == '0'):
        print("{}".format(i))
