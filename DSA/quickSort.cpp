#include<bits/stdc++.h>
using namespace std;


int Partition(vector<int>&v, int l, int r){
    //take v[0] as the target element and find its correct position int vector v
    int ele = v[l];
    int i=l+1, j=r;
    while(i<j){
        while(v[i]<=ele && i<=r){
            i++;
        }
        while(v[j]>ele && j>=l){
            j--;
        }
        if(i<j){
            swap(v[i],v[j]);
        }
    }
    swap(v[j],v[l]);
    return j;
}

void quickSort(vector<int>&v, int l, int r){
    if(l>=r) return;
    int pivot = Partition(v,l,r);
    quickSort(v,l,pivot-1);
    quickSort(v,pivot+1,r);
}

int main(){
    vector<int>v = {4,3,5,1,2};
    quickSort(v,0,4);
    for(int&i:v) cout<<i<<"\n";
    return 0;
}