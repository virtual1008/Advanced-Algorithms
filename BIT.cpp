#include<bits/stdc++.h>
using namespace std;

class BIT{
    private:
       vector<int> tree;
       int n;
    public:
       BIT(int size){
           n = size + 2;
           tree.assign(n,0);
       }

       void update(int i,int val){
           while(i<n){
              tree[i]+=val;
              i+=(i&-i);
           }
       }

       int query(int i){
            int sum = 0;
            while(i>0){
                sum+=tree[i];
                i-=(i&-i);
            }
            return sum;
       }
}; 

vector<int> countSmaller(vector<int> &nums){
    int n = nums.size();
    vector<int> result(n);
    vector<int> sorted = nums;
    sort(sorted.begin(),sorted.end());
    int rank = 1;
    unordered_map<int,int> ranks;
    for(auto it:sorted){
        if(!ranks.count(it)) ranks[it] = rank++;
    }
    BIT bits(rank);
    for(int i=0;i<n;i++){
        int rank = ranks[nums[i]];
        result[i] = bits.query(rank-1);
        bits.update(rank,1);
    }
    return result;
}

vector<int> countSmallerAfer(vector<int> &nums){
    int n = nums.size();
    vector<int> result(n);
    vector<int> sorted = nums;
    sort(sorted.begin(),sorted.end());
    int rank = 1;
    unordered_map<int,int> ranks;
    for(auto it:sorted){
        if(!ranks.count(it)) ranks[it] = rank++;
    }
    BIT bits(rank);
    for(int i=n-1;i>=0;i--){
        int rank = ranks[nums[i]];
        result[i] = bits.query(rank-1);
        bits.update(rank,1);
    }
    return result;
}
int main(){
    vector<int> temp = {1,1,2,3,1,2,3,4,5,21,2,34,2,13,3};
    vector<int> result1 = countSmaller(temp);
    for(auto it:result1) cout<<it<<" ";
    cout<<"\n";
    vector<int> result2 = countSmallerAfer(temp);
    for(auto it:result2) cout<<it<<" ";
    return 0; 
}  