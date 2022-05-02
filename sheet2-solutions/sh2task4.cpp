#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 10;
void my_sort(int arr[N]){
    int mn,idx;
    for(int i = 0;i <N;i++){
        mn = arr[i],idx=i;
        for(int j = i+1;j<N;j++){
            if(arr[j]<mn)
                mn =arr[j],idx=j;
        }
        swap(arr[i],arr[idx]);
    }
}

void my_sort(ll arr[N]){
    ll mn,idx;
    for(int i = 0;i <N;i++){
        mn = arr[i],idx=i;
        for(int j = i+1;j<N;j++){
            if(arr[j]<mn)
                mn =arr[j],idx=j;
        }
        swap(arr[i],arr[idx]);
    }
}

void my_sort(double arr[N]){
    double mn;
    int idx;
    for(int i = 0;i <N;i++){
        mn = arr[i],idx=i;
        for(int j = i+1;j<N;j++){
            if(arr[j]<mn)
                mn =arr[j],idx=j;
        }
        swap(arr[i],arr[idx]);
    }
}
int main() {
    double arr[N];
    
    for(int i = 0;i<N;i++)
        cin>>arr[i];
    
    my_sort(arr);
    
    for(int i = 0;i<N;i++)
        cout<<arr[i]<<" ";
}

