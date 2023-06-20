/**
 * @file        Symmetrical-Axis.cpp
 * @author      Aditya Kumar
 * @brief       A simulation of the weights inside the cross-section of a 
 *              space cargo container is as follows:
 *              The weights are represented as a matrix
 *              The weights will need to be symmetrical about an axis 
 *              corresponding to the middlemost column. (i.e the weights 
 *              should be arranged symmetrically to the left and right of 
 *              this column.). The number of columns is always odd.
 *              The value 1 in the matrix represents the presence of a block 
 *              of weight.  
 *              0 represents empty space.
 *              Any weight can be moved to an empty space on the same row 
 *              without disturbing any of the other weights.
 *              What is the minimum number of blocks that should be moved 
 *              such that symmetry is achieved?
 * @date        16 May, 2023
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
    ll m;
    cin>>n>>m;
    vector<vector<ll> >v(n,vector<ll>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>v[i][j];
    }
    ll a=0,s=0;
    for(int i=0;i<n;i++)
    {
        ll a=0;
        for(int j=0;j<m/2;j++)
        {
            if(v[i][j]!=v[i][m-j-1])
            a++;
        }
        if(a%2==0)
        s+=a/2;
        else
        s+=a/2+1;
    }
    cout<<s;
}