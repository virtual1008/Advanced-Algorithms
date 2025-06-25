#include<bits/stdc++.h>
using namespace std;

// Simple Sieve: Generates all primes up to sqrt(R)
vector<long long> simpleSieve(int limit) {
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i * i <= limit; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    vector<long long> primes;
    for (int i = 2; i <= limit; ++i) {
        if (isPrime[i])
            primes.push_back(i);
    }
    return primes;
}

// Segmented Sieve for range [L, R]
void segmentedSieve(long long L, long long R) {
    int limit = sqrt(R) + 1;
    vector<long long> primes = simpleSieve(limit);

    int size = R - L + 1;
    vector<bool> isPrime(size, true);

    for (auto p : primes) {
        // Find the minimum number in [L, R] that is a multiple of p
        long long start = max(p * p, ((L + p - 1) / p) * p);

        for (long long j = start; j <= R; j += p) {
            isPrime[j - L] = false;
        }
    }

    // Edge case: if L is 1, mark it as non-prime
    if (L == 1) isPrime[0] = false;

    // Output primes in [L, R]
    for (int i = 0; i < size; ++i) {
        if (isPrime[i])
            cout << (L + i) << " ";
    }
    cout << endl;
}

int main() {
    long long L = 10, R = 50;
    segmentedSieve(L, R);
    return 0;
}
