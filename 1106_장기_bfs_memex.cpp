//
//  1106_장기_bfs.cpp
//  codeup
//
//  Created by Yongduek Seo on 4/11/18.
//  Copyright © 2018 com.yndk. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

struct rc {
    int r, c;
};

int r0, c0, r1, c1;
int rows, cols;
int map[110][110];

#ifdef ROUTE
rc  malprev[110][110];

void pr (int n) {
    cout << "--- " << n << "  ---" << endl;
    for (int i = 0; i < rows; i++) {
        printf ("%d : ", i);
        for (int c= 0; c < cols; c++) {
            if (i == 0)
                printf ("   %d    ", c);
            else
                printf (" (%d,%d)%c ", malprev[i][c].r, malprev[i][c].c, i==r0 && c==c0 ? '!' : (i==r1 && c==c1 ? '*' : ' '));
        }
        printf ("\n");
    }
    
    deque<rc> route;
    rc p = rc{r1, c1};
    route.push_front (p);
    while (p.r != r0 || p.c != c0) {
        p = malprev[p.r][p.c];
        route.push_front(p);
    }
    printf (" route: !(%d, %d) ", route[0].r, route[0].c);
    for (auto i = 1; i < route.size(); i++)
        printf (" -> (%d, %d) ", route[i].r, route[i].c);
    printf ("\n");
}
#endif

bool inside (int r, int c)
{
    return r >= 1 && r <= rows && c >= 1 && c <= cols;
}

int njump = 8;
int dr[] = {1, 2,  2,  1, -1, -2, -2, -1};
int dc[] = {2, 1, -1, -2, -2, -1,  1,  2};

int solve (int r, int c)
{
    queue<rc> q;
    q.push (rc{r, c});
    
    int maljump = 3;
    bool found = false;
    while (!q.empty() ) {
        maljump ++;
        size_t nq = q.size();
        for (auto i = 0; i < nq; i++) {
            rc mal = q.front(); q.pop();
            
            if (mal.r == r1 && mal.c == c1) {
                map[mal.r][mal.c] = maljump; // set visited.
                found = true; break;
            }
            map[mal.r][mal.c] = maljump; // set visited.

            for (int k = 0; k < njump; k++) {
                int rr = mal.r+dr[k], cc = mal.c+dc[k];
                if (inside(rr, cc) && map[rr][cc] == 0) { // not visited inside the map
                    q.push(rc{rr,cc});
#ifdef ROUTE
                    malprev[rr][cc] = mal;
#endif
                    
                }
            } // for (k
        } // for (nq
        if (found) break;
    } // while
    
#ifdef ROUTE
    pr (maljump-4);
#
    return maljump - 4;
}


int main ()
{
    cin >> rows >> cols;
    cin >> r0 >> c0 >> r1 >> c1;
    
    cout << solve (r0, c0);
    return 0;
}
/*
 9 10 2 5 7 5
 3
 */
