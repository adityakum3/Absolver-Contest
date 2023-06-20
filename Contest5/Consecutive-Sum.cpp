/**
 * @file        Consecutive-Sum.cpp
 * @author      Aditya Kumar
 * @brief       Given a long integer, find the number of ways to represent it 
 *              as a sum of two or more consecutive positive integers.
 * @date        14 May, 2023
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
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    ll s=0;
    for(ll i=2;i*(i+1)/2<=n;i++)
    {
        if(i%2==1)
        {
            if(n%i==0)
            s++;
        }
        else
        {
            if(n%i==i/2)
            s++;
        }
    }
    cout<<s<<endl;
}