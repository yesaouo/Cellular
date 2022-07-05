#include<iostream>
#include<fstream>
#include<string>
#include"Load.h"
using namespace std;
load::load(string filename){
    string ptr;
    ifstream in;
    in.open(".//folder//"+filename+".txt");
    sizex=0;
    sizey=0;
    while(in>>ptr){
        if(ptr.size()>sizex)sizex=ptr.size();
        sizey++;
    }
    in.close();
    alive = new bool*[sizey];
    for(int i = 0; i < sizey; i++){
        alive[i] = new bool[sizex]{0};
    }
    in.open(".//folder//"+filename+".txt");
    int j=0;
    while(in>>ptr){
        for(int i=0;i<ptr.size();i++){
            if(ptr[i]!='0')alive[j][i] = true;
        }
        j++;
    }
    in.close();
}
load::~load(){
    for(int i = 0; i < sizey; i++){
        delete[] alive[i];
    }
    delete [] alive;
}
bool load::get_alive(int x, int y){return alive[x][y];}
bool** load::get_alive(){return alive;}
int load::get_sizex(){return sizex;}
int load::get_sizey(){return sizey;}