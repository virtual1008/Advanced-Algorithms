#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p = 31;            // base (can also use 53 for lowercase+uppercase)
const ll mod = 1e9 + 9;     // large prime modulus

vector<ll> computePowers(int n){
    vector<ll> power(n);
    power[0] = 1;
    for(int i=1;i<n;i++){
        power[i] = (power[i-1]*p)%mod;
    }
    return power;
}

vector<ll> computePrefixHash(const string& s, const vector<ll>& p_pow){
    int n = s.size();
    vector<ll> hash(n + 1, 0);
    for (int i = 0; i < n; i++) {
        hash[i + 1] = (hash[i] + (s[i] - 'a' + 1) * p_pow[i]) % mod;
    }
    return hash;
}

ll getSubstrHash(int l, int r, const vector<ll>& hash, const vector<ll>& p_pow) {
    ll result = (hash[r + 1] - hash[l] + mod) % mod;
    result = (result * p_pow[p_pow.size() - l - 1]) % mod; // Normalize if needed
    return result;
}

int main(){
    string s = "abacaba";
    int n = s.size();
    
    vector<ll> p_pow = computePowers(n + 1);
    vector<ll> hash = computePrefixHash(s, p_pow);

    // Example: Compare substrings s[0..2] and s[4..6]
    ll h1 = getSubstrHash(0, 2, hash, p_pow); // "aba"
    ll h2 = getSubstrHash(4, 6, hash, p_pow); // "aba"

    if (h1 == h2)
        cout << "Substrings are equal!" << endl;
    else
        cout << "Substrings are different!" << endl;

    return 0;
}