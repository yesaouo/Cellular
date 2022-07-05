#include<iostream>
#include"Cellular.h"
using namespace std;
Cellular::Cellular(bool **matrix,int x,int y):b1(matrix),hei(y),wid(x){
    b2 = new bool*[hei];
    for(int i = 0; i < hei; ++i) {
        b2[i] = new bool[wid]();
    }
    board[0]=b1;
    board[1]=b2;
}
Cellular::~Cellular(){
    for(int i = 0; i < hei; i++){
        delete[] b2[i];
    }
    delete [] b2;
}
void Cellular::print_board(bool **b){
    for (int i=0; i<hei; ++i){
        for (int j=0; j<wid; ++j)
            cout << (b[i][j] ? "▒▒▒" : "   ");
        cout << '\n';
    }
    cout << '\n';
}
void Cellular::print_board(bool **B1,bool **B2){
    for (int i=0; i<wid+2; i++){
        cout<<" ■ ";
    }
    cout<<endl;
    for (int i=0; i<hei; ++i){
        cout<<" ■ ";
        for (int j=0; j<wid; ++j){
            if(B1[i][j]==B2[i][j]){
                B1[i][j] =0;
                B2[i][j] =0;
                cout <<"   ";
            }
            if(B1[i][j]!=0)cout <<" ● ";
            if(B2[i][j]!=0)cout <<" ▲ ";
        }
        cout<<" ■ \n";
    }
    for (int i=0; i<wid+2; i++){
        cout<<" ■ ";
    }
    cout<<endl;
}
void Cellular::go(int x, int y, bool **now, bool **next){
    int n = count_neighbor(x, y, now);
    if (!now[x][y])
        if (n == 3)                 //復活
            next[x][y] = true;
        else                        //仍舊死亡
            next[x][y] = now[x][y];
    else
        if (n == 2 || n == 3)       //存活
            next[x][y] = true;
        else if (n == 0 || n == 1)  //死於孤單
            next[x][y] = false;
        else if (n >= 4)            //死於擁擠
            next[x][y] = false;
}
int Cellular::count_neighbor(int x, int y, bool **b){
    static const int dx[8] = {-1,-1,-1,0,0,1,1,1};
    static const int dy[8] = {-1,0,1,-1,1,-1,0,1};
    int n = 0;
    for (int i=0; i<8; ++i)
    {
        int mx = x + dx[i];
        int my = y + dy[i];
        if (mx >= 0 && mx < hei && my >= 0 && my < wid)
            n += b[mx][my];
    }
    return n;
}
bool** Cellular::get_board(int t){return board[t];}