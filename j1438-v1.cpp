//
//  j1438.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 4. 3..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct BIT {
    vector<int> count;
    vector<int> tree;
    int MaxIndex;

    void init (int N) {
        MaxIndex=N;
        tree.resize(MaxIndex+1, 0); // index runs from 0
        count.resize (MaxIndex+1, 0);
    }
    void print() {
        for (int i=1; i<=MaxIndex; i++)
            printf("%d %d   %d\n", i, tree[i], count[i]);
    }
    void update(int idx ,int val) { // idx의 값에 val 을 합치는 함수
        while (idx <= MaxIndex){
            tree[idx] += val;
            idx += (idx & -idx);
        }
    }
    void set(int i0, int i1) {
        for (int i=i0+1; i<=i1; i++) {
            count[i]++;
            if (count[i]==1) update(i, 1);
        }
    }
    void reset(int i0, int i1) {
        for (int i=i0+1; i<=i1; i++) {
            count[i]--;
            if (count[i]==0) update(i,-1);
            if (count[i]<0) {printf("negative count!\n"); exit (0); }
        }
    }
    int getsum(int idx) { // cdf[idx] 를 리턴, 1~idx 까지의 합
        int sum = 0;
        while (idx > 0){
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
    int getsum(void) { return getsum(MaxIndex); }
};

BIT bitree;

struct Data {
    int x, y0, y1;
    bool isStart; // if true, then x is the start
    
    Data(int _x, int _y0, int _y1, bool iss) {x=_x; y0=_y0; y1=_y1; isStart=iss;}
};
bool compareData(Data a, Data b) {
    if (a.x==b.x) return b.isStart; // end preceeds start
    else return a.x < b.x;
}

vector<Data> data;

void print(vector<Data>& d) {
    for (int i=0; i<d.size(); i++)
        printf ("%d %d-%d %s\n", d[i].x, d[i].y0, d[i].y1, d[i].isStart?"start":"end");
    return;
}

const int length=10;
int N;

int main()
{
    cin >> N;
    vector<int> x, y;
    for (int i=0; i<N; i++) {
        int _x, _y;
        cin >> _x >> _y;
//        x.push_back(_x); x.push_back(_x+length);
        y.push_back(_y); y.push_back(_y+length);
        
        data.push_back(Data {_x, _y, _y+length, true} ); // start x
        data.push_back(Data {_x+length, _y, _y+length, false} ); // end x
    }
    sort (y.begin(), y.end());
    sort (data.begin(), data.end(), compareData);
//    print(data);

    bitree.init(y[y.size()-1]);
    Data dp = data[0];
    int area = 0;
    for (int i=0; i<data.size(); i++) {
        int width = data[i].x-dp.x;
        int height = bitree.getsum();
        area += width*height;
//        printf("width[%d]=%d  height=%d\n", i, width, height);
        if (data[i].isStart)
            bitree.set (data[i].y0, data[i].y1);
        else
            bitree.reset(data[i].y0, data[i].y1);
//        bitree.print();
        dp = data[i];
    }
    printf ("%d\n", area);
    return 0;
}
// EOF //