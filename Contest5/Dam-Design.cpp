/**
 * @file        Dam-Design.cpp
 * @author      Aditya Kumar
 * @brief       Your company is designing a dam to be built across a stream 
 *              to create a small lake. To reduce materials cost, it will be 
 *              made of one or more concrete walls with mud packed in between 
 *              them. Determine the maximum height of the mud segments in the 
 *              dam with the following restrictions: One unit width of the 
 *              gap between walls will contain one segment of packed mud. The
 *              height of mud in a segment cannot exceed 1 unit more than an 
 *              adjacent wall or mud segment. Given the placement of a number 
 *              of walls and their heights, determine the maximum height of a 
 *              mud segment that can be built. If no mud segment can be built, 
 *              output 0.
 * @date        15 May, 2023
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
    vector<pair<ll,ll> >v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first;
    }
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>v[i].second;
    }
    ll ma = 0;
    sort(v.begin(),v.end());
    for(int i=1;i<n;i++)
    {
        ll m = v[i].first-v[i-1].first-1;
        if(m==0)
        continue;
        ll x = min(v[i].second,v[i-1].second);
        ll y = max(v[i].second,v[i-1].second);
        if(x+m<=y)
        {
            ma = max(ma,x+m);
        }
        else
        {
            ll k = y+m-x;
            if(k%2==0)
            ma=max(ma,x+k/2);
            else
            ma = max(ma,x+k/2+1);
        }
    }
    cout<<ma<<endl;
}