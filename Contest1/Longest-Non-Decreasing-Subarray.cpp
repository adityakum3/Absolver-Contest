/**
* @file       Longest-Non-Decreasing-Subarray.cpp
*
* @brief      Find the length of the longest subarray whose elements are in
*             non-decreasing order.
*
* @author     Aditya Kumar
* @date       19 May, 2023
*
**/
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
    for(ll i=0;i<n;i++)
    cin>>v[i];
    ll l=1,m=1;
    for(int i=1;i<n;i++)
    {
        if(v[i]>=v[i-1])
        l++;
        else
        {
            m=max(m,l);
            l=1;
        }
    }
    cout<<max(m,l)<<endl;
}
//cout<<setprecision(15)