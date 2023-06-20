/**
 * @file        Power-Company.cpp
 * @author      Aditya Kumar
 * @brief       During a surge in demand, an electric company activated generators to 
 *              meet the demand. Now that the demand has passed, at least half of the 
 *              generators need to be shut down. All generators of a particular model 
 *              are similar and can be controlled as a single unit. Find the minimum 
 *              number of models required to deactivate at least half of the generators.
 *              If there are 𝑛 generators, then the ceiling of 𝑛/2 generators must be
 *              deactivated. The ceiling is obtained when a floating point value is 
 *              rounded up to the next higher integer. For example, ceiling(5/4) = 
 *              ceiling(1.25) = 2.
 * @date        17 May, 2023
 * 
 */
#include <iostream>
#include<cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <map>
#include <string>
using namespace std;
typedef long long ll;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    vector<int>v(1000001,0);
    while(t--)
    {
        ll n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            v[a]++;
        }
        sort(v.rbegin(),v.rend());
        int c=0,i=0;
        while(c<(n-1)/2+1)
        {
            c+=v[i];
            i++;
        }
        cout<<i<<endl;
    }
}