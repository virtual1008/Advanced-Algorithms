#include<bits/stdc++.h>
using namespace std;

/**
 * Time Complexity: O(√n)
 * Auxiliary Space: O(1)
 */
bool isPrime(int n){
    bool flag = true;
    for(int i=2;i<=sqrt(n);i++){
        if(n%2==0) return false;
    }
    return true;
}
int main(){
    cout<<"Enter the number";
    int n;
    cin>>n;
    bool flag = isPrime(n);
    if(flag){
        cout<<"it is Prime number";
    }else{
        cout<<"it is not a Prime number";
    }
    return 0;
}