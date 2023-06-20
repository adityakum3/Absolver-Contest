/**
 * @file        Maximum-Force.cpp
 * @author      Aditya Kumar
 * @brief       Alex is studying about Newton Gravitational Force and an idea 
 *              occurred in his mind. He has 𝑁 objects placed in a line from 
 *              1 to 𝑁 and the distance between adjacent objects is 1 metre. 
 *              He is interested in knowing the maximum Gravitational Force 
 *              between all the pairs present between the 𝐿𝑡ℎ object and the 
 *              𝑅𝑡ℎ object. You are given Gravitational force(magnitude) 
 *              between all pairs of different objects and 𝑄 queries of the 
 *              form 𝐿 and 𝑅. Alex thought that this is easy so he also 
 *              wanted to know the maximum product of masses between any two 
 *              objects in the given range along with the maximum Force.
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
        ll q;
        cin>>q;
        vector<vector<ll> >f(n,vector<ll>(n,0));
        vector<vector<ll> >h(n,vector<ll>(n,0));
        ll x,y,p;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                cin>>x;
                cin>>y;
                p=min(x,y);
                y=max(x,y);
                x=p;
                cin>>f[x-1][y-1];
                h[x-1][y-1]=f[x-1][y-1]*(y-x)*(y-x);
            }
        }
        //cout<<"*****"<<endl;
        vector<vector<ll> >l(n,vector<ll>(n,0));
        vector<vector<ll> >m(n,vector<ll>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                l[i][j]=max(l[i][j-1],f[i][j]);
                m[i][j]=max(m[i][j-1],h[i][j]);
            }
        }
        for(ll j=0;j<n;j++)
        {
            for(ll i=j-1;i>=0;i--)
            {
                l[i][j]=max(l[i+1][j],l[i][j]);
                m[i][j]=max(m[i+1][j],m[i][j]);
            }
        }
        for(ll i=0;i<q;i++)
        {
            ll a,b;
            cin>>a>>b;
            cout<<l[a-1][b-1]<<" "<<m[a-1][b-1]<<endl;
        }
    }
}