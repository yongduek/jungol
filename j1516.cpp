//
//  1516.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 2. 2..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <bitset>
#include <sstream>

using namespace std;

typedef unsigned long       ul;
typedef unsigned long long ull;

typedef std::pair<int,int>  ii;
typedef std::pair<int,ii>  iii;
typedef std::vector<int>    vi;
typedef std::vector<ii>    vii;
typedef std::vector<iii>  viii;
typedef vector<std::vector<int> >   vvi;

int main()
{
    string s;
    while (std::getline(std::cin, s))
        {
        std:map<string,int> keyCount;
        std::stringstream ss (s);
        string astr;
        while (ss >> astr)
            {
            if (astr == string("END")) return 0;
            
            if (keyCount.find(astr) == keyCount.end())
                {
                keyCount[astr] = 1;
                }
            else
                keyCount[astr] ++;
            }
        for (auto it=keyCount.begin(); it!=keyCount.end(); ++it)
            printf ("%s : %d\n", it->first.c_str(), it->second);
        }
    
    return 0;
}