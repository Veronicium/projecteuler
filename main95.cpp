//
//  main.cpp
//  pe95
//
//  Created by You-know-who on 10/7/2017.
//  Copyright © 2017 You-know-who. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    
    //clock
    clock_t start, end1, end2, end3;
    start = clock();
    
    //violent

    int sum[1000000];
    bool picked[1000000]; //1:picked
    bool back[1000000];
    
    cout<<"start"<<endl;
    
    for (int j=1; j<1000000; j++)
    {
        sum[j]=1;
        picked[j]=0;
        back[j]=0;
        
    for (int i=2; i<=sqrt(j); i++)
        if (j%i==0) { sum[j]+=i; sum[j]+=j/i;}
        
    }
    end1 = clock();
    cout <<"+"<< (double)(end1 - start) / CLOCKS_PER_SEC <<"s"<< endl;
    
    //calculate length
 
    for (int i=1; i<1000000; i++)
    {
        //if (picked[i]) continue;

        int temp=sum[i];
        int now=1;
        
        while (temp!=i)
        {
            if (temp<=10) {now=0; break;}
            //cout<<temp<<" ";
            if (temp>1000000 || now>=150) {now=0; break;}
            now++;
            picked[temp]=1;
            temp=sum[temp];
        }
        if (now>=2) cout<<"step="<<now<<" num="<<i<<endl;
    }
    
    end2 = clock();
    cout <<"+"<< (double)(end2 - end1) / CLOCKS_PER_SEC <<"s"<< endl;
    /*
    int i=203034;
    int temp=sum[i];
    while (temp!=i)
    {
        cout<<temp<<" ";
        cout<<sum[temp]<<endl;
        temp=sum[temp];
        if (temp==1) return 5;
    }
    **/
    
    return 0;
}






