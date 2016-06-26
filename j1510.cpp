//
//  j1510.cpp
//  색종이 올려 놓기
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 5. 16..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm> // std::sort()

using namespace std;

struct paper{
    
    int x, y;
    
    // 비교를 위한 함수
    bool operator < (const paper& p) const {
        if ( this->x < p.x ) return true;
        else if (this->x == p.x) {
            if (this->y < p.y) return true;
            else return false;
        }
        else return false;
    }
    
};

vector<paper> a; // array for 색종이

void print (vector<paper>& vp) {
    for (int i=0; i < vp.size(); i++)
        printf ("%d : %d %d\n", i, vp[i].x, vp[i].y);
}

void print (vector<int>& v) {
    for (int i=0; i < v.size(); i++)
        printf ("%d : %d\n", i, v[i]);
}

// ------------------------------------
// dp bottom-up
int solve_LIS(vector<int>& a)
{
    int N = a.size();
    int lis[a.size()];
    int maxlis = 0;

    lis[0] = 1;
    for (int k=1; k<N; k++)
        {
        lis[k] = 1; // init
        for (int i=k-1; i>=0; --i)
            if (a[k] >= a[i]) // 등호가 포함되어 있다. 같은 값들이 있을 수 있다.
                {
                lis[k] = max( lis[k], lis[i] + 1 );
                }
        maxlis = max (maxlis, lis[k]);
        }
    
    return maxlis;
}
// ------------------------------------

int main()
{
    int N;
    cin >> N;
    while (--N>=0)
        {
        int x, y;
        cin >> x >> y;
        // 읽어들인 색종이의 크기를 저장한다.
        // 저장할 때, 큰쪽의 길이가 x가 되도록 미리 색종이를 회전시킨다.
        if (x>y)
            a.push_back (paper{x,y});
        else
            a.push_back(paper {y,x});
        }
//    print(a);
    // x 에 대해서 오름차순으로 정렬한다.
    std::sort (a.begin(), a.end());
//    print(a);
    
    // 이제 y 에 대한 LIS 를 구하면 된다.
    // 그런데 y 값 중에서 같은 값이 있을 수 있으므로 엄밀히 말하자면
    // longest non-decreasing sequence 의 길이를 구하는 문제가 된다.
    // 먼저 y 값들만 뽑아낸다.
    vector<int> y;
    for (int i=0; i<a.size(); i++)
        y.push_back(a[i].y);
//    print (y);
    
    // 최대 길이를 구한다.
    int maxlis = solve_LIS(y);
    
    printf ("%d\n", maxlis);
    return 0;
}
// eof //