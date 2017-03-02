//
//  j2578.cpp
//  cool-project
//
//  Created by Yongduek Seo on 2017. 1. 15..
//  Copyright © 2017년 Yongduek Seo. All rights reserved.
//
/*
 2578 : 버스 갈아타기
 제한시간: 1000 ms    메모리제한: 64 MB
 해결횟수: 264 회    시도횟수: 1822 회
 
 
 2차원 평면상에 m개의 수직선과 n개의 수평선으로 이루어진 격자 형태의 도로망이 있다. 아래 그림은 7개의 수직선과 6개의 수평선으로 이루어진 도로망의 예이다.
 
 7ce7f2eba5731c8babe39036322897a0_1449744
 
 수직선과 수평선이 만나는 교차점들 중 가장 왼쪽 아래 점의 위치는 (1,1)이고, 가장 오른쪽 위 점의 좌표는 (m,n)이다. 이 도로망을 운행하는 버스들이 k개 있고, 각 버스는 하나의 수평선 상의 두 교차점 사이 선분이나 하나의 수직선 상의 두 교차점 사이 선분을 왕복 운행한다. 각 버스는 운행하는 선분 사이의 모든 교차점(선분의 양 끝 교차점 포함)에서 정차한다.
 
 출발지 교차점과 목적지 교차점 (출발지와 목적지는 다름)이 주어질 때, 출발지에서 목적지로 버스만을 이용하여 가려고 한다. 이용하는 버스의 최소 수를 구하는 프로그램을 작성하시오.
 
 예를 들어,  8대의 버스가 다음과 같이 운행한다고 하자.
 1번 버스: (2, 1) - (2, 2)
 2번 버스: (1, 1) - (5, 1)
 3번 버스: (3, 2) - (6, 2)
 4번 버스: (5, 6) - (5, 1)
 5번 버스: (1, 5) - (7, 5)
 6번 버스: (7, 3) - (7, 6)
 7번 버스: (2, 1) - (2, 6)
 8번 버스: (3, 5) - (6, 5)
 
 출발지가 (2, 1)이고 목적지가 (7, 4)라 하자. 한 가지 방법으로, 처음에 2번 버스를 타고 교차점 (5, 1)에서 내려, 4번 버스를 타고 (5, 5)에서 내리고, 5번 버스를 탄 후 (7, 5)에서 내려, 마지막으로 6번 버스를 타서 목적지 (7, 4)에서 내린다. 그러면 이용하는 버스 수는 4이다. 다른 방법으로, 7번 버스를 타고 (2, 5)에서 내려, 5번 버스를 타고 (7, 5)에서 내린 후, 마지막으로 6번 버스를 타서 목적지 (7, 4)에서 내린다. 그러면 이용하는 버스 수는 3이고 이것이 최소이다.
 
 첫 번째 줄에 수직선의 수 m과 수평선의 수 n이 빈칸을 사이에 두고 주어진다(1 ≤ m,n ≤ 100,000).
 두 번째 줄에 버스의 수 (1≤k≤5,000)가 주어진다.
 세 번째 줄부터 k줄에 걸쳐 각 줄에 버스의 운행구간을 나타내는 5개의 수 b, x1, y1, x2, y2가 빈칸을 사이에 두고 주어진다.
 여기서 b(1≤b≤k)는 버스의 번호, (x1,y1)과 (x2,y2)는 이 버스가 운행하는 양쪽 끝 교차점의 좌표를 나타낸다.
 마지막 줄에 출발지와 목적지 좌표를 나타내는 네 개의 수 sx, sy, dx, dy가 빈칸을 사이에 두고 주어진다. 여기서 (sx,sy)는 출발지 좌표이고 (dx,dy)는 목적지 좌표이다. 1≤x1, x2, sx, dx≤m이고, 1≤y1, y2, sy, dy≤n이다.
 모든 입력에 대하여, 출발지와 목적지는 다르게 주어지며 출발지에서 목적지로 가는 방법은 한 가지 이상 존재한다.
 
 <제약조건>
 m 혹은 n이 1인 테스트데이터가 전체의 20%이다.
 
 
 첫째 줄에 이용하는 최소 버스 수를 출력한다.
 
 < 테스트데이터 조건 >
 • m 혹은 n이 1인 테스트데이터가 전체의 20%이다.
 */

