#include <bits/stdc++.h>
using namespace std;

void multiplicationTable(int n,int to){
    if(to<1)
        return;
    multiplicationTable(n,to-1);
    cout<<n<<" * "<<to<<" = "<<n*to<<"\n";
}
int main() {
    int n,to;
    cout<<"Enter a number to get multiplication table and a number to get that multiplication table to: ";
    cin>>n>>to;
    multiplicationTable(n,to);
}

