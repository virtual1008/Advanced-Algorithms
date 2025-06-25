#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &ans , int l , int h){
    int i = l , j = h;
    int pivot = ans[h];
    while(i<j){
        while(i<h && ans[i]<=pivot) i++;
        while(l<j && ans[j]>=pivot) j--;
        if(i<j) swap(ans[i],ans[j]);
    }
    swap(ans[h],ans[i]);
    return i;
}
void QuickSort(vector<int> &ans , int l , int h){
    if(l<h){
        int pi =  partition(ans ,l ,h);
        QuickSort(ans,l,pi-1);
        QuickSort(ans,pi+1,h);
    }
}

int main() {
    int n = 5;
    vector<int> ans = {4,7,23,0,1};
    QuickSort(ans, 0, n - 1);   
    
    for(auto it : ans) cout << it << " ";  
    
    return 0;
}
