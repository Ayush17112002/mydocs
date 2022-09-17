#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin>>v[i];
    vector<int>prefix(n,1);
    vector<int>suffix(n,1);
    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i-1]*(v[i-1]);
    }   
    for(int i = n-2; i >= 0; i--){
        suffix[i] = suffix[i+1]*(v[i+1]);
    }   
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        ans[i] = prefix[i]*suffix[i];
        cout<<ans[i]<<" ";
    }
    return 0;
}