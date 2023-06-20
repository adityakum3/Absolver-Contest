/**
 * @file        Digit-Sum.cpp
 * @author      Adtiya Kumar
 * @brief       You are given a string of length 2N consisting of only digits
 *              from 0 to 9. You can make a move to choose an arbitrary 
 *              position and replace the digit in that position with any 
 *              digit from 0 to 9.Determine the minimum number of moves 
 *              required to make the sum of the first N digits equal to the
 *              sum of the N digits that follow.
 * @date        23 May, 2023
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
        string s;
        cin>>s;
        vector<ll>z;
        ll left=0,right =0;
        for(int i=0;i<2*n;i++)
        {
            if(i<n)
            left +=s[i]-'0';
            else
            right +=s[i]-'0';
        }
        if(left==right)
        {
            cout<<0<<endl;
            continue;
        }
        if(left >right)
        {
            for(int i=0;i<2*n;i++)
            {
                if(i<n)
                z.push_back(s[i]-'0');
                else
                z.push_back(9-s[i]+'0');
            }
        }
        else
        {
            for(int i=0;i<2*n;i++)
            {
                if(i>=n)
                z.push_back(s[i]-'0');
                else
                z.push_back(9-s[i]+'0');
            }
        }
        sort(z.rbegin(),z.rend());
        ll sum=0,count=0;
        for(auto i:z)
        {
            sum+=i;
            count++;
            if(sum>=abs(left-right))
            {
                break;
            }
        }
        cout<<count<<endl;
    }
}
//cout<<setprecision(15)