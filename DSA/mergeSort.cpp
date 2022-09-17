#include<bits/stdc++.h>
using namespace std;
//merge sort divides the array into two equal halves and compare two portions only so no. of comparisons does not exceed total number of elements  at that level
//ternary merge sort divides the array into 3 parts so comparison while sorting will be greater so overall complexity becomes greater
void mergeTwoSortedArrays(vector<int>&v, int i, int mid, int end){
    int j = mid+1;
    int start = i;
    vector<int> tmp;
    while(start<= mid && j<= end){
        if(v[start] < v[end]){
            tmp.push_back(v[start]);
            start++;
        }else{
            tmp.push_back(v[j]);
            j++;
        }
    }
    while(start <= mid) tmp.push_back(v[start++]);
    while(j <= end) tmp.push_back(v[j++]);
    for(int &data : tmp){
        v[i] = data;
        i++;
    }
}

void mergeSort(vector<int>&v, int i, int j){
    if(i == j){
        return;
    }
    int mid = (i+j)/2;
    mergeSort(v,i,mid);
    mergeSort(v,mid+1,j);
    mergeTwoSortedArrays(v,i,mid,j);
}

int main(){
    vector<int>v;
    int n; cin>>n;
    v.resize(n);
    for(int i = 0; i < n; i++) cin>>v[i];
    mergeSort(v,0,n-1);
    for(int &i:v) cout<<i<<" ";
    return 0;
}