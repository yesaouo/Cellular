#include".\function\Cellular.h"
#include".\function\Load.h"
#include".\function\Paint.h"
#include".\function\Print.h"
#include<iostream>
#include<windows.h>
#include<string>
#include<vector>
#include<fstream>
#include<cstdio>
using namespace std;
string getname(char a){
    cin.clear();
    cin.sync();
    cout<<"Filename"<<a<<":";
    string filename;
    cin>>filename;
    while(filename=="Filelist"){
        cout<<"You don't have permission to specify this file.\nRetype:";
        cin>>filename;
    }
    return filename;
}
void Paint(string filename){
    cout<<"Range(width height):";
    int ptrx,ptry;
    cin >> ptrx>>ptry;
    paint paint_file(ptrx,ptry);
    while(cin >> ptrx >>ptry){
        cout << "\x1B[2J\x1B[H";
        paint_file.draw(ptry,ptrx);
        paint_file.save(filename);
        load load_file(filename);
        print print_file(load_file.get_alive(),load_file.get_sizex(),load_file.get_sizey(),true);
    }
}
void Show(string filename){
    load load_file(filename);
    print print_file(load_file.get_alive(),load_file.get_sizex(),load_file.get_sizey(),true);
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
void Print(string f1, string f2){
    load load_1(f1);
    load load_2(f2);
    if((load_1.get_sizex()!=load_2.get_sizex())||(load_1.get_sizey()!=load_2.get_sizey())){
        cout<<"The files are incompatible\n";
        return;
    }
    Cellular c1(load_1.get_alive(),load_1.get_sizex(),load_1.get_sizey());
    Cellular c2(load_2.get_alive(),load_2.get_sizex(),load_2.get_sizey());
    cout<<"Evolution times:";
    int times;
    cin >> times;
    cout<<"\x1B[2J\x1B[H";
    c1.print_board(c1.get_board(0),c2.get_board(0));
    for(int t=0; t<times; t++){
        for(int x=0; x<load_1.get_sizey(); x++)
            for(int y=0; y<load_1.get_sizex(); y++){
                c1.go(x, y, c1.get_board(t%2), c1.get_board((t+1)%2));
                c2.go(x, y, c2.get_board(t%2), c2.get_board((t+1)%2));
            }
        Sleep(500);
        cout << "\x1B[2J\x1B[H";
        c1.print_board(c1.get_board((t+1)%2),c2.get_board((t+1)%2));
    }
}
void Filelist(){
    cout << "\x1B[2J\x1B[H";
    ifstream in;
    in.open(".\\folder\\Filelist.txt");
    string ptr;
    while(in>>ptr){
        cout<<ptr<<endl;
    }
    in.close();
    cout<<"----------------------------------------\n";
}
void Deletefile(string filename){
    string ptr;
    vector<string>strvec;
    ifstream in;
    in.open(".\\folder\\Filelist.txt");
    while(in>>ptr){
        if(ptr!=filename)strvec.push_back(ptr);
    }
    in.close();
    filename=".\\folder\\"+filename+".txt";
    char *fn=new char[filename.size()+1];
    for(int i=0;i<filename.size(); i++)fn[i]=filename[i];
    fn[filename.size()]='\0';
    remove(fn);
    cout<<strerror(errno)<<endl;
    delete fn;
    ofstream out;
    out.open(".\\folder\\Filelist.txt");
    for(int i=0;i<strvec.size(); i++)out<<strvec[i]<<endl;
    out.close();
}
void Illustrate(){
    cin.clear();
    cin.sync();
    cout<<"Enter '0' to end this program.\n";
    cout<<"Enter '1' to make a file.\n";
    cout<<"Enter '2' to show a file.\n";
    cout<<"Enter '3' to cellularization a file.\n";
    cout<<"Enter '4' to compete two files.\n";
    cout<<"Enter '5' to show the filelist.\n";
    cout<<"Enter '6' to delete a file\n";
}
int main(){
    int Do;
    Illustrate();
    while(cin>>Do){
        if(Do==0)break;
        else if(Do==1)Paint(getname(' '));
        else if(Do==2)Show(getname(' '));
        else if(Do==3)Print(getname(' '));
        else if(Do==4)Print(getname('2'),getname('1'));
        else if(Do==5)Filelist();
        else if(Do==6)Deletefile(getname(' '));
        Illustrate();
    }
    system("pause");
    return 0;
}