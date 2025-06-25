#include<bits/stdc++.h>
using namespace std;
/*Given a number n, print all primes smaller than or equal to n. It is also given that n is a small number.*/
/**
 * Time Complexity: O(N*log(log(N))) 
 * Auxiliary Space: O(N) 
 * 
 */

void All_prime_numbers(int n){
    vector<int> isPrime(n+1,1);
    for(int p=2;p*p<=n;p++){
        if(isPrime[p]){
            for(int i=p*p;i<=n;i+=p){
               isPrime[i] = false;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<i<<"->"<<isPrime[i]<<"\n";
    }
}

int main(){
    int n;
    cout<<"Enter the value of n";
    cin>>n;
    All_prime_numbers(n);
    return 0;
}