/*
 이 문제의 해법에서 주요 요소는 다음과 같다.
 1. 전체 맵을 사용하지 않는 방법. 초중급의 BFS 알고리듬 학습할 때는 사각형 맵에 거리값 또는 방문횟수 등을 기록하면서 큐의 값을 업데이트한다. 이 문제에서는 버스노선을 중심으로 생각해야한다.
    이 문제에서 최대 맵의 크기는 100K x 100K 이기 때문에 맵을 업데이트하는 방식으로 처리하면 메모리 초과가 나오게 된다.
    * 버스 노선을 노드로 설정하여, 연결된 버스노선을 에지로 연결하는 그래프를 생각하면 문제가 쉽게 이해된다. 
    * 만약, 시작->끝 까지의 노선 순서를 알고 싶다면 그래프를 만든 후에, 끝점에서 시작하여 카운트값(또는 뎁스값)을 기준으로 연결된 노드들을 찾아가면 시작점으로 오게된다. 스텍에 쌓은 후 하나씩 꺼내면 노선순서를 얻게된다. 일반적인 그래프에 적용하는 방법이므로 설명은 생략한다.
 2. 두 직선 선분 (line segment)이 만나는지 확인하는 방법.
    어렵지는 않은데 좀 까다롭다. 각 경우를 따져서 만들면 쉽게 된다.
 */
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Bus {
    int r0, c0, r1, c1;
    bool rbus; // row bus if true
    int count;
    bool line(int rr, int cc) { // 이 점이 라인위에 있는지 확인하는 함수
        return r0<=rr && rr<=r1 && c0<=cc && cc<=c1;
    }
    bool cross(Bus& b) {
        // 두 개의 버스 노선이 중첩하는 경우가 생기는지 알아보는 함수
        // 그냥 쉽게 루프 돌려서 만들었더니 TLE 가 발생하더라.
        bool flag = false;
        if (this->rbus && b.rbus) { // 둘 다 행방향으로 같은 방향인 경우
            flag = r0==b.r0 && ( (b.c0<=c0 && c0<=b.c1) || (b.c0<=c1 && c1<=b.c1) );
        } else if (this->rbus==false && b.rbus==false) {
            // 둘 다 열 방향인 경우
            flag = c0==b.c0 && ( (b.r0<=r0 && r0<=b.r1) || (b.r0<=r1 && r1<=b.r1) );
        } else {
            // 하나는 행 직선, 하나는 열 직선인 경우
            // 만나는 점의 좌표를 사용하여, 그 점이 두 직선분 위에 모두 존재하는지 확인한다.
            if (this->rbus && b.rbus==false) {
                // the cross point is at (this->r0, b.c0),
                // now check if this point is on both of the lines
                flag = (c0<=b.c0 && b.c0<=c1) && (b.r0<=r0 && r0<=b.r1);
            }
            else {
                // cross point is at (this->c0, b.r0)
                // so,
                flag = (r0<=b.r0 && b.r0<=r1) && (b.c0<=c0 && c0<=b.c1);
            }
        }
        return flag;
    }
};

