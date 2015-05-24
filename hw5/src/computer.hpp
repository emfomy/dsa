////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Homework 5                                //
// computer.hpp                                                               //
// The header file of Computer                                                //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef HW5_COMPUTER_HPP_

#define HW5_COMPUTER_HPP_

#include "binomial_heap.hpp"
#include "task.hpp"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////
// The namespace hw5                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace hw5 {

////////////////////////////////////////////////////////////////////////////////
// The type Computer                                                          //
////////////////////////////////////////////////////////////////////////////////
typedef BinomialHeap<Task> Computer;

////////////////////////////////////////////////////////////////////////////////
// Assign a new task to the computer                                          //
//                                                                            //
// Parameters:                                                                //
// computer: the computers                                                    //
////////////////////////////////////////////////////////////////////////////////
void Assign( Computer*& computer ) {
  int cm, id, p;
  std::cin >> cm >> id >> p;

  auto task = CreateTask(id, p);
  computer[cm].Insert(task);
  std::cout << "There are " << computer[cm].size()
            << " tasks on computer " << cm << "." << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
// Execute a tasks with largest priority on the computer                      //
//                                                                            //
// Parameters:                                                                //
// computer: the computers                                                    //
////////////////////////////////////////////////////////////////////////////////
void Execute( Computer*& computer ) {
  int cm;
  std::cin >> cm;

  Task task;

  do {
    task = computer[cm].Pop();
    std::cout << "Computer " << cm
              << " executed task " << TaskID(task) << "." << std::endl;
  } while ( computer[cm].size() != 0 &&
            TaskPriority(computer[cm].Top()) == TaskPriority(task) );
}

////////////////////////////////////////////////////////////////////////////////
// Merge two computers                                                        //
//                                                                            //
// Parameters:                                                                //
// computer: the computers                                                    //
// w:        the workload judging parameter                                   //
////////////////////////////////////////////////////////////////////////////////
void Merge( Computer*& computer, int w ) {
  int cm1, cm2;
  std::cin >> cm1 >> cm2;

  if ( computer[cm2].size() >= w ) {
    computer[cm1].Merge(&computer[cm2]);
    auto task = computer[cm1].Top();
    std::cout << "The largest priority number is now " << TaskPriority(task)
              << " on " << cm1 << "." << std::endl;
  } else {
    std::cout << "Merging request failed." << std::endl;
  }
}

}

#endif
