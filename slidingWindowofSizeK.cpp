#include<bits/stdc++.h>
using namespace std;
void maxKwindow(int k , vector<int> &arr){
    deque<int> dq;
    int n = arr.size();
    vector<int> ans;
    for(int i=0;i<k;i++){
        while(!dq.empty() && arr[i]>=arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for(int i=k;i<n;i++){
        ans.push_back(arr[dq.front()]);
        while(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }
        while(!dq.empty() && arr[i]>=arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for(auto it:ans) cout<<it<<" ";
}
int main(){
    int n ,k;
    cout<<"Enter the size of the array\n";
    cin>>n;
    cout<<"Enter the size of the window\n";
    cin>>k;
    cout<<"Enter the elements\n";
    vector<int> arr(n);
    for(auto &x:arr){
        cin>>x;
    }
    maxKwindow(k,arr);
    return 0;
}