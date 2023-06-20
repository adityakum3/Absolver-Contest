/**
 * @file        Load-Balancing.cpp
 * @author      Aditya Kumar
 * @brief       A developer created a web application that solves a very 
 *              difficult mathematical equation. As the computational load 
 *              of the incoming requests to the application server may be 
 *              very heavy, it was decided to scale the application using 
 *              multiple servers so that multiple requests can be handled 
 *              simultaneously. No two requests come at the exact same time, 
 *              and they are assigned to the next server which is not busy. 
 *              Servers are allocated to requests in round robin fashion 
 *              starting from the first server. If a server is busy, it is 
 *              skipped. If no server is free, then the request is dropped, 
 *              i.e. not handled at all. The servers have infinite 
 *              computational capacity, so each server can serve any incoming 
 *              request. At the end of the day, the developer takes down the 
 *              busiest server that day for maintenance. Determine which 
 *              server did the most computational work during the day. If 
 *              there is a tie for the most work, return the list of servers 
 *              sorted in ascending order of server id.
 * @date        17 May, 2023
 */
#include <iostream>
#include<cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <string>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll k,n;
    cin>>k>>n;

    vector<pair<ll,ll> >a(n);
    for(int i=0;i<n;i++)
    cin>>a[i].first;
    cin>>n;

    for(int i=0;i<n;i++)
    cin>>a[i].second;

    sort(a.begin(),a.end());
    set<ll>s;
    for(int i=0;i<k;i++)
    s.insert(i);
    vector<ll>ans(k,0);
    ll ind =0;
    set<pair<ll,ll> >st;
    for(int i=0;i<n;i++)
    {
        if(!st.empty())
        {
            set<pair<ll,ll> >::iterator it = st.upper_bound(make_pair(a[i].first,INT_MAX));
            for(set<pair<ll,ll> >::iterator it1=st.begin();it1!=it;it1++)
            {
                s.insert(it1->second);
            }
            st.erase(st.begin(),it);
        }
        if(!s.empty())
        {
            set<ll>::iterator it = s.lower_bound(ind);
            ind = *it+1;
            if(it==s.end())
            {
                it=s.begin();
                ind=*it+1;
            }
            st.insert(make_pair(a[i].first+a[i].second-1,*it));
            ans[*it]+=a[i].second;
            s.erase(it);
        }
    }
    ll k1=*max_element(ans.begin(),ans.end());
    for(ll i=0;i<k;i++)
    {
        if(ans[i]==k1)
        {
            cout<<i+1<<endl;
        }
    }
}