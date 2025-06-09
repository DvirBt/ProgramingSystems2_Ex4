Programing Systems 2 - Assignment 4
-
This repository contains the fourth assignment in the course Programming Systems 2.  
This assignment mainly focuses on templates, containers, iterators, algorithms and functors.  
We were required to implement a generic container suitable to all comparable data types such as int, double, char, string etc.

The core of this assignment
-
1. Implement and use templates, containers, iterators, algorithms and functors in C++.
2. To search and use new algorithms in the STL library.
3. Throw exceptions when needed.
4. Create Test class to check functionality using DocTest.

Makefile commands
-
- make Main - activates the main.cpp file which runs a few examples.
- make test - runs the Tests.cpp file using DocTest.
- make valgrind - checks for memory leaks (runs on the Tests.cpp file).
- make clean - removes all irrelevant files.

Structor of my project
-
My project files are divided to 2 directories:\n
- Test - contains the tests for the generic container and the doctest header file.
- Ex4 - all the other files such as MyContainer.hpp, main.cpp and Makefile files.

![image](https://github.com/user-attachments/assets/a10e8672-3ecb-4ba1-a649-62936d4c9543)

Important notes
-
1. Each class and function has it's own description and explanation above it's signiture.
2. MyContainer class and each Iterator inner class has it's own TEST CASE.
3. To run the main: make Main -> ./Main -> results.
4. To run the tests: make test -> ./Tests -> results.
5. To run the valgrind: make valgrind -> results.

Information sources
-
1. C++ Iterators - https://www.w3schools.com/cpp/cpp_iterators.asp
2. Iterators in C++ STL - https://www.geeksforgeeks.org/iterators-c-stl/
3. Containers in C++ STL - https://www.geeksforgeeks.org/containers-cpp-stl/
4. ITERATORS in C++ - https://www.youtube.com/watch?v=SgcHcbQ0RCQ&t=892s&ab_channel=TheCherno
5. Writing an ITERATOR in C++ - https://www.youtube.com/watch?v=F9eDv-YIOQ0&t=646s&ab_channel=TheCherno
6. ASCII TABLE - https://www.geeksforgeeks.org/ascii-table/
7. Templates in C++ - https://www.geeksforgeeks.org/templates-cpp/
8. I also used the presentations that are given in the Moodle.
