#@author Jake Runyan
#@desc Prompt from https://github.com/charulagrl/data-structures-and-algorithms

#Prompt: Program to find the number of duplicate elements in an array

#Plan: store in hash, add up to return a total number and that's it

#uses hash(dict) to insert and query at O(1), for overall runtime of O(n).
def num_dupes(arr):
    cts = {} #fast dict
    for a in arr:
        if a in cts:
            cts[a] = cts[a] + 1
        else:
            cts[a] = 1
    ans = 0
    for a in cts:
        if(cts[a] > 1):
            ans = ans + cts[a]
    return ans 

#main
if __name__ == "__main__":
    arr = [1,4,7,3,7,9,5,3,6,7,3,6,8,4,2,1,4,6,8,9,4,3,2]
    print(num_dupes(arr))
    arr = [1,2,3,4,4,5,6,6,7,8,9]
    print(num_dupes(arr))
    arr = "hello world" #strs are equivalent to arrays in python
    print(num_dupes(arr))
