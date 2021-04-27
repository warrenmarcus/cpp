//
// Linked list that adds values to a vector and then removes a certain number
//      of values that is determined by the user.
#include <iostream>
#include "LinkedList.h"
#include <string>
using namespace std;


int main ()
{
    int num = 1;
    int remove;
    string name;
    
    LinkedList<int> ll;
    LinkedList<string> sl;
    
    
    cout << "Create list of integers: (enter '0' to stop)" << endl;
    
    while (num != 0)
    {
        cin >> num;
        ll.push_front(num);
    }
    
    cout << "How many values do you want to remove? " ;
    cin >> remove;
    
    for (int i = 0; i < remove; i++)
    {
        ll.pop_front();
    }
    
    ll.print();
    cout << endl;
    
    cout << "Create a list of strings: (enter 'exit' to stop)" << endl;
    
    while (name != "exit")
    {
        cin >> name;
        sl.push_front(name);
    }
    
    cout << "How many values do you want to remove? " ;
    cin >> remove;
    
    
    for (int i = 0; i < remove; i++)
    {
        sl.pop_front();
    }
    
    sl.print();
    
    
    return 0;
}
