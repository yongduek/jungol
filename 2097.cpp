//
//  2097.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 2. 5..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//
/**
 2097 : 지하철
 제한시간: 1Sec    메모리제한: 64mb
 해결횟수: 507회    시도횟수: 1668회    Special Judge
 
 
 지방에서 서울에 관광온 성수는 지하철 노선을 보고 깜짝 놀랐다. 노선이 엄청나게 복잡하기 때문이었다. 각 노선들이 서로 얽혀있어서 잘못하면 10분도 안걸리는 거리를 1시간 동안 갈 수도 있는 상황이었다.  어쩔 수 없이 성수는 현재 숙소에서 관광할 목적지까지 가장 짧은 시간에 도착할 수 있는 경로와 시간을 표로 만들려고 한다.
 
 단, 각 지하철역에서 관광지가 있고, 지하철을 갈아타는데 소요되는 시간은 없다고 가정한다.
 
 첫줄에 N(3≤N≤100), M(1≤M≤N)을 입력 받는다. N은 지하철역의 수, M은 원하는 목적역의 번호를 입력받는다.
 
 둘째 줄부터 N개의 줄이 나오고, 각 줄에는 N개의 수 S가 입력된다.
 
 i번째 줄에서 j번째 수 Sij는 i번역에서 j번 역까지 가는데 걸리는 시간이다. 1번 역이 숙소가 있는 역이고, Sij에서 i = j 일 때는 항상 0 이다. (0≤S≤100)
 
 
 목적 역까지 가는데 걸리는 최소 시간과 최소시간으로 가는 최단경로를 출력한다.
 
 [Copy]
 5 5
 0 2 2 5 9
 2 0 3 4 8
 2 3 0 7 6
 5 4 7 0 5
 9 5 6 5 0
 [Copy]
 8
 1 3 5
 **/
#include <stdio.h>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <set>
#include <limits>

typedef std::pair<int,int> ii;

using namespace std;




int w[102][102];
int N, M;
int d[102];
int p[102];

int main()
{
    cin >> N >> M;
    --M; // 0-based
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            cin >> w[i][j]; // weight matrix
    }
    
    // initialize single source
    for (int i=0; i<N; i++) {
        d[i] = 1<<30; // infinity
        p[i] = -1; // previous node
    }
    d[0] = 0; // source node

    for (int i=N-1; i>=0; --i) // simple iteration
    {
        for (int u=0; u<N; ++u)
            for (int v=0; v<N; ++v)
            { // relax
                if (w[u][v]!=0) // node is connected
                { // Relaxe
                    if (d[v] > d[u] + w[u][v]) {
                        d[v] = d[u] + w[u][v];
                        p[v] = u;
                    }
                }
            }
    }
    
    printf("%d\n", d[M]);
    stack<int> path;
    for (int k=M; k!=-1; k=p[k])
    {
        path.push(k+1);
        //        printf ("%d ", k+1);
    }
    while (!path.empty()) {
        printf("%d ", path.top());
        path.pop();
    }
    printf("\n");

    return 0;
}

/***
 Dijkstra algorithm with priority-queue
 ***/

/****
int main()
{
    cin >> N >> M;
    --M; // 0-based
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            cin >> w[i][j]; // weight matrix
    }

    // initialize single source
    for (int i=0; i<N; i++) {
        d[i] = 1<<30; // infinity
        p[i] = -1; // previous node
    }
    d[0] = 0; // source node

    std::priority_queue<std::pair<int,int> > q;
    q.push(ii(d[0], 0));
    
    while (!q.empty()) {
        ii t = q.top(); q.pop();
        int u = t.second;
        int dist = t.first; // == d[u]

        if (d[u] < dist) { // could happen for the nodes stored deep down in the q
//            printf("d[%d]=%d < %d\n", d[u], u, dist);
            continue;
        }
        for (int v=0; v<N; v++) // for each node connected to u
        {
            if (w[u][v]!=0) // node is connected
            { // Relaxe
                if (d[v] > d[u] + w[u][v]) {
                    d[v] = d[u] + w[u][v];
                    p[v] = u;
                    
                    q.push(ii(d[v], v));
                }
            }
        }
    }
    
    printf("%d\n", d[M]);
    stack<int> path;
    for (int k=M; k!=-1; k=p[k])
    {
        path.push(k+1);
//        printf ("%d ", k+1);
    }
    while (!path.empty()) {
        printf("%d ", path.top());
        path.pop();
    }
    printf("\n");
    
    return 0;
}
****/

/***
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
***/