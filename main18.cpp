//
//  main.cpp
//  pe18
//
//  Created by You-know-who on 8/6/2017.
//  Copyright © 2017 You-know-who. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int max(int a, int b)
{
    if (a>b) return a;
    else return b;
}


int main(int argc, const char * argv[]) {
    
    const int ROW=100;
    
    string line;
    string w[ROW];
    int inp[ROW][ROW*3];
    int what[ROW][ROW];
    int ans[ROW][ROW];
    cout<<"start:"<<endl;

    for (int i=0; i<ROW; i++)
        w[i]="";
    
    //read
    ifstream myfile ("pe67.txt");
    if (myfile.is_open())
    {
        int s=0;
        while (getline(myfile, w[s]))
        {
          //cout<<s<<" "<<w[s]<<endl;
          s++;
        }
        cout<<"finished reading"<<endl;
        myfile.close();
    }
    else
    {
    cout << "Unable to open file"<<endl;
    return 5;
    }
    
    cout<<w[0]<<endl;
/*
    
    for (int i=0; i<ROW; i++)
    {
        string temp=w[i];
        //cout<<temp<<endl;
        
        for (int j=0; j<=3*i+2; j++)
        {
            {
                inp[i][j]=temp[j]-'0';
                //cout<<i<<" "<<j<<" "<<inp[i][j]<<endl;
                if (j%3==1) what[i][j/3]=inp[i][j]*10;
                if (j%3==2)
                {
                what[i][j/3]+=inp[i][j];
                //cout<<j/3<<" "<<what[i][j/3]<<"("<<inp[i][j-1]<<inp[i][j]<<") ";
                }
            }
        }
        //cout<<endl;
    }
    cout<<"finished processing"<<endl;
    ans[0][0]=59;
    
    
    for (int i=1; i<ROW; i++)
    {
        ans[i][0]=what[i][0]+ans[i-1][0];
        for (int j=1; j<i; j++)
        {
            ans[i][j]=what[i][j]+max(ans[i-1][j-1], ans[i-1][j]);
        }
        ans[i][i]=what[i][i]+ans[i-1][i-1];
    }

    for (int i=0; i<ROW; i++)
    {
        //for (int j=0; j<=i; j++)
        if (ans[99][i]>7000)
        cout<<ans[99][i]<<" ";
    }
     
**/
    return 0;
}







