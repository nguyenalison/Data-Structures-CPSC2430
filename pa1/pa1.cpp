// Nguyen, Ali
// pa1.cpp
// 09-28-2020

// DESCRIPTION: This program is used for planning a tour around Seattle.
//          it reads in a file of activitys listed with their price, rating,
//          and priority. It enqueues each of the activity and prioritizes
//          it by its priority number 1 being the highest and 5 the lowest

//ASSUMPTION: activities. csv must exist. There will be an error message
//          that appears that will tell the user to enter, then ends the
//          program. These files also must be within the same folder for this
//          program to function properly. 


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "activity.h"


using namespace std;

const string FILENAME = "activities.csv";


int main() {

  ActivityList al, al3,al4;       // Activity list objects
  string line;                    // String for getling line from file
  string name;                    // Name of activity
  string price;                   // Price of activity
  string rating;                  // Rating of activity
  string priority;                // Priority of activty
  
  ifstream infile;                // infile for reading in file
  
  infile.open(FILENAME);
  
  if(infile.fail()){
    cout << "There is a problem in the file... Press Enter...";
    cin.get();
    return 0;
  }else{
    getline(infile,line);
    while(getline(infile, line)){
      
      istringstream s1(line);
      getline(s1,name,',');
      getline(s1,price,',');
      getline(s1,rating,',');
      getline(s1,priority,',');
        
      al.enqueue(name, stof(price), stof(rating), stoi(priority));
    }
  }
  infile.close();
  
  cout << "PRINTING ORIGINAL LIST: " << endl;
  al.printList();
  
  cout << endl << "TESTING COPY CONSTRUCTOR: " << endl;
  ActivityList al2(al);
  al2.printList();

  cout << endl << "TESTING ENQUEUE: GUM WALL " << endl;
  al.enqueue("Gum Wall", 0, 2.6, 1);
  al.printList();
  
  cout << endl << "TESTING DEQUEUE: PIKE PLACE MARKET" << endl;
  al.dequeue("Seattle Great Wheel");
  al.printList();
  
  cout << endl << "TESTING COPY ASSIGNMENT: " << endl;
  al3 = al;
  al3.printList();

  cout << endl << "RATING OF SEATTLE GREAT WHEEL: "
       << al.getRating("Seattle Great Wheel");

  cout << endl << endl << "SIZE OF ORIGINAL LIST: " << al.getSize();
  
  cout << endl << endl << "TESTING CREATELIST FOR PRIORITY 2: " << endl ;
  al.createList(al4,2);
  al4.printList();


  cout << endl << endl ;
  
  return 0;
}
