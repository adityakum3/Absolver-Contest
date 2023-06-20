/**
 * @file        Two-Divisors.cpp
 * @author      Aditya Kumar
 * @brief       You are given an integer 𝑁. Your task is to find out how many
 *              numbers (denoted by 𝑋) exist for the given 𝑁 such that 1≤𝑋≤𝑁
 *               and the number of divisors of 𝑋 is a power of 2.
 * @date        19 May, 2023
 * 
 * 
 */
#include <iostream>
#include<cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <string>
#include <set>
using namespace std;
typedef long long ll;
#define MAXN   1000001
ll spf[MAXN];
ll no[MAXN];
ll sumi[MAXN];
vector<set<pair<ll,ll> > >v(MAXN);
void sieve()
{
    spf[1] = 1;
    for (ll i=2; i<MAXN; i++)
    spf[i] = i;
    for (ll i=4; i<MAXN; i+=2)
    spf[i] = 2;
    for (ll i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (ll j=i*i; j<MAXN; j+=i)
            {
                if (spf[j]==j)
                spf[j] = i;
            }
        }
    }
}
void number()
{
    for(ll i=1;i<MAXN;i++)
    {
        if(spf[i]==i)
        {
            no[i]=2;
            v[i].insert(make_pair(i,1));
        }
        else
        {
            v[i]=v[i/spf[i]];
            set<pair<ll,ll> >::iterator it=v[i].lower_bound(make_pair(spf[i],0));
            if(it->first==spf[i])
            {
                v[i].insert(make_pair(spf[i],it->second+1));
                no[i]=no[i/spf[i]]/(it->second+1)*(it->second+2);
                v[i].erase(*it);
            }
            else
            {
                v[i].insert(make_pair(spf[i],1));
                no[i]=no[i/spf[i]]*2;
            }
        }
    }
}
void fill()
{
    sumi[0]=0;
    for(int i=1;i<MAXN;i++)
    {
        if((ll)(pow(2,(ll)(log2(no[i]))))==no[i])
        sumi[i]=sumi[i-1]+1;
        else
        sumi[i]=sumi[i-1];
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    number();
    fill();
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        cout<<sumi[n]<<" ";
    }
}
//cout<<setprecision(15)