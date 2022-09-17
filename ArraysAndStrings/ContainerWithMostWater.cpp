#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++) cin>>vec[i];
    int ans = 0;
    int i = 0, j = n-1;
    while(i < j){
        ans = max(ans, (j-i)*min(vec[i],vec[j]));
        if(vec[i] <= vec[j]){
            i++;
        }else{
            j--;
        }
    }
    cout<<ans;
    return 0;
}