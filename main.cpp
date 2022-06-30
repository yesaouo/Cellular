#include<iostream>
#include<windows.h>
#include"Cellular.h"
#include"Load.h"
#include"Paint.h"
#include"Print.h"
using namespace std;
int main(){
    paint paint_file(33,11);
    int ptrx,ptry;
    while(cin >> ptrx >>ptry){
        cout << "\x1B[2J\x1B[H";
        paint_file.draw(ptry,ptrx);
        paint_file.save("8746");
        load load_file("8746");
        print print_file(load_file.get_alive(),load_file.get_sizex(),load_file.get_sizey(),true);
    }
    load load_file("8746");
    Cellular c(load_file.get_alive(),load_file.get_sizex(),load_file.get_sizey());
    c.print_board(c.get_board(0));
    for(int t=0; t<5; t++){
        for(int x=0; x<load_file.get_sizey(); x++)
            for(int y=0; y<load_file.get_sizex(); y++)
                c.go(x, y, c.get_board(t%2), c.get_board((t+1)%2));
        Sleep(1000);
        cout << "\x1B[2J\x1B[H";
        c.print_board(c.get_board((t+1)%2));
    }

    system("pause");
    return 0;
}
/*Cellular::Cellular():Board(){
    cout<<"演化次數:";cin>>times;
    cout<<"生存空間大小(長 寬):";cin>>hei>>wid;
}*/