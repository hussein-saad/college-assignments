#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll fact(ll n){
    if(n<2)
        return 1;
    return n * fact(n-1);
}
int main() {
  
    cout<<"Enter the length of the sequence: ";
    int n;cin>>n;
    ll ans=0;
    for(int i =1;i<=n;i++)
        ans+=fact(i-1); //when i dived n! over n i simply got !(n-1) 
    cout<<ans;
}

