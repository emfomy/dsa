////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 2                                //
// unode_depth.hh                                                             //
// The header file of UNodeDepth                                              //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW2_UNODE_DEPTH_HH_

#define HW2_UNODE_DEPTH_HH_

#include <unordered_map>
#include "hw2.hh"
#include "line.hh"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw2                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw2 {

////////////////////////////////////////////////////////////////////////////////
// The class of a Depth node in U-tree                                        //
////////////////////////////////////////////////////////////////////////////////
class UNodeDepth {
 public:
  // The the total click number
  Click click;

  // The the total impression number
  Impression impression;

  UNodeDepth();
  void insert( Line& );
  friend std::ostream& operator<<( std::ostream&, const UNodeDepth& );
};

////////////////////////////////////////////////////////////////////////////////
// The hash map of Depth to UNodeDepth                                        //
////////////////////////////////////////////////////////////////////////////////
typedef std::unordered_map<Depth, UNodeDepth> UMapDepth;

}

#endif
