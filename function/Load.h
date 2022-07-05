#ifndef LOAD_H
#define LOAD_H
#include<iostream>
#include<string>
using namespace std;
class load{
public:
    load(string filename);
    ~load();
    bool get_alive(int x,int y);
    bool** get_alive();
    int get_sizex();
    int get_sizey();
private:
    bool **alive;
    int sizex,sizey;
};
#endif