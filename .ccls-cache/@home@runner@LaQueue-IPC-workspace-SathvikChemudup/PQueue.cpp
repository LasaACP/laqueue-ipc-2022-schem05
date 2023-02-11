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
  node* element = new node();
  element->data = item;
  element->priority = priority;
  element->link = nullptr;
  
  if (front == nullptr) {
    front = element;
    front->link = nullptr;
  }
    
  else if (front->priority <= priority) {
    node* parse = new node();
    parse = front;
    while (parse != nullptr && parse->link != nullptr) {
      node* next = new node();
      next = parse->link;
      int pr_compare = next->priority;
      if (pr_compare > priority) {
        break;
      }
      parse = parse->link;
    }
    element->link = parse->link;
    parse->link = element;
  }
    
  else {
    node* tmp = new node();
    tmp = front;
    element->link = tmp;
    front = element;
  }
  
}
/*
 * Delete from Priority Queue
 */
void* PQueue::top()
{
	/* Your code here */
  if (front == nullptr) {
    return nullptr;
  }
  return front->data;
}
/*
 * Delete from Priority Queue
 */
void PQueue::pop()
{
	/* Your code here */
  // node* loc = front;
  // node* nextLoc = loc->link;
  // front = nextLoc;
  // return loc->data;

  front = front->link;
}

/*
 * Print Priority Queue
 */
void PQueue::display()
{

	/* Your code here */
	node* ptr = front;

  while (ptr != NULL) {
  	/* Use the following out command for the data */
  	std::cout<<ptr->priority<<" "<<(char*)ptr->data<<std::endl;
    ptr = ptr->link;
  }
}
	