//
//  main.cpp
//  pe66
//
//  Created by Veronicium on 29/12/2017.
//  Copyright © 2017 You-know-who. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    
    long long ans[1000]={};
    
    int D;
    
    for ( D=8; D<=1000; D++ )
    {
        if (  abs(sqrt(D)-(int)sqrt(D))<0.001  ) continue;
        for ( long long y=1; y<=100000000; y++ )
        {
            long long x=(long long)(sqrt( 1+D*y*y ));
            if ( x*x-D*y*y==1)
            {
                ans[D-8]=x;
                break;
            }
            ans[D-8]=0;
            if (y==100000000) cout<<"unsolved"<<D<<" "<<endl;
        }
    }
    
    cout<<"D="<<D<<endl;
    
    //extract max;
    long long max=9;
    int answ=0;
    
    for (int i=0; i<D-8; i++)
    {
        cout<<i+8<<"     "<<ans[i]<<"     "<<endl;
        if (ans[i]>max) { max=ans[i]; answ=i+8;}
    }
    cout<<"max="<<max<<" D="<<answ<<endl;
    
    return 0;
}
