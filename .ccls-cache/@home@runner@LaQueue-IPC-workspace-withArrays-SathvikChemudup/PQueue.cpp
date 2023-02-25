/*
 * LaQueue
 * 
 * 
 * This is part of a series of labs for the Liberal Arts and Science Academy.
 * The series of labs provides a mockup of an POSIX Operating System
 * referred to as LA(SA)nix or LAnix.
 *  
 * (c) copyright 2018, James Shockey - all rights reserved
 * 
 * */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "PQueue.h"

/*
 * Class Priority Queue
 */


/*
* Insert into Priority Queue
*/
void PQueue::push(void *item, int priority)
{
  
	/* Your code here */
  node* d = new node();
  d->data = item;
  d->priority = priority;

  if (((end + 1) % size) == start) {
    return;
  }

  end = (end + 1) % size;
  front[end] = *d;

  if (start == -1) {
    start = 0;
  }
  
}

/*
 * Delete from Priority Queue
 */
void* PQueue::top()
{
  
	/* Your code here */
  return front[start].data;
  
}

/*
 * Delete from Priority Queue
 */
void PQueue::pop()
{
  
	/* Your code here */  
  if (start == -1) {
    return;
  }
  if (start == end) {
    start = -1;
    end = -1;
  }
  else {
    start = (start + 1) % size;
  }

}

/*
 * Print Priority Queue
 */

void PQueue::display()
{

	/* Your code here */
	
	/* Use the following out command for the data */
  
  for (int i = 0; i < size; i++) {
    std::cout<<front[i].priority<<" "<<(char*)front[i].data<<std::endl;
  }
  
}