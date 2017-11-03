#include<iostream>
#include <iomanip>
#include <vector>
using namespace std;
int FillMatrix(vector<vector<int>>&  M,int start,int length,int start_x,int start_y);
void PrintMatrix(vector<vector<int>> M,int length);
int main(){
    int N;
    N = 4;
    vector<vector <int> > M;
    M.resize(N);
    for(int i=0;i<N;i++) M[i].resize(N);
    int start = 1;
    int length = 4;
    int start_x = 0;
    int start_y = 0;
    int Ncount = 0;
    if(N%2 == 0){
        while(length!=0){
            start = FillMatrix(M, start, length, start_x, start_y);
            length -= 2;
            start_x += 1;
            start_y += 1;
            Ncount++;
        }
    }
    else{
        while(length!=1) {
            start = FillMatrix(M, start, length, start_x, start_y);
            length -= 2;
            start_x += 1;
            start_y += 1;
            Ncount++;
            //start+=1;
        }
        M[Ncount][Ncount] = N*N;
    }

    PrintMatrix(M,N);
}
int FillMatrix(vector<vector<int>> &M ,int start,int length,int start_x,int start_y){
    int T_x = start_x;
    int T_y = start_y;
    for(int i = start;i<start+length;i++,T_y++){
        M[T_x][T_y] = i;
    }
    start += length;
    T_y--;
    T_x++;
    for(int i = start;i<start+length-1;i++,T_x++){
        M[T_x][T_y] = i;
    }
    start += length-1;
    T_y--;
    T_x--;
    for(int i = start;i<start+length-1;i++,T_y--){
        M[T_x][T_y] = i;
    }
    start += length-1;
    T_x--;
    T_y++;
    for(int i = start;i<start+length-2;i++,T_x--){
        M[T_x][T_y] = i;
    }
    start += length-2;
    return start;
}
void PrintMatrix(vector<vector<int>> M,int length){
    for(int i = 0;i<length;i++){
        for(int j = 0;j<length;j++){
            cout<<setw(6) <<M[i][j];
        }
        cout<<endl;
    }
}