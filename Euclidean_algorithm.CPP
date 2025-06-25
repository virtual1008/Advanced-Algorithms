//Euclidean_algorithm.CPP
#include<bits/stdc++.h>
using namespace std;

/**Basic Euclidean Algorithm for GCD*/
int gcdFun(int a,int b){
    if(b==0) return a;
    return gcdFun(b,a%b);
}
/**Extended Euclidean Algorithm */
int main(){
    int a ,b;
    cout<<"Enter the value of A:-";
    cin>>a;
    cout<<"Enter the Value of B:-";
    cin>>b;
    cout<<gcdFun(a,b);
    return 0;
}