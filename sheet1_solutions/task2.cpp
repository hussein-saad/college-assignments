#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int matrix[MAX][MAX],result[MAX][MAX];
int row,col;
void read_matrix(){

    cout<<"Enter number of rows and columns of the matrix: ";
    cin>>row>>col;
    cout<<"Enter the "<<row<<" * "<<col<<" matrix\n";

    for(int i = 0;i < row;i++)
        for(int j = 0;j< col;j++){
            cout<<"Enter element "<<i+1<<j+1<<": ";
            cin>>matrix[i][j];
        }

}


int main(){

    read_matrix();


    for(int i = 0; i < col;i++){
        for(int j = 0; j < row; j++){
            result[i][j]=matrix[j][i];
        }
    }
    cout<<"the result after transpose is \n";
    for(int i = 0; i < col;i++){
        for(int j = 0; j < row; j++)
            cout<<result[i][j]<<" ";
        cout<<"\n";
    }

}

