//
//  1459-choice.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 2. 3..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

/*
 Each node has only one directed edge.
 Find nodes of loops.
 */

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


int main()
{
    int N;
    std::cin >> N;
    vector<int> arr(N+1);
    for (int i=1; i<=N; i++) {
        int k;
        std::cin >> k;
        arr[i] = k;
    }

    set<int> choice;
    for (int i=1; i<=N; i++) {
//        cout << "Starting with " << i << endl;
        int sid = i;
        int next = arr[sid];
        if (choice.find(next)!=choice.end())
            continue; // already chosen
        else
            //if (choice.find(next)==choice.end()) // not chosen as a loop node
            {
            set<int> c; c.insert(next);
            bool isLoop=false;
            while (1)
                {
                if (choice.find(next)==choice.end() // not in the list
                    && next == sid) // loop-back
                    {
                        isLoop=true; break;
                    }
                next = arr[next];
                if (c.find(next)!=c.end() // already in c
                    && next!=sid) // loop found but sid is not included.
                    break;
                c.insert(next);
                }
            if (isLoop)
                {
                choice.insert(c.begin(),c.end());
                }
//            print (choice);
            }
    }
    printf("%lu\n", choice.size());
    for (auto i=choice.begin(); i!=choice.end(); i++) {
        printf("%d\n", *i);
    }
    return 0;
}
/***/