////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 6                                //
// node.hpp                                                                   //
// The header file of Node                                                    //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW6_GAME_HPP_

#define HW6_GAME_HPP_

extern "C" {
#include "../avl_ntudsa.h"
}

////////////////////////////////////////////////////////////////////////////////
// The namespace hw6                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw6 {

////////////////////////////////////////////////////////////////////////////////
// The class of a node                                                        //
////////////////////////////////////////////////////////////////////////////////
class Node {
 private:
  // the ID of this node
  int id_;

  // the parent of this node
  Node* parent_;

  // the price tree under this node
  avl_table* price_tree_;

 public:
  Node( const int id, const int price );

  int id();

  Node* Find();
  void Merge( Node* that );
  int Afford( const long long int money );
};

// AVL tree functions
int price_compare( const void *pa, const void *pb, void *param );
void price_merge( avl_node *node, avl_table *tree );
int price_afford( avl_node *node, long long int money );

}

#endif
