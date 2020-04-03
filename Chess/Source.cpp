// using standard exceptions
#include <iostream>
#include <exception>
#include "ChessBoard.h"
#include "Figure.h"

using namespace std;

class MyClass1
{
public:
    MyClass1(int c, int d)
    {
        this->c = c;
        this->d = d;
    }

    void SetC(int c)
    {
        this->c = c;
    }

    void SetD(int d)
    {
        this->d = d;
    }

private:
    int c;
    int d;
};

class MyClass
{
public:
    MyClass(int a, int b, MyClass1* x)
    {
        this->a = a;
        this->b = b;
        this->x = x;
    }

    void SetA(int a)
    {
        this->a = a;
    }

    void SetB(int b)
    {
        this->b = b;
    }

private:
    int a;
    int b;
    MyClass1* x;
};

void Function(MyClass x)
{
    x.SetA(10);
    x.SetB(10);
}

int main() 
{
    //try
    //{
    //    throw myex;
    //}
    //catch (exception & e)
    //{
    //    cout << e.what() << '\n';
    //}
    //system("pause");
    //return 0;
    //    ChessBoard chessBoard = ChessBoard();
    //Function(x);
    int c = 10;
    int& d = c;
    int* f = &c;
    int g = *f;
    g++;
    d++;
    system("pause");
}