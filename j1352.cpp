//
//  j1352.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 7. 5..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n;
int chu[30];
// -- C with hashing
/*****/
// max num. of weights = 500*30 = 15000
const int maxWeight = 15000;
bool weights[maxWeight+1] ={}; // initially all false
bool imsi[maxWeight+1] = {};
int main() {
    
    weights[0]=true; // initial
    cin >> n;
    for (int k=0; k<n; k++) {
        cin >> chu[k];
        // make all possible weights
        for (int i=0; i<=maxWeight; i++) {
            if (weights[i]==true) {
                int a = i - chu[k];
                int b = i + chu[k];
                imsi[abs(a)]=true;
                imsi[abs(b)]=true;
            }
        }
        for (int i=0; i<=maxWeight; i++)
            if (imsi[i]==true) weights[i]=true;
    }
    
    //    cout << "\n$ weights: ";
    //    for (int i=0; i<=maxWeight; i++)
    //        if (weights[i]==true) cout << i << ' ';
    //    cout << endl;
    
    // now try searching
    cin >> n; // recyle n
    for (int i=0; i<n; i++) {
        int ball;
        cin >> ball;
        if (weights[ball]==false) // not found
            cout << "N";
        else
            cout << "Y";
        cout << ' ';
    }
    return 0;
}
/*****/

// -- C++
/****
 set<int> weights; // possible weights
 set<int> imsi;
 int main() {
 
 weights.insert(0); // initial
 cin >> n;
 for (int i=0; i<n; i++) {
 cin >> chu[i];
 // make all possible weights
 for (auto it = weights.begin(); it!=weights.end(); ++it) {
 int a = *it - chu[i];
 int b = *it + chu[i];
 imsi.insert(abs(a));
 imsi.insert(abs(b));
 //imsi.insert(chu[i]); // 필요없음
 }
 for (auto it=imsi.begin(); it!=imsi.end(); ++it)
 weights.insert(*it);
 }
 
 //    cout << "\n$ weights: ";
 //    for (auto it = weights.begin(); it!=weights.end(); ++it) {
 //        cout << *it << ' ';
 //    }
 //    cout << endl;
 
 // now try searching
 cin >> n; // recyle it
 for (int i=0; i<n; i++) {
 int ball;
 cin >> ball;
 if (weights.find(ball) == weights.end()) // not found
 cout << "N";
 else
 cout << "Y";
 cout << ' ';
 }
 return 0;
 }
 ****/
// --
