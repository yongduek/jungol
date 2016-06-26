//
//  2097.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 2. 5..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <set>

using namespace std;

int m[102][102];
int N, M;

void print (const vector<int>& q) {
    for (int i=0; i<q.size(); i++)
        printf ("%d ", q[i]);
    printf("\n");
}

int minCost = 10000000;
vector<int> minPath;

void go (int s, int c, vector<int> path, vector<bool> visited, int cost)
{
    path.push_back(c);
    visited[c]=true;
    cost += m[s][c];

    if (cost > minCost) { // don't have to go more
        return;
    }
    
    if (c==M) { // final destination
//        printf("cost= %d\n", cost);
//        print (path);
//        printf("---\n");
        if (cost < minCost) {
//            printf("== min ==\n");
            minCost = cost;
            minPath = path;
//            printf("mincost= %d\n", cost);
//            print (minPath);
//            printf("=========\n");
        }
        
        return; //
    }
    
    for (int i=0; i<N; i++)
        if (m[c][i] && !visited[i]) {
            go (c, i, path, visited, cost);
        }
}

int main()
{
    cin >> N >> M;
    --M; // 0-based
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            cin >> m[i][j];
    }
    
    // start 1 -> end M
    for (int i=0; i<N; i++)
        if (m[0][i]) {
            vector<int> path;
            vector<bool> visited(N, false);
            path.push_back(0);
            int cost = 0;
            visited[0] = true;
            go (0, i, path, visited, cost);
//            print (path);
        }
    
    printf ("%d\n", minCost);
    for (int i=0; i<minPath.size(); i++)
        printf ("%d ", minPath[i]+1);
    printf("\n");
    
    return N;
}