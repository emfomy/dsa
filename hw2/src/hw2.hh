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
typedef uint32_t AdID;
typedef uint32_t QueryID;
typedef uint16_t Position;
typedef uint16_t Depth;
typedef uint32_t Click;
typedef uint32_t Impression;
typedef uint64_t DisplayURL;
typedef uint16_t AdvertiserID;
typedef uint32_t KeywordID;
typedef uint32_t TitleID;
typedef uint32_t DescriptionID;

////////////////////////////////////////////////////////////////////////////////
// The hash set of UserID                                                     //
////////////////////////////////////////////////////////////////////////////////
typedef std::unordered_set<UserID> SetUserID;

}

#endif
