#include <iostream>
#include <conio.h>
using namespace std;

	bool gameOver;
	const int width = 30;
	const int height = 14;
	int x, y, fruitX, fruitY, fruitX2, fruitY2, score, nTail = 0, k=0;
    int tailX[100], tailY[100];
	enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
	eDirection dir;

	void Setup() {
	    gameOver = false;
	    dir = STOP;
	    x = width/2;
	    y = height/2;
	    fruitX = rand()%width;
	    fruitY = rand()%height;
	    fruitX2 = rand()%width;
	    fruitY2 = rand()%height;
	    score = 0;
	}

	void Draw() {
	    system("cls");
	    for (int i=0; i<20; i++) {cout << " ";}
	    for (int i=0; i<=width; i++) {cout << ".";}
	    cout << endl;
        tailX[0] = x; tailY[0] = y;
	    for (int i=0; i<height+1; i++) {
            for (int i=0; i<20; i++) {cout << " ";}
            for (int j=0; j<width+1; j++) {
                k=0;
                if (j==0 || j==width) {cout << ":";}
                else {if (i==y && j==x) {cout << 'O';}
                    else {if (i==fruitY && j==fruitX || i==fruitY2 && j==fruitX2) {cout << "F";}
                        else {  for (int v=0; v<=nTail; v++) {
                                if (i == tailY[v] && j == tailX[v]) {cout << "o"; k=3;}}
                                if (k==0) {cout << " ";}}}}
            }
            cout << endl;}

        for (int i=0; i<20; i++) {cout << " ";}
        cout << ":";
	    for (int i=1; i<width; i++) {cout << ".";}
	    cout << ":" << endl << endl;
	    cout << "                                WELCOME!" << endl << endl;
	    cout << "              Press 'a' to go LEFT, 'd' - RIGHT, 'w' - UP," << endl;
	    cout << "                  's' - DOWN, 'c' - to END the game." << endl;
	    cout << "                   You can go out of the frame, but" << endl;
	    cout << "                crossing snake's tail will finish a try." << endl << endl;
	    cout << "                                SCORE: " << score << endl << endl;
	}

	void Input() {
	    if (_kbhit()) {
                switch(_getch()) {
                    case 'a' : dir = LEFT; break;
                    case 'd' : dir = RIGHT; break;
                    case 's' : dir = DOWN; break;
                    case 'w' : dir = UP; break;
                    case 'c' : gameOver = true; break;
                }
	    }

	}

    void Logic() {
        int prevX = tailX[0], prevY = tailY[0], prevX2, prevY2;
        for (int i=0; i<=nTail; i++) {
            prevX2 = tailX[i]; prevY2 = tailY[i];
            tailX[i] = prevX; tailY[i] = prevY;
            prevX = prevX2; prevY = prevY2;
        }

        switch(dir) {
            case LEFT: x--; break;
            case RIGHT: x++; break;
            case DOWN: y++; break;
            case UP: y--; break;
        }
        if (x<1) {x=width-1;}
        else {if (x>width-1) {x=1;}}
        if (y<0) {y=height+1;}
        else {if (y>=height+1) {y=1;}}

        for (int i=1; i<=nTail; i++) {
            if (x == tailX[i] && y == tailY[i]) {gameOver = true;}
        }

        if (y==fruitY && x==fruitX) {
            score+=10; nTail++;
            fruitX = rand()%width;
            fruitY = rand()%height;}
	    else {if (y==fruitY2 && x==fruitX2) {
            score+=10; nTail++;
            fruitX2 = rand()%width;
            fruitY2 = rand()%height;}}
	}

	int main(){
	    Setup();
	    while (!gameOver) {
            Draw();
            Input();
            Logic();
	    }
        return 0;
    }
