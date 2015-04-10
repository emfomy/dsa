////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 2                                //
// unode_pos_dep.hh                                                           //
// The header file of UNodePosDep                                           //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW2_UNODE_POS_DEP_HH_

#define HW2_UNODE_POS_DEP_HH_

#include <unordered_map>
#include "hw2.hh"
#include "line.hh"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw2                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw2 {

////////////////////////////////////////////////////////////////////////////////
// The class of a Position-Depth node in U-tree                               //
////////////////////////////////////////////////////////////////////////////////
class UNodePosDep {
 public:
  // The the total click number
  Click click;

  // The the total impression number
  Impression impression;

  UNodePosDep();
  void insert( const Line& );
  friend std::ostream& operator<<( std::ostream&, const UNodePosDep& );
};

////////////////////////////////////////////////////////////////////////////////
// The hash map of PosDep to UNodePosDep                                      //
////////////////////////////////////////////////////////////////////////////////
typedef std::unordered_map<PosDep, UNodePosDep> UMapPosDep;

}

#endif
