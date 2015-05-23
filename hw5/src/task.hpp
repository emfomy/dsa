////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 5                                //
// task.hpp                                                                   //
// The header file of Task                                                    //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW5_TASK_HPP_

#define HW5_TASK_HPP_

#include <cstdint>

////////////////////////////////////////////////////////////////////////////////
// The namespace hw5                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw5 {

////////////////////////////////////////////////////////////////////////////////
// The types                                                                  //
////////////////////////////////////////////////////////////////////////////////
typedef uint64_t Task;
typedef uint32_t ID;
typedef uint32_t Priority;

////////////////////////////////////////////////////////////////////////////////
// Create a task by ID and priority                                           //
//                                                                            //
// Parameters:                                                                //
// id: the ID                                                                 //
// p:  the priority                                                           //
//                                                                            //
// Return Value:                                                              //
// the task                                                                   //
////////////////////////////////////////////////////////////////////////////////
Task CreateTask( ID id, Priority p ) {
  Task task;
  reinterpret_cast<uint32_t*>(&task)[0] = UINT32_MAX-id;
  reinterpret_cast<uint32_t*>(&task)[1] = p;
  return task;
}

////////////////////////////////////////////////////////////////////////////////
// Get the task ID                                                            //
//                                                                            //
// Parameters:                                                                //
// task: the task                                                             //
//                                                                            //
// Return Value:                                                              //
// the task ID                                                                //
////////////////////////////////////////////////////////////////////////////////
ID TaskID( Task task ) {
  return (UINT32_MAX-reinterpret_cast<uint32_t*>(&task)[0]);
}

////////////////////////////////////////////////////////////////////////////////
// Get the task priority                                                      //
//                                                                            //
// Parameters:                                                                //
// task: the task                                                             //
//                                                                            //
// Return Value:                                                              //
// the task priority                                                          //
////////////////////////////////////////////////////////////////////////////////
Priority TaskPriority( Task task ) {
  return (reinterpret_cast<uint32_t*>(&task)[1]);
}

}

#endif
