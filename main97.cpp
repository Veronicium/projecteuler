//
//  main.cpp
//  pe97
//
//  Created by You-know-who on 9/7/2017.
//  Copyright © 2017 You-know-who. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int64_t ans=28433;
    for (int i=1; i<=7830457; i++)
    {
        ans*=2;
        ans=ans%10000000000;
    }
    
        cout<<ans+1<<endl;
    
    return 0;
}
