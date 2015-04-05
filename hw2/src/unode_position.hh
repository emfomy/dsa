////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 2                                //
// unode_position.hh                                                          //
// The header file of UNodePosition                                           //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW2_UNODE_POSITION_HH_

#define HW2_UNODE_POSITION_HH_

#include <unordered_map>
#include "hw2.hh"
#include "line.hh"
#include "unode_depth.hh"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw2                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw2 {

////////////////////////////////////////////////////////////////////////////////
// The class of a Position node in U-tree                                     //
////////////////////////////////////////////////////////////////////////////////
class UNodePosition {
 public:
  // The the map of Depth nodes
  UMapDepth child;

  UNodePosition();
  void insert( Line& );
  UNodeDepth& operator[]( Depth );
};

////////////////////////////////////////////////////////////////////////////////
// The hash map of Position to UNodePosition                                  //
////////////////////////////////////////////////////////////////////////////////
typedef std::unordered_map<Position, UNodePosition> UMapPosition;

}

#endif
