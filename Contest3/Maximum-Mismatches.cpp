/**
 * @file        Maximum-Mismatches.cpp
 * @author      Aditya Kumar
 * @brief       You are given the following: 𝑁 : An integer, 𝑆 : A string of
 *              length Nvconsisting of the lowercase English alphabet You can
 *              select and reverse any substring of string 𝑆. You are allowed
 *              to perform this operation any number of times. You have to 
 *              determine the maximum number of mismatches in the final 
 *              string 𝑆.
 * @date        24 May, 2023 
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
        vector<ll>a(26);
        for(int i=0;i<n;i++)
        {
            a[s[i]-'a']++;
        }
        sort(a.rbegin(),a.rend());
        if(s.length()%2==1)
        {
            if(a[0]>s.length()/2)
            cout<<2*(s.length()-a[0])<<endl;
            else
            cout<<s.length()-1<<endl;
        }
        else
        {
            if(a[0]>s.length()/2)
            cout<<2*(s.length()-a[0])<<endl;
            else
            cout<<s.length()<<endl;
        }
    }
}