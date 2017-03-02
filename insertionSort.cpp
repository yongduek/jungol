//
//  insertionSort.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 2. 24..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

void print (vector<int>& a)
{
    for (int i=0; i<a.size(); i++)
        printf ("%d ", a[i]);
    printf("\n");
}

void insertion_sort (vector<int>& a)
{
    for (int i=1; i<a.size(); i++) {
        int key = a[i];
        int j=i-1;
        for (; j>=0; j--)
            if (a[j] > key)
                a[j+1] = a[j];
            else
                break;
        a[j+1]=key;
    }
}

int main()
{
    vector<int> a(20);

    for (int i=0; i<a.size(); i++)
        a[i] = random()%(a.size()*a.size()*a.size());

    cout << "a=" ;
    print(a);
    
    insertion_sort (a);
    
    cout << "a=" ;
    print(a);
    
}