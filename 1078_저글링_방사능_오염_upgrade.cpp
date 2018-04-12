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

bool inside (int x, int y) {
    return x >= 0 && x < W && y >= 0 && y < H;
}
void kill_j(int& ktime, int& krest, int x0, int y0)
{
    queue<p2> q;
    q.push (p2{x0,y0});
    board[y0][x0] = ktime = 3;
    
    while (!q.empty()) {
        auto nq = q.size(); // get the size of current queue
        for (auto n = 0; n < nq; n++) { // for each of them
            p2 xy = q.front(); q.pop();
                // check its neighbor
            for (int i = 0; i < 4; i++) {
                int xx = xy.x + dx[i];
                int yy = xy.y + dy[i];
                if (inside(xx, yy) && board[yy][xx]==1/*저글링*/) {
                    q.push (p2{xx, yy});
                    board[yy][xx] = ktime = board[xy.y][xy.x] + 1; // ktime update
                }
            }
        }
        // pr(ktime); // see the status of the board
    }
    
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
