//
//  main.cpp
//  pe83
//
//  Created by You-know-who on 22/6/2017.
//  Copyright © 2017 You-know-who. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <cmath>
#include <sstream>

#define ROW 80
#define COL 80

using namespace std;

int main(int argc, const char * argv[]) {

    /*
    //read file
    clock_t s,e;
    s=clock();
    int data[80][80];
    ifstream f("p083_matrix.txt");
    string line;
    int i = 0;
    while (getline(f,line)){
        istringstream ss( line );
        string s; int j = 0;
        while (getline(ss, s, ','))
            data[i][j++]=stoi(s);
        ++i;
    }

    vector<bool> off(6400,0);  //0=on the ground
    vector<int> dist(6400,100000000);
    off[0]=1;
    dist[0]=data[0][0];
    
    while ( true )
    {
        if (off[6399]==1) break;
        
    for (int i=0; i<6400; i++)
      {
        if (off[i])
         {
             if ( i%80!=0 ) {int k=data[i/80][i%80-1]+dist[i];  if (dist[i-1]>k) dist[i-1]=k;  }
            if ( (i+1)%80!=0 ) {int k=data[i/80][i%80+1]+dist[i];  if (dist[i+1]>k) dist[i+1]=k;  }
            if ( i>80 ) {int k=data[i/80-1][i%80]+dist[i];  if (dist[i-80]>k) dist[i-80]=k;  }
            if ( i<6400-80 ) {int k=data[i/80+1][i%80]+dist[i];  if (dist[i+80]>k) dist[i+80]=k;  }
         }
      }
    
    int temp=0; //index
    int min=100000000;
    int i=0;
        
    for (int i=0; i<6400; i++)
    {
        if (dist[i]<100000000)
            if ( !off[i] )
                if ( dist[i]<min )
                { temp=i;  min=dist[i];}
    }
      off[temp]=1;
      //cout<<temp<<endl;
    }
    
    cout<<endl;
    
    cout<<"result: "<<dist[6399]<<endl;
    e=clock();
    cout<<(double)(e-s)/CLOCKS_PER_SEC<<endl;
    **/
    
    //read file
    clock_t s,e;
    s=clock();
    int data[ROW][COL];
    ifstream f("p083_matrix.txt");
    string line;
    int i = 0;
    while (getline(f,line)){
        istringstream ss( line );
        string s; int j = 0;
        while (getline(ss, s, ','))
            data[i][j++]=stoi(s);
        ++i;
    }
    //dijkstra
    int res = 0;
    priority_queue<    pair<int, int>,
    vector<  pair<int, int>   > ,
    greater<  pair<int, int>  >      > q;
    
    vector<int> dist(ROW*COL, INT_MAX);
    q.push(make_pair(0, 0));
    dist[0] = data[0][0];
    while (!q.empty()){
        int u = q.top().second;
        q.pop();
        //find target
        if (u==ROW*COL-1) {
            res=dist[u];
            break;
        }
        //build adjacent node list
        vector<int> adj_list;
        if (u%COL!=0) adj_list.push_back(u-1);
        if (u%COL!=COL-1) adj_list.push_back(u+1);
        if (u/COL!=0) adj_list.push_back(u-COL);
        if (u/COL!=ROW-1) adj_list.push_back(u+COL);
        //update distance to origin
        for (auto v: adj_list)
            if (dist[v] > dist[u] + data[v/COL][v%COL]){
                dist[v] = dist[u] + data[v/COL][v%COL];
                q.push(make_pair(dist[v], v));
            }
    }
    cout<<"result: "<<res<<endl;
    e=clock();
    cout<<(double)(e-s)/CLOCKS_PER_SEC<<endl;

    
    return 0;
}












