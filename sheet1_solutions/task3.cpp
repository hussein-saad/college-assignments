#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int matrix1[MAX][MAX],matrix2[MAX][MAX],result[MAX][MAX];

void read_matrix(int &row,int &col,int matrix[MAX][MAX]){

    cout<<"Enter number of rows and columns of the matrix: ";
    cin>>row>>col;
    cout<<"Enter the "<<row<<" * "<<col<<" matrix\n";

    for(int i = 0;i < row;i++)
        for(int j = 0;j< col;j++){
            cout<<"Enter element "<<i+1<<j+1<<": ";
            cin>>matrix[i][j];
        }

}

int can_multiply(int c1,int r2){
    return (c1==r2);
}

int main(){

    int row1,col1,row2,col2;
    read_matrix(row1,col1,matrix1);
    read_matrix(row2,col2,matrix2);
    if(!can_multiply(col1,row2)){
        cout<<"Can't multiply\n";
        return 0;
    }

    for(int i = 0; i < row1;i++){
        for(int j = 0; j < col2; j++){
            for(int h = 0; h < col1; h++)
                result[i][j]+=(matrix1[i][h]*matrix2[h][j]);
        }
    }
    cout<<"the result from multiplication is \n";
    for(int i = 0; i < row1;i++){
        for(int j = 0; j < col2; j++)
            cout<<result[i][j]<<" ";
        cout<<"\n";
    }

}

