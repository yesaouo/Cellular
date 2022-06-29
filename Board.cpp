/*#include<iostream>
#include"Board.h"
#include"Loadfile.h"
using namespace std;
Board::Board(int a,int b){
    board1 = new bool*[a];
    board2 = new bool*[a];
    for(int i = 0; i < a; ++i) {
        board1[i] = new bool[b]();
        board2[i] = new bool[b]();
    }
    board[0]=board1;
    board[1]=board2;
    cout<<"�]�w�ͦs�ӭM�y�СA���i�W�L�ͦs�Ŷ�(0 0�פ��J):"<<endl;
    int x,y;
    while(cin >>x>>y){
        if((x==0&&y==0)||(x>b&&y>a))break;
        board[0][x][y]= true;
    }
}
Board::Board(string filename):Loadfile(filename){
    board1 = get_board();
    board2 = new bool*[get_size()];
    for(int i = 0; i < get_size(); ++i) {
        board2[i] = new bool[get_size()]();
    }
    board[0]=board1;
    board[1]=board2;
}*/