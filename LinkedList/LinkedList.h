// LinkedList.h
#ifndef LL_H
#define LL_H
#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
private:
    struct NodeType
    {
        T data;
        NodeType* next;
        
        NodeType(): data(), next(nullptr)
        {}
        
        NodeType(const T& d): data(d), next(nullptr)
        {}
    };
    
public:
    // Default constructor
    LinkedList(): size(0)
    {
        head = new NodeType;
    }
    
    //Destructor
    ~LinkedList()
    {
        make_empty();
    }
    
    // Returns the list to the empty state.
    void make_empty()
    {
        head->next = nullptr;
        size = 0;
        
    }
    
    // Returns the number of items in the list.
    int get_size() const
    {
        return size;
        
    }
    
    // Checks if item is in the list.
    bool find(const T& item) const
    {
        NodeType * ptr = head;
        &find = false;
        for (int i = 0 ; i < size; i++)
        {
            if (ptr->next == item)
            {
                &find = true;
            }
            else
            {
                ptr->next = ptr->next->next;
            }
            
        }
        return &find;
    }
    
    // Inserts item at the front.
    void push_front(const T& item)
    {
        NodeType* ptr = new NodeType(item);
        ptr->next = head->next;
        head->next = ptr;
        size++;
        
    }
    
    // Removes the first item.
    void pop_front()
    {
        
        NodeType* ptr = head->next;
        if (ptr != nullptr)
        {
            head->next = ptr->next;
            delete ptr; size--;
        }
        
    }
    
    // Prints the list.
    void print() const
    {
        cout << "The list is: " << endl;
        NodeType* ptr = head->next;
        while (ptr->next != nullptr)
        {
            NodeType* temp = ptr->next;
            ptr = temp;
            cout << ptr->data << ", ";
        }
        cout << endl;
    }
    
private:
    int size;    // the size of the linked list.
    NodeType* head;    // points to the header node.
};

#endif

