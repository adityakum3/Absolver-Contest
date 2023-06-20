/**
 * @file        Favourite-Candy.cpp
 * @author      Aditya Kumar 
 * @brief       You have 𝑁 different types of candies in which the 𝑖𝑡ℎ type of
 *              candy is available in the quantity of 𝑀𝑖 units, where 𝑖 
 *              varies from 1 to 𝑁. You are allowed to eat only one type of
 *              candy each day. Since you like some candies more than others,
 *              you give each type of candy a priority and eat the higher 
 *              priority-candies first. However, there is a limit to it that
 *              you cannot eat more than 𝐾 candies in one day (that is, you
 *              may eat 1 or 2 or 3, ... or 𝐾 candies in a day). Predict 
 *              whether you will be able to eat the 𝑥𝑡ℎ type of candy on the
 *              𝑦𝑡ℎ day.
 * @date        26 May, 2023
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    ll k;
    cin>>k;
    vector<ll >m(n);
    for(int i=0;i<n;i++)
    cin>>m[i];
    vector<ll>a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    vector<pair<ll,pair<ll,ll>>>v(n);
    for(int i=0;i<n;i++)
    {
        v[i].first =a[i];
        v[i].second.first = m[i];
        v[i].second.second = m[i]/k;
        if(m[i]%k!=0)
        v[i].second.second++;
    }
    sort(v.rbegin(),v.rend());
    vector<ll>pre(n);
    vector<ll>pre2(n);
    pre[0]=v[0].second.first;
    pre2[0]=v[0].second.second;
    for(int i=1;i<n;i++)
    {
        pre[i]=pre[i-1]+v[i].second.first;
        pre2[i]=pre2[i-1]+v[i].second.second;
    }
    ll q;
    cin>>q;
    while(q--)
    {
        ll x;
        cin>>x;
        ll y;
        cin>>y;
        auto it1 = lower_bound(pre.begin(),pre.end(),y);
        auto it2 = lower_bound(pre2.begin(),pre2.end(),y);
        if(it1==pre.end())
        {
            cout<<"NO"<<endl;
            continue;
        }
        else if(it2==pre2.end())
        {
            ll lp=v[it1-pre.begin()].first;
            if(lp >=a[x-1])
            cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;
        }
        else
        {
            ll lp=v[it1-pre.begin()].first;
            ll rp=v[it2-pre2.begin()].first;
            if(lp >=a[x-1]&&a[x-1]>=rp)
            cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;
        }
    }
}