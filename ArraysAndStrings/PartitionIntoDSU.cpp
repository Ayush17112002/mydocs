#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin>>v[i];
    int leftmax = v[0], upd = v[0];
    int ans = 0;
    for(int i = 1; i < n; i++){
        if(v[i] < leftmax){
            ans = i;
            leftmax = upd;
        }else{
            if(v[i] > leftmax) upd = v[i];
        }
    }
    cout<<ans+1;
    return 0;
}