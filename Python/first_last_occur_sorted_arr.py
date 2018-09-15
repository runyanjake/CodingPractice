#@author Jake Runyan
#@desc Prompt from https://github.com/charulagrl/data-structures-and-algorithms

#Prompt: Program to find the first and last occurence of an element in an array

#Plan: Easily grab first occurrence and save position of every following val until done in O(n).

def firstandlast(arr, item):
    if arr is None: #no arr
        return (-1,-1)
    else:
        first = -1
        last = -1
        for a in range(len(arr)): #itor to first
            print(a)
            if arr[a] == item:
                first = a
                break
        if first == -1: #searched and not found
            return (-1,-1)
        # for a in range(len(arr)-1, -1, -1):
        for a in reversed(range(len(arr))):
            print(a)
            if arr[a] == item:
                last = a
                break
        return (first,last)



arr = [1,2,3,4,5,6,7,8,9,3]
first, last = firstandlast(arr, 1)
print("First: " + str(first) + "  Last: " + str(last))
first, last = firstandlast(arr, 3)
print("First: " + str(first) + "  Last: " + str(last))
first, last = firstandlast(arr, 39)
print("First: " + str(first) + "  Last: " + str(last))
