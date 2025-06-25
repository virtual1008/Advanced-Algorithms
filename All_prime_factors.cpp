#include<bits/stdc++.h>
using namespace std;
/**
 * Time Complexity: O(sqrt(n))
 * Auxiliary Space: O(1) 
 */
void AllPrimeFactors(int n){
    for(int i=2;i<=sqrt(n);i++){
        while(n%i==0){
            cout<<i<<" ";
            n/=i;
        }
    }
    if(n>1) cout<<n;
}
int main(){
    cout<<"Enter the Number:-";
    int n;
    cin>>n;
    AllPrimeFactors(n);
    return 0;
}