/* 1370
 
 회의실이 하나 있다. 여러 회의들이 시작시간과 종료시간이 예약되어 있으며, 시간대가 겹치는 회의는 동시에 개최가 불가능하다. 따라서 같은 시간대에 속하는 회의들 중 하나만 개최하고 나머지 회의들은 버려야한다.
 
 단, 종료시간과 시작시간이 같은 경우에는 시간이 겹친다고 말하지 않는다. 회의의 개수 N과 각 회의의 시작시간, 종료시간이 주어졌을 때 되도록 많은 회의를 개최하고자 한다.
 회의를 최대한 많이 배정하는 프로그램을 작성하시오.
 
 첫줄에는 회의의 수 N(5≤N≤500), 둘째 줄부터 i-1번 회의의 번호와 시작시간과 종료시간이 차례로 주어진다. (500 이하의 정수)
 
 
 첫줄에는 배정 가능한 최대의 회의수를 출력하고 다음 줄부터는 배정한 회의의 번호를 시간대순으로 출력한다. 만약, 답이 여러 가지(최대회의수가 될 수 있는 배정 방법이 여러가지)라면 그 중 아무거나 하나 출력한다.

 sol:
 끝나는 시간을 기준으로 정렬, 큐의 마지막 것의 끝나는 시간이후에 가능한 회의시간을 순차적으로 고른다.
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
#include <algorithm>

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


int main()
{
    int N;
    cin >> N;
    int id[N], s[N], e[N];
    viii cs;
    for (int i=0; i<N; i++) {
        cin >> id[i] >> s[i] >> e[i];
        
        cs.push_back(iii(e[i], ii(s[i],id[i])));
    }
    std::sort (cs.begin(), cs.end());
    
//    for (int i=0; i<cs.size(); i++)
//        printf("(%d %d) ", cs[i].first, cs[i].second.first);
//    printf("\n");
    
    viii sel;
    sel.push_back(cs[0]);
    
    for (int i=1; i<cs.size(); i++) {
        if (cs[i].second.first/*start time*/ >= sel.back().first/*end time*/)
            sel.push_back(cs[i]);
    }
    
    printf("%d\n", sel.size());
    for (int i=0; i<sel.size(); i++)
        printf("%d ", sel[i].second.second);
    printf("\n");
    
//    printf("(%d: %d %d)", sel[i].second.second, sel[i].second.first, sel[i].first);
    return 0;
}