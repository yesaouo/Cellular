#include<iostream>
#include<windows.h>
#include"Cellular.h"
#include"Load.h"
#include"Paint.h"
#include"Print.h"
using namespace std;
int main(){
    /*Cellular c;
    Board b(c.get_hei(),c.get_wid());
    c.print_board(b.get_board(0));
    for (int t=0; t<c.get_times(); ++t){
        for (int x=0; x<c.get_hei(); ++x)
            for (int y=0; y<c.get_wid(); ++y)
                c.go(x, y, b.get_board(t%2), b.get_board((t+1)%2));
        Sleep(1000);
        system("cls");
        c.print_board(b.get_board((t+1)%2));
    }*/

    load load_file("8746");
    print print_file(load_file.get_alive(),load_file.get_sizex(),load_file.get_sizey(),true);
    paint paint_file(9,9);
    paint_file.save("8746");
    
    system("pause");
    return 0;
}