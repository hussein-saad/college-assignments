#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isPrime(ll n){
    if(n<2)
        return false;
    if(n==2)
        return true;
    /*
     * let's get the divisors of 16 it will be 1,2,4,8,16
     * 1 16 -> 16
     * 2 8  -> 16
     * 4 4  -> 16
     * 8 * 2 -> 16
     * 16 * 1 -> 16
     * when i reach to sqrt(n) i repeat my self so i don't have to iterate over whole n
     * instead  sqrt(n)
    */
    for(int i = 2;i*i<=n;i++)
        if(n%i==0)
            return false;
    return true;
}
int main() {
    ll n;
    cout<<"Enter number to check if it's prime or not: ";
    cin>>n;
    if(isPrime(n))
        cout<<"number "<<n<<" is prime\n";
    else cout<<"number "<<n<<" isn't prime\n";

}

