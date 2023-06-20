/**
 * @file        Water-And-The-Grid.cpp
 * @author      Aditya Kumar
 * @brief       There is a place in the form of 𝑀×𝑁 grid where each cell 
 *              either has a tower built on it, represented by '*' or is 
 *              empty, represented by '.'. Each cell is a square of unit area
 *              and each tower has a height of 1 unit. You are required to 
 *              estimate the volume of water that could be trapped in between
 *              the towers. 
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
using namespace std;
typedef long long ll;
void dfs(ll i,ll j,vector<vector<bool> >&vis, vector<vector<char> >&v)
{
    vis[i][j]=true;
    v[i][j]='#';
    if(i+1<v.size()  && v[i+1][j]=='.')
    {
        v[i][j]='#';
        dfs(i+1,j,vis,v);
    }
    if(i-1>=0  && v[i-1][j]=='.')
    {
        v[i][j]='#';
        dfs(i-1,j,vis,v);
    }
    if(j+1<v[0].size() && v[i][j+1]=='.')
    {
        v[i][j]='#';
        dfs(i,j+1,vis,v);
    }
    if(j-1>=0 && v[i][j-1]=='.')
    {
        v[i][j]='#';
        dfs(i,j-1,vis,v);
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<vector<char> >v(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>v[i][j];
    }
    vector<vector<bool> >vis(n,vector<bool>(m,false));
    for(ll i=0;i<n;i++)
    {
        if(!vis[i][0]&&v[i][0]=='.')
        dfs(i,0,vis,v);
        if(!vis[i][m-1]&&v[i][m-1]=='.')
        dfs(i,m-1,vis,v);
    }
    for(int i=0;i<m;i++)
    {
        if(!vis[0][i]&&v[0][i]=='.')
        dfs(0,i,vis,v);
        if(!vis[n-1][i]&&v[n-1][i]=='.')
        dfs(n-1,i,vis,v);
    }
    ll ans=0;
    for(ll i=1;i<n-1;i++)
    {
        for(ll j=1;j<m-1;j++)
        {
            //cout<<v[i][j];
            if(v[i][j]=='.')
            ans++;
        }
        cout<<endl;
    }
    cout<<ans;
}
//cout<<setprecision(15)