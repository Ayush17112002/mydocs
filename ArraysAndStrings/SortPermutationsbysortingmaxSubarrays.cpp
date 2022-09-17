#include<bits/stdc++.h>
using namespace std;
int sortIt(vector<int> v){
    int n = v.size();
    int mx = -1, ans = 0;
    for(int i = 0; i < n; i++){
        if(mx > v[i]){
            // curr element lies in the previous array and we have reached max sorted location so close the chunk
            if(mx == i){
                ans++;
                mx = -1;
            }else{
                // we have not yet reach to the max sorted location 
                continue;
            }
        }else{
            // curr element needs to go farther than till mx and also we cannot close the chunk 
            mx = v[i];
            if(mx == i){
                mx = -1;
                ans++;
            }
        }
    }
    return ans;
}
int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin>>v[i];
    int mx = -1, ele = 0, ans = 0;
    for(int i = 0; i < n; i++){
        if(mx == -1){
            mx = v[i];
            ele = v[i]-i;
            if(ele == 0){
                ans++;
                mx = -1;
            }
        }else{
            if(v[i] <= mx){
                ele--;
                if(!ele){
                    ans++;
                    mx = -1;
                }
            }else{
                ele += (v[i]-mx-1);
                mx = v[i];
            }
        }
    }
    cout<<sortIt(v);
    cout<<ans<<endl;
    return 0;
}