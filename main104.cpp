//
//  main.cpp
//  pe104
//
//  Created by You-know-who on 5/6/2017.
//  Copyright © 2017 You-know-who. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

const int X=8000;

long produce(long a1, long a2)
{
    int i1=log10(a1);
    //cout<<i1<<endl;
    long i=a1*powl(10, 8-i1)+a2/powl(10,i1+1);
    
    return i;
}

bool ifpan(long a)
{
    int m[9];
    for (int i=0; i<9; i++)
    {
        m[i]=(int)(a/pow(10,8-i))%10 ;
        if ( m[i]==0 ) return false;
        //cout<<m[i];
        for (int j=0; j<i; j++)
            if ( m[j]==m[i] ) return false;
    }
    
    return true;
}

struct fibo
{
    long f[X];
};

int main(int argc, const char * argv[]) {
    
    
    cout<<"start"<<endl;
    fibo f1,f2,f3;
    bool carry=0;
    int pos2=0;
    for (int i=1; i<X; i++) f1.f[i]=f2.f[i]=f3.f[i]=0;
    int count=3;
    
    f1.f[0]=1;
    f2.f[0]=f3.f[0]=2;
    int i;

    while(pos2<X-1)
    {
    count++;
    carry=0;
        
    for (i=0; i<=pos2; i++)
    {
        if ((f1.f[i]+f2.f[i]+carry)/1000000000>0)
        {
            f3.f[i]=f1.f[i]+f2.f[i]+carry-1000000000;
            carry=1;
        }
        
        else
        {
            f3.f[i]=f1.f[i]+f2.f[i]+carry;
            carry=0;
        }
    }
        if(carry)
        {
            pos2++;
            f3.f[pos2]=1;
        }
        
        for (int i=0; i<=pos2+carry; i++)
        {
            f1.f[i]=f2.f[i];
            f2.f[i]=f3.f[i];
        }
        
        //cout<<count<<endl;
        //cout<<count<<" "<<pos2<<" "<<f3.f[0]<<" ";
        if (pos2>0)
        {
            if ( ifpan(f3.f[0]) )
                //cout<<count<<" "<<produce(f3.f[pos2], f3.f[pos2-1])<<" "<<f3.f[0]<<"last"<<endl;
               if (      ifpan(   produce(f3.f[pos2], f3.f[pos2-1])   )    )
                cout<<count<<" "<<produce(f3.f[pos2], f3.f[pos2-1])<<" "<<f3.f[0]<<"first"<<endl;
        }
    }
    cout<<"finished"<<endl;
    return 0;
}
