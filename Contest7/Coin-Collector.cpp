/**
 * @file        Coin-Collector.cpp
 * @author      Aditya Kumar
 * @brief       You are playing a game where you have to obtain maximum score. 
 *              You are initially on level 1 and the game has a total of 𝑁
 *              levels. Each level has 𝐴𝑖 number of coins. Whenever you reach 
 *              a level, the number of coins collected by you is added to 
 *              your score. The score is initially zero. If you are at 𝑖𝑡ℎ 
 *              level then you can go to any level from 𝑖+1 to 𝑁. You have to 
 *              collect all the coins of the level you are currently in to 
 *              move forward. You cannot go backward. However whenever you 
 *              collect the number coins with even parity (𝐴𝑖 on division by 
 *              2 gives remainder 0) then you can move forward to any level 
 *              having even parity without any penalty, but if you want to go 
 *              to a level having number of coins with odd parity (𝐴𝑖 on 
 *              division by 2 gives remainder 1), penalty 𝑋 would be 
 *              subtracted from your score and vice versa if you are on level 
 *              containing number of coins with odd parity. Basically, if you 
 *              are moving forward on a level that has number of coins with 
 *              different parity than of current level then penalty 𝑋 is 
 *              subtracted from the score. Determine the maximum score you 
 *              can achieve if you collect the coins optimally starting on 
 *              level 1 and ending on level 𝑁.
 * @date        17 May, 2023
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
ll dfs(vector<ll>&v,vector<ll>&dp,ll i, ll x,ll n,ll p)
{
    if(i==n-1)
    {
        dp[i]=v[i];
        if(p%2!=v[i]%2)
        return dp[i]-x;
        else
        return dp[i];
    }
    if(v[i+1]%2==v[i]%2)
    {
        if(dp[i+1]==INT_MIN)
        dp[i]=v[i]+dfs(v,dp,i+1,x,n,v[i]);
        else
        dp[i]=v[i]+dp[i+1];
    }
    else
    {
        ll j;
        for(j=i+1;j<n-1;j++)
        {
            if(v[j]%2!=v[i]%2)
            {
                if(dp[j]==INT_MIN)
                dp[i]=max(v[i]+dfs(v,dp,j,x,n,v[i]),dp[i]);
                else
                dp[i]=max(v[i]+dp[j]-x,dp[i]);
            }
            else
            {
                if(dp[j]==INT_MIN)
                dp[i]=max(v[i]+dfs(v,dp,j,x,n,v[i]),dp[i]);
                else
                dp[i]=max(v[i]+dp[j],dp[i]);
                break;
            }
        }
        if(j==n-1)
        {
            if(v[j]%2!=v[i]%2)
            {
                if(dp[j]==INT_MIN)
                dp[i]=max(v[i]+dfs(v,dp,j,x,n,v[i]),dp[i]);
                else
                dp[i]=max(v[i]+dp[j]-x,dp[i]);
            }
            else
            {
                if(dp[j]==INT_MIN)
                dp[i]=max(v[i]+dfs(v,dp,j,x,n,v[i]),dp[i]);
                else
                dp[i]=max(v[i]+dp[j],dp[i]);
            }
        }
    }
    if(p%2!=v[i]%2)
    return dp[i]-x;
    else
    return dp[i];
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
        vector<ll>v(n);
        for(int i=0;i<n;i++)
        cin>>v[i];
        ll x;
        cin>>x;
        vector<ll>dp(n,INT_MIN);
        dfs(v,dp,0,x,n,v[0]);
        cout<<dp[0]<<endl;
    }
}