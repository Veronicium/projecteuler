//
//  main.cpp
//  pe71
//
//  Created by You-know-who on 8/6/2017.
//  Copyright © 2017 You-know-who. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int p=20;
    int q=49;
    
    for (int i=50; i<1000000; i++)
    {
        int now=i*3/7;
        if (p*i<now*q && 7*now<3*i)
        {
            p=now;
            q=i;
        }
    }
    
    cout<<p<<" "<<q<<endl;
    
    return 0;
}
