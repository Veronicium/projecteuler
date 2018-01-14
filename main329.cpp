//
//  main.cpp
//  pe329
//
//  Created by You-know-who on 29/5/2017.
//  Copyright © 2017 You-know-who. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

bool ifP[500];


bool isPrime(int x)
{
    if (x==1) return false;
    if (x==2 || x==3) return true;
    for (int i=2; i<=sqrt(x); i++)
        if (x%i==0) return false;
    
    return true;
}

void create(int x,  long& totalprob, long long prob, int depth=1, int count=0)
{
    
    //calculate prob
    if (depth==5 || depth==6 || depth==10 || depth==13 || depth==15)
    {
        if (!isPrime(x-1)) prob*=2;
    }
    
    else if (isPrime(x-1)) prob*=2;
    
    //if (depth==0) prob=1;
    
    if (depth==15) {totalprob+=prob;  return;}
    
    if (x==1 || x==500) {prob*=2; count++;}
    if (x!=1) create(x-1, totalprob,  prob, depth+1,count);
    if (x!=500) create(x+1,  totalprob, prob, depth+1,count);
}



int main(int argc, const char * argv[]) {
    
    ifP[0]=ifP[3]=false;
    ifP[1]=ifP[2]=true;

    for (int i=5; i<500; i++)
    {
        if (isPrime(i)) ifP[i-1]=true;
        else ifP[i-1]=false;
    }
    
    //for (int i=1; i<=500; i++) cout<<i<<" "<<ifP[i-1]<<endl;
    
    //now start

    long totalprob[500];
    for (int i=0; i<500; i++) totalprob[i]=0;
    
    for (int i=1; i<=500; i++)
        create(i, totalprob[i-1], 1);
    
    long long T=0, A=0;

    for (int i=0; i<500; i++)
    {
        T+=totalprob[i];
        cout<<i+1<<" "<<totalprob[i]<<endl;
    }
    cout<<T<<endl;
    
    int m=15, n=16, o=3;
    
    while(T%3==0 && m!=0) {T=T/3; m--;}
    while(T%2==0 && n!=0) {T=T/2; n--;}
    while(T%5==0 && o!=0) {T=T/5; o--;}

    long long s=pow(3,m);
    long long r=pow(2,n);
    long long t=pow(5,o);

    cout<<T<<"/("<<s<<"*"<<r<<"*"<<t<<")"<<endl; // /3^15*2^14*500 = 3^15*2^16*5^3
    
    return 0;
}








