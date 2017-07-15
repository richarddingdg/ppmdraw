//use g++ main.cpp -std=c++11
 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#define SIZE 2048
using namespace std;
struct rgb
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
};
rgb board[SIZE][SIZE] = {};

int DIST(int, int);
int DIST(int xa, int ya, int xb, int yb) {
    return (int)(sqrt((xa-xb) *(xa-xb)+(ya-yb) *(ya-yb)));
}                                                           // euclid dist
double DISTF(int, int);
double DISTF(int xa, int ya, int xb, int yb) {
    return (sqrt((xa-xb) *(xa-xb)+(ya-yb) *(ya-yb)));
}                                                           // euclid dist (float ver(or double, sort of))
void pixdrw(int, int, int, int, int);
void pixdrw(int x, int y, int r, int g, int b)
{
    board[x][y].r = r;
    board[x][y].g = g;
    board[x][y].b = b;
}

//__maindraw part


void maindraw(void);
void maindraw() 
{
    // Insert code here
}


// _inside part

void pushbin(int, int);
void pushasc(int, int);
FILE *fp;
int main(int argc, char *argv[]){
    srand((unsigned)time(NULL));
    maindraw();
    const char* filename = argv[1] ? argv[1]:"Default.ppm"; // if I grasp cmdline switch I maybe rewrite them
    fp = fopen(filename,"wb");
    bool isbin = true;                                      // decide push as binary or ascll.I do admit it is ugly.
    fprintf(fp, "P%d\n%d %d\n255\n",isbin ? 6:3, SIZE, SIZE);
    for(int j=0;j<SIZE;j++)
        for(int i=0;i<SIZE;i++)                             // To let the North-South y axis and West-East x axis
            isbin ? pushbin(i,j):pushasc(i, j);             // Maybe I should use conditional compile?
    fclose(fp);
    return 0;
}
void pushbin(int i, int j){                             
    static unsigned char pixel[3];
    pixel[0] = board[i][j].r&255;
    pixel[1] = board[i][j].g&255;
    pixel[2] = board[i][j].b&255;
    fwrite(pixel, 1, 3, fp);
}
void pushasc(int i, int j) {
    fprintf(fp, "%d %d %d ", board[i][j].r, board[i][j].g, board[i][j].b);
}

