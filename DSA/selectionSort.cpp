#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n;
void selectionSort(){
    for(int i = 0; i <= n-2; i++){
        int mn=v[i];
        int pos=i;
        for(int j = i+1; j<n; j++){
            if(v[j]<mn){
                mn=v[j];
                pos=j;
            }
        }
        swap(v[i],v[pos]);
    }
    for(int&i:v) cout<<i<<endl;
}
int main(){
    cin>>n;
    v.resize(n);
    for(int &i:v) cin>>i;
    selectionSort();
    return 0;
}