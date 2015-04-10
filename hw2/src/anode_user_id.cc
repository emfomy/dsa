////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 2                                //
// anode_user_id.cc                                                           //
// The class ANodeUserID                                                      //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "anode_user_id.hh"

////////////////////////////////////////////////////////////////////////////////
// The namespace hw2                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw2 {

////////////////////////////////////////////////////////////////////////////////
// The constructor of ANodeUserID                                             //
////////////////////////////////////////////////////////////////////////////////
ANodeUserID::ANodeUserID() {
  click = 0;
  impression = 0;
}

////////////////////////////////////////////////////////////////////////////////
// Insert a line object under this node                                       //
//                                                                            //
// Parameters:                                                                //
// line: the inserted line object                                             //
////////////////////////////////////////////////////////////////////////////////
void ANodeUserID::insert( const Line& line ) {
  click += line.click;
  impression += line.impression;
}

////////////////////////////////////////////////////////////////////////////////
// Compute click-through-rate                                                 //
//                                                                            //
// Return:                                                                    //
// the click-through-rate of this node                                        //
////////////////////////////////////////////////////////////////////////////////
double ANodeUserID::ctr() {
  return ( impression == 0 ) ? 0.0 : ((double) click / (double) impression);
}

}
