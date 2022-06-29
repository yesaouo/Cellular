#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class paint{
public:
    paint(int x,int y){}
    paint(bool **matrix){}
    ~paint(){}
    void draw(int x,int y);
    void save(string filename);
    bool **get_value();
private:
    bool **value;
    int sizex,sizey;
};