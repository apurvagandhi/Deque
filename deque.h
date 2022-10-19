/**************************************************************
 * Filename: deque.h
 * Author: Apurva Gandhi
 * Date: 02/18/2019
 * Course: CSCI 132-01
 * Purpose: SPECIFICATION of the functions for Deque.cc class
 **************************************************************/

#include "queue.h"
#include <iostream>
using namespace std;

class Deque : private Queue
{
 public:
	Error_code append_front(const Queue_entry &item);
	Error_code append_rear(const Queue_entry &item); 
	Error_code serve_front(void);                     
	Error_code serve_rear(void);                      
	Error_code retrieve_front(Queue_entry &item) const;
	Error_code retrieve_rear(Queue_entry &item) const;
};//end of deque.h
