//
//  array-vector-int.cpp
//  UVa-XCode
//
//  Created by Yongduek Seo on 2016. 3. 27..
//  Copyright © 2016년 Yongduek Seo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <array>

int main()
{
    std::array<std::vector<int>, 3> adjlist;
    
    int cnt=0;
    for (int k=0; k<adjlist.size(); k++) {
        for (int i=0; i<3; i++) {
            adjlist[k].push_back(cnt++);
        }
        std::cout << adjlist.size() << std::endl;
    }

    for (auto a:adjlist) {
        std::cout << ">> " ;
        for (int i=0; i<a.size(); i++) {
            std::cout << a[i] << ' ';
        }
        std::cout << std::endl;
    }

    std::array<bool, 5> table = {}; // initialize all to zero
    for (auto t:table)
        std::cout << t << ' ' ;
    std::cout << std::endl;
    
    return 0;
}
// EOF //
