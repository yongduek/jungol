//
//  j1183.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 2. 22..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//
/*
 Input Data
 968
 1 7 5 9 9 7
 
 
 CPU Result
 30
 0 6 5 7 9 3
 
 
 You Result
 22
 0 7 4 5 3 3
*/

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int nc = 6;
int coins[nc] {500,100,50,10,5,1};
int ncoins[nc];
int a[nc][nc];
int q[nc][nc];
int nused[nc];
int decr[nc][nc];

int main()
{
    int W;
    scanf("%d", &W);
    
    for (int i=0; i<nc; i++) {
        scanf("%d", &ncoins[i]);
    }

    for (int i=0; i<nc; i++) { // 각각의 동전 금액 i 대해서
        for (int j=0; j<=i; j++) { // 동전 j 를 사용하여 만들수있는  방법들
            a[i][j]=coins[j]/coins[i]; // coins[j] 를 여러개의 coins[i] 로 만들려면 a 만큼 있어야함.
            int ratio = ncoins[i] / a[i][j]; // 현재 i동전
            q[i][j] = ratio; // 가능 갯수
            decr[i][j] = ratio*a[i][j]; // 총 갯수
            ncoins[i] -= decr[i][j];
        }
    }
    
    for (int j=0; j<nc; ++j) { // 동전 큰 것 부터
        for (int i=nc-1; i>=0; --i) { // (i,j) i 코인으로 만든 동전 j
            while (q[i][j]>0 && W >= coins[j])
                W -= coins[j], nused[i] += q[i][j], decr[i][j]--;
        }
    }
    
    int sum(0);
    for (int i=0; i<nc; i++)
        sum += nused[i];
    
    printf ("%d\n", sum);
    for (int i=0; i<nc; i++)
        printf ("%d ", nused[i]);
    printf ("\n");
    
    return 0;
}