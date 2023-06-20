/**
 * @file        Arrangement-Of-Candies.cpp
 * @author      Aditya Kumar
 * @brief       You are given 𝑁 red candies and 𝑀 blue candies. Write a 
 *              program to find the number of arrangements of candies in 
 *              which not more than 𝐾 candies of the same color are placed 
 *              next to each other.
 * @date        27 May, 2023
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    ll mod = 1000000007;
    cin>>t;
    while(t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        vector<vector<vector<ll>>> dp(n+2,vector<vector<ll>>(m+2,vector<ll>(2,0)));
        vector<vector<ll>> pref1(n+2,vector<ll>(m+2,0));
        vector<vector<ll>> pref2(n+2,vector<ll>(m+2,0));
        dp[1][1][0]=1;
        dp[1][1][1]=1;
        for(ll i=1;i<=n+1;i++)
        {
            for(ll j=1;j<=m+1;j++)
            {
                ll vl = i-min(i,k);
                ll vr = i-1;
                if(vl<=vr)
                {
                    if(vl>0)
                    {
                        dp[i][j][0]+=(pref1[vr][j]-pref1[vl-1][j])%mod;
                        dp[i][j][0]%=mod;
                        if(dp[i][j][0]<0)
                        dp[i][j][0]+=mod;
                    }
                    else
                    {
                        dp[i][j][0]+=pref1[vr][j]%mod;
                        dp[i][j][0]%=mod;
                        if(dp[i][j][0]<0)
                        dp[i][j][0]+=mod;
                    }
                }
                ll hl = j-min(j,k);
                ll hr = j-1;
                if(hl <=hr)
                {
                    if(hl>0)
                    {
                        dp[i][j][1]+=(pref2[i][hr]-pref2[i][hl-1])%mod;
                        dp[i][j][1]%=mod;
                        if(dp[i][j][1]<0)
                        dp[i][j][1]+=mod;
                    }
                    else
                    {
                        dp[i][j][1]+=pref2[i][hr]%mod;
                        dp[i][j][1]%=mod;
                        if(dp[i][j][1]<0)
                        dp[i][j][1]+=mod;
                    }
                }
                pref1[i][j] = (pref1[i-1][j]+dp[i][j][1])%mod;
                pref2[i][j] = (pref2[i][j-1]+dp[i][j][0])%mod;
            }
        }
        cout<<(dp[n+1][m+1][0]+dp[n+1][m+1][1])%mod<<endl;
    }
}