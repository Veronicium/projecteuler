//
//  main.cpp
//  pe103
//
//  Created by You-know-who on 20/6/2017.
//  Copyright © 2017 You-know-who. All rights reserved.
//

#include <iostream>
#include <ctime>
using namespace std;

const int STEP=7;

bool judge(int n[])
{
    //ii
    if ( n[0]+n[1]+n[2]+n[3]<=n[4]+n[5]+n[6] ) return false;
    
    //i C(7,2)
    int sum[7][6];
    for (int i=0; i<7; i++)
        for (int j=0; j<6; j++)
            sum[i][j]=0;
    
    for (int i=0; i<6; i++)
        for (int j=i+1; j<7; j++)
        {
            sum[i][j]=n[i]+n[j];
            //cout<<n[i]<<"+"<<n[j]<<"="<<sum[i][j]<<endl;
            for (int k=0; k<i; k++)
                for (int l=k+1; l<7; l++)
                    if (sum[i][j]==sum[k][l]) return false;
        }
    
    //i C(7,3)
    
    int sum2[7][6][5];
    for (int i=0; i<7; i++)
        for (int j=0; j<6; j++)
            for (int k=0; k<5; k++)
            sum2[i][j][k]=0;
    
    for (int i=0; i<6; i++)
        for (int j=i+1; j<7; j++)
            for (int k=j+1; k<7; k++)
        {
            sum2[i][j][k]=n[i]+n[j]+n[k];
            //cout<<n[i]<<"+"<<n[j]<<"+"<<n[k]<<"="<<sum2[i][j][k]<<endl;
            for (int l=0; l<i; l++)
                for (int m=l+1; m<7; m++)
                    for (int n=m+1; n<7; n++)
                    if (sum2[l][m][n]==sum2[i][j][k]) return false;
        }

    
    return true;
}

int sa(int n[7])
{
    int sum=0;
    for (int i=0; i<7; i++)
        sum+=n[i];
    
    return sum;
}

bool ifsorted(int n[7])
{
    for (int i=0; i<6; i++)
        if (n[i]>=n[i+1]) return false;
    return true;
}

int main(int argc, const char * argv[]) {
    clock_t start, end;
    
    start = clock();
   
    const int opti[7]={18, 31, 38, 35, 40, 46, 47};
    int opti2[7]={20, 31, 38, 39, 40, 42, 45};
    int temp[7];
    //cout<<judge(opti2)<<" "<<sa(opti2)<<endl;
    int s=260;
    
    int change[7];
    
    for (change[0]=-STEP; change[0]<=STEP; change[0]++)
        for (change[1]=-STEP; change[1]<=STEP; change[1]++)
            for (change[2]=-STEP; change[2]<=STEP; change[2]++)
                for (change[3]=-STEP; change[3]<=STEP; change[3]++)
                    for (change[4]=-STEP; change[4]<=STEP; change[4]++)
                        for (change[5]=-STEP; change[5]<=STEP; change[5]++)
                            for (change[6]=-STEP; change[6]<=STEP; change[6]++)
                            {
                                for (int i=0; i<7; i++)
                                {
                                    temp[i]=opti[i]+change[i];
                                    //cout<<change[i]<<" ";
                                }
                                //cout<<endl;
                                
                                if ( !ifsorted(temp)) continue;
                                
                                //if ( sa(temp)<s)
                                  if ( judge(temp) )
                                  {
                                      s=sa(temp);
                                      cout<<s<<endl;
                                      for (int i=0; i<7; i++)
                                      {
                                          opti2[i]=temp[i];
                                          cout<<temp[i]<<" ";
                                      }
                                      cout<<endl;
                                  }
                            }
    for (int i=0; i<7; i++) cout<<opti2[i];
    cout<<endl;
    end = clock();
    cout<<"Run time: "<<(double)(end - start) / CLOCKS_PER_SEC<<"S"<<endl;
    return 0;
}






