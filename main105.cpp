//
//  main.cpp
//  pe105
//
//  Created by You-know-who on 21/6/2017.
//  Copyright © 2017 You-know-who. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

unsigned int factorial(unsigned int n)
{
    unsigned int retval = 1;
    for (int i = n; i > 1; --i)
        retval *= i;
    return retval;
}

bool test2(int m, int* data)
{
    int sum1, sum2;
    sum1=sum2=0;
    for (int i=0; i<=(m-1)/2; i++)
        sum1+=data[i];
    
    for (int i=(m+2)/2; i<m; i++)
        sum2+=data[i];
    
    if (sum1<=sum2) return 0;
    
    return 1;
}

bool test1(int n, int m, int* data,
           int* temp=NULL, int* history=NULL, int index=0 ,int cmn=0)
{
    //at first
    if (temp==NULL)
    {
        temp = new int[n];
        int sum=0;
        for (int i=0; i<n; i++)
        {
            temp[i]=i;
            sum+=data[i];
        }
        cmn = factorial(m)/factorial(n)/factorial(m-n);
        history = new int[cmn];
        history[index] = sum;
    }
    else
    {
    //update temp
        index++;
        if ( temp[n-1]!=m-1 )
        {
            temp[n-1]++;
        }
        else
        {
            for (int i=n-2; i>=0; i--)
            {
                //dont need to change the back
                if ( temp[i]==temp[i+1]-2 )
                {
                    temp[i]++;
                    break;
                }
                //need to move all the back terms
                if ( temp[i]<temp[i+1]-2 )
                   {
                       temp[i]++;
                       for (int j=i+1; j<n; j++)
                          temp[j]=temp[j-1]+1;
                       
                       break;
                   }
            }
        }
        int sum=0;
        for (int i=0; i<n; i++)
        {
            sum+=data[ temp[i] ];
        }
        history[index]=sum;
    /*
        cout<<index<<": ";
        for (int i=0; i<n; i++)
            cout<<temp[i]<<" ";
        cout<<endl;
    **/
        
    //bad end
        for (int i=0; i<index; i++)
            if ( history[index]==history[i] )
            {
                /*
                for (int i=0; i<n; i++)
                {
                    cout<<temp[i]<<" ";
                }
                cout<<endl;
                **/
                
                return 0;
            }
    }
    
    //happy end
    if ( temp[0]==m-n )
        return 1;
    
    //continue
    return test1(n, m, data, temp, history, index, cmn);

    return 0;
}

int len(string str, int length0)
{
    int length=1;
    for (int i=0; i<length0; i++)
        if (str[i]==',') length++;
    
    return length;
}

bool test(int* data, int m)
{
    if (!test2(m, data)) {  cout<<"no "<<"test2"<<endl; return 0;}
    for (int i=1; i<=m/2; i++)
        if ( !test1(i, m, data) ) { return 0;}
    
    return 1;
}

int su(int* data, int m)   //find sum
{
    int sum=0;
    for (int i=0; i<m; i++)
        sum+=data[i];
    return sum;
}

int* sorting(int* data, int m)
{
    int* sorted = new int[m];
    sorted[0]=data[0];
    
    for (int i=1; i<m; i++)
    {
        
        if ( data[i]>sorted[i-1] )
             sorted[i]=data[i];
        
        else
        for (int j=0; j<=i-1; j++)
        {
            if ( data[i]<sorted[j] )
            {
                for (int k=i; k>=j+1; k--)
                    sorted[k]=sorted[k-1];
                
                sorted[j]=data[i];
                break;
            }
        }
        
        
    }
    return sorted;
}

