"""
ID: deadly51
TASK: frac1
LANG: PYTHON3
"""

from fractions import Fraction
with open("frac1.in", "r") as file:
    n = int(file.readline())


collection = set()

for i in range(n, 1 , -1):
    for j in range(1, i):
        collection.add(Fraction(j, i))


with open("frac1.out", "w") as file:
    file.write("0/1\n")
    for i in sorted(collection):
        file.write(f"{i}\n")
    file.write("1/1\n")



