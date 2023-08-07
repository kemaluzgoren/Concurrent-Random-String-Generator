# Concurrent-Random-String-Generator 
## How it works

The program uses two separate functions to generate two different random strings:

1. `generateRandomLetters(int n)`: Generates random letter strings of length n characters.
2. `generateRandomDigits(int n)`: Generates random strings of numbers of length N characters.

Both functions use the `std::mt19937` random number generator provided by the C++11 standard and use the `std::uniform_int_distribution` class to generate random characters within a specified range.

The execution of the programme takes place in the `main()` function:

1. Two separate threads are created: The first one runs the `generateRandomLetters` function and the second one runs the `generateRandomDigits` function.
2. Both threads complete their execution and assign the results to variables `s1` and `s2`.
3. The programme calculates the processing time and prints the result on the screen.

### Note
You will need a C++ compiler to compile the project. You can use any C++ compiler that supports C++11 or later.
