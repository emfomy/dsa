////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 6                                //
// hw6_2.cpp                                                                  //
// The main functions                                                         //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
extern "C" {
#include "../avl.h"
#include "../bst.h"
#include "../rb.h"
}

using namespace std;

// Constants
const int kNumInput = 32;

// Functions
int string_compare( const void *pa, const void *pb, void *param );
void preorder_string_avl( const avl_node *node );
void preorder_string_bst( const bst_node *node );
void preorder_string_rb( const rb_node *node );

////////////////////////////////////////////////////////////////////////////////
// Main function                                                              //
////////////////////////////////////////////////////////////////////////////////
int main( int argc, char const *argv[] ) {
  ios::sync_with_stdio(false);

  // Create trees
  string str[kNumInput];
  auto avl_tree = avl_create(string_compare, nullptr, nullptr);
  auto bst_tree = bst_create(string_compare, nullptr, nullptr);
  auto rb_tree  = rb_create(string_compare, nullptr, nullptr);
  for( auto i = 0; i < kNumInput; ++i ) {
    getline(cin, str[i]);
    avl_probe(avl_tree, &str[i]);
    bst_probe(bst_tree, &str[i]);
    rb_probe(rb_tree, &str[i]);
  }

  // Display trees
  preorder_string_avl(avl_tree->avl_root);
  cout << endl;
  preorder_string_bst(bst_tree->bst_root);
  cout << endl;
  preorder_string_rb(rb_tree->rb_root);
  cout << endl;
  return 0;
}

////////////////////////////////////////////////////////////////////////////////
// The compare function of string                                             //
//                                                                            //
// Parameters:                                                                //
// pa: the pointer of a string object                                         //
// pb: the pointer of another string object                                   //
//                                                                            //
// Return Value:                                                              //
// whether a signed integral indicating the relation between the strings      //
////////////////////////////////////////////////////////////////////////////////
int string_compare( const void *pa, const void *pb, void *param ) {
  const string& a = *reinterpret_cast<const string*>(pa);
  const string& b = *reinterpret_cast<const string*>(pb);
  return a.compare(b);
}

////////////////////////////////////////////////////////////////////////////////
// Pre-order traversal of a AVL tree for string                               //
//                                                                            //
// Parameters:                                                                //
// node: the root node of the AVL tree                                        //
////////////////////////////////////////////////////////////////////////////////
void preorder_string_avl( const avl_node *node ) {
  if ( node == nullptr ) {
    return;
  }
  cout << *reinterpret_cast<string*>(node->avl_data) << ' ';
  if (node->avl_link[0] != nullptr || node->avl_link[1] != nullptr) {
    cout << '(';
    preorder_string_avl(node->avl_link[0]);
    cout << ", ";
    preorder_string_avl(node->avl_link[1]);
    cout << ')';
  }
}

////////////////////////////////////////////////////////////////////////////////
// Pre-order traversal of a height-bounded binary search tree for string      //
//                                                                            //
// Parameters:                                                                //
// node: the root node of the height-bounded binary search tree               //
////////////////////////////////////////////////////////////////////////////////
void preorder_string_bst( const bst_node *node ) {
  if ( node == nullptr ) {
    return;
  }
  cout << *reinterpret_cast<string*>(node->bst_data) << ' ';
  if (node->bst_link[0] != nullptr || node->bst_link[1] != nullptr) {
    cout << '(';
    preorder_string_bst(node->bst_link[0]);
    cout << ", ";
    preorder_string_bst(node->bst_link[1]);
    cout << ')';
  }
}

////////////////////////////////////////////////////////////////////////////////
// Pre-order traversal of a Red-Black tree for string                         //
//                                                                            //
// Parameters:                                                                //
// node: the root node of the Red-Black tree                                  //
////////////////////////////////////////////////////////////////////////////////
void preorder_string_rb( const rb_node *node ) {
  if ( node == nullptr ) {
    return;
  }
  cout << *reinterpret_cast<string*>(node->rb_data) << ' ';
  if (node->rb_link[0] != nullptr || node->rb_link[1] != nullptr) {
    cout << '(';
    preorder_string_rb(node->rb_link[0]);
    cout << ", ";
    preorder_string_rb(node->rb_link[1]);
    cout << ')';
  }
}
