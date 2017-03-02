//
//  j1295.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 3. 21..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int N;
int A[500001];
int T;

int b_search (int q, int s, int e)
{
    if (! (s<=e) ) return 0;
    
    int m = (s+e)/2;
    if (A[m] == q) return m;
    else if (A[m] > q)
        return b_search (q, s,  m-1);
    else
        return b_search(q, m+1, e);
}

int main()
{
    cin >> N;
    for (int i=1; i<=N; i++)
        cin >> A[i];
    
    cin >> T;
    while (--T >= 0) {
        int q;
        cin >> q;
        
        int index = b_search (q, 1, N);
        printf ("%d\n", index);
    }
    return 0;
}