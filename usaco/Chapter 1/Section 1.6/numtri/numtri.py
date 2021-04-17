"""
ID: deadly51
TASK: numtri
LANG: PYTHON3
"""
with open("numtri.in", "r") as file:
    n = int(file.readline())
    map = [[int(x) for x in file.readline().split()] for _i in range(n)]

# просто рекурсия с кешом

def wrapper():
    cache = set([])




with open("numtri.out", "w") as file:
    file.write(f"{sum}\n")



