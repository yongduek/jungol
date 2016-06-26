//
//  j1077-bottomup.cpp
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

int main()
{
    int N, W;
    cin >> N >> W;

    for (int i=0; i<N; i++) { // read input data
        int weight, val;
        cin >> weight >> val;
        jews.push_back(jewelry {weight, val});
    }

    for (int w=1; w<=W; w++) {
        // given the possible weight w, find the possible maximum value
        for (int j=0; j<jews.size(); j++) {
            // for each jewelry, check if it can be included.
            int weight_after_including_j = w - jews[j].weight;
            if (weight_after_including_j < 0) continue; // impossible

            // choose max { current packTable[w], jews[j].value + packTable[weight_after_including_j] }
            packTable[w] = std::max (packTable[w], // current value
                                     packTable[weight_after_including_j] + jews[j].value
                                     );
        }
    }
    
    
    cout << packTable[W] << endl;
    
        cout << "--" << endl;
        for (int i=0; i<=W; i++)
            cout << i << ": " << packTable[i] << endl;
    
    return 0;
}
// eof //