/**
 * @file        The-Value-Of-An-Array.cpp
 * @author      Aditya Kumar
 * @brief       You are given the following: An array of numbers, A number 𝐾
 *              There are two types of values — value of an array and value 
 *              of a subarray. These values are defined as follows: The value 
 *              of an array is defined as the maximum value of all possible 
 *              subarrays of size 𝐾. The value of a subarray is defined as 
 *              the sum of all the distinct numbers raised to the power of 
 *              the frequency of that number in the subarray taking modulo 
 *              109+7. Determine the maximum value of the array.
 * @date        16 May, 2023
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
vector<ll>a(1000001);
ll mod = 1000000007;
ll pow(ll a, ll e)
{
    ll ans = 1;
    while(e)
    {
        if(e&1)
        ans = (ans*a)%mod;
        a = (a*a)%mod;
        e>>=1;
    }
    return ans;
} 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    ll k;
    cin>>n>>k;
    vector<ll>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    for(int i=0;i<k;i++)
    a[v[i]]++;
    ll s=0;
    for(ll i=1;i<1000001;i++)
    {
        if(a[i]>0)
        s=(s+((ll)pow(i,a[i]))%mod)%mod;
    }
    ll m = s;
    for(ll i=k;i<n;i++)
    {
        s=(s-((ll)pow(v[i-k],a[v[i-k]]))%mod)%mod;
        if(s<0)
        s+=mod;
        a[v[i-k]]--;
        if(a[v[i-k]]>0)
        s= (s+((ll)pow(v[i-k],a[v[i-k]]))%mod)%mod;
        if(a[v[i]]>0)
        s = (s - ((ll)pow(v[i],a[v[i]]))%mod)%mod;
        if(s<0)
        s+=mod;
        a[v[i]]++;
        s = (s + ((ll)pow(v[i],a[v[i]]))%mod)%mod;
        m = max(m,s);
    }
    cout<<m<<endl;
}