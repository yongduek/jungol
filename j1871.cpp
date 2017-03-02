//
//  j1871.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 4. 28..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

// LIS  찾는 문제.

int N;
int a[201]; // max 200
int lis[201];
int maxlis = 0;

void print ()
{
    for (int i=0; i<N; i++)
        printf ("%d  ", lis[i]);
    puts("");
}

// --------------------------------
// dp bottom-up
void solve_forloop()
{
    lis[0] = 1;
    for (int k=1; k<N; k++)
        {
        lis[k] = 1; // init
        for (int i=k-1; i>=0; --i)
            if (a[k] > a[i])
                {
                lis[k] = max( lis[k], lis[i] + 1 );
                }
        maxlis = max (maxlis, lis[k]);
        }
}

// --------------------------------
// dp top-down
int getlis(int k)
{
//    if (k==0) return 1;
    if (lis[k]>0) // already computed.
        return lis[k];
    
    // lets find LIS[k]
    lis[k]=1;
    for (int i=0; i<k; ++i)
        if (a[k] > a[i])
            lis[k] = max (lis[k], getlis(i)+1);

    return lis[k];
}

void solve_recursive ()
{
    lis[0] = 1;
    
    for (int k=N-1; k>=0; --k)
        maxlis = max(maxlis, getlis(k));
}

//
// 모든 서브시퀀스에 대해서 그 서브시퀀스가 증가하는 것인지 검사하고,
// 만약 그렇다면 길이를 업데이트하여, 가장 긴 것을 찾아냄.
//
// bit mask allows maximum 64 bit. If the input is longer than 64, this function is wrong.
void solve_exhaustive()
{
    maxlis = 0;
    // N 개의 값들 중에서 0개, 1개, 2개 등등을 고르는 방법을 모두 세어보면 2^N 개가 된다.
    unsigned long maxnum = 1L<<N; // 2^N

    for (unsigned long i=1; i<maxnum; i++)
        {
        // the bit string of i indicates the selected numbers among N numbers
        int k=0;
        int sub[N];
        for (unsigned shift = 0 ; shift < N; shift ++)
            {
            unsigned long mask = 1 << shift;
            // 서브시퀀스를 찾는다.
            if (mask & i)
                sub[k++] = a[shift];
            }
        // 서브시퀀스가 준비되었으므로 증가하는 시퀀스인지 검사한다.
        // now one sub-sequence is available
        bool flag = true;
        for (int j=1; j<k; j++)
            if (sub[j-1] < sub[j]) continue;
            else { flag=false; break; }
        // 증가하는 시퀀스이면 길이는 테스트하고 업데이트한다.
        if (flag) // this sub sequence is increasing
            {
            if (maxlis < k)
                maxlis = k; // update the length of the list
            }
        }
}

int main()
{
    
    cin >> N;
    for (int i=0; i<N; i++) cin >> a[i];

//  두 가지 방법 중에 하나를 선택한다.
// 1. for-loop 를 사용하는 방법
    solve_forloop();

// 2. top-down 방법
//    for (int i=0; i<N; i++) lis[i] = 0;
//    solve_recursive();

// 3. 모든 해를 다 구해보는 방법인데 무지 느리고 한계가 있다.
//    solve_exhaustive();
    
    printf ("%d\n", N - maxlis);
    return 0;
}
// 끝
