////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 2                                //
// line.cc                                                                    //
// The class Line                                                             //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "line.hh"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////
// The namespace hw2                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw2 {

////////////////////////////////////////////////////////////////////////////////
// The constructor of Line                                                    //
////////////////////////////////////////////////////////////////////////////////
Line::Line() {
}

////////////////////////////////////////////////////////////////////////////////
// Extract from stream                                                        //
//                                                                            //
// Parameters:                                                                //
// is:  the istream object                                                    //
// obj: the line object to be extracted into from stream                      //
//                                                                            //
// Return Value:                                                              //
// the istream object                                                         //
////////////////////////////////////////////////////////////////////////////////
std::istream& operator>>( std::istream& is, Line& obj ) {
  is >> obj.click    >> obj.impression     >> obj.display_url
     >> obj.ad_id    >> obj.advertiser_id  >> obj.depth
     >> obj.position >> obj.query_id       >> obj.keyword_id
     >> obj.title_id >> obj.description_id >> obj.user_id;
  return is;
}

////////////////////////////////////////////////////////////////////////////////
// Insert into stream                                                         //
//                                                                            //
// Parameters:                                                                //
// os:  the ostream object                                                    //
// obj: the line object  to be inserted into the stream                       //
//                                                                            //
// Return Value:                                                              //
// the ostream object                                                         //
////////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<( std::ostream& os, const Line& obj ) {
  os << obj.click          << '\t' << obj.impression << '\t'
     << obj.display_url    << '\t' << obj.ad_id      << '\t'
     << obj.advertiser_id  << '\t' << obj.depth      << '\t'
     << obj.position       << '\t' << obj.query_id   << '\t'
     << obj.keyword_id     << '\t' << obj.title_id   << '\t'
     << obj.description_id << '\t' << obj.user_id;
  return os;
}

}
