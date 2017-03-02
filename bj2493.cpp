//
//  bj2493.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 2. 25..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void bj2493()
{
    int n;
    cin >> n;
    vector<int> v(n+1);
    vector<int> next_id(n+1,0);
    v[0] = 100000001;
    next_id[0] = 0;
    
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        // compare with v[i-1]'s height
        if (v[i] <= v[i-1]) {
            next_id[i] = i-1;
        } else {
            int nid = next_id[i-1];
            while (v[i] > v[nid])
                nid = next_id[nid];
            next_id[i] = nid;
        }
        printf("%d ", next_id[i]);
    }
    printf ("\n");
}

int main()
{
    bj2493();
    
    return 0;
}