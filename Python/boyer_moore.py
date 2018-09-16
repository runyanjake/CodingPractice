#@author Jake Runyan
#@desc Prompt from https://github.com/charulagrl/data-structures-and-algorithms

#Prompt: Find out the majority element in the array using Moore's algorithm
#A majority element in an array A[] of size n is an element that appears more than n/2 times (and hence there is at most one such element).

#Plan: 
#   hold index 
#   match first instance of last item in key past the index
#       check for solution
#       solution fails:
#   try all key instances of last item in key K(n,a,a,a,a,a,n), A(a,n,a,n,a,n,n,a,a,n,n,a) match a 3, then try 2 remaining 3 positions before moving on
#   update index    

#start at keylength
#move right by MAX OF:
#       ind(mismatch) - ind(prev_occurence_arr_value) (bad character value)
#       difference between index of matching from R to L, and a previous instance earlier in the key (good suffix rule)
#can serialize into table
# a,b,r,b,c,b,a,c,b,d,a,b,c,d,f,f,f,f,d,a
# a,b,c,d
# xxxxa,b,c,d
# xxxxxxxxa,b,c,d
# xxxxxxxxxxa,b,c,d
# xxxxxxxxxxxxxxa,b,c,d
# xxxxxxxxxxxxxxxxxxxxa,b,c,d  < MATCH, move until last 
# xxxxxxxxxxxxxxxxxxxxxxxxxxxxa,b,c,d

#strs only
def boyer_moore(arr, key):
    #make bad value table
    bad_table = {}
    bad_table['*'] = len(key)
    for i in range(len(key)):
        if i == len(key)-1:
            bad_table[key[i]] = len(key)
        else:
            if not(key[i] in bad_table): #insert into blank dict
                bad_table[key[i]] = len(key) - i - 1
            else: #overwriting
                val = len(key) - i - 1
                if val < bad_table[key[i]]:
                    bad_table[key[i]] = val
    # print(bad_table)
    #parse arr
    itor = len(key)
    last_in_key = key[len(key)-1]
    while(itor < len(arr)):
        # print("Itor: " + str(itor))
        success = True
        for a in reversed(range(len(key))):
            # print("Cmp " + str(key[a]) + " to " + str(arr[itor-(len(key)-a)]))
            if not(key[a] == arr[itor-(len(key)-a)]):
                success = False
                break
        if success:
            # print("Found success")
            return True
        if arr[itor-(len(key)-a)] in bad_table:
            itor = itor + bad_table[arr[itor-(len(key)-a)]]
            # print("Increment itor by " + str(bad_table[arr[itor-(len(key)-a)]]))
        else: 
            itor = itor + bad_table['*']
            # print("Increment itor by " + str(bad_table['*']))
    return False
        
    

if __name__ == "__main__":
    arr = "tobeemaymaytoothcats"
    key = "tooth"
    print(boyer_moore(arr,key))

    arr = "helloworldthisisjake"
    key = "ekaj"
    print(boyer_moore(arr,key))

    arr = ";alskgj;lkjg;elgkjae;lakjb;aldfkjb;aslgkjag;lekwjg;aelrkj;zflbkjadf;lbkjar;hlakjerg;elrkajb;dflbkjad;lkjn;lsgkjad;blkjadsg;lkbjb;alkdjb;lsadkbja;lsdkgj;elkjew;glhkajerg;leqkjg;alkefja;dflkjare;lhkjerglekjerlgkj;alksj;alskbj;adlkbj;adslbkjasd;blkajsb;laskdjb;sldkbjas;ldkbjads;lkgj;alskdbjadkl;bjadlkbjadskbjadlskbjkbdieielajsdhflkjahlakjbhalskdjbhalsdkbjhasdlbkjhasdlbkajdshblkjhalkbjhadlskbjhadlkbjhsdlkajdshblkajhdslkbjhavlkdjshvlkjbhldsakbjhalksdjvhadlskvjahlskdjhalsdjkbhadsjkh"
    key = "ieie"
    print(boyer_moore(arr,key))