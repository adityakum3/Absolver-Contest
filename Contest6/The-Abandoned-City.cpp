/**
 * @file        The-Abandoned-City.cpp
 * @author      Aditya Kumar
 * @brief       You bought a virtual reality glasses. There is only one game 
 *              installed to it called "The Abandoned City". You are lost in 
 *              an abandoned city. In order to escape, You have to pay a 
 *              number of golden coins. So, you decided to collect the gold 
 *              in the houses of that city. The city contains many houses 
 *              aligned in a straight line. Each house contains a specific 
 *              amount of golden coins. You need to figure out the shortest 
 *              distance you have to walk until you collect the needed amount 
 *              of golden coins to get out.
 * @date        16 May, 2023
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
using namespace std;
typedef long long ll;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    ll k;
    cin>>k;
    ll s=0;
    ll m =0;
    ll i;
    for(i=0;i<n;i++)
    {
        s+=v[i];
        m++;
        if(s>=k)
        break;
    }
    if(i==n)
    {
        cout<<-1;
        return 0;
    }
    ll j=0;
    ll p=m;
    while(s-v[j]>=k)
    {
        s-=v[j];
        j++;
        m--;
    }
        p=min(p,m);
    for(i=i+1;i<n;i++)
    {
        s+=v[i];
        m++;
        while(s-v[j]>=k)
        {
            s-=v[j];
            j++;
            m--;
        }
        p=min(p,m);
    }
    cout<<p;
}