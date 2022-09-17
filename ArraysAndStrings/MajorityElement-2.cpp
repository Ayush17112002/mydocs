#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++) cin>>arr[i];
    int val1 = arr[0], cnt1 = 1, val2 = -1, cnt2 = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] == val1){
            cnt1++;
        }else if(arr[i] == val2){
            cnt2++;
        }else{
            if(cnt1 == 0){
                val1 = arr[i];
                cnt1 = 1;
            }else if(cnt2 == 0){
                val2 = arr[i];
                cnt2 = 1;
            }else{
                //pair it up with two elements val1 and val2
                cnt1--; cnt2--;
            }
        }
    }
    if(!cnt1 && !cnt2) cout<<"[]";
    else{
        int ans1 = 0, ans2 = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == val1) ans1++;
            else if(arr[i] == val2) ans2++;
        }
        cout<<"[";
        if(ans1 > n/3){
            cout<<val1;
            if(ans2 > n/3) cout<<", "<<val2;
        }else{
            cout<<val2;
        }
        cout<<"]"; 
    }
    return 0;
}