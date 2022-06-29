#include<iostream>
#include"Cellular.h"
using namespace std;
Cellular::Cellular(){
    cout<<"�t�Ʀ���:";
    cin>>times;
    cout<<"�ͦs�Ŷ��j�p(�� �e):";
    cin>>hei>>wid;
}
int Cellular::get_hei(){return hei;}
int Cellular::get_wid(){return wid;}
int Cellular::get_times(){return times;}
void Cellular::print_board(bool **board){
    for (int x=0; x<hei; ++x)
    {
        for (int y=0; y<wid; ++y)
            cout << (board[x][y] ? '@' : '*');
        cout << '\n';
    }
    cout << '\n';
}
void Cellular::go(int x, int y, bool **board, bool **next){
    int n = count_neighbor(x, y, board);
    if (!board[x][y])
        if (n == 3)                 //�_��
            next[x][y] = true;
        else                        //���¦��`
            next[x][y] = board[x][y];
    else
        if (n == 2 || n == 3)       //�s��
            next[x][y] = true;
        else if (n == 0 || n == 1)  //����t��
            next[x][y] = false;
        else if (n >= 4)            //�������
            next[x][y] = false;
}
int Cellular::count_neighbor(int x, int y, bool **board){
    static const int dx[8] = {-1,-1,-1,0,0,1,1,1};
    static const int dy[8] = {-1,0,1,-1,1,-1,0,1};
    int n = 0;
    for (int i=0; i<8; ++i)
    {
        int mx = x + dx[i];
        int my = y + dy[i];
        if (mx >= 0 && mx < hei && my >= 0 && my < wid)
            n += board[mx][my];
    }
    return n;
}