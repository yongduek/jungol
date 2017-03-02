//
//  1111.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 2. 11..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <bitset>

using namespace std;

typedef unsigned long       ul;
typedef unsigned long long ull;

typedef std::pair<int,int>  ii;
typedef std::pair<int,ii>  iii;
typedef std::vector<int>    vi;
typedef std::vector<ii>    vii;
typedef std::vector<iii>  viii;
typedef vector<std::vector<int> >   vvi;

const int BIGNUM = 1<<29;
const int nei[4][2] = {
    {-1,0}, {1,0}, {0,1}, {0,-1}
};
int W[104][104];
int N;
int cost[100][100];
bool visited[104][104];
int d[104][104];
int pr[104][104], pc[104][104];
int c0, r0;
int K;

#define SQR(a) ((a)*(a))

int getWeight (ii u, const int n[2])
{
    int hsrc = W[u.first][u.second];
    int hdst = W[u.first+n[0]][u.second+n[1]];
    
    if (cost[hsrc][hdst]<0)
        {
        int w=0;
        if (hsrc==hdst)
            w=0;
        else if (hdst < hsrc) // since we are going down
            w = SQR(hsrc-hdst);
        else
            w = hdst-hsrc;
    
        cost[hsrc][hdst]=w;
        }
    
    return cost[hsrc][hdst];
}

int main()
{
    cin >> N;
    cin >> r0 >> c0;
    for (int r=1; r<=N; r++)
        for (int c=1; c<=N; c++)
            cin >> W[r][c];
    K=N+2;
    for (int i=0; i<K; i++)
        for (int j=0;j<K; j++)
            d[i][j]= BIGNUM; // big number
    
    d[r0][c0]=0; // source node
    
    for (int i=0; i<100; i++)
        std::fill (cost[i], cost[i]+100, -1);
    
    priority_queue<iii> q;
    q.push (iii(d[r0][c0], ii(r0,c0)));
    
    bool done=false;
    ii final;
    while (!q.empty())
        {
        iii top = q.top(); q.pop();
        ii u=top.second;
        int dist = top.first;
        
        if (d[u.first][u.second] < dist) continue;
        
        for (int i=0; i<4; i++)
            {
            if (u.first+nei[i][0] < 0
                || u.first+nei[i][0] >= K
                || u.second+nei[i][1] < 0
                || u.second+nei[i][1] >= K)
                continue;

            int weight = getWeight(u, nei[i]);
            int &dv = d[u.first+nei[i][0]][u.second+nei[i][1]];
            if ( dv > d[u.first][u.second] + weight)
                {
                dv = d[u.first][u.second] + weight;
                q.push (iii(dv, ii(u.first+nei[i][0], u.second+nei[i][1])));
                
                pr[u.first+nei[i][0]][u.second+nei[i][1]] = u.first;
                pc[u.first+nei[i][0]][u.second+nei[i][1]] = u.second;
                
//                final.first = u.first+nei[i][0];
//                final.second = u.second+nei[i][1];
//                if ( final.first == 0 || final.second ==0)
//                    {
//                    done=true;
//                    break;
//                    }

                }
            }
//        if (done)
//            break;
        }

//    for (int r=0; r<K; r++) {
//        for (int c=0; c<K; c++)
//            printf ("%3d ", W[r][c]);
//        printf("\n");
//    }
//    printf("----\n");
//    for (int r=0; r<K; r++) {
//        for (int c=0; c<K; c++)
//            printf ("(%2d,%2d) ", pr[r][c], pc[r][c]);
//        printf("\n");
//    }
//    for (int r=0; r<K; r++) {
//        for (int c=0; c<K; c++)
//            printf ("%3d ", d[r][c]);
//        printf("\n");
//    }
    // the minimum power used for climbing up the mountain
    // the same through the boundary because of the Dijkstra algorithm update.
    printf("%d\n", d[0][0]);
    return 0;
}

/*
 5
 2 5
 39 41 31 37 36
 5 1 9 32 41
 36 3 24 7 14
 4 18 10 17 30
 30 31 45 26 23
 0   0   0   0   0   0   0
 0  39  41  31  37  36   0
 0   5   1   9  32  41   0
 0  36   3  24   7  14   0
 0   4  18  10  17  30   0
 0  30  31  45  26  23   0
 0   0   0   0   0   0   0
 ----
 ( 1, 0) ( 0, 2) ( 0, 3) ( 0, 4) ( 0, 5) ( 0, 6) ( 1, 6)
 ( 2, 0) ( 1, 2) ( 1, 3) ( 1, 4) ( 1, 5) ( 2, 5) ( 2, 6)
 ( 2, 1) ( 2, 2) ( 2, 3) ( 1, 3) ( 1, 4) ( 0, 0) ( 3, 6)
 ( 2, 0) ( 2, 1) ( 2, 2) ( 2, 3) ( 2, 4) ( 3, 6) ( 4, 6)
 ( 3, 0) ( 4, 0) ( 3, 2) ( 4, 2) ( 3, 4) ( 5, 5) ( 5, 6)
 ( 4, 0) ( 5, 2) ( 4, 2) ( 5, 2) ( 6, 4) ( 6, 5) ( 6, 6)
 ( 5, 0) ( 6, 0) ( 6, 1) ( 6, 2) ( 6, 3) ( 6, 4) ( 6, 5)
 639 639 639 639 639 639 639
 639  76  72  62  26  25 639
 639 614 610 546  51   0 639
 639 645 612 561 676 653 639
 639 643 627 691 686 669 639
 639 641 640 654 665 662 639
 639 639 639 639 639 639 639
 639
*/