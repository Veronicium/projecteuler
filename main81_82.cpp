//
//  main.cpp
//  pe81
//
//  Created by You-know-who on 23/6/2017.
//  Copyright © 2017 You-know-who. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {

    clock_t s,e;
    s=clock();
    
    int data[80][81];
    
    //read file
    ifstream f("p082_matrix.txt");
    string line;
    int i = 0;
    while (getline(f,line)){
        istringstream ss( line );
        string s; int j = 0;
        while (getline(ss, s, ','))
            data[i][j++]=stoi(s);
        ++i;
    }
    
    //pe81
/*
    //setup
    int dist[80][80];
    dist[0][0]=data[0][0];
    for (int i=1; i<80; i++)
    {
        dist[0][i]=data[0][i]+dist[0][i-1];
        dist[i][0]=data[i][0]+dist[i-1][0];
    }
    
    //dp
    for (int i=1; i<80; i++)
    {
        for (int j=1; j<i; j++)
        {
            dist[i][j]=data[i][j] + min( dist[i-1][j], dist[i][j-1] );
            dist[j][i]=data[j][i] + min( dist[j-1][i], dist[j][i-1] );
        }
        dist[i][i]= data[i][i] + min( dist[i-1][i], dist[i][i-1] );
    }
    cout<<"w "<<dist[79][79]<<endl;
**/
    
    //pe82
    
    //setup
    int dist[80][81];
    for (int i=0; i<80; i++)
    {
        dist[i][0]=data[i][0];
        data[i][80]=0;
    }
    
    //dp
    
    for (int i=0; i<81; i++)
        cout<<data[79][i]<<" ";
    cout<<endl;
    
    for (int i=1; i<81; i++)
    {
        
        for (int j=0; j<80; j++)
        {
            int temp;
            int min=100000000;
            for (int k=0; k<80; k++)
            {
                temp=dist[k][i-1]+data[j][i];
                
                for (int l=k; l<j; l++)
                     temp+=data[l][i];
                
                for (int l=k; l>j; l--)
                    temp+=data[l][i];
                
                if ( temp<min )  min=temp;
                
            }
            
            dist[j][i]=min;
        }
        
    }

    cout<<"result="<<dist[0][80]<<endl;
    e=clock();
    cout<<(double)(e-s)/CLOCKS_PER_SEC<<endl;
    
    return 0;
}
