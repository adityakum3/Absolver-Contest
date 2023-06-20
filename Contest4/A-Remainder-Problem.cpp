/**
 * @file        A-Remainder-Problem.cpp
 * @author      Aditya Kumar
 * @brief       You are given the following: Given number 𝑁 in the form of 
 *              string. An integer 𝐾, 𝑄 queries. For each query, you are 
 *              required to determine whether such subsequences of 𝑁 exist 
 *              and follow the provided condition: When the number formed by
 *              concatenating the digits of 𝑁 without changing relative 
 *              ordering is divided by 𝐾, then it leaves the remainder 𝑋.
 * @date        13 May, 2023
 * 
 * 
 */
#include <iostream>
#include<cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
typedef long long ll;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string n;
    cin>>n;
    int k;
    cin>>k;
    vector<bool> v(k,false);
    int q;
    cin>>q;
    for(int i=0;i<n.length();i++)
    {
        vector<int>p;
        for(int j=0;j<k;j++)
        {
            if(v[j])
            p.push_back((j*10+(n[i]-'0'))%k); 
        }
        v[(n[i]-'0')%k]=true;
        for(int j=0;j<p.size();j++)
        v[p[j]]=true;
    }
    while(q--)
    {
        int x;
        cin>>x;
        if(v[x])
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
}