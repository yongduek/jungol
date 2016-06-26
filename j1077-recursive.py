
#  j1077-recursive.py
#
#  Created by Yongduek Seo on 2016. 4. 25..
#  Copyright Yongduek Seo. All rights reserved.
#  yndk@sogang.ac.kr

import sys

class jewelry:
    def __init__(self, w, v):
        self.weight=w
        self.value=v
    #end def
#end class definition

N,W = map(int, sys.stdin.readline().split())
packTable = [-1 for i in range (W+1)]

#print (N)
#print (W)
#print (packTable)

jewList = []

for i in range(N) :
    w,v = map(int, sys.stdin.readline().split())
    jewList.append(jewelry(w,v))

#for i in range(N) :
#    print (jewList[i].weight, jewList[i].value)

def pack(w) :
    maxval = 0
    if packTable[w] < 0 :
        for j in jewList :
            weight_diff = w - j.weight
            if weight_diff >= 0 :
                total_val = j.value + pack(weight_diff)
                if maxval < total_val :
                    maxval = total_val
                #endif
            #endif
        #end-for
        packTable[w] = maxval;
    #endif
    return packTable[w]
# end def pack(w)

maxval = pack(W)
print (maxval)

# eof #
