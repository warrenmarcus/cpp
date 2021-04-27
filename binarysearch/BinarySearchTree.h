// BinarySearchTree.h
// after Mark A. Weiss, Chapter 4, Dr. Kerstin Voigt

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <cassert>
#include <iostream>
using namespace std;      

template <typename C>
class BinarySearchTree
{
  public:
    BinarySearchTree( ) : root{ nullptr }
    {
    }

    ~BinarySearchTree( ) 
    { 
        makeEmpty();
    }

    const C & findMin( ) const
    {
      assert(!isEmpty());
      return findMin( root )->data;
    }

    const C & findMax( ) const
    {
      assert(!isEmpty());
      return findMax( root )->data;
    }

    bool contains( const C & x ) const
    {
        return contains( x, root );
    }

    bool isEmpty( ) const
    {
        return (root == nullptr);
    }

    void printTree( ) const
    {
        if( isEmpty( ) )
            cout << "Empty tree" << endl;
        else
            printTree( root );
    }

    void makeEmpty( )
    {
        makeEmpty( root );
    }
    
    void insert( const C & x )
    {
        insert( x, root );
    }     

    void remove( const C & x )
    {
        remove( x, root );
    }

    void print_Internal() 
    {
        print_Internal(root,0);
    }

  private:
    

    struct BinaryNode
    {
        C data;
        BinaryNode* left;
        BinaryNode* right;

        BinaryNode( const C & theData, BinaryNode* lt, BinaryNode* rt )
          : data{ theData }, left{ lt }, right{ rt } 
        { }
    };

    BinaryNode* root;
    

    // Internal method to find the smallest item in a subtree t.
    // Return node containing the smallest item.    
    BinaryNode* findMin( BinaryNode* t ) const
    {
        if( t == nullptr )
            return nullptr;
        if( t->left == nullptr )
            return t;
        return findMin( t->left );
    }
    
    // Internal method to find the largest item in a subtree t.
    // Return node containing the largest item.
    BinaryNode* findMax( BinaryNode* t ) const
    {
        if( t != nullptr )
            while( t->right != nullptr )
                t = t->right;
        return t;
    }

    // Internal method to test if an item is in a subtree.
    // x is item to search for.
    // t is the node that roots the subtree.    
    bool contains( const C & x, BinaryNode* t ) const
    {
        if( t == nullptr )
            return false;
        else if( x < t->data )
            return contains( x, t->left );
        else if( t->data < x )
            return contains( x, t->right );
        else
            return true;    // Match
    }
    
    void printTree( BinaryNode* t) const
    {
        if( t != nullptr )
        {
            printTree( t->left);
            cout << t->data << " - ";
            printTree( t->right);
        }
    }

    void makeEmpty( BinaryNode* & t )
    {
        if( t != nullptr )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = nullptr;
    }
    
    // Internal method to insert into a subtree.
    // x is the item to insert.
    // t is the node that roots the subtree.
    // Set the new root of the subtree.    
    void insert( const C & x, BinaryNode* & t )
    {
        if( t == nullptr )
            t = new BinaryNode{ x, nullptr, nullptr };
        else if( x < t->data )
            insert( x, t->left );
        else if( t->data < x )
            insert( x, t->right );
        else
            ;  // Duplicate, do nothing
    }
    
    // Internal method to remove from a subtree.
    // x is the item to remove.
    // t is the node that roots the subtree.
    // Set the new root of the subtree.    
    void remove( const C & x, BinaryNode* & t )
    {
        if( t == nullptr )
            return;   // Item not found, do nothing
        if( x < t->data )
            remove( x, t->left );
        else if( t->data < x )
            remove( x, t->right );
        else if( t->left != nullptr && t->right != nullptr ) // Two children
        {
            t->data = findMin( t->right )->data;
            remove( t->data, t->right );
        }
        else
        {
            BinaryNode* oldNode = t;
            t = ( t->left != nullptr ) ? t->left : t->right;
            delete oldNode;
        }
    }

   void print_Internal(BinaryNode* t, int offset)
   {
     if (t == nullptr)
         return;

     for(int i = 1; i <= offset; i++) 
         cout << "...";
     cout << t->data << endl;
     print_Internal(t->left, offset + 1);
     print_Internal(t->right, offset + 1);
   }


};
#endif
