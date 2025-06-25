#include<bits/stdc++.h>
using namespace std;
/**
 * Time Complexity: O(sqrt(n)), where n is the input number. 
 * Auxiliary Space: O(1) 
 */
void AllDivisorOfNaturalNumber(int n){
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            cout<<i<<" "<<n/i<<" ";
        }
    }
}
int main(){
    cout<<"Enter number";
    int n ;
    cin>>n;
    AllDivisorOfNaturalNumber(n);
    return 0;
}