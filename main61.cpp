//
//  main.cpp
//  pe61
//
//  Created by You-know-who on 16/7/2017.
//  Copyright © 2017 You-know-who. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <ctime>

using namespace std;
/*
 0 88
 1 53
 2 47
 3 44
 4 40
 5 30
**/

bool check(int n)
{
    if (n%100 <=99  && n%100 >=10)
        if (n/100 <=99  && n/100 >=10)
            return true;
    
    return false;
}

void printset(set<int> se)
{
    for(set<int>::iterator it=se.begin(); it!=se.end(); it++ )
        cout<<*it<<" ";
    cout<<endl;
}

void pick(const int init, int temp, int start, int end, const vector<int> num[6],
         set<int> left, const int count[6], vector<int> ans)
{
    if (left.size()==1)
    {
        int temp2=*left.begin();
        for (int i=0; i<count[temp2]; i++)
        {
            if ( num[temp2][i]%100 == init/100 )
                if ( num[temp2][i]/100 == temp%100 )
                {
                    ans.push_back(num[temp2][i]);
                    for (int j=0; j<6; j++)
                        cout<<ans[j]<<" ";
                    cout<<endl;
                    return;
                }
        }
        //cout<<init<<" last step failed"<<endl;
        return;
    }
    
    for (int i=0; i<=4; i++)
    {
        if (left.count(i)==0) continue;
        for (int j=0; j<count[i]; j++)
        {
            if ( num[i][j]/100 == start || start ==0 )
                if ( num[i][j]%100 == end || end ==0 )
                {
                    left.erase(i);
                    
                    //cout<<num[i][j]<<"     ";
                    //printset(left);
                    ans.push_back( num[i][j] );
                    pick(init, num[i][j], num[i][j]%100, 0, num, left, count, ans);
                    
                    left.insert(i);
                    ans.pop_back();
                    
                }
        }
    }
    
    //cout<<"fail"<<endl;
    return;
}

int main(int argc, const char * argv[]) {
    
    clock_t start, end;
    
    
    start = clock();

    
    vector<int> num[6];
    int count[6]={0,0,0,0,0,0};
    
    //create the basetable
    for (int i=19; i<141; i++)
    {
        int t3=i*(i+1)/2;
        if ( check(t3) )
        {
            num[0].push_back(t3);
            count[0]++;
        }
        
        int t4=i*i;
        if (check(t4))
        {
            num[1].push_back(t4);
            count[1]++;
        }
        
        int t5=i*(3*i-1)/2;
        if (check(t5))
        {
            num[2].push_back(t5);
            count[2]++;
        }
        int t6=i*(2*i-1);
        if (check(t6))
        {
            num[3].push_back(t6);
            count[3]++;
        }
        int t7=i*(5*i-3)/2;
        if (check(t7))
        {
            num[4].push_back(t7);
            count[4]++;
        }
        int t8=i*(3*i-2);
        if (check(t8))
        {
            num[5].push_back(t8);
            count[5]++;
        }
    }


    //start looping

    for (int i=0; i<count[5]; i++)
    {
        int start=num[5][i];
        
        //cout<<i<<" start="<<start<<endl;
        
        set<int> left={0,1,2,3,4};
        vector<int> ans;
        ans.push_back(start);
        pick(start, start, start%100, 0, num, left, count, ans);
    }

    end = clock();
    
    
    cout <<"+"<< (double)(end - start) / CLOCKS_PER_SEC <<"s"<< endl;
    return 0;
}














