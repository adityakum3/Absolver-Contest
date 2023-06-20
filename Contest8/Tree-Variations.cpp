/**
 * @file        Tree-Variations.cpp
 * @author      Aditya Kumar
 * @brief       A tree with 𝑔_𝑛𝑜𝑑𝑒𝑠 nodes is a connected graph having 𝑔_𝑛𝑜𝑑𝑒𝑠−1
 *              edges. A rooted tree is a tree in which one node has been 
 *              designated the root and all edges are directed in such a way 
 *              that every node except the root has exactly one outgoing edge 
 *              called parent link. Traversing the parent links eventually 
 *              arrives at the root. The desired rooted tree structure is one 
 *              in which all nodes have values less than or equal to those of 
 *              their ancestors. In a rooted tree, ancestors of node 𝑣 are 
 *              all nodes that are reachable from v following the parent 
 *              links up to the root.cDetermine the number of nodes that can 
 *              be selected as the root of the tree to form the desired 
 *              structure.
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
void dfs(vector<vector<int> >&adj,vector<bool>&visited,vector<int>&v,int ind,bool *f)
{
    visited[ind]=true;
    for(int i=0;i<adj[ind].size();i++)
    {
        if(!visited[adj[ind][i]])
        {
            if(v[adj[ind][i]]>v[ind])
            {
                *f=false;
                return;
            }
        
            dfs(adj,visited,v,adj[ind][i],f);
        }
        
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<vector<int> >adj(n);
    int ma=0,ind=-1,s=0;
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        if(v[i]>ma)
        {
            ma=v[i];
            ind=i;
            s=1;
        }
        else if(v[i]==ma)
        s++;
    }
    vector<bool>visited(n,false);
    bool f=true;
    dfs(adj,visited,v,ind,&f);
    if(f)
    cout<<s<<endl;
    else
    cout<<0<<endl;
}