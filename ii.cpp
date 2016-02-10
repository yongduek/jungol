#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int visited[26][26];
int M[26][26];
int N;
int home = 0;
vector<int> homes;

const int di[] = { -1, 0, 0, 1 };
const int dj[] = { 0, 1, -1, 0 };

void dfs(int I, int J){
    cout << "DFS visits " << I << " " << J << endl;
    visited[I][J] = 1;
    for (int i = 0; i < 4; ++i){
        int ni = I + di[i];
        int nj = J + dj[i];
        if (ni<1 || ni>N || nj<1 || nj>N) continue;
        if (M[ni][nj] == 0) continue;

        if (!visited[ni][nj]){
            home++;
            dfs(ni, nj);
        }
    }
}


int main(){
    int component = 0;
    cin >> N;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= N; ++j){
            cin >> M[i][j];
        }
    }

    memset(visited, 0, sizeof(visited));

    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= N; ++j){
            if (!visited[i][j] && M[i][j]!=0){
                home = 1;
                dfs(i, j);
                component++;
                homes.push_back(home);
                cout << "call : " << component << endl;
            }
        }
    }
    sort(homes.begin(), homes.end());
    cout << component << endl;
    for (int i = 0; i < homes.size(); ++i){
        cout << homes[i] << endl;
    }
    return 0;
}

