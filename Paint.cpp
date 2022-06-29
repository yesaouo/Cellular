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
void paint::draw(int x,int y){value[x][y]=(value[x][y])?0:1;}
void paint::save(string filename){
    fstream file;
    file.open(filename+".txt", ios::out | ios::trunc);
    for(int i = 0; i <sizey; i++){
        char ptr[sizex+1];
        for(int j = 0; j < sizex; j++){
            ptr[j] = '0'+value[i][j];
        }
        ptr[sizex] = '\n';
        file.write(ptr, sizex+1);
    }
    file.close();
}
bool **paint::get_value() {return value;}