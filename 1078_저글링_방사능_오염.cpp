//
//  1078_저글링_방사능_오염.cpp
//  codeup
//
//  Created by Yongduek Seo on 4/7/18.
//  Copyright © 2018 com.yndk. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <iostream>
#include <sstream>
using namespace std;

int board[100][100];
int W, H;

const int dx[] = { 0,  0,  +1,  -1 };
const int dy[] = { +1, -1,  0,  0 };

void pr(int ktime) {
    printf ("--- ktime: %d ---\n", ktime);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++)
            printf ("%3d", board[i][j]);
        printf ("\n");
    }
}

struct p2 {
    int x, y;
};

bool inside (p2 xy) {
    return xy.x >= 0 && xy.x < W && xy.y >= 0 && xy.y < H;
}
void kill_j(int& ktime, int& krest, int x, int y)
{
    ktime = 2;
    
    queue<p2> q;
    q.push (p2{x,y});
    
    while (!q.empty()) {
        ktime++;

        auto nq = q.size();
        
        for (auto n = 0; n < nq; n++) {
            p2 xy = q.front(); q.pop();
            if (board[xy.y][xy.x] == 1) {
                board[xy.y][xy.x] = ktime;
                // check its neighbor
                for (int i = 0; i < 4; i++)
                    if (inside(p2{xy.x+dx[i], xy.y+dy[i]})) {
                        q.push (p2{xy.x+dx[i], xy.y+dy[i]});
                    }
            }
            else //if (board[xy.y][xy.x] == 0 || board[xy.y][xy.x] == -1)
                continue;
        }
        //pr(ktime);
    }
    
    ktime--; // it is one more than the time.
    
    krest = 0;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if (board[i][j] == 1) // not killed
                krest ++;
    
    return;
}
int main()
{
    string str;
    getline (cin, str);
    istringstream isstrm (str);
    isstrm >> W >> H;
    //cin >> W >> H;
    for (int i = 0; i < H; i++) {
        getline (cin, str);
        for (int j = 0; j < W; j++)
            board[i][j] = str[j] - '0';
    }
    int x, y;
    getline (cin, str);
    isstrm.str (str);
    isstrm >> x >> y;
    
    int period, left;
    kill_j (period, left, x-1, y-1); // 1-based  :=>  0-based
    cout << period << endl << left << endl;
    
    return 0;
}
