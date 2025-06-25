#include<bits/stdc++.h>
using namespace std;
vector<long long> p_pow;
long long mod = 1e9+7;
long long p = 31;
// string -> maxScore string , hashValue , score of string 
unordered_map<string,pair<string,pair<int,int>>> data;
void preCalculation(int n){
    p_pow.resize(n+1);
    p_pow[0] = 1;
    for(int i=1;i<=n;i++){
       p_pow[i] = (p_pow[i-1]*p)%mod;
    }
}
//create hash Value of string
long long getHashValue(string &str){
    long long result = 0;
    int n = str.size();
    for(int i=0;i<n;i++){
        result=(result%mod + (p_pow[i]*(str[i]-'a'+1))%mod)%mod;
    }
    data[str].second.first = result;
    return result;
}
//create anagram of string with highest score
string getMaxScoreString(string &str){
    unordered_map<char,int> freq;
    for(auto it:str) freq[it]++;
    char l = 'a' , r = 'z';
    bool flag = true;
    string result = "";
    while(l<=r){
        if(freq[l]>0 && freq[r]>0){
            if(flag){
                result+=l;
                freq[l]--;
                if(freq[l]==0) l++;
            }else{
                result+=r;
                freq[r]--;
                if(freq[r]==0) r--;
            }
            flag = !flag;
        }else if(freq[l]==0){
            l++;
        }else if(freq[r]==0){
            r--;
        }
    }
    data[str].first = result;
    return result;
} 
//get score of the string
long long getScore(string &str){
    long long result = 0;
    int n = str.size();
    for(int i=1;i<n;i++){
        result+=abs(str[i]-str[i-1]);
    }  
    data[str].second.second = result; 
    return result;
}
int main(){
    int n;
    cin>>n;
    int maxLen = 1000;
    preCalculation(maxLen);
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        getScore(str);
        getHashValue(str);
        getMaxScoreString(str);
    }   
    for(auto it:data){
        cout<<it.first<<" "<<it.second.first<<" "<<it.second.second.first<<" "<<it.second.second.second<<"\n";
    }
    return 0;
}