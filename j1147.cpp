//
//  1147.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 2. 3..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include <stack>

using namespace std;

typedef std::pair<int,int> pii;

void print (set<int>& m) {
    for (auto i=m.begin(); i!=m.end(); i++)
        printf("(%d)", *i);
    printf("\n");
}

// for opposite indexing
//             1 2 3 4 5 6
int opp[6] = {6,4,5,2,3,1};

// E.g. when 1 (0) is face down, {2 3 4 5} is on the side wall
int f[6][4] = {
    {2,3,4,5},
    {1,3,5,6},
    {1,2,4,6},
    {1,3,5,6},
    {1,2,4,6},
    {2,3,4,5}
};

int dice[10000][6];

int main()
{
    for (int i=0; i<6; i++) {
        opp[i]--;
        for (int j=0; j<4; j++) f[i][j]--; // 0-based
    }
    int N;
    std::cin >> N;
    for (int i=0; i<N; i++)
        for (int k=0; k<6; k++)
            cin >> dice[i][k];
    
    return 0;
}