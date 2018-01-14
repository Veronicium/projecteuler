//
//  main.cpp
//  pe107
//
//  Created by Veronicium on 1/1/2018.
//  Copyright © 2018 You-know-who. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int extract_min(int* ori, int length, int& value)
//return the index of the min value
{
    int index=0;
    int temp=ori[0];
    
    for (int i=1; i<length; i++)
    {
        if ( ori[i]<temp )
        {
            temp=ori[i];
            index=i;
        }
    }
    value=temp;
    
    index=index%40;
    
    cout<<index<<endl;

    return index;
}

int main(int argc, const char * argv[]) {
    
    string w[40];
    int s=0;
    int dis[40][40];
    
    for (int i=0; i<40; i++)
        for (int j=0; j<40; j++)
            dis[i][j]=0;

    
    //read file
    ifstream myfile ("p107_network.txt");
    if (myfile.is_open())
    {
        while (getline(myfile,w[s]))
        {
            int k=0;
            for (int i=0; i<w[s].length(); i++)
            {
                if ( w[s][i]=='-' )
                { dis[s][k]=100000; continue; }
                
                if ( w[s][i]==',' )
                {k++; continue; }

                dis[s][k]=dis[s][k]*10 + w[s][i] - '0';
            }
            
            s++;
        }
    }
    
    //loop, find the max

    
    int total=0;
    for (int i=0; i<40; i++)
        for (int j=0; j<40; j++)
        {
            if ( dis[i][j]!=100000) total+=dis[i][j];
        }
    
    total=total/2;
    
    vector<int> ensure = {0};
    int ans = 0;
    
    while (ensure.size() < 40)
    {
        int k=ensure.size();
        int value=0;
        int temp[40*k];
        
        for (int j=0; j<k; j++)
          for (int i=0; i<40; i++)
          {
              temp[j*40+i]=dis[ensure[j]][i];
          }
        int next = extract_min( temp, 40*k, value);
        
        ensure.push_back(next);
        ans+=value;
        
        for (int i=0; i<k; i++)
        {
            dis[ensure[i]][next] = dis[next][ensure[i]]=100000;
        }
    }
    
    cout<<total-ans<<endl;
    
 
    
    //test read file
    /*
    for (int i=0; i<40; i++)
    {
        for (int j=0; j<40; j++)
            cout<<dis[i][j]<<" ";
        cout<<endl;
    }
     **/
    
    return 0;
}
