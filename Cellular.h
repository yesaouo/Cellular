#include<iostream>
using namespace std;
class Cellular{
public:
    Cellular();
    int get_hei();
    int get_wid();
    int get_times();
    void print_board(bool **board);
    void go(int x, int y, bool **board, bool **next);
    int count_neighbor(int x, int y, bool **board);
private:
    int times,hei,wid;
};