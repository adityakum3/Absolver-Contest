/**
 * @file        Strokes-To-Paint.cpp
 * @author      Aditya Kumar
 * @brief       Alex wants to paint a picture. In one stroke, Alex can only 
 *              paint adjacent cells with the same letter which are connected 
 *              horizontally or vertically but not diagonally. Given the 
 *              painting as a 2-dimensional array of letters where each 
 *              letter represents a color, find the minimum number of strokes 
 *              to completely paint the picture.
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
void dfs(int i,int j,vector<vector<bool> >&vis,vector<string>&v)
{
    vis[i][j]=true;
    if(i+1<v.size()&&!vis[i+1][j]&&v[i+1][j]==v[i][j])
    dfs(i+1,j,vis,v);
    if(i-1>=0&&!vis[i-1][j]&&v[i-1][j]==v[i][j])
    dfs(i-1,j,vis,v);
    if(j+1<v[0].length()&&!vis[i][j+1]&&v[i][j+1]==v[i][j])
    dfs(i,j+1,vis,v);
    if(j-1>=0&&!vis[i][j-1]&&v[i][j-1]==v[i][j])
    dfs(i,j-1,vis,v);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int h;
    cin>>h;
    vector<string>v(h);
    for(int i=0;i<h;i++)
    cin>>v[i];
    vector<vector<bool> >vis(h,vector<bool>(v[0].length(),false));
    int ans=0;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<v[0].length();j++)
        {
            if(!vis[i][j])
            {
                ans+=1;
                dfs(i,j,vis,v);
            }
        }
    }
    cout<<ans<<endl;
}