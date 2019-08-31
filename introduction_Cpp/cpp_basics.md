



## Compile basics

### How to compile and execute a program

Given a program saved in `main.cpp` we can compile it and make an executable called `main.out` with the following commad:

```C++
g++ main.cpp -o main.out
```

then to execute the program we can use **`./main.out`**.

The most basic library we can use is **`iostream`** which allows us to print o the terminal whatever we want. In order to import a library from the basic C++ root directory we have to use the **`#include<some_library>`** command. For example the following line

```c++
#include<iostream> 
```

allows us to use the `std` library in our code. With this library we can print strings into the terminal. Let us consider the following "hello world" program.

```C++
#include<iostream>  //Standard Input / Output Streams Library

int main(){
   std::cout <<"\nhello world\n\n";
   return 0;
}
```

If the program is saved as `0_print_example.cpp` we can compile it with the following command and make an executable `0_print_example.out`. 

```
g++ 0_print_example.cpp -o 0_print_example.out
```

We can execute the program using **`./0_print_example.out`** this program will simply print `hello world` into the terminal.

```
>>>./0_print_example.out

hello world
```

Instead of using `std::cout` every time, we can use the comand **`using namespace std;`**  to avoid having to specify every time that `cout` comes from the `std` library. The following code would work

```C++
#include<iostream>  //Standard Input / Output Streams Library
using namespace std;

int main(){
   cout <<"\n\nhello world\n\n";
   return 0;
}
```

This is not recommended because using namespaces can lead to problems (specially when different libraries contain different functions that have the same name). 



### Compiling programs with multiple files

If the source code of a program is composed of several `.cpp` files some special instructions are needed to compile the code. We will assume that all the `cpp` files are in a single folder. From the root of the folder, we can use the following commands to generate an executable `executable.out`. 

```bash
c++ -std=c++11 -c *.cpp
c++ -std=c++11 *.o -o executable.out
```



## Basic library iostream

As you may have noticed, we used “cout” to write to the console. There are some things to notice:

- Any string literal must be enclosed in double quotes. 
- Numbers do not require double quotes.
- If a variable name is used, the value of the variable is printed. We can have multiple insertions to cout.  

We can see the previous

```C++
#include<iostream>  
int main(){
   int integer = 4543;
   std::cout<<”The value of integer is “<<integer;
}
```

Will print

```
The value of integer is 4543
```

Also, note that cout does not automatically add newlines. You must add them using the escape sequence “\n”.

### Variable sizes

As with other programming languages, the size a variable is allocated in memory is dependent upon its type. To determine how many bytes each variable type uses, C++ provides the function sizeof(variableType). 

You will use the command :

```C++
 sizeof(variable type); // example: sizeof(int)
```

When printing out the variable types, you may want to print them out, one per line. 
To do this, add `\n` or `endl` to the end of the text to be printed. 

For example,  

```c++
cout<<"int size = "<<sizeof(int)<<"\n";
```

A second option is `endl`

```c++
cout<<"int size = "<<sizeof(int)<<endl;
```

In many instances endl and "\n" will perform the same function. There are cases where they will be different. 

About `sizeof`:https://www.tutorialspoint.com/cplusplus/cpp_sizeof_operator.htm

Input

```c++
#include <iostream>
using namespace std;
 
int main() {
   cout << "Size of char : " << sizeof(char) << endl;
   cout << "Size of int : " << sizeof(int) << endl;
   cout << "Size of short int : " << sizeof(short int) << endl;
   cout << "Size of long int : " << sizeof(long int) << endl;
   cout << "Size of float : " << sizeof(float) << endl;
   cout << "Size of double : " << sizeof(double) << endl;
   cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;  
   return 0;
}
```

Output

```c++
Size of char : 1
Size of int : 4
Size of short int : 2
Size of long int : 8
Size of float : 4
Size of double : 8
Size of wchar_t : 4
```



#### Constants

In C++ we can define a variable as a constant. Meaning, its value does not change for the life of the program.  We use the keyword `const` to define a constant. 

```c++
const int weightGoal = 100;
```

With this statement we have set the integer `weightGoal` to 100. It cannot be changed during the program. If you want to change the value of weightGoal, you will have to edit the source code and recompile it. 

Look at the error messages that are generated when we attempt to compile and execute the code below. You will see that our attempt to change a constant variable fails. 

```c++
#include <iostream>
using namespace std;

int main()
{
    const int weightGoal = 100;
    cout<<"WeightGoal = "<<weightGoal<<"\n";
    weightGoal = 200;
    cout<<"WeightGoal = "<<weightGoal<<"\n";
    return 0;
}
```

Outputs when compiled:

```
error: assignment of read-only variable ‘weightGoal’
     weightGoal = 200;
```

### Ennumerated constants

C++ also allows for enumerated constants. This means the programmer can create a new variable type and then assign a finite number of values to it. Here is the form of the enum keyword:

```c++
enum type_name {
  value1,
  value2,
  value3,
  .
  .
} object_names;
```

For example: 

```c++
 enum MONTH {Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};
```

In this example the enum variable `MONTH` has twelve possible values. These 12 values translate into 12 integer values. 

