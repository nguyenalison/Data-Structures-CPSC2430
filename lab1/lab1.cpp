// Nguyen, Ali
// lab1.cpp
// 09-10-20

#include <iostream>

using namespace std;

void getInput(int arr[], int max);
     //Asks the user to input numbers into an int array
     //Pre: Must enter while loop in order for getinput() to be called
     //Post: After enters values into array, it prints, and stores in array

int findMin(int arr[]);
     //Finds the minimun value entered in the array
     //Pre: There needs to be an array of ints created and passed in
     //Post: Returns the minimun value in the array passed in 


int main()
{
  int min;                                  // Minimum value in array
  int max;                                  // Maxmimun value in array
  int array[10];                            // Array 
  char again = 'y';                         // User input to play again
  
  cout << endl << "Welcome message" << endl;

  while(again == 'y'){
    cout << "Enter a max number: ";
    cin >> max; 
    getInput(array,max);
    
    min = findMin(array);
    cout << endl << "The min the the array is: " << min << endl;

    cout << endl << "Would you like to play again? ";
    cin >> again;
  }    
    cout << endl << "End of Lab1 Program" << endl;
    return 0;
}



//Functions
void getInput(int arr[],int max){
    int addNum;
    for (int i = 0; i < 10; i++) {
      cout << "#" << i+1 << " = ";
        cin >> addNum;
        if (addNum > max or addNum < 0){
            cout << "TRY AGAIN(Enter a num between 0 and " << max << "): ";
            cin >> addNum;
        }
        arr[i] = addNum;
    }
} 

int findMin(int arr[]){
  int min = arr[0];
  for (int i = 0; i < 10; i++){
    if(min > arr[i+1]){
      min = arr[i+1];
    }
  }
  return min;
}
