#include <bits/stdc++.h>
using namespace std;

const int N = 6;

int main(){

   char arr[N][N];
   string message;
   cout<<"Enter your message (maximum allowed length is 36 characters): ";
   getline(cin,message);
   int idx=0;
   for(int i = 0;i < N;i++){
      for(int j = 0;j<N;j++){
         if(idx<message.size())
            arr[i][j]=message[idx++];
         else arr[i][j]='-';
      }
   }
   int key[N];
   cout<<"Enter your key: ";
   for(int i = 0;i<N;i++)
      cin>>key[i];
   

   for(int i = 0;i<N;i++)
      for(int j = 0;j<N;j++)
         cout<<arr[j][key[i]];
  
}
