//Assignment 1:
//Templated class definition of DA ( data array) has been provided below . Implement its functionalities. 
//main() function contain test code to test the class functionalities.
//Do not change the class definition or main code.
//Save the file as <YourUSN>-assignment1.cpp
//Upload the completed file in text format. Ensure it is executing fine before submission


template<class T>
class DA
{
  Public:
  T   *ele; //element array buffer pointer ( use malloc or new to allocate memory)
  int len; //length of buffer or maximum size
  int size;// size of array
  DA(); //constructor to initialise len,size
  DA(T *source, int len); // Constructor to initialise from a given array
  void append (T  d); // append an element d in array
  void remove(int index);// remove element from array mentioned by index
  int find( T  val); // return number of occurrence of val in array
  void show();// show all elements in array sequentially
};
DA::DA(T *source,int len){
  
}
int main()
{
  int isource[10]={ 1,2,3,4,5};
  char csource[10]={ 'a','b','c','b','e','f'};
  DA<int> ida(isource,5);
  ida.show(); // should show 1 2 3 4 5
  ida.append(3);
  ida.show(); //should show 1 2 3 4 5 3
  cout<<"Element present = "<<ida.find(3)<<endl; // should show 2
  ida.remove(2);
  ida.show(); // should show 1 2 4 5 3

  DA<char> cda(csource,6);
  cda.show(); // should show a b c b e f
  cda.append('b');
  cda.show(); //should show a b c b e f b
  cout<<"Element present = "<<cda.find('b')<<endl; // should show 3
  cda.remove(4);
  cda.show(); // should show a b c b f b
}

