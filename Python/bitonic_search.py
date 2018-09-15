#@author Jake Runyan
#@desc Prompt from https://github.com/charulagrl/data-structures-and-algorithms

#Prompt: Program to search a element in bitonic array

#Plan: search for LARGEST VALUE IN RANGE, inclusive, so can use indices to break up ranges.

#implements fast binary search in O(log n), but slightly faster than pure binary search
def bitonic_search(arr, low, high): #(0-indexed)
    if arr is None: #no arr
        return -1 
    elif low == high: #size 1 arr
        return arr[low]
    else: #size >=2 arr
        midpt = int((high+low) / 2)
        if arr[midpt] < arr[midpt+1]: #on LHS of midpt, search right side
            return bitonic_search(arr, midpt+1, high)
        elif arr[midpt] < arr[midpt-1]: #on RHS of midpt, search left side
            return bitonic_search(arr, low, midpt-1)
        else: #at local max, aka overall max
            return arr[midpt]

# #main
if __name__ == "__main__":
    arr = [-3, 2, 4, 5, 6, 9, 10, 45, 99, 34, 23, 12, 11, 5, 3, 2, 1, -99]
    print(bitonic_search(arr, 0, len(arr)-1))
    arr = [1,2,3,4,5,6,7,8,9]
    print(bitonic_search(arr, 0, len(arr)-1))
    arr = [1,2,3,4,5,4,3,2,3,6,9] #mistakenly searches if non-monotonic, in which case either has precondition or would benefit from straight up binary search.
    print(bitonic_search(arr, 0, len(arr)-1))
    