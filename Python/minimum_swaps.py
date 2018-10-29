#@author Jake Runyan
#@desc Prompt from https://www.hackerrank.com/challenges/minimum-swaps-2/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays

import sys

#verify we have an array containing arrangement of 1-(n-1)
def verify_array(arr):
    ctr = {}
    for a in arr:
        if not a in ctr:
            ctr[a] = 1
        else:
            return False
    # (this is not held on the hackerrank test cases)
    # for a in range(1,len(arr)):
    #     if a not in arr:
    #         return False
    return True

#main function to recursively determine how many swaps to be made
def dynamic_swaps(arr):
    num_swaps = 0
    sorted_arr = sorted(arr)
    swap_indices = {}
    for idx, val in enumerate(arr):
        swap_indices[val] = idx
    for a in range(0, len(arr)):
        if arr[a] != sorted_arr[a]:
            target_idx = swap_indices[sorted_arr[a]]
            swap_indices[arr[a]] = target_idx
            tmp = arr[target_idx]
            arr[target_idx] = arr[a]
            arr[a] = tmp
            num_swaps = num_swaps + 1
            print(arr)
    return num_swaps

#main
if __name__ == "__main__":
    arr = [1,3,5,2,4,6,8]
    if not verify_array(arr):
        print("Array {} contained one or more duplicates or doesnt contain exactly 1-(n-1).\n".format(arr))
    
    print("Min swaps: {}".format(dynamic_swaps(arr)))
