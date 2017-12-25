#include <iostream>
#include <vector>

#include "Stack.h"

using namespace std;

int main()
{
    stack<int> s = { 7, 8, 6 ,5, 2, 4, 4, 1, 3 };
    s.print();

    s.push(78);
    cout << "after push stack size: " << s.size() << endl;
    s.push(6767);
    cout << "after push stack size: " << s.size() << endl;
    s.push(4321);
    cout << "after push stack size: " << s.size() << endl;
    s.print();

    if (s.isEmpty())
    {
        cout << " stack is empty!!!" << endl;
    }
    else
    {
        cout << " stack is not empty!!!" << endl;
    }

    s.pop();
    cout << "after pop stack size: " << s.size() << endl;
    s.pop();
    cout << "after pop stack size: " << s.size() << endl;
    s.pop();
    cout << "after pop stack size: " << s.size() << endl;
    s.pop();
    cout << "after pop stack size: " << s.size() << endl;
    s.pop();
    cout << "after pop stack size: " << s.size() << endl;
    s.pop();
    cout << "after pop stack size: " << s.size() << endl;
    s.pop();
    cout << "after pop stack size: " << s.size() << endl;

    s.print();
}