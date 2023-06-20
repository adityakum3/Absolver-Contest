/**
 * @file        Count-Triplets.cpp
 * @author      Aditya Kumar
 * @brief       You are given an array 𝐴 (comprising 𝑁 non-negative integers) 
 *              and an integer 𝐾. Find the number of triplets (𝑥,𝑦,𝑧), such 
 *              that all the following conditions are satisfied:
 *              1≤𝑥<𝑦<𝑧≤𝑁
 *              |𝐴𝑥−𝐴𝑦|≤𝐾
 *              |𝐴𝑦−𝐴𝑧|≤𝐾
 *              |𝐴𝑥−𝐴𝑧|≤𝐾
 *              where |𝑝| denotes the absolute value of 𝑝 and 𝐴𝑖 denotes 𝑖𝑡ℎ
 *              element of the array 𝐴. Print the count of such triplets. 
 *              Two triplets are considered to be same if all elements in 
 *              them are same.
 * @date        13 May, 2023
 * 
 * 
 */
#include <iostream>
#include<cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>
using namespace std;
typedef long long ll;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        vector<ll>v(n);
        for(int i=0;i<n;i++)
        cin>>v[i];
        sort(v.begin(),v.end());
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            vector<ll>::iterator it = upper_bound(v.begin(),v.end(),v[i]+k);
            ll x = it-v.begin()-1-i;
            //ll y = it1-v.begin()-2-i;
            ans+=((x)*(x-1))/2; 
        }
        cout<<ans<<endl;
    }
}