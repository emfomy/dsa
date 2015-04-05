////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 2                                //
// hw2.hh                                                                     //
// The header file of namespace hw2                                           //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW2_HW2_HH_

#define HW2_HW2_HH_

#include <cstdint>
#include <unordered_set>

////////////////////////////////////////////////////////////////////////////////
// The namespace hw2                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw2 {

////////////////////////////////////////////////////////////////////////////////
// Base types                                                                 //
////////////////////////////////////////////////////////////////////////////////
typedef uint64_t UserID; 
typedef uint64_t AdID;
typedef uint64_t QueryID;
typedef uint64_t Position;
typedef uint64_t Depth;
typedef uint64_t Click;
typedef uint64_t Impression;
typedef uint64_t DisplayURL;
typedef uint64_t AdvertiserID;
typedef uint64_t KeywordID;
typedef uint64_t TitleID;
typedef uint64_t DescriptionID;

////////////////////////////////////////////////////////////////////////////////
// The hash set of UserID                                                     //
////////////////////////////////////////////////////////////////////////////////
typedef std::unordered_set<UserID> SetUserID;

}

#endif
