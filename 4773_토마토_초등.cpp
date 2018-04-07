//
//  4773_토마토_초등.cpp
//  codeup
//
//  Created by Yongduek Seo on 4/5/18.
//  Copyright © 2018 com.yndk. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct triple {
    int i, j, k;
};

int box[100][100][100];
int M, N, H;

bool v[100][100][100];

void print (int d) {
    printf ("-- days = %d\n", d);
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++)
                printf ("%3d", box[k][i][j]);
            printf ("\n");
        }
        printf (" - \n");
    }
}
bool is_visited (triple t)
{
    return v[t.k][t.i][t.j] == true;
}

void set_visited (triple t) { v[t.k][t.i][t.j] = true; }

bool outside (triple t) {
    return t.i < 0 || t.i >= N || t.j < 0 || t.k < 0 || t.j >= M || t.k >= H;
}

int check()
{
    queue<triple> q;
    for (int k = 0; k < H; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (box[k][i][j] == 1) {
                    q.push (triple{i,j,k});
                    box[k][i][j] = 0; // reset to 0 for easy iteration
                }
    
    
    int days = -1;
    
    while (!q.empty()) {
        days ++;
        
//        print (days);
        
        auto nq = q.size(); // the # of nodes at the current layer
        int added = 0;
        for (auto n = 0; n < nq; n++) {
            triple sn = q.front(); q.pop(); // for each source node
            if (outside(sn) == true) continue;

            int bbl = box[sn.k][sn.i][sn.j];
            
            if (bbl == -1) continue;
            
            if (is_visited(sn) == false && bbl == 0)
                {
                set_visited(sn);
                box[sn.k][sn.i][sn.j] = 1; // ripen
                // now put neighbours into Q
                q.push (triple{sn.i+1,sn.j,sn.k}); q.push (triple{sn.i-1,sn.j,sn.k});
                q.push (triple{sn.i,sn.j+1,sn.k}); q.push (triple{sn.i,sn.j-1,sn.k});
                q.push (triple{sn.i,sn.j,sn.k+1}); q.push (triple{sn.i,sn.j,sn.k-1});
                added += 6;
                }
        }
    }
    
    --days; // this is necessary
    
    for (int k = 0; k < H; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (box[k][i][j] == 0) // some tomato is not touched and will not be.
                    { days = -1; goto DONE;}
DONE:
    return days;
}

int main()
{
    std::cin >> M >> N >> H;
    for (int k = 0; k < H; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                scanf ("%d", &box[k][i][j]);
//                std::cin >> box[k][i][j];
    
    std:: cout << check ();
    
    return 0;
}
