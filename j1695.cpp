/* 1695 : 단지번호붙이기
 제한시간: 1Sec    메모리제한: 64mb
 해결횟수: 736회    시도횟수: 2189회
 
 
 <그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다.
 
 철수는 이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다.
 
 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.
 
 efc6e5f9d670c6da62174cf11a66a8c2_1449731
 
 첫 번째 줄에는 지도의 크기 N(정사각형임으로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고,
 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.
 
 
 첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.
 
 [Copy]
 7
 0110100
 0110101
 1110101
 0000111
 0100000
 0111110
 0111000
 
 [Copy]
 3
 7
 8
 9

 20
 11101110011100000100
 00001000011111000001
 01100110010110010000
 10011011100010011001
 10101101110001100100
 01111111001000010001
 00010001101110011100
 10010100100110011101
 11111110111001111111
 10010111011110101011
 01110000101101000010
 01011010010110110001
 01000111101111111100
 01001111010010010110
 00110100001100111000
 00111010010100101100
 11101001100100100001
 11011000111011001111
 10001111111000001110
 11110010101001101100
 28
 1
 1
 1
 1
 1
 1
 1
 1
 1
 1
 1
 1
 2
 2
 2
 2
 2
 3
 3
 4
 4
 6
 10
 10
 12
 20
 33
 79

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

void print (vii& s, string st="") {
    if (!s.empty()) printf ("%s\n", st.c_str());
    for (int i=0; i<s.size(); i++)
        printf ("(%d,%d) ", s[i].first, s[i].second);
    printf ("\n");
}


int N; // max 25
int mat [25][25]; // max
bool visited[25][25] = {false};
int label[25][25] = {0};
int ngroup=0;
int members[26]={0};

void dfs (int r, int c) {
    label[r][c] = ngroup;
    members[ngroup]++;
    
    const int sr[] = {1, -1, 0, 0};
    const int sc[] = {0, 0, 1, -1};
    
    // check the neighbors
    for (int i=0; i<4; i++) {
        int rr = r + sr[i];
        int cc = c + sc[i];
        if (rr>=0 && cc>=0 && rr<N && cc<N
            && mat[rr][cc]
            && visited[rr][cc]==false) {
            visited[rr][cc]=true;
            dfs (rr,cc);
        }
    }
    
}



int main()
{
    char str[32];
    cin >> str;
    N = atoi (str);
    for (int i=0; i<N; i++) {
        cin >> str;
        for (int k=0; k<N; k++)
            if (str[k]=='0') mat[i][k]=0;
            else mat[i][k]=1;
    }
    
    for (int r=0; r<N; r++)
        for (int c=0; c<N; c++)
            if (mat[r][c] && visited[r][c]==false) {
                ++ngroup;
                
                visited[r][c] = true;
                dfs (r, c);
                
                //                for (int rr=0; rr<N; rr++) {
                //                    for (int cc=0; cc<N; cc++)
                //                        printf("%d", label[rr][cc]);
                //                    printf("\n");
                //                }
                //                printf("---\n");
            }
    printf("%d\n", ngroup);
    std::sort (members+1, members+ngroup+1);
    for (int i=1; i<=ngroup; i++)
        printf("%d\n", members[i]);
    
    return 0;
}

/*****
int N; // max 25
int mat [25][25]; // max
bool visited[25][25] = {false};
int label[25][25] = {0};
int ngroup=0;
int members[26]={0};

void bfs (std::deque<ii>& q) {
    ii node = q.front();
    q.pop_front();
    int r=node.first, c=node.second;
    label[r][c] = ngroup;
    members[ngroup]++;
    
    int sr[] = {1, -1, 0, 0};
    int sc[] = {0, 0, 1, -1};
    
    // check the neighbors
    for (int i=0; i<4; i++) {
        int rr = r + sr[i];
        int cc = c + sc[i];
        if (rr>=0 && cc>=0 && rr<N && cc<N
            && mat[rr][cc]
            && visited[rr][cc]==false) {
            visited[rr][cc]=true;
            q.push_back(ii(rr,cc));
        }
    }
    
    while (!q.empty()) {
        bfs (q);
    }
}



int main()
{
    char str[32];
    cin >> str;
    N = atoi (str);
    for (int i=0; i<N; i++) {
        cin >> str;
        for (int k=0; k<N; k++)
            if (str[k]=='0') mat[i][k]=0;
            else mat[i][k]=1;
    }

    for (int r=0; r<N; r++)
        for (int c=0; c<N; c++)
            if (mat[r][c] && visited[r][c]==false) {
                ++ngroup;
                
                std::deque<ii> q;
                visited[r][c] = true;
                q.push_back (ii(r,c));
                bfs (q);

//                for (int rr=0; rr<N; rr++) {
//                    for (int cc=0; cc<N; cc++)
//                        printf("%d", label[rr][cc]);
//                    printf("\n");
//                }
//                printf("---\n");
            }
    printf("%d\n", ngroup);
    std::sort (members+1, members+ngroup+1);
    for (int i=1; i<=ngroup; i++)
        printf("%d\n", members[i]);
    
    return 0;
}
***/