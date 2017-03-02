//
//  j2584.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 5. 16..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/****
 struct picture {
 int h, c;
 
 picture(int hh, int cc) : h(hh), c(cc) {}
 
 // 정렬을 위한 비교 함수
 bool operator < (const picture& p) const {
 if ( this->h < p.h ) return true;
 else return false;
 }
 };
 void print (vector<picture>& p) {
 for (int i=0; i<p.size(); i++)
 printf ("%d : %d %d\n", i, p[i].h, p[i].c);
 }
 
 vector<picture> pics;
 
 int main()
 {
 int N, S;
 cin >> N >> S ;
 //    printf("N: %d  S: %d\n", N, S);
 for (int i=0; i<N; i++)  {
 int h, c;
 cin >> h >> c;
 pics.push_back(picture(h,c));
 //        printf ("%d: %d %d\n", i, h, c);
 //        cin >> pics[i].h >> pics[i].c ;
 }
 
 std::sort (pics.begin(), pics.end());
 //    print(pics);
 
 int cmax = 0;
 int maxval[N];
 for (int k=0; k<N; k++) {
 maxval[k] = pics[k].c; // starting value
 for (int prev=k-1; prev>=0; prev--)
 // 만약 높이차이가 S 이상이면
 if ((pics[k].h-pics[prev].h) >= S) {
 // 가능한 최대 그림값의 합을 업데이트한다.
 maxval[k] = max (maxval[k], maxval[prev]+pics[k].c);
 
 if (maxval[k] > cmax)
 cmax = maxval[k];
 else
 maxval[k] = cmax;
 
 break;
 }
 }
 printf ("%d\n", maxval[N-1]);
 return 0;
 }
 /****/
// eof //
/***/
#include<stdio.h>
#include<algorithm>
using namespace std;
struct pp{
    int h;
    int c;
} ar[11];

bool cmp(const struct pp &a,const struct pp &b)
{
    return a.h<b.h;
}
int ans[11];
int main()
{
    struct pp a;
    int n,s,i;
    long j;
    
    scanf("%d %d",&n,&s);
    
    for(i=1;i<=n;i++)
        scanf("%d %d",&ar[i].h,&ar[i].c);
    
    sort(ar+1,ar+n+1,cmp);
    
    ans[1]=ar[1].c;
    for(i=2;i<=n;i++){
        a.c=1001;
        a.h=ar[i].h-s;
        j= upper_bound(ar+1,ar+1+n,a,cmp) - ar - 1;
        pp *pj = upper_bound(ar+1,ar+1+n,a,cmp);
//        j = j - long(ar+1);
        if(ar[j].h>ar[i].h-s)
            ans[i]=ans[i-1];
        else{
            ans[i]=ans[j]+ar[i].c;
            if(ans[i]<ans[i-1])
                ans[i]=ans[i-1];
        }
    }
    
    printf("%d",ans[n]);
}
/***/