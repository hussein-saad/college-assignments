#include <bits/stdc++.h>
using namespace std;
const int N = 4;
int main(){

    string arr[N][N]={{"8","3","11","2"},{"10","6","14","15"},
    {"12","1","5","9"},{"7","-","13","4"}};


    int n = 1;
    for(int i = 0; i < N;i++)
      for(int j = 0;j<N;j++)
         arr[i][j]=to_string(n++);


   arr[3][3]="-";//for empty one

   for(int i = 0; i < N;i++){
      for(int j = 0;j<N;j++)
         cout<<arr[i][j]<<" ";
      cout<<"\n";
   }



}
