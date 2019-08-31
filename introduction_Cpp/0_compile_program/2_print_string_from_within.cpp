/*
## To compile this program go to the terminal
g++ 0_print_example.cpp -o 0_print_example.out

## To execute the compiled program
./0_print_example.out
*/

/*
Notice that

cout -> cout is a function used to print into the terminal we can import it in the source file 
        we can avoid explicitly stating the library std if we import it with "using namespace std;"

string s; -> defines a variable of type string.


*/



#include<iostream>  //Standard Input / Output Streams Library

using namespace std;

int main(){
   string s;
   s = "this is a string";
   cout << "\n\nhello world\n\n";
   cout << s << "\n\n";
   
   return 0;
}
