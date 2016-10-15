from __future__ import print_function
import sys

data = sys.stdin.read().splitlines()

for line in data :
    string = ""
    i = 1
    while(len(string) < int(line)):
        found= False
        j = 1
        while(not found):
            if(str(4*j)[0:len(str(i))] == str(i)):
                string += str(4*j)
                found = True
            j+=1
        i+=1
    print(string[int(line) - 1])
