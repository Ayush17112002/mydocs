#include<bits/stdc++.h>
using namespace std;

void toh(int n, int source, int dest, int helper){
    if(n == 0){
        return;
    }
    //move n disks from source to dest using helper tower
    toh(n-1,source,helper,dest);
    cout<<n<<"["<<source<<"->"<<dest<<"]\n";
    toh(n-1,helper,dest,source);
    return;
}

int main(){
    int n;
    cin>>n;
    toh(n,1,2,3);
    return 0;
}