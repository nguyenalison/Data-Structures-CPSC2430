// Nguyen, ALison
// lab6.cpp
// 10-30-2020

#include <iostream>
using namespace std;


class Book{
private:
  string title;
  long ISBN;
  
public:
  Book();
  Book(string t, long num);
  int hashFun(long key);
  bool addBook(Book arr[],string t,long key);
  void print(Book arr[]);
};

const int ARRSIZE = 13;
  
int main()
{
  Book bookshelf [20];
  Book hash;
  int numBooks = 20, collision = 0;
  bool canAdd;

  string titleArr [] = {"Sherlock Holmes: The Complete Novels and Stories",
   "The Very Hungry Caterpillar","Goodnight Moon","On the Night You Were Born",
  "The Kissing Hand","The Monster at the End of this Book",
  "The Story of Ruby Bridges","The Road Not Taken and Other Poems",
  "The Cat in the Hat and Other Dr. Seuss Favorites","Green Eggs and Ham",
  "One Morning in Maine","The Glass Castle","A Child's Garden of Verses",
  "Twenty Love Poems and a Song of Despair","The Lorax",
  "Letters to a Young Poet","The Body","The Missing Piece Meets the Big O",
  "Matilda","Harry Potter and the Sorcerer's Stone"};

  long isbnArr [] = {9780553212419,9780241003008,9780060775858,9780312346065,
    9781933718002,9780375829130,9780439598446,9780486275505,9780807218730,
    9780394800165,9780140501742,9780743247542,9780689823824,9780143039969,
    9780679889106,9780486422459,9780582418172,9780060256579,9780141301068,
    9780439554930};

  for(int i=0; i < numBooks; i++){
    canAdd = hash.addBook(bookshelf,titleArr[i],isbnArr[i]);
    if(!canAdd) {
      collision++;
    }
  }

  cout << "\n\nThere were " << collision << " collisions \n";
  
  hash.print(bookshelf);
  return 0;
}


Book::Book():title(""),ISBN(0) {}

Book:: Book(string t, long num){
    title = t;
    ISBN = num;
}

int Book::hashFun(long key) {
    return key%ARRSIZE;
}

bool Book::addBook(Book arr[],string t, long key) {
    long hash = hashFun(key);
    Book newBook(t,key);
    bool status = true;

    if (arr[hash].title != "") {
            status = false;
            cout << "Collision at index " << hash << endl;
    } else {
        arr[hash].ISBN = key;
        arr[hash].title = t;
    }
    return status;
}

void Book:: print(Book arr[]) {
    for(int i =0 ; i < ARRSIZE; i++) {
        cout << "\nBookshelf[" << i << "]---------"
             << "\nTitle: " << arr[i].title
             << "\nISBN: " << arr[i].ISBN << endl;
    }
}
