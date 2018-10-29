#@author Jake Runyan
#@desc Concurrency practice in Python

import sys
import os

#tokenizes a file by whitespace using threadpool_size threads.
def regurgitator(filename, threadpool_size=10):
    try:
        file = open(filename)
    except(IOError):
        sys.stderr.write("File does not exist.\n")
        sys.exit(1)
    #todo
    

#main
if __name__ == "__main__":
    regurgitator("blah.txt")
    pass
