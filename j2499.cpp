//
//  j2499.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 2. 22..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//
/*
 Input Data
 100
 10 200000 200000 200000 200000 1 100 10000 10000 200000 100 1 200000 100 200000 1000 200000 100 200000 200000 200000 200000 100 10000 200000 200000 200000 200000 200000 10 10 200000 1 200000 1000 200000 10 10000 1 200000 10000 100 200000 200000 200000 100 200000 200000 200000 10000 10000 1000 200000 10 1000 200000 10 1 10000 200000 200000 200000 200000 200000 1000 100 1 100 200000 1000 200000 1000 200000 1000 200000 200000 200000 200000 10 1000 200000 1 1 200000 200000 100 200000 1 200000 10 200000 200000 1 10000 200000 10 1000 10000 200000 10
 
 
 CPU Result
 111111
 
 
 You Result
 111117

 10
 4 64 256 128 8 1 32 512 2 16
 1024
 
 
 10
 6 100 101 3 5 102 104 2 103 4
 
 
 CPU Result
 1
 
 
 You Result
 7
 */
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void print (vector<int>& a) {
    printf("::");
    for (int i=0; i<a.size(); i++)
        printf ("%d ", a[i]);
    printf ("\n");
}

const int nq=1000010;
int q[nq];
vector<int> vq;

char str[2][10] = {"false", "true"};


bool check (int num, vector<int> q)
{
    auto it = std::upper_bound(q.begin(), q.end(), num);
    if (it ==q.end())
        --it; // it is the upper_bound.
    //    printf("%d (%d): ", num, *it);
    //    vector<int> a;
    bool res = false;
    while (it != q.begin()) {
        if(*it <= num) {
            num -= (*it);
            //            a.push_back(*it);
            if (num==0) { res = true; break; }
            //            printf ("%d ", *it);
        }
        --it;
    }
    
    // now it == q.begin()
    if (*it <= num) {
        num -= (*it);
        //        a.push_back(*it);
    }
    if (num==0) res=true;
    
    //    print (a);
    //    printf("\n----%s----\n", str[res]);
    
    return res;
}

int bs(int num, int q[], int nq)
{
    int sti=nq-1;
    return sti;
}

bool check (int num, int q[], int nq)
{
    int sti = bs (num, q, nq);
//    printf("%d (%d): ", num, q[sti]);
    vector<int> a;
    bool res = false;
    for (int i=sti; i>=0; --i) {
        if(q[i] <= num) {
            num -= q[i];
            if (num==0) { res = true; break; }
//            a.push_back(q[i]);
//            printf ("%d ", q[i]);
        }
    }
//    printf("\n----%s----\n", str[res]);
    
    return res;
}

bool check2 (int num, int q[], int nq)
{
    int sti = bs (num, q, nq);
    //    printf("%d (%d): ", num, q[sti]);
    vector<int> a;
    bool res = false;
    for (int i=sti; i>=0; --i) {
        if(i <= num) {
            for (int j=0; j<q[i]; j++) {
                num -= i;
                if (num==0) { res = true; break; }
            }
            //            a.push_back(q[i]);
            //            printf ("%d ", q[i]);
        }
    }
    //    printf("\n----%s----\n", str[res]);
    
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    
//    for (int i=0; i<n; i++)
//        {
//        int x; cin >> x; vq.push_back(x);
//        }
//    sort (vq.begin(), vq.end());
    
//    for (int i=0; i<n; i++) {
//        scanf("%d", q+i);
//    }
//
//    sort (q, q+n);

    for (int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        q[x] += 1;
    }

    int num=1;
    while (true) {
        if (check(num, q, nq)==false) break;
        ++num;
    }
    printf("%u\n", num);
    return 0;
}