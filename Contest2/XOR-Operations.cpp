/**
 * @file        XOR-Operations.cpp
 * @author      Aditya Kumar
 * @brief       You are given an array 𝐴 of size 𝑁. You can perform the 
 *              following operation on the array. Choose a random integer 𝑋 
 *              of your choice. Additionally, 𝑋 should be a power of 2. 
 *              Choose any index i from 0 to 𝑁−1 and replace 𝐴𝑖 with 𝐴𝑖 ⊕ X. 
 *              Here ⊕ denotes XOR operation. You have to answer 𝑄 queries.
 *              Each query contains two integers 𝑙vand 𝑟 and you have to find
 *              the minimum operations required to make all the elements in
 *              the subarray from 𝑙𝑡ℎ to 𝑟𝑡ℎ index (inclusive) equal. Print 𝑄
 *              space-separated integers where the 𝑖𝑡ℎ integer represents the
 *              answer for the 𝑖𝑡ℎ query.
 * @date        23 May, 2023
 * 
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
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>a(n);
        for(int i=0;i<n;i++)
        cin>>a[i];
        vector<vector<ll>>n1(n,vector<ll>(33,0));
        vector<vector<ll>>n0(n,vector<ll>(33,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<33;j++)
            {
                if(i==0)
                {
                    if(a[i]%2==0)
                    n0[i][j]=1;
                    else
                    n1[i][j]=1;
                }
                else
                {
                    if(a[i]%2==0)
                    {
                        n0[i][j]=n0[i-1][j]+1;
                        n1[i][j]=n1[i-1][j];
                    }
                    else
                    {
                        n1[i][j]=n1[i-1][j]+1;
                        n0[i][j]=n0[i-1][j];
                    }

                }
                a[i]/=2;
            }
        }
        ll q;
        cin>>q;
        while(q--)
        {
            ll l,r;
            cin>>l>>r;
            ll count=0;
            if(l==0)
            {
                for(int i=0;i<33;i++)
                {
                    count+=min(n0[r][i],n1[r][i]);
                }

            }
            else
            {
                for(int i=0;i<33;i++)
                {
                    count+=min(n0[r][i]-n0[l-1][i],n1[r][i]-n1[l-1][i]);
                }
            }
            cout<<count<<" ";
        }
        cout<<endl;
    }
}