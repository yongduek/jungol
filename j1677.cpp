//
//  j1677.cpp
//  경로찾기
//
//  Created by Yongduek Seo on 2016. 5. 20..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define max2(a,b)((a>b)?a:b)
#define max3(a,b,c) max2(a,max2(b,c))

struct Solve1 {
#define MAX 10000
#define max4(a,b,c,d) max2(a,max3(b,c,d))
    FILE* infile ;
    int n,table[2][3][MAX] ; // 0 : UP 1 : LEFT 2 : RIGHT
    
    void test_output(int t) {
        int i ;
        for(i=0 ; i<n ; i++)
            printf(" (%3d,%3d,%3d)",table[t][0][i],table[t][1][i],table[t][2][i]);
        printf("\n");
    }
    
    int process() {
        infile = stdin;
        fscanf(infile,"%d",&n); // 행렬크기를 읽어들인다.
        
        int i,j,turn=0,current_line[MAX] ;
        fscanf(infile,"%d",&current_line[0]);
        // 왼쪽 맨위 초기화한다.
        table[turn][0][0] =table[turn][1][0] =table[turn][2][0] = current_line[0] ;
        
        for(j=1 ; j<n ;j++){
            fscanf(infile,"%d",&current_line[j]); // 가장 위쪽
            
            table[turn][0][j] = table[turn][1][j] = table[turn][2][j] = current_line[j]+table[turn][1][j-1] ;
            
        }
        //test_output(turn);
        for(i=1 ; i<n ; i++) {
            turn = 1- turn ;
            for(j=0 ; j<n ;j++)fscanf(infile,"%d",&current_line[j]);
            
            for(j=0 ; j<n ;j++)
                table[turn][0][j] = current_line[j]+max3(table[1-turn][0][j],table[1-turn][1][j],table[1-turn][2][j]);
            
            table[turn][1][0] = table[turn][0][0];
            for(j=1 ; j<n; j++)
                table[turn][1][j] = current_line[j]+max2(table[turn][1][j-1],table[turn][0][j-1]);
            
            table[turn][2][n-1] = table[turn][0][n-1] ;
            for(j=n-2 ; j>=0 ;j--)
                table[turn][2][j]= current_line[j]+max2(table[turn][2][j+1],table[turn][0][j+1]);
            //test_output(turn);
        }
        return max3(table[turn][0][n-1],table[turn][1][n-1],table[turn][2][n-1]) ;
    }
} solve1;

const int maxn = 1010; // max array size
const int MAX_A = 10000; // max value of any element in the array

int n, table[maxn][maxn], arr[maxn][maxn];
int sum[maxn][maxn] = {};
int ltab[maxn][maxn];
int rtab[maxn][maxn];

enum Direction {UP, LEFT, RIGHT, NONE};
char dir[] =   {'U', 'L', 'R',  'N' };
int prev[maxn][maxn]; // previous location indicator, debug
int upIndx[maxn][maxn]; // debug


struct BottomUp {
    void readInput() {
        scanf ("%d", &n);
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++) {
                scanf("%d", & arr[i][j]);
                ltab[i][j]=-1; // not determined
                rtab[i][j]=-1;
                // integral along the column
                sum[i][j] = j==0? arr[i][j] : sum[i][j-1] + arr[i][j];
            }
    }
    
    int solve () {
        readInput();
        
        // first row. The only way to move right is from let to right.
        int r=0;
        for (int c=0; c<n; c++) table[r][c] = c==0? arr[r][c] : arr[r][c] + table[r][c-1];
        
        int lp[maxn], rp[maxn]; // for debug & display
        for (r = 1; r<n; r++) {
            // make ltab, rtab
            int ltab[maxn]={}, rtab[maxn]={};
            { // compute l-table
                int c=0;
                ltab[c] = -MAX_A; // no left exists for c=0
                lp[c] = -1;
                ++c; ltab[c] = table[r-1][0] + arr[r][0]; // initial value
                lp[c] = c-1;
                for (++c; c<n; ++c) {
                    ltab[c] = arr[r][c-1] + max2(ltab[c-1], table[r-1][c-1]);
                    lp[c] = (ltab[c-1] > table[r-1][c-1]) ? lp[c-1] : c-1;
                }
            }
            { // compute r-table
                int c=n-1; //
                rtab[c] = -MAX_A; // no right
                rp[c]=-1; // no right exists
                --c; rtab[c] = table[r-1][c+1] + arr[r][c+1]; // the first right value at the index c-2
                rp[c] = c+1;
                for (--c; c>=0; --c) {
                    rtab[c] = arr[r][c+1] + max2(rtab[c+1], table[r-1][c+1]);
                    rp[c] = (rtab[c+1]>table[r-1][c+1])? rp[c+1]: c+1;
                }
            }
            
            // compute the table
            for (int c=0; c<n; c++) {
                table[r][c] = arr[r][c] + max3(ltab[c], rtab[c], table[r-1][c] /* up */);
                
                if (0) { // debug
                    if (ltab[c] == max3(ltab[c], rtab[c], table[r-1][c]))
                        prev[r][c] = LEFT, upIndx[r][c]=lp[c];
                    else if (rtab[c] == max3(ltab[c], rtab[c], table[r-1][c]))
                        prev[r][c] = RIGHT, upIndx[r][c]=rp[c];
                    else if (table[r-1][c] == max3(ltab[c], rtab[c], table[r-1][c]))
                        prev[r][c] = UP, upIndx[r][c]=c;
                    else
                        prev[r][c] = NONE, upIndx[r][c]=-1;
                }
            }
        }
        return table[n-1][n-1];
    }
} bottomUp;


int main()
{
    fprintf(stdout,"%d\n", bottomUp.solve());

    if (0) {
        for (int r=0; r<n; r++) {
            for (int c=0; c<n; c++)
                printf("%+5d  ", table[r][c]);
            printf("\n");
        }
        printf("----\n");
        for (int r=0; r<n; r++) {
            for (int c=0; c<n; c++)
                printf("%c%d  ", dir[prev[r][c]], upIndx[r][c]);
            printf("\n");
        }
    }
    return 0;
}
/**
 Input Data
 10
 -50 6 -28 -96 -36 73 69 -48 82 6
 65 -51 41 58 -5 -41 -21 -22 -97 79
 -91 94 -54 -27 59 -64 94 50 20 53
 82 -79 -20 24 -33 -89 -45 33 94 -32
 46 -36 -78 -42 -95 48 -87 -94 50 47
 42 -76 -69 -99 15 91 41 93 -18 -96
 -20 85 74 5 -68 0 -79 80 -84 -45
 61 -85 -9 73 17 1 62 -2 -6 -14
 18 -82 92 57 10 -32 20 -90 -34 -89
 49 -74 94 77 -82 -59 87 33 -93 -46
 
 
 CPU Result
 997
 **/
// eof - 1677 경로찾기 끝 //