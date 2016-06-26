//
//  j1169.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 3. 21..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int N, option;
int d[10]={1,0};
int mask[10];

void print () {
    for (int i=1; i<=N; i++)
        printf ("%d ", d[i]);
    printf("\n");
}

void dice1(int k, int N)
{
    if (N==0) {
        print();
        return;
    }
    for (int i=1; i<=6; i++) {
        d[k] = i;
        dice1(k+1, N-1);
    }
}

void dice2(int k, int N)
{
    if (N==0) {
        print();
        return;
    }
    for (int i=d[k-1]; i<=6; i++) {
        d[k] = i;
        dice2(k+1, N-1);
    }
}

void dice3(int k, int N)
{
    if (N==0) {
        print();
        return;
    }
    for (int i=1; i<=6; i++) {
        if (mask[i]==true) continue;
        d[k] = i;
        mask[i]=true;
        dice3(k+1, N-1);
        mask[i]=false;
    }
}

int main()
{
    cin >> N >> option;

    switch (option) {
        case 1: dice1(1, N); break;
        case 2: dice2(1, N); break;
        case 3: dice3(1, N); break;
    }
    return 0;
}