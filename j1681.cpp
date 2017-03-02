/* 1681 : 해밀턴 순환회로
 제한시간: 1Sec    메모리제한: 64mb
 해결횟수: 473회    시도횟수: 2027회
 
 
 문제를 잘 풀기로 소문난 도경이는 모든 올림피아드 대회에 참가하고 싶어 했다. 대회에 참가하여 상이란 상은 다 타고 싶은 마음이었지만, 한 가지 걸리는 것이 있었다.
 
 문제는 올림피아드 대회가 모두 해외에서 열리는 관계로 비행기 값이 굉장히 많이 들어간다는 것이다. 결국에는 집으로 다시 돌아와야 하는데, 모든 대회에 1번씩만 참가하고 집으로 돌아오는 경비를 가장 최소화하고 싶다. 도경이는 이것을 해결하지 못하면, 대회에 참가하기가 어렵게 된다. 대회는 참가하기만 하면 언제든지 알고리즘 문제를 풀 수 있기 때문에 경비를 계산하는 것 이외의 사항은 고려하지 않아도 된다.
 
 첫 줄은 참가하는 대회의 수 N(1≤N≤12)을 입력 받는다. 이때, 출발지(집)는 1번으로 한다.
 
 둘째 줄은 N X N 크기의 대회 개최지와 개최지를 이동하는 항공료(0 ≤ 항공료＜ 100)가 나온다. 각 항공료는 한 칸의 공백으로 구분된다. 만약에 개최지에서 개최지로 이동할 수 있는 항공로가 없다면 항공료의 값을 0으로 표시한다.
 
 
 집에서 출발하여 전체 대회를 모두 참가하고 돌아올 때 최소의 항공료를 출력한다.
 
 [Copy]
 5
 0 14 4 10 20
 14 0 7 8 7
 4 5 0 7 16
 11 7 9 0 2
 18 7 17 4 0
 [Copy]
 30

 3
 0 86 0
 69 0 83
 45 97 0
 
 214
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
#include <list>
#include <deque>
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

void print(vi s, string st="") {
    printf("%s", st.c_str());
    for (int i=0; i<s.size(); i++)
        printf ("%d ", s[i]);
    printf("\n");
}

void print (vvi s) {
    for (int i=0; i<s.size(); i++)
        print (s[i], to_string(i)+" : ");
    printf("\n----\n");
}

void print (vii& s, string st="") {
    if (!s.empty()) printf ("%s\n", st.c_str());
    for (int i=0; i<s.size(); i++)
        printf ("(%d,%d) ", s[i].first, s[i].second);
    printf ("\n");
}


int N;
int mat [12*12]; // max 12x12
int mincost = 100*12*1000;

void fly (int crow, int cost, unsigned visited, int path) {
    // now at crow
    visited |= 1<<crow;
//    path.push_back (ii(crow,cost));
    path++;
    
    if (crow==0) {
        if (path!=N)
            return; // still to go
        else {
        
            //        print (path, "path: ");
            //        printf ("total cost = %d\n ---- \n", cost);
            // the cost
            mincost = min (mincost, cost);
            return;
        }
    }
    
    for (int c=0; c<N; c++) { // for each destination
        int ii = crow*N+c;
        if ((visited&(1<<c))==0 && mat[ii]!=0) {
            if (cost+mat[ii] < mincost)
                fly (c%N, cost + mat[ii], visited, path);
        }
    }
}

int main()
{
//    cin >> N;
    scanf("%d", &N);
    for (int i=0; i<N*N; i++)
        scanf ("%d", mat+i);
    
//    vector<bool> visited(N,false);
    unsigned visited = 0;
    int path=0;
    for (int c=0; c<N; c++) { // for each destination
        if (mat[c]!=0)
            fly (c, mat[c], visited, path);
    }
    printf("%d\n", mincost);
    return 0;
}

/*** TLE ***/
/***
int N;
vi mat (12*12); // max 12x12
int mincost = 100*12*1000;

void fly (int crow, int cost, vector<bool> visited, vii path) {
    // now at crow
    visited[crow] = true;
    path.push_back (ii(crow,cost));
    
    if (crow==0) {// now at home
        for (int i=0; i<visited.size(); i++)
            if (visited[i]==false)
                return; // useless
        
//        print (path, "path: ");
//        printf ("total cost = %d\n ---- \n", cost);
        // the cost
        mincost = min (mincost, cost);
        return;
    }
    
    for (int c=0; c<N; c++) // for each destination
        if (visited[c]==false && mat[crow*N+c]!=0) {
            fly (c%N, cost + mat[crow*N+c], visited, path);
        }
}

int main()
{
    cin >> N;
    for (int i=0; i<N*N; i++)
        cin >> mat[i];

    vector<bool> visited(N,false);
    vii path;
    for (int c=0; c<N; c++) { // for each destination
        if (mat[c]!=0)
            fly (c, mat[c], visited, path);
    }
    printf("%d\n", mincost);
    return 0;
}
***/