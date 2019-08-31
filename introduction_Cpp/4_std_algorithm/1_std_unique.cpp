
/*
#### Compilation code
c++ -std=c++11 1_std_unique.cpp  -o 1_std_unique.out

*/




// unique algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::unique, std::distance
#include <vector>       // std::vector

bool myfunction (int i, int j) {
  return (i==j);
}

int main () {
  int myints[] = {10,20,20,20,30,30,20,20,10};           // 10 20 20 20 30 30 20 20 10
  std::vector<int> unique_elements (myints,myints+9);

  // using default comparison:
  std::vector<int>::iterator it;
  it = std::unique (unique_elements.begin(), unique_elements.end());   // 10 20 30 20 10 ?  ?  ?  ?
                                                         //                ^

  unique_elements.resize( std::distance(unique_elements.begin(),it) ); // 10 20 30 20 10

  // using predicate comparison:
  std::unique (unique_elements.begin(), unique_elements.end(), myfunction);   // (no changes)

  // print out content:
  std::cout << "\nunique_elements contains:";
  for (it=unique_elements.begin(); it!=unique_elements.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << "\n\n";

  return 0;
}