void pe106(int& ans, int n, int m)
{
    //at first
    int* temp = new int[n];

        for (int i=0; i<n; i++)
        {
            temp[i]=i;
        }
    
        int cmn = factorial(m)/factorial(n)/factorial(m-n);
        int index=0;
    
        int** history = new int* [cmn];
        for (int i=0; i<cmn; i++)
            history[i] = new int[n];
    
    while ( temp[0]!=m-n )
    {
    //update temp
        index++;
        if ( temp[n-1]!=m-1 )
        {
            temp[n-1]++;
        }
        else
        {
            for (int i=n-2; i>=0; i--)
            {
                //dont need to change the back
                if ( temp[i]==temp[i+1]-2 )
                {
                    temp[i]++;
                    break;
                }
                //need to move all the back terms
                if ( temp[i]<temp[i+1]-2 )
                {
                    temp[i]++;
                    for (int j=i+1; j<n; j++)
                        temp[j]=temp[j-1]+1;
                    
                    break;
                }
            }
        }

        
        for (int i=0; i<n; i++)
            history[index][i]=temp[i];
        
        //count need check
        for (int i=0; i<index; i++)
        {
            bool needcheck=0;   //assume all in history <= that in temp
            bool exist=1;
            for (int j=0; j<n; j++)
            {
                
                for (int k=0; k<n; k++)
                    if ( history[i][k] == temp[j] ) //不存在的
                    {
                        exist=0;
                        break;
                    }
                if (!exist) break;
            }
            
            if (exist)
            for (int j=0; j<n; j++)
            {

                if ( history[i][j] > temp[j] )
                {
                    needcheck=1;
                    break;
                }
                
            }
            
            if (needcheck==1)
            {
                for (int k=0; k<n; k++)
                    cout<<temp[k]<<" ";
                cout<<"<";

                for (int k=0; k<n; k++)
                    cout<<history[i][k]<<" ";
                cout<<endl;
                
                ++ans;
            }
            
        }
    }


}


//pe106


int main(int argc, const char * argv[]) {
    
    clock_t start, end;
    
    start = clock();
    
    //pe105
/*
    string w[100];
    int* data[100][2];
    int length[100], length0[100];
    int sum=0;
    
    //read
    ifstream myfile ("p105_sets.txt");
    if (myfile.is_open())
    {
        int s=0;
        while (getline(myfile, w[s]))
        {
            //basic things
            length0[s]=w[s].length();
            
            length[s]=len( w[s],length0[s] );
            cout<<s<<" "<<length[s]<<endl;
            
            //create int*
            data[s][0] = new int[ length[s] ];
            int index=0;
            
            for (int i=0; i<length[s]; i++) data[s][0][i]=0;
            
            for (int i=0; i<length0[s]; i++)
            {
                if ( w[s][i]==',' ) index++;
                else
                {
                    data[s][0][index]*=10;
                    data[s][0][index]+=w[s][i]-'0';
                }
            }
            
            //sort
            
            data[s][1]=sorting( data[s][0], length[s] );
            
            //check
            
            for (int i=0; i<length[s]; i++)
                cout<<data[s][0][i]<<" ";
            cout<<endl;
            
            for (int i=0; i<length[s]; i++)
                cout<<data[s][1][i]<<" ";
            cout<<endl;
            
            //test+sum
            
            if (test(data[s][1], length[s]))
            {
                int k=su(data[s][1], length[s]);
                cout<<"yes "<<sum<<" "<<k<<endl;
                sum+=k;
            }
            s++;
        }
        //cout<<s<<endl;
        cout<<"finished reading"<<endl;
        myfile.close();
    }
    else
    {
        cout << "Unable to open file"<<endl;
        return 5;
    }
    
    cout<<sum<<endl;
    
    //delete
    for (int i=0; i<100; i++)
    {
        delete[] data[i][0];
        delete[] data[i][1];
    }
**/
    //pe106
    
    int ans=0;
    
    for (int i=2; i<=6; i++)
        pe106(ans, i, 12);
    
    cout<<ans<<endl;
    
    end = clock();
    cout<<"Run time: "<<(double)(end - start) / CLOCKS_PER_SEC<<"S"<<endl;
    
    return 0;
}