int main() {
    int m, n;
    cin >> n >> m;
    int nbus;
    cin >> nbus;
    vector<Bus> buses(nbus+1);
    for (int i=0; i<nbus; i++) {
        int n;
        cin >> n;
        cin >> buses[n].c0 >> buses[n].r0 >> buses[n].c1  >> buses[n].r1;
        // 크기 비교를 하게 되므로 작은값을 왼쪽으로.
        if (buses[n].c0 > buses[n].c1) std::swap(buses[n].c0, buses[n].c1);
        if (buses[n].r0 > buses[n].r1) std::swap(buses[n].r0, buses[n].r1);
        buses[n].rbus = (buses[n].r0 == buses[n].r1); // 행방향 노선인지 아닌지
        buses[n].count = 0; // not used
    }
    
    int sr, sc, er, ec; // start row, start col, end row, end col
    cin >> sc >> sr >> ec >> er;
    
    // 큐를 초기화한다.
    queue<int> q;
    for (int i=1; i<=nbus; i++) {
        // 시작점이 있는 노선을 큐에 넣는다.
        bool check = buses[i].line(sr,sc);
        if (check) {
            buses[i].count = 1;
            q.push(i);
        }
    }

    // BFS
    while (!q.empty()) {
        int u = q.front(); q.pop();
        Bus& ubus = buses[u];
        for (int i=1; i<=nbus; i++) {
            if (buses[i].count==0) {
                // 아직 사용하지 않는 버스 노선에 대해서만 처리하면 된다.
                bool flag = buses[i].cross(ubus);
                if (flag) {
                    buses[i].count = ubus.count + 1;
                    q.push(i);
//                    printf ("bus %d meets bus %d (count=%d)\n", u, i, buses[i].count);
                }
            }
        }
    }

    // 전체 노선 중에서 최소가 되는 경우를 찾는다.
    int count = nbus; // worst case,
    for (int i=1; i<=nbus; i++) {
        bool check = buses[i].line(er, ec);
        if (check && count>buses[i].count) {
            count = buses[i].count;
        }
    }
    
//    for (int i=1; i<=nbus; i++) {
//        printf("bus %d : %d\n", i, buses[i].count);
//    }
    
    cout << count;
    
    return 0;
}




//int map[1000][1000];
#if 0
// 이 방법으로 하면 가장 간단하게 만들수 있지만 ... 맵의 크기가 너무 큰 경우
// Memory exceed!
int main() {
    int m, n;
    cin >> n >> m;
    int nbus;
    cin >> nbus;
    vector<Bus> buses(nbus+1);
    for (int i=0; i<nbus; i++) {
        int n;
        cin >> n;
        cin >> buses[n].c0 >> buses[n].r0 >> buses[n].c1  >> buses[n].r1;
        buses[n].rbus = buses[n].r0 == buses[n].r1;
    }
    
    int sr, sc, er, ec; // start row, start col, end row, end col
    cin >> sc >> sr >> ec >> er;
    
    if(0) {
        printf ("%d %d\n", m, n);
        for (int i=1; i<=nbus; i++)
            printf("%d %d %d %d %d\n", i, buses[i].c0, buses[i].r0, buses[i].c1, buses[i].r1);
        printf("%d %d %d %d\n", sc, sr, ec, er);
        }
    
    int **map;
    map = (int **) malloc (sizeof(int*)*(m+1));
    for (int i=1; i<=m; i++) {
        map[i] = (int *) malloc(sizeof(int)*(n+1));
        if (!map[i]) { printf("memsize error: %dx%d\n", m, n); return 0; }
        memset(map[i], 0, sizeof(int)*(n+1));
    }
    //int map[m+1][n+1];
    map[sr][sc]=1; // start point
    queue<Coord> q;
    q.push (Coord{sr,sc});
    
    int count = 0;
    bool reached=false;
    while (!q.empty() && !reached) {
        Coord co = q.front(); q.pop();
        for (int i=1; i<=buses.size()  && !reached; i++) {
            Bus b = buses[i];
            if (b.line(co))
                for (int r=b.r0; r<=b.r1  && !reached; r++)
                    for (int c=b.c0; c<=b.c1  && !reached; c++) {
                        if (map[r][c]==0) {
                            map[r][c] = map[co.r][co.c] + 1;
                            q.push(Coord{r,c});
                        }
                        if (r==er && c==ec) { // reached the goal
                            reached=true;
                            count = map[r][c]-1;
                            break;
                        }
                    }
            
        }
    }
    
    //    for (int i=1; i<=m; i++) {
    //        for (int j=1; j<=n; j++)
    //            printf("%3d", map[i][j]);
    //        printf("\n");
    //    }
    
    if (reached) {
        cout << count;
    } else
        cout << "unreacheable." << endl;
    
    return 0;
}
#endif


