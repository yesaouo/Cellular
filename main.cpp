#include<iostream>
#include<windows.h>
#include<string>
#include"Cellular.h"
#include"Load.h"
#include"Paint.h"
#include"Print.h"
using namespace std;
string getname(){
    cin.clear();
    cin.sync();
    cout<<"Filename:";
    string filename;
    cin>>filename;
    return filename;
}
void Paint(){
    cout<<"Range(width height):";
    int ptrx,ptry;
    cin >> ptrx>>ptry;
    paint paint_file(ptrx,ptry);
    while(cin >> ptrx >>ptry){
        cout << "\x1B[2J\x1B[H";
        paint_file.draw(ptry,ptrx);
        paint_file.save("8746");
        load load_file("8746");
        print print_file(load_file.get_alive(),load_file.get_sizex(),load_file.get_sizey(),true);
    }
}
void Print(string filename){
    load load_file(filename);
    Cellular c(load_file.get_alive(),load_file.get_sizex(),load_file.get_sizey());
    cout<<"Evolution times:";
    int times;
    cin >> times;
    cout<<"\x1B[2J\x1B[H";
    c.print_board(c.get_board(0));
    for(int t=0; t<times; t++){
        for(int x=0; x<load_file.get_sizey(); x++)
            for(int y=0; y<load_file.get_sizex(); y++)
                c.go(x, y, c.get_board(t%2), c.get_board((t+1)%2));
        Sleep(500);
        cout << "\x1B[2J\x1B[H";
        c.print_board(c.get_board((t+1)%2));
    }
}
int main(){
    Paint();
    Print(getname());

    system("pause");
    return 0;
}