#include<bits/stdc++.h>
using namespace std;
void printMajorityElement(int arr[], int n){
    int val = arr[0], count = 1;
    for(int i = 1; i < n; i++){
        if(count == 0){
            val = arr[i]; count = 1;
            continue;
        }
        if(arr[i] == val){
            count++;
        }else{
            count--;
        }
    }
    if(count == 0) cout<<"No Majority Element exist";
    else{
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == val) cnt++;
        }
        if(cnt > n/2) cout<<val;
        else cout<<"No Majority Element exist";
    }
}
int main(){
    int n; cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    printMajorityElement(arr,n);
    return 0;
}