//
//  j2264.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 4. 24..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <iostream>
using namespace std;

const int a=1004;
int table[a][a/2];
const int D = 1000000003;

long stripe(int n, int k)
{
    int v;
    if (table[n][k]<0) {
        if (n<2*k-1) v=0;
        else if (k==0) v=1;
        else if (n==1 && k==1) v=1;
        else
            v = ( stripe(n-1,k) + stripe(n-2,k-1) ) % D;
        
        table[n][k] = v;
    }
    
    v = table[n][k];

    return v;
}

int main()
{
    int N, K;
    cin >> N >> K;
    
    // initialize the table
    for (int i=0; i<a; i++) for (int j=0; j<a/2; j++) table[i][j]=-1;
    
    int c_N_K = (stripe(N-3, K-1) + stripe (N-1, K))%D;
    
    printf ("%ld\n", c_N_K);
    return 0;
}
// eof //