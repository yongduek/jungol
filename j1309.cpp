//
//  1309.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 2. 2..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
unsigned long factorial (long n) {
    return (n==2? 2L : factorial(n-1)*(unsigned long)n);
}

int main()
{
    unsigned long n;
    std::cin >> n;
    unsigned long fac=1;
    for (unsigned long i=n; i>=2; --i) {
        printf ("%lu! = %lu * %lu!\n", i, i, i-1);
        fac *= i;
    }
    printf("1! = 1\n");
//    printf("%lu\n", factorial(n));
    printf("%lu\n", fac);
 
//    printf("ll=%d l=%d\n", sizeof(unsigned long), sizeof(long));
    
    return 0;
}