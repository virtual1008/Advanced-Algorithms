#include<bits/stdc++.h>
using namespace std;

/**
 * Time Complexity: O(n + m)
 * Auxiliary Space: O(m)
 */
void construct_LPS(string &str , vector<int> &lps){
   int len = 0;
   lps[0] = 0;
   int i = 1;
   int n = str.size();
   while(i<n){
       if(str[i]==str[len]){
          len++;
          lps[i] = len;
          i++;
       }else{
          if(len>0) len = lps[len-1];
          else {
            lps[i] = 0;
            i++;
          }
       }
   }

}

vector<int> search(string &pat, string &txt) {
    int n = txt.length();
    int m = pat.length();
    vector<int> lps(m);
    vector<int> res;
    construct_LPS(pat, lps);
    int i = 0;
    int j = 0;
    while (i < n) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
            if (j == m) {
                res.push_back(i - j);
                j = lps[j - 1];
            }
        }
        else {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return res;
}
int main(){
    cout<<"Please Enter Sample String:-";
    string sample , pattern;
    cin>>sample;
    cout<<"Please Enter pattern String:-";
    cin>>pattern;
    vector<int> ans = search(pattern , sample);
    cout<<"OUTPUT WILL BE"<<"\n";
    for(auto it:ans) cout<<it<<" ";
    return 0;
}