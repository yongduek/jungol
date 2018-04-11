//
//  1462_보물섬.cpp
//  codeup
//
//  Created by Yongduek Seo on 4/11/18.
//  Copyright © 2018 com.yndk. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <iostream>
#include <sstream>
using namespace std;
int rows, cols;
char board[51][51];
short bfs[51][51];
short visited[51][51];

struct rc { int r, c; };

int neighbor = 4;
const int dr[] = { 0,  0,  +1,  -1 };
const int dc[] = { +1, -1,  0,  0 };


void pr(int val, short b[51][51])
{
    cout << " -- " << val << " -- " << endl;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++)
            printf (" %d ", b[r][c]);
        printf("\n");
    }
}
bool inside (rc p) {
    return p.r >= 0 && p.r < rows && p.c >= 0 && p.c < cols;
}

int find_longest (int r, int c)
{
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            visited[r][c] = 0;
    
    queue<rc> q;
    int dist = 0;
    q.push (rc{r, c}); // starting
    while (!q.empty()) {
        dist ++;
        int nq = q.size();
        for (int nn = 0; nn < nq; nn++) {
            rc p = q.front(); q.pop();
            visited[p.r][p.c] = dist;
            for (int n = 0; n < neighbor; n++) {
                rc nei{p.r + dr[n], p.c + dc[n]};
                if (inside(nei) && board[nei.r][nei.c]=='L' && visited[nei.r][nei.c] == 0) {
                    visited[nei.r][nei.c] = dist;
                    q.push (nei);
                }
            }
        }
    }
//    pr (dist, visited);
    return dist - 1;
}

int solve ()
{
    int longest = 0;
    int dist;
    
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            if (board[r][c] == 'L')
                if (longest < (dist = find_longest (r,c))) {
                    longest = dist;
                    // copy for examination
                    for (int rr=0; rr<rows; rr++)
                        for (int cc=0; cc<cols; cc++)
                            bfs[rr][cc] = visited[rr][cc];
                }

    return longest;
}

int main()
{
    string str;
    getline (cin, str);
    istringstream isstrm (str);
    isstrm >> rows >> cols;
    for (int i = 0; i < rows; i++) {
        getline (cin, str);
        for (int j = 0; j < cols; j++)
            board[i][j] = str[j];
    }

    cout << solve () ;
//    pr (-1, bfs);
    return 0;
}
