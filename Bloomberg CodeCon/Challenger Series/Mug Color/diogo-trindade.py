from __future__ import print_function
import sys

data = sys.stdin.read().splitlines()

N = int(data[0]) 
colors = ["White", "Black", "Blue", "Red", "Yellow"]

for i in range(1,N+1):
    try:
        colors.remove(data[i])
    except ValueError:
        pass  # do nothing!
    

print(colors[0])
