//
//  1161-hanoiTower.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 2. 2..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

void hanoi (int N, char src, char tmp, char dst)
{
    if (N==0) return;
    
    // 1. move disk 1~N-1 from SRC to TMP
    hanoi (N-1, src, dst, tmp);
    // 2. move disk N from SRC to DST
    printf ("move %d from %c to %c\n", N, src, dst);
//    printf ("%d : %d -> %d\n", N, src - 'A' + 1, dst - 'A' + 1);
    // 3. move disk 1~N-1 from TMP to DST
    hanoi (N-1, tmp, src, dst);
}

int main()
{
    int N;
    cin >> N;
    
    hanoi (N, 'A', 'B', 'C');
    
    return 0;
}
