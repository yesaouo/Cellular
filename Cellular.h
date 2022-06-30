#include<iostream>
using namespace std;
class Cellular{
public:
    Cellular(bool **matrix,int x,int y);
    ~Cellular();
    void print_board(bool **b);
    void go(int x, int y, bool **now, bool **next);
    int count_neighbor(int x, int y, bool **b);
    bool **get_board(int t);
private:
    bool **board[2], **b1, **b2;
    int hei,wid;
};