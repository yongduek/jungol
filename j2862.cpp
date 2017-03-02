//
//  j2862.cpp
//  cool-project
//
//  Created by Yongduek Seo on 2017. 1. 9..
//  Copyright © 2017년 Yongduek Seo. All rights reserved.
//

// Problem: given a rectangle of size (m,n), find the minimum number of squares.
// the cutting cannot stop in the middle of a rectangle. it always divides the rectangle into two smaller ones.
// cutting can be done vertically or horizontally, only at the integeger index.
//
// m: height, [0,100]
// n: width, [0,10000]

#include <stdio.h>
#include <iostream>

using namespace std;

int memo[102][10010];
int table[102][10010];

void print(int mem[102][10010], int m,int n) {
    for (int j=0; j<=n; j++)
        printf ("%4d", j);
    printf("\n");
    for (int i=1; i<=m; i++) {
        printf("%4d", i);
        for (int j=1; j<=n; j++)
            printf ("%4d", mem[i][j]);
        printf("\n");
    }
}

int cuts_memo(int m, int n) {
    if (m>n) std::swap(m,n);
    if (memo[m][n]) return memo[m][n];
    if (n%m==0) return (memo[m][n]=n/m);

    int minc=0, minr=0;
    int ncmin = m*n+100; // a large number
    int rest = n%m;
    for (int c=1; c<=rest; c++) {
        int nc = cuts_memo(m, n-c) + cuts_memo(m,c);
        if (nc < ncmin) {
            ncmin = nc;
            minc = c;
        }
    }
    for (int r=1; r<=m/2; r++) {
        int nc = cuts_memo(m-r, n) + cuts_memo(r,n);
        if (nc < ncmin) {
            ncmin = nc;
            minr = r;
        }
    }
    printf("cuts(%2d,%2d)= %2d at (%2d, %2d) rest=%d\n", m,n, ncmin, minr, minc, rest);
    return memo[m][n] = ncmin;
}

int cuts(int m, int n) {
    if (m>n) std::swap(m,n);
    int ncuts;
    
    if (memo[m][n])
        return memo[m][n];
    else if (n%m==0)
        ncuts = n/m;
    else {
        int ncmin = m*n+100; // a large number
        for (int r=1; r<=m/2; r++) {
            int nc = cuts(m-r, n) + cuts(r,n);
            if (nc < ncmin) {
                ncmin = nc;
            }
        }
        for (int c=1; c<=n/2; c++) {
            int nc = cuts(m, n-c) + cuts(m,c);
            if (nc < ncmin) {
                ncmin = nc;
            }
        }
    //printf("cuts(%2d,%2d)= %2d at (%2d, %2d) rest=%d\n", m,n, ncmin, minr, minc, rest);
        ncuts = ncmin;
    }
    return memo[m][n]=ncuts;
}

int main() {
    int m, n;
    cin >> m >> n;
    if (m>n) std::swap(m,n);
    
    for (int j=1; j<=n; j++) memo[1][j] = j;
    
    int minc = cuts (m, n);
    printf("%d\n", minc);
    
//    printf("memo= %d\n", cuts_memo(m, n));
//    print(memo, m,n);
    
//    for (int j=1; j<=n; j++) table[1][j] = j;
//    for (int i=2; i<=m; i++) {
//        for (int j=i; j<=n; j++) {
//            table[i][j] = j/i + table[j%i][i];
//        }
//    }
//    print(table, m,n);
    return 0;
}
