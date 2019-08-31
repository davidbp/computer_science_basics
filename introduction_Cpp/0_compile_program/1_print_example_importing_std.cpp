
/*
## To compile this program go to the terminal
g++ 0_print_example.cpp -o 0_print_example.out

## To execute the compiled program
./0_print_example.out
*/

/*
Notice that

std::cout -> cout is a function used to print into the terminal we can import it in the source file 
             we can avoid explicitly stating the library std if we import it with "using namespace std;"

*/



#include<iostream>  //Standard Input / Output Streams Library

using namespace std;

int main(){
   std::cout <<"\nhello world\n";
   return 0;
}

