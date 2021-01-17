#ifndef HASH_TABLE 
#define HASH_TABLE


#include "list.h"
#include "array.h" 
using namespace std; 
  
class hashTable // a class for a Linked List implemantation of an hash table
{ 
    int items;
    int size;    // amount of lists in the hash table 
    list<Array<int>*> *table; //The hash table- maps course number to its "double array" that contains the lessons and some data about it
public: 
    ~hashTable();
    hashTable(int size);  // Constructor 
  
    // insert a course into the hash table 
    void insertItem(int course_number,Array<int>* array); 
  
    // delete a course from the hash table 
    void deleteItem(int course_number); 
  
    // basic modulo hash function to map values to key 
    int hashFunction(int x) { 
        return (x % size); 
    }
    Array<int>* getItem(int course_number); 
    Array<int>* getArray(); 
    void changeSize(int changeTo);

}; 
hashTable::~hashTable(){
  delete[] table;
}

hashTable::hashTable(int size) 
{ 
    items=0;
    this->size =size; 
    table = new list<Array<int>*>[size];
} 
  
void hashTable::insertItem(int course_number,Array<int>* array) 
{ 
    int index = hashFunction(course_number); 
    table[index].insert(array); 
    items++; 
    if(items>size)
      changeSize(size*2);
} 
void hashTable::changeSize(int changeTo){
        list<Array<int>*> * temp=new list<Array<int>*>[changeTo];
        list<Array<int>*> * curr=&table[0];
        size=changeTo;
        int c=0;
        
        for(int j=0;j<items;j++)
        {
          if(curr->getSize()==-1){
            j--;
            c++;
            curr=&table[c];
          }else{
            int index = hashFunction(curr->getArray()->getCourseNum()); 
            temp[index].insert(curr->getArray()); 
            if(curr->getNext()==nullptr){
              c++;
              curr=&table[c];
            }else{
              curr=curr->getNext();
            }
          }
        }
        delete[] table;
        table=temp;
} 

void hashTable::deleteItem(int course_number) 
{ 
  // get the hash index of course number 
  int index = hashFunction(course_number); 
  int i=0;
  // find the course in the hash table
  list <Array<int>*> *t=&table[index];// a temporary pointer to travel the list 
  for (i = 0; i<= table[index].getSize(); i++) { 
    if (t->getArray()->getCourseNum() == course_number) 
      table[index]=*table[index].remove(t->getArray()->getCourseNum());
      delete t;
      items--;
      break;
    t=t->getNext();
  } 
} 
Array<int>* hashTable::getItem(int course_number)
{ 
  // get the hash index of course number 
  int index = hashFunction(course_number);
  return table[index].getItem(course_number);//get the item from the list
} 
#endif