#if 0
// The solution was copied from
// http://codingfun.net/?mid=classifyViewSolution&pid=12rh3&solNo=15

#include <stdio.h>
#include <string.h>
#define BUS_MAX 5002
int X1[BUS_MAX], Y1[BUS_MAX];
int X2[BUS_MAX], Y2[BUS_MAX];
int Best[BUS_MAX], Que[BUS_MAX], tail;
int Check[BUS_MAX];

/* Check if (x, y) is included to the (idx)th bus line */
int is_included(int x, int y, int idx)
{
    if (X1[idx] == X2[idx])
        {
        return x == X1[idx] && Y1[idx] <= y && y <= Y2[idx];
        }
    else
        {
        return y == Y1[idx] && X1[idx] <= x && x <= X2[idx];
        }
}

/* Check if the two bus lines are meeting */
int is_cross(int a, int b)
{
    if (X1[a] == X2[a])
        {
        if (X1[b] == X2[b])
            {
            return X1[a] == X1[b] && !(Y1[a] > Y2[b] || Y1[b] > Y2[a]);
            }
        else
            {
            return X1[b] <= X1[a] && X1[a] <= X2[b] &&
            Y1[a] <= Y1[b] && Y1[b] <= Y2[a];
            }
        }
    else
        {
        if (Y1[b] == Y2[b])
            {
            return Y1[a] == Y2[b] && !(X1[a] > X2[b] || X1[b] > X2[a]);
            }
        else
            {
            return Y1[b] <= Y1[a] && Y1[a] <= Y2[b] &&
            X1[a] <= X1[b] && X1[b] <= X2[a];
            }
        }
}

int main()
{
    int M, N; // The size of board (1 <= N, M <= 100,000)
    int K; // The number of bus lines (1 <= K <= 5,000)
    int s_x, s_y; // The starting point is (s_x, s_y)
    int e_x, e_y; // The destination is (e_x, e_y)
    int i, j, idx;
    scanf("%d%d", &M, &N);
    scanf("%d", &K);
    for (i = 0; i < K; i++)
        {
        scanf("%d%d%d%d%d", &idx, &X1[i], &Y1[i], &X2[i], &Y2[i]);
        Check[idx - 1] = 1;
        if (X1[i] > X2[i])
            {
            int tmp = X1[i];
            X1[i] = X2[i];
            X2[i] = tmp;
            }
        if (Y1[i] > Y2[i])
            {
            int tmp = Y1[i];
            Y1[i] = Y2[i];
            Y2[i] = tmp;
            }
        }
    scanf("%d%d%d%d", &s_x, &s_y, &e_x, &e_y);
    
    /* Initial setting */
    memset(Best, 255, sizeof(Best)); // Best[i]= -1;
    tail = 0;
    for (i = 0; i < K; i++)
        {
        if (is_included(s_x, s_y, i))
            {
            Best[i] = 1;
            Que[tail++] = i;
            }
        }
    /* BFS */
    for (i = 0; i < tail; i++)
        {
        for (j = 0; j < K; j++)
            {
            if (Best[j] != -1)
                {
                continue;
                }
            if (is_cross(Que[i], j))
                {
                Best[j] = Best[Que[i]] + 1;
                Que[tail++] = j;
                }
            }
        }
    
    /* Finding answer */
    int res = K;
    for (i = 0; i < tail; i++)
        {
        if (Best[i] == -1)
            {
            continue;
            }
        if (is_included(e_x, e_y, i) && res > Best[i])
            {
            res = Best[i];
            }
        }
    printf("%d\n", res);
    return 0;
}
#endif