```c++
/*Enum example*/
#include <iostream>
using namespace std;

int main()
{
    //define MONTHS as having 12 possible values
    enum MONTHS {Jan, Feb, Mar, Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec};
    
    //define bestMonth as a variable type MONTHS
    MONTHS bestMonth;
  
    //assign bestMonth one of the values of MONTHS
    bestMonth = Jan;
    
    //now we can check the value of bestMonths just 
    //like any other variable
    if(bestMonth == Jan)
    {
        cout<<"I'm not so sure January is the best month\n";
    }
    return 0;
}
```

### Format output

The C++ escape sequences are pretty similar to other languages. The most common ones are:

-  `\n`for newline
-  ` \t` for  tab

We can also format the output by using the **`iomanip`** library.  Include it with `#include` . Once it is included, you can format output using the `iomanip` library. For example, we can set the width of an output using the **`setw`** command.

- **`setw`** function takes as input an integer `n` and prints `n` spaces.

Input example

```c++
#include <iostream>  // This is needed otherwise std::cout is not found
#include <iomanip>   // This is needed otherwise std::setw is not found
int main()
{	
   std::cout<<"\nThe text without any formating\n";
   std::cout<<"Ints"<<"Floats"<<"Doubles"<< "\n";
   std::cout<<"\nThe text with setw(15)\n";
   std::cout<<"Ints"<<std::setw(15)<<"Floats"<<std::setw(15)<<"Doubles"<< "\n";
   std::cout<<"\n\nThe text with tabs\n";
   std::cout<<"Ints\t"<<"Floats\t"<<"Doubles"<< "\n";
}
```

Output

```

The text without any formating
IntsFloatsDoubles

The text with setw(15)
Ints         Floats        Doubles


The text with tabs
Ints	Floats	Doubles
```



## Read and write to files

As with other programming languages, we can read and write files.  There are different steps for reading from files and for writting to files. Summarized as follows:

 - Include the **`<fstream>`**  library 
 - Create a stream `(input, output, both)`
      - **`ofstream myfile`**:  Is used for writing to a file. This command creates an output stream.
      - **`ifstream myfile`**:  Is used for reading from a file. This command creates an input stream. 
      - **`fstream myfile`**: Is used for reading and writting to a file. This command creates an input-output stream. 
 - Open the file  **`myfile.open(“filename”)`** : Opens the file `filename`. If the file does not exist the program will create it.
 - Write or read the file.
 - Close the file **`myfile.close()`**;

Example with `<fstream>`. The following program 

- In case `./files/input.txt` exists, it opens the files and writes two lines
- In case `./files/input.txt` does not exists, it creates the file and writes two lines.

```c++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
    string line;
    //create an output stream to write to the file
    //append the new lines to the end of the file
    ofstream myfileI ("./files/input.txt", ios::app);
    if (myfileI.is_open())
    {
        myfileI << "\nI am adding a line.\n";
        myfileI << "I am adding another line.\n";
        myfileI.close();
    }
    else cout << "Unable to open file for writing";
    return 0;
}
```



## Reading edge lists from file

Let us assume the file `graph1.in` contains the following information

```
4 7
0 1
1 2
0 3
1 2
1 2
2 2
3 1
```

where 

- The first row indicates the number of vertices and the number of edges in the graph.
- The following rows indicate edges from source vertex to target vertex. For example ` [0, 1]` indicates that there is an edge `0->1`. In general, if not specified, we will assume the edge is undirected 0-1.



#### Directed edge lists

Notice that the previous `graph1.in` can be saved as an edge list as follows:

```
0: [1,3]
1: [2,2,2]
2: [2]
3: [1]
```

This is a dictionary where keys are vertices and values are the adjacent vertices of the keys. 

In C++ we can do this as a `vector<vector int> AdjList` where `AdjList[v]` is a vector containing all the edges from `v` to any other vertex. Notice that this graph representation allows multiple edges `(v,w)` going from `v` to `w`. 



#### Undirected edge lists



####Adjacency matrices



####Undirected adjacency matrices





The following code snippet reads a file like the one just described and prints the information to the terminal.

`````c++
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::vector;
typedef vector<vector<int>> edgelist;

edgelist graphE_read(std::string fname)
 { 
    std::ifstream stream_file;
    stream_file.open( fname.c_str() );    
    if( stream_file.fail() ) {
        std::cerr << "unable to open file " << fname.c_str() << " for reading" << std::endl;
        exit(1);
    }
    
    // Read vertices and edges numbers
    int n_vertices, n_edges;
    stream_file >> n_vertices >> n_edges;
    
    // Initialize Edge matrix to 0
    edgelist E(n_edges, {0,0});
    
    // Fill edge list
    for( int j=0; j<n_edges; j++ ) {
        int u, v;
        stream_file >> u >> v;
        E[j][0] = u; E[j][1] = v;
    }    
    stream_file.close( );    
    return E;
}

int main() {
    edgelist E;
    std::string f = "./graph1.in";
    E = graphE_read(f);
    std::cout << "\nGraph read from file: " << f << std::endl;
    std::cout << "\nn_edges: " << E.size() <<"\n";
    std::cout << "\nEdge list pairs: \n";
    for(int i=0; i<E.size(); i++)
        std::cout << E[i][0] << " " << E[i][1] << "\n";

    std::cout << "\n";      
}
`````



