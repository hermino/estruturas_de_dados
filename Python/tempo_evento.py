import re
from datetime import datetime

di = int(re.sub("[^\d+]", "", input()))
hi = [int(i) for i in input().split(" : ")]

df = int(re.sub("[^\d+]", "", input()))
hf = [int(i) for i in input().split(" : ")]

data_inicial = datetime.strptime("{}-3-2020 {}:{}:{}".format(di, hi[0],
                                                            hi[1], hi[2]),
                                                            '%d-%m-%Y %H:%M:%S')

data_final = datetime.strptime("{}-3-2020 {}:{}:{}".format(df, hf[0],
                                                            hf[1], hf[2]),
                                                            '%d-%m-%Y %H:%M:%S')

i = data_final - data_inicial

print("{} dia(s)".format(i.day))
print("{} hora(s)".format(i.hours))
print("{} minuto(s)".format(i.minute))
print("{} segundo(s)".format(i.second))