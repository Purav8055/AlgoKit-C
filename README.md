# C Programming Project: Custom Libraries
### Project Description
This project involves the development of a set of custom C libraries to implement a variety of commonly used algorithms and functions. The project showcases the use of modular programming in C by separating functionalities into distinct header files and their corresponding implementations. The project includes sorting algorithms, searching algorithms, mathematical operations, and base64 encoding/decoding functionalities.

### Project Goals
**Modularity:** Develop reusable and modular code through custom libraries.

**Algorithm Implementation:** Implement fundamental algorithms and functions commonly used in software development.

**Code Efficiency:** Write efficient and well-documented code that adheres to best practices.

**Learning:** Deepen understanding of C programming, especially in the areas of memory management, algorithm implementation, and modular design.
### Project Specifications
#### Libraries Implemented
**sorting.h**

**Functionality:** Implements the selection sort algorithm to sort an array of integers.

**Functions:**
void sort(int arr[], int n);

**searching.h**

**Functionality:** Provides implementations of linear and binary search algorithms.

**Functions:**
int linearSearch(int arr[], int target, int n);
int binarySearch(int arr[], int target, int n);

**math.h**

**Functionality:** Contains basic mathematical functions such as absolute value, power calculation, and factorial computation.

**Functions:**
int absolute(int n);
double power(double base, int exp);
int factorial(int n);

**encoding.h**

**Functionality:** Implements base64 encoding for data conversion.

**Functions:**
void encoder(char str[]);

**decoding.h**

**Functionality:** Implements base64 decoding to revert encoded data back to its original form.

**Functions:**
void decoder(char str[]);

#### Design and Implementation
**Project Structure:**

include/: Contains all header files (.h files).

src/: Contains all source files (.c files) that implement the functions declared in the headers.

main.c: The main program file that includes and utilizes the libraries.

**Modular Design:**

Each library is designed to be self-contained, meaning that each header file is paired with a corresponding .c file. This modular approach allows for easy updates and maintenance of individual libraries without affecting the rest of the codebase.

### Installation and Compilation
To compile the project, navigate to the root directory of the project and use the following gcc command:

gcc -I./include -o main ./src/main.c ./src/sorting.c ./src/searching.c ./src/math.c ./src/encoding.c ./src/decoding.c

After compilation, you can run the executable with:
./main

## Conclusion
This project is a demonstration of modular programming in C, showcasing the development of custom libraries for sorting, searching, mathematical operations, and base64 encoding/decoding. The project highlights the importance of clean code organization, reusability, and efficiency in software development.