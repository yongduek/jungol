//
//  1021.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 2. 3..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

#define id(r,c,N) ((r)*N+(c)) // be careful with the parenthesis

void print (vector<int>& m, int N)
{
    for (int r=0; r<N; r++) {
        for (int c=0; c<N; c++)
            printf("%d ", m[id(r,c,N)]);
        printf("\n");
    }
}
void print (vector<int>& m)
{
    for (int c=0; c<m.size(); c++)
        printf("%d ", m[c]);
    printf("\n");
}

int N, M;
vector<int> basicPart;

void take (int i, int count, vector<int>& table, vector<int>& mat)
{
//    print (table);
    table[i] += count;
    
    if (basicPart[i]==0) return;
    
    for (int c=0; c<N; c++)
        {
        int n = id(i,c,N);
        if (mat[n]>0)
            {
            take (c, count*mat[n], table, mat);
            }
        }
}

int main()
{
    cin >> N;
    cin >> M;
    vector<int> mat(N*N,0);

    for (int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        mat[id(a,b,N)] = c;
    }
//    print (mat, N);
    
    basicPart.resize(N,0);
    for (int r=0; r<N; r++) {
        for (int c=0; c<N; c++)
            basicPart[r] += mat[id(r,c,N)];
    }
//    printf("basic:"); print(basicPart);
    
    vector<int> table(N,0);
    
    for (int i=0; i<N; i++)
        {
        int n = id(N-1/*main part*/,i,N);
        if (mat[n]>0)
            {
            take (i, mat[n], table, mat);
            }
        }
//    print(table);
    for (int i=0; i<N; i++)
        if (basicPart[i]==0)
            printf("%d %d\n", i+1, table[i]);
    return 0;
}