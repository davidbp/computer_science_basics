/*
  vector<int> v;          // creates an empty vector of integers v
  v.push_back(i)          // increases a unit the vector (similar to Julia push! Python .append)
  v.pop_back(i)           // deletes the last element of the vector
  v.insert(v.end(), n, x) // adds value x, n times, at the end of vector v
*/


// constructing vectors
#include <iostream>
#include <vector>
using namespace std;

// Print function for a vector in C++ 11

/*
void Print(const std::vector<int> &v) {
    for(auto& i : v)
        std::cout << i << ' ';
}
*/

/*
// THIS ALSO WORKS, WHY???
void Print(const std::vector<int> v) {
    for(auto i : v)
        std::cout << i << ' ';
}
*/

// NO need to add &v, what's the difference??
void Print(const vector<int> &v){
    for(unsigned i = 0; i< v.size(); ++i) 
        cout << v[i] << ' ';
}


int main ()
{
  vector<int> myints;          // empty vector of ints
  vector<int> v (4,100);       // four ints with value 100

  cout << "\nv = "; Print(v);
  cout << '\n';
  
  cout << "myints.size()=" << myints.size() << "\n\n";
  for (int i=0; i<10; i++) 
    myints.push_back(i); // add element "i" at every iteration

  cout << "After push_back:\n\tmyints.size()=" << myints.size() << endl;
  cout << "\tmyints = "; Print(myints); cout << "\n";
  cout << "\n";

  myints.pop_back();
  cout << "After .pop_back():\n\tmyints.size()=" << myints.size() << '\n';
  cout << "\tmyints = "; Print(myints); cout << "\n";
  cout << "\n";

  myints.insert(myints.end(),10,21);
  cout << "After .insert:\n\tmyints.size()=" << myints.size() << '\n';
  cout << "\tmyints: ";
  Print(myints);
  cout << "\n\n";

  return 0;

}