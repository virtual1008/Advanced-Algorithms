#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<int,int> mp;

// Time Complexity O(N(sqrt(N)))
void AllPrimeFactors(int n, bool flag) {
    for (int i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
            if (flag) mp[i]++;
            else mp[i]--;
            n /= i;
        }
    }
    if (n > 1) {
        if (flag) mp[n]++;
        else mp[n]--;
    }
}

// Function for calculating nCr using prime factorization
ll calculation(ll n , ll r , ll mod) {
    for (int i = 2; i <= n; i++) {
        bool flag = true;
        AllPrimeFactors(i, flag);
    }
    for (int i = 2; i <= r; i++) {
        bool flag = false;
        AllPrimeFactors(i, flag);
    }
    for (int i = 2; i <= (n - r); i++) {
        bool flag = false;
        AllPrimeFactors(i, flag);
    }
    ll ans = 1;
    for (auto it: mp) {
        ll num = it.first;
        ll cnt = it.second;
        while (cnt > 0) {
            ans = ((ans % mod) * (num % mod)) % mod;
            ans %= mod;
            cnt--;
        }
    }
    return ans;
}

// Function for optimal calculation of nCr under modulo
ll modInverse(ll a, ll m) {
    // Fermat's Little Theorem: a^(m-1) ≡ 1 (mod m)
    // Hence, a^(m-2) ≡ a^(-1) (mod m)
    ll result = 1, exp = m - 2;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * a) % m;
        a = (a * a) % m;
        exp /= 2;
    }
    return result;
}

// Optimal calculation of nCr using multiplicative approach and modular inverse
ll OptimalCalculation(ll n, ll r, ll mod) {
    if (r > n) return 0;  // If r > n, nCr is 0
    
    ll res = 1LL;
    for (int i = 1; i <= r; i++) {
        res = (res * (n - i + 1)) % mod;
        res = (res * modInverse(i, mod)) % mod;  // Multiply by modular inverse of i
    }
    return res;
}

int main() {
    // nCr
    ll n , r, mod;
    cout << "Enter the value of n" << "\n";
    cin >> n;
    cout << "Enter the value of r" << "\n";
    cin >> r;
    cout << "Enter the value of mod" << "\n";
    cin >> mod;
    mod = 1e9+7;
    // Using the prime factorization method
    cout << calculation(n, r, mod) << "\n";
    
    // Using the optimal method
    cout << OptimalCalculation(n, r, mod) << "\n";
    
    return 0;
}
