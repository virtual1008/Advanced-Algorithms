#include<bits/stdc++.h>
using namespace std;

long long CalculationMod(long long base , long long power,long long mod){
    long long res = 1;
    long long x = base;
    while(power>0){
        if(power&1){
            res=((res%mod)*(base%mod))%mod;
        }
        base*=base;
        base = ((base%mod)*(base%mod))%mod;
        power =(power>>1);
        res%=mod;
    }
    return res;
}
// Time Complexity - O((log(power))2)
// Space ComplexityO(log(power))
map<long long , long long> dp;
long long calculate(long long base , long long power){
    if(power==1) return base;
    if(dp.find(power)!=dp.end()) return dp[power];
    long long a = calculate(base,power/2);
    if(power%2) return dp[power]=a*a*base;
    else return dp[power] = a*a;
}
int main(){
    long long base , power,mod;
    cout<<"Enter The base value"<<"\n";
    cin>>base;
    cout<<"Enter the power value"<<"\n";
    cin>>power;
    cout<<"Enter the mod value"<<"\n";
    cin>>mod;
    //long long mod = 1e9+7;
    //cout<<calculate(base,power);
    cout<<CalculationMod(base,power,mod);
    return 0;
}