/**
 * @file        A-Connected-Tree.cpp
 * @author      Aditya Kumar
 * @brief       You are given a connected tree where each node is assigned a
 *              lowercase alphabet. Find the sum of the number of edges for
 *              all paths from node 𝑖 to node 𝑗 where node 𝑖 and node 𝑗 
 *              contain the same alphabet. Here, 𝑝𝑎𝑡ℎ(𝑖,𝑗) and 𝑝𝑎𝑡ℎ(𝑗,𝑖) are 
 *              considered as two different paths.
 * @date        26 May, 2023 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,ll>> dfs(ll v,vector<vector<ll>>&adj,vector<bool> &vis,vector<char> &ch,ll *ans)
{
    vis[v]=true;
    vector<pair<ll,ll>>temp(26);
    for(auto i:adj[v])
    {
        if(!vis[i])
        {
            vector<pair<ll,ll>> t = dfs(i,adj,vis,ch,ans);
            for(int j=0;j<26;j++)
            {
                if(ch[v]==j+'a')
                *ans+=t[j].second;
                *ans+=t[j].first*temp[j].second + t[j].second*temp[j].first;
                temp[j].first+=t[j].first;
                temp[j].second+=t[j].second;
            }
        }
    }
    for(int j=0;j<26;j++)
    {
        temp[j].second+=temp[j].first;
        if(ch[v]==j+'a')
        {
            temp[j].first++;
            temp[j].second++;
        }
        
    }
    return temp;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<char>ch(n);
        for(int i=0;i<n;i++)
        {
            cin>>ch[i];
        }
        vector<vector<ll>>adj(n);
        for(int i=0;i<n-1;i++)
        {
            ll u,v;
            cin>>u>>v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(n,false);
        ll ans=0;
        dfs(0,adj,vis,ch,&ans);
        cout<<2*ans<<endl;
    }
}