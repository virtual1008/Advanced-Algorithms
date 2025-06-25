#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &ans , int l ,int r , int mid){
    vector<int> temp;
    int i = l;
    int j = mid+1;
    while(i<=mid && j<=r){
        if(ans[i]<=ans[j]){
            temp.push_back(ans[i]);
            i++;
        }else{
            temp.push_back(ans[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(ans[i]);
        i++;
    }
    while(j<=r){
        temp.push_back(ans[j]);
        j++;
    }
    for(int k=l;k<=r;k++){
        ans[k] = temp[k-l];
    }
}
void mergeSort(vector<int> &ans , int l ,int r){
     if(l<r){
        int mid = (l+r)/2;
        mergeSort(ans,l,mid);
        mergeSort(ans,mid+1,r);
        merge(ans,l,r,mid);
     }
}
int main(){
    int n = 15;
    vector<int> ans = {4,3,1,7,23,2,0,1,3,54,43,5,67,2,3};
    mergeSort(ans, 0, n - 1);   
    
    for(auto it : ans) cout << it << " ";  
    return 0;
}