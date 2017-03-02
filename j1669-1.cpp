/* 1669, with std::list
 
 영훈이가 소시지 공장에 견학을 갔다. 그 소시지공장에서는 하나의 기계가 길이와 너비가 다양한 소시지를 만들어 내고 있었다.
 
 유심히 살펴보니 그 기계는 현재 만들고 있는 소시지의 길이와 너비가 바로 전에 만들었던 소시지의 길이, 너비보다 크거나 같아야만 기계가 쉬지 않고 작동하고 있었다. 만약 현재 만들고 있는 소시지의 길이 또는 너비가 바로 전에 만든 것보다 작다면, 기계가 준비 작업을 하는데 1분이 소요된다는 것을 알았다.
 
 영훈이는 주문 받은 소시지의 길이와 너비를 보고 어떤 소시지부터 만들어 나가는 것이 기계의 준비 작업에 소요되는 시간을 줄일 수 있을지 고민하고 있다.
 
 주문받은 소시지들을 만드는데 기계가 준비 작업에 소요한 최소의 시간을 구하는 프로그램을 작성하시오.
 
 단, 첫 소시지를 만들 때는 기계의 준비작업 시간이 1분 소요된다.
 
 첫 줄에는 주문받은 소시지의 개수 N(1≤N≤5,000)이다.
 
 둘째 줄에는 소시지의 길이 SL과 소시지의 너비 SW가 N개의 쌍으로 나열된다.
 
 
 주문받은 소시지들을 만드는데 기계가 준비 작업에 소요한 최소의 시간을 출력한다.
 
 [Copy]
 5
 4 9 5 2 2 1 3 5 1 4
 [Copy]
 2
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <bitset>

using namespace std;

typedef unsigned long       ul;
typedef unsigned long long ull;

typedef std::pair<int,int>  ii;
typedef std::pair<int,ii>  iii;
typedef std::vector<int>    vi;
typedef std::vector<ii>    vii;
typedef std::vector<iii>  viii;
typedef vector<std::vector<int> >   vvi;

void print(vi s, string st="") {
    printf("%s", st.c_str());
    for (int i=0; i<s.size(); i++)
        printf ("%d ", s[i]);
    printf("\n");
}

void print (vvi s) {
    for (int i=0; i<s.size(); i++)
        print (s[i], to_string(i)+" : ");
    printf("\n----\n");
}

void print (vii& s) {
    for (int i=0; i<s.size(); i++)
        printf ("(%d,%d) ", s[i].first, s[i].second);
    printf ("\n");
}

int main()
{
    int N;
    cin >> N;
    int w, l;
    std::vector<ii> cs;
    for (int i=0; i<N; i++) {
        cin >> l >> w;
        
        cs.push_back(ii(l,w));
    }

    std::sort (cs.begin(), cs.end());
//    print (cs);
    
    vector<ii> q;
    vector<bool> used(N,false); // N <= 5000
    int t=1;
    int last = 0;
    
    while (1) {
        ii p = cs[last];
        q.push_back(p);
        used[last]=true;

        for (int k=last+1; k<N; k++)
            if ( (used[k]==false)
                && (p.first <= cs[k].first && p.second <= cs[k].second)) {
                //                    fprintf (stderr, "[%d:%d] (%d,%d) <= (%d,%d) ", last, k,
                //                            cs[last].first,cs[last].second,
                //                            cs[k].first,cs[k].second);
                last = k;
                p = cs[last]; // update the last
                q.push_back(cs[k]);
                used[k]=true;
            }
        
//        print (q);
        
        // check if finished.
        int i=0;
        while (i<N && used[i]==true)
            i++;
        
        if (i==N) break; // all done
        
        // another list
        t++;
        last = i;
        q.clear();
    }
    printf("%d\n", t);
    
    return 0;
}