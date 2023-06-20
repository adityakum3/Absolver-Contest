/**
 * @file        Distinct-Features.cpp
 * @author      Aditya Kumar
 * @brief       You are given 𝑁 positions in a queue. Each of the positions
 *              contains elements of specific features denoted by specific 
 *              integers. You can traverse the whole queue and select 𝐾 
 *              positions that contain the same features. The selected 𝐾
 *              positions are deleted from the queue. The remaining places 
 *              are considered for the next iteration. If you cannot select 
 *              𝐾 positions, then no places can be deleted from the queue.
 *              You are given 𝑄 queries and each query contains an integer 𝑃.
 *              Minimize the number of distinct specific integers in the 
 *              queue available after each iteration. For each query, print 
 *              the number of distinct specific integers present in the queue
 *              after P iterations.
 * @date        13 May, 2023
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
    ll n,k, q;
    cin>>n>>k>>q;
    vector<ll> a(n,0);
    vector<ll> b(100001,0);
    int c=0;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        if(b[a[i]]==0)
        c++;
        b[a[i]]++;
    }
    sort(b.begin(),b.end());
    vector<ll> bt;
    vector<ll>::iterator it = lower_bound(b.begin(),b.end(),k);
    for(int i=it-b.begin();i<=b.size();i++)
    {
        if(b[i]%k==0)
        bt.push_back(b[i]);
    }
    for(int i=it-b.begin();i<=b.size();i++)
    {
        if(b[i]%k!=0)
        bt.push_back(b[i]);
    }
    it=bt.begin();
    vector<ll> p(n+1,0);
    p[0]=c;
    int i;
    for(i=1;i<=n;i++)
    {
        if(it==b.end())
        break;
        *it-=k;
        if(*it==0)
        p[i]=p[i-1]-1;
        else
        p[i]=p[i-1];
        if(*it<k)
        it++;
    }
    for(;i<=n;i++)
    p[i]=p[i-1];
    while(q--)
    {
        int o;
        cin>>o;
        cout<<p[o]<<endl;
    }
}
//cout<<setprecision(15)
