// Ali Nguyen
// activities.h
// 09-21-20

#include <iostream>
using namespace std;

#ifndef ACTIVITIES_H
#define ACTIVITIES_H

class ActivityList{
private:
  struct ActivityNode{              //Structure for queue nodes
    ActivityNode* next;             // Pointer to next node
    string name;                    // Name of activity
    float price;                    // Price of activity
    float rating;                   // Rating of activity
    int priority;                   // Priority of activity
  };
    ActivityNode* front;            // Front of queue
  
  
public:
  // Constructor
  ActivityList();
  
  // Copy Constructor
  ActivityList( const ActivityList& object);
  
  // Copy Assignment
  ActivityList operator=(const ActivityList& object);
  
  // Destructor
  ~ActivityList();
  
  void destroy();
       // Destorys the list
       // Pre: Existing ActivityList object
       // Post: Deallocates memory of ActivityList
       //used in copy assignment and destructor
  
  
  void enqueue(string n, float p, float r, int pri);
       // Adds all the activities in the list by priority
       // Pre: Existing ActivityList object
       // Post: New activity added by priority into a linked list
  
  string dequeue(string name);
       // Deletes activity from list
       // Pre: List has to exist and have at least one activity
       // Post: Returns activity chosen to be deleted by name
  
  int getSize();
        // Method gets size of list
        // Pre: Existing ActivityList object
        // Post: Returns size of list

  void printList();
        // Prints all items in list
        // Pre: Existing ActivityList object
        // Post: Prints all items in the list

  float getRating(string name);
        // Method gets rating of activity
        // Pre: Existing ActivityList
        // Post: Returns the rating of an activity
        //       0 if activity doesnt exist

  void createList(ActivityList& s2, int priority);
        // Adds all items of priority entered into new list
        // Pre: Existing ActivityList object
        // Post: New list of items of all the same priority is created


};

#endif //ACTIVITIES_H
