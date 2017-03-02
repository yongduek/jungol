//
//  j1077-recursive.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 4. 25..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct jewelry {
    int weight, value;
};

vector<jewelry> jews;

const int maxWeight = 10000;
int packTable[maxWeight+1];

int pack(int w)
{
//    if (w<=0) return 0;
    
    int maxval = 0;
    if (packTable[w]<0)
        {
        for (int i=0; i<jews.size(); i++)
            {
            int weight_possible = w - jews[i].weight;
            if (weight_possible < 0) continue;
            int total_val = jews[i].value + pack (weight_possible);
            if (maxval < total_val) maxval = total_val;
            }
        packTable[w] = maxval;
        }
    
    maxval = packTable[w];
    return maxval;
}
int main()
{
    int N, W;
    cin >> N >> W;
    
    for (int i=0; i<=W; i++) packTable[i] = -1;
    
    for (int i=0; i<N; i++) {
        int weight, val;
        cin >> weight >> val;
        jews.push_back(jewelry {weight, val});
    }
    
    int maxval = pack (W);
    
    cout << maxval << endl;

//    cout << "--" << endl;
//    for (int i=0; i<=W; i++)
//        cout << i << ": " << packTable[i] << endl;

    return 0;
}
// eof //