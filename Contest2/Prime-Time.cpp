/**
 * @file        Prime-Time.cpp
 * @author      Aditya Kumar
 * @brief       You are given two numbers L and R. A number is said to be
 *              lucky if the factors of that number are not repeated (power 
 *              to the factors can only be 1). For example, 2, 3, 5, 6 are 
 *              lucky numbers. while 4, 8, 9 are not. Determine the total 
 *              number of lucky numbers present in between 𝐿 and 𝑅 (inclusive).
 * @date        23 May, 2023
 */
#include "bits/stdc++.h"
using namespace std;
#define MAXN 5000001
int spf[MAXN];
int x[MAXN];
typedef long long ll;
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
    spf[i] = i;
    for (int i = 4; i < MAXN; i += 2)
    spf[i] = 2;
    for (int i = 3; i * i < MAXN; i++) 
    {
        if (spf[i] == i) 
        {
            for (int j = i * i; j < MAXN; j += i)
            {
                if (spf[j] == j)
                spf[j] = i;
            }
        }
    }
}
void fill()
{
    x[1]=0;
    for(int i=2;i<MAXN;i++)
    {
        if(spf[i]==i)
        x[i]=1;
        else
        {
            if((i/spf[i])%spf[i]==0)
            x[i]=0;
            else
            x[i]=x[i/spf[i]];
        }
    }
}
void sum()
{
    for(int i=1;i<MAXN;i++)
    x[i]+=x[i-1];
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    fill();
    sum();
    ll t;
    cin>>t;
    while(t--)
    {
        ll r,l;
        cin>>l>>r;
        cout<<x[r]-x[l-1]<<endl;
    }
}