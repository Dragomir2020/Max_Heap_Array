#ifndef MAXHEAP_H
#define MAXHEAP_H 

/*    file MaxHeap.h    
      author: Dillon Dragomir
      date: 7-6-2017

      @description Implements a templated maximum queue, using a
      heap structure.
*/

////////////////
//Contributers//
////////////////

///////////////////////////////////////////////

// NAME                   DATE           CHANGE
// Dillon Dragomir        07-06-2017     Added basic functionality and started structure of class
// Dillon Dragomir        07-09-2017     Added heap_down and heap_up private functionality
// Dillon Dragomir        07-10-2017     Added 20 unit test cases 
   
///////////////////////////////////////////////

////////////////
//DEPENDANCIES//
////////////////

#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

template <class T> 
class MaxHeap {
public: 

// isEmpty
unsigned int isEmpty() {
	return size() == 0;
}

MaxHeap(){
//Constuctor
count = 0;
}

//Push value into heap
void push(T value){
  // Push back element on vector
  stuff.push_back(value);
  //Add to count
  count++;
  heap_up(size()-1);
}
//Remove element from heap
void pop(){
  //Check whether heap is empty
  if(size() != 0){
     stuff[0] = stuff.back();
     stuff.pop_back();
     //remove top element
     count--;
     //Heap_down on root node
     heap_down(0);
  }
}

bool isHeap(int s){
  if(s > count || s == 0){
    return true;
  }
  if(stuff[s] < stuff[parent(s)]){
    return isHeap(lChild(s)) && isHeap(rChild(s));
  }else{
    return false;
  } 
}

T top(){
  //Get first element from vector
  if(!isEmpty()){
     return stuff[0];
  }
  throw logic_error("Vector Empty");
}

unsigned int size(){
  //Return size of vector
  //cout << count << endl;
  return count;// stuff.size();
}

private:
//Heap Vector
vector<T> stuff;
//Count of number of elements
unsigned int count;
//Returns parent of stuff[i]
unsigned int parent(unsigned int i){
  return (i-1)/2;
}
//Returns left child of stuff[i]
unsigned int lChild(unsigned int i){
  return i*2 + 1;
}
//Returns right child of stuff[i]  
unsigned int rChild(unsigned int i){
  return i*2 + 2;
}

// Recursive heap-down algorithm
// Node at index i violates heap properties
void heap_down(unsigned int i){
	// Get left and right child for node at index i
	unsigned int left = lChild(i);
	unsigned int right = rChild(i);
	
	unsigned int largest = i;
	
	//Compare left and right child
	if(left < size() && stuff[left] > stuff[i]){
		largest = left;
	}
	if(right < size() && stuff[right] > stuff[largest]){
		largest = right;
	}
	
	//Swap with child with greater value and call heap-down
	if(largest != i){
		swap(stuff[i], stuff[largest]);
		heap_down(largest);
	}
}

//Heap_up
void heap_up(unsigned int i){
	//Check if index i violates heap property
	if(i && stuff[parent(i)] < stuff[i]){
		//Swap both
		swap(stuff[i], stuff[parent(i)]);
		//Recursive call to rippe up
		heap_up(parent(i));
	}
}
  
};

#endif
