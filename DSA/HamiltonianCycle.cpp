#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9+7
vector<vector<int>> edges;
int findhamiltonianCycle(int n,vector<int>&v, int source, vector<bool>&vis){
    //add source to our current testing path that might be a cycle
    v.push_back(source);
    vis[source] = true;
    if(v.size() == n){
        //check if there is an edge btw last and first node
        for(auto & node : edges[source]){
            if(node == v[0]){
                v.pop_back();
                return 1;
            }
        }
        v.pop_back();
        return 0;
    }
    //try out all nodes connecting to source
    int ans = 0;
    for(auto & node : edges[source]){
        if(vis[node]==false){
            ans += findhamiltonianCycle(n,v,node,vis);
        }
    }
    v.pop_back();
    return ans;
}

int main(){
    
    return 0;
}