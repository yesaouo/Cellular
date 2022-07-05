#include <iostream>
#include <fstream>
#include <string>
#include "Paint.h"
using namespace std;
paint::paint(int x,int y) : sizex(x), sizey(y){
    value = new bool*[y];
    for(int i = 0; i < y; i++){
        value[i] = new bool[x]{0};
    }
}
paint::paint(bool **matrix) : value(matrix){}
paint::~paint(){
    for(int i = 0; i < sizey; i++){
        delete[] value[i];
    }
    delete [] value;
}
void paint::draw(int x,int y){
    if(x>=sizex&&y>=sizey)cout<<"Error\n";
    else value[x][y]=(value[x][y])?0:1;
}
void paint::save(string filename){
    fstream file;
    file.open(".//folder//"+filename+".txt", ios::out | ios::trunc);
    for(int i = 0; i <sizey; i++){
        char ptr[sizex+1];
        for(int j = 0; j < sizex; j++){
            ptr[j] = '0'+value[i][j];
        }
        ptr[sizex] = '\n';
        file.write(ptr, sizex+1);
    }
    file.close();
    string ptr;
    ifstream in;
    bool fn=true;
    in.open(".//folder//Filelist.txt");
    while(in>>ptr){
        if(ptr==filename)fn=false;
    }
    in.close();
    if(fn){
        file.open(".//folder//Filelist.txt", ios::out | ios::app);
        char *f=new char[filename.size()+1];
        for(int i = 0; i <filename.size(); i++)f[i]=filename[i];
        f[filename.size()] ='\n';
        file.write(f,filename.size()+1);
        file.close();
    }
}
bool **paint::get_value() {return value;}