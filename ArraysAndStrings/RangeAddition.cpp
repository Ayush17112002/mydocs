#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q; cin>>n>>q;
    vector<long> vec(n, 0);
    vector<long> helper(n+1,0);
    for(int i = 0; i < q; i++){
        int a,b,inc; cin>>a>>b>>inc;
        helper[a] += inc;
        helper[b+1] -= inc;
    }
    //we have created a helper array that stores what impact to be taken in for ith element
    for(int i = 1; i < n; i++){
        helper[i] += helper[i-1];
    }
    for(int i = 0; i < n; i++){
        vec[i] += helper[i];
    }

    return 0;
}