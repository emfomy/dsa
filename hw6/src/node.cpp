////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 6                                //
// node.cpp                                                                   //
// The class Node                                                             //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "node.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw6                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw6 {

////////////////////////////////////////////////////////////////////////////////
// The constructor of Node                                                    //
// Initialize by ID                                                           //
//                                                                            //
// Parameters:                                                                //
// id:    the ID of this node                                                 //
// price: the price of this node                                              //
////////////////////////////////////////////////////////////////////////////////
Node::Node( const int id, const int price ) {
  id_ = id;
  parent_ = this;
  price_tree_ = avl_create(price_compare, nullptr, nullptr);
  avl_probe(price_tree_, price);
}

////////////////////////////////////////////////////////////////////////////////
// Get the ID of this node                                                    //
// Return Value:                                                              //
// the ID of this node                                                        //
////////////////////////////////////////////////////////////////////////////////
int Node::id() {
  return id_;
}

////////////////////////////////////////////////////////////////////////////////
// Find the owner of this node                                                //
//                                                                            //
// Return Value:                                                              //
// find the root node of this node                                            //
////////////////////////////////////////////////////////////////////////////////
Node* Node::Find() {
  return (this == parent_ ? this : (parent_ = parent_->Find()));
}

////////////////////////////////////////////////////////////////////////////////
// Merge another node to this node                                            //
//                                                                            //
// Parameters:                                                                //
// that: another node                                                         //
////////////////////////////////////////////////////////////////////////////////
void Node::Merge( Node* that ) {
  auto p = this->Find(), q = that->Find();
  if ( p != q ) {
    q->parent_ = p;
    price_merge(q->price_tree_->avl_root, p->price_tree_);
  }
}

////////////////////////////////////////////////////////////////////////////////
// Count the maximum number of games that is afforded                         //
//                                                                            //
// Parameters:                                                                //
// money: the money                                                           //
//                                                                            //
// Return Value:                                                              //
// the number of games                                                        //
////////////////////////////////////////////////////////////////////////////////
int Node::Afford( const long long int money ) {
  return price_afford(price_tree_->avl_root, money);
}

////////////////////////////////////////////////////////////////////////////////
// The compare function of price                                              //
//                                                                            //
// Parameters:                                                                //
// pa: the pointer of a price                                                 //
// pb: the pointer of another price                                           //
//                                                                            //
// Return Value:                                                              //
// whether a signed integral indicating the relation between the prices       //
////////////////////////////////////////////////////////////////////////////////
int price_compare( const void *pa, const void *pb, void *param ) {
  const int& a = *reinterpret_cast<const int*>(pa);
  const int& b = *reinterpret_cast<const int*>(pb);
  return (a < b);
}

////////////////////////////////////////////////////////////////////////////////
// Merge all AVL nodes to another AVL tree                                    //
//                                                                            //
// Parameters:                                                                //
// node: the AVL node                                                         //
// tree: the AVL tree                                                         //
////////////////////////////////////////////////////////////////////////////////
void price_merge( avl_node *node, avl_table *tree ) {
  if ( node == nullptr ) {
    return;
  }
  avl_probe(tree, node->avl_data);
  price_merge(node->avl_link[0], tree);
  price_merge(node->avl_link[1], tree);
}

////////////////////////////////////////////////////////////////////////////////
// Count the maximum number of games that is afforded                         //
//                                                                            //
// Parameters:                                                                //
// node: the AVL node                                                         //
// money: the money                                                           //
//                                                                            //
// Return Value:                                                              //
// the number of games                                                        //
////////////////////////////////////////////////////////////////////////////////
int price_afford( avl_node *node, long long int money ) {
  while( node == nullptr ) {
    return 0;
  }

  // Not enough money
  if ( node->avl_sum[0] > money ) {
    return price_afford(node->avl_link[0], money);
  }

  // Enough money
  money -= node->avl_sum[0];
  auto number = money / node->avl_data;
  if ( number <= node->avl_cnt ) {
    return (node->avl_cnode[0] + number);
  }

  // Too much money
  money -= node->avl_data * node->avl_cnt;
  return (price_afford(node->avl_link[1], money) +
      node->avl_cnode[0] + node->avl_cnt);
}

}
