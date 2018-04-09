'''
   python3
'''
import sys
import numpy as np
import queue

dbug = False
dbug = True
cols, rows = map(int, sys.stdin.readline().split());
if dbug: print('cols=', cols, type(cols), 'rows=', rows, type(rows));

board = np.zeros((rows,cols), dtype=int);

for i in range(rows):
    ins = sys.stdin.readline()
    for j in range(cols):
        board[i][j] = int(ins[j]);

if dbug:
    print (board)

c0, r0 = map(int, sys.stdin.readline().split())
c0 -= 1 # 0-based indexing
r0 -= 1
if dbug: print ('staring loc(r,c) = {}, {}'.format(r0, c0))

q = queue.Queue() # create a queue
'''
    q.put(1)
    q.put(2)
    print (q.qsize())
    print (q.get())
    print (q.qsize())
'''

dr = [-1, +1, 0, 0]
dc = [0,  0, -1, +1]

def inside( r, c ):
    if r >= 0 and c >= 0 and r < rows and c < cols: return True
    else: return False
#

q.put ( (r0, c0) )
ktime = 2;
while q.qsize() > 0:
    ktime += 1

    nq = q.qsize()
    for n in range (nq):
        rc = q.get()
        if dbug:  print ('rc = ', rc, rc[0], rc[1])
        r = rc[0]
        c = rc[1]
        if board[r][c] == 1:
            board[r][c] = ktime
            for i in range(4):
                if inside(r+dr[i], c+dc[i]) is True:
                    q.put( (r+dr[i], c+dc[i]) )
        else:
            continue
    #
#
ktime -= 1
if dbug: print ('ktime = ', ktime)

'''
if dbug: # print the board
    for r in range(rows):
        for c in range(cols):
            print ('{:3d}'.format(board[r][c]), end='')
        print ('\n')
    #
    print ('type(board[0][0]=', type(board[0][0]), '  type(1)=', type(1))
#
'''

krest = 0
for r in range(rows):
    for c in range(cols):
        if np.equal(board[r][c], 1): krest += 1
#
if dbug: print ('krest = ', krest)

# output
# print ('{}\n{}'.format(ktime, krest))
print (ktime)
print (krest)