# Exercise 4

**Update this README with your answers to the questions below.**

## Learning Multi-File C++ Projects

- Move code that can be shared between `tcp_echo_server.cc` and 
  `tcp_echo_client.cc` to separate `.h` and `.cc` files
- How would you compile from the command line?
g++ networking.cc tcp_echo_client.cpp -o client

- How would you compile using make?
Have made a Makefile for this very purpose and have attacked it there. 
- How would you compile using VS Code?
vscode doesnt't automatically compile C++ or knw how to work with multiple C++ files, so we need to add the instructions for that in the ./vscode tasks.json file. 
### Compiling vs Linking

- What is the difference between compiling and linking in C++?

Compiling is the process of converting source files into object files. Linking is the process of combining two object files so that all symbols are resolved and an executable is created. 

- What is the difference between creating an executable and creating a 
  library?

An executable is a file that has a single main function, is standalone and runs on its own. A library on the other hand cannot run on its own and needs to be immported into another executable to run properly. 

- How do you compile a library, and then use that library to compile an
  executable?

  There are two ways to do this. First is making a proper shared library. The way to do this is to first compile with the -c flag to make an object file without making an executable.

  Then, we bundle that object file into a shared library. The way we do that is using some archiving tool. One exmaple of an arhciving tool like ar. Then, we use the -L. and -L<name of your library> flags alonside the compilation of your code to add the library to the program. 

  

### Reminder 
[Quickstart tutorial to make](https://makefiletutorial.com/) - Learn make 
fundamentals with practical examples and common patterns.

## Experiments in Performance

- Is it better to have many small files spread across many directories, or
  a few large files across fewer directories?

I think smaller files are better. There are a few reasons why and let me detail some of them here. 
  1) Small changes require smaller times of compilation
      For any change made to the codebase, only the particular file needs to be recompiled. So smaller the file, lesser the compilation time. 
  2) easier to debug and understand codebase
     There are more files and directories, so it is easier to identify where each function lives and to separate out the code. This also allows easier modularizaton of the code. 
  3) lesser code is copied onto each file
    Let us say we import one file in another, if the file is particularly large, alrge amounts of code will be imported, increasing the compilation time. 
- Is there a difference in compilation time between the two?
For reasons noted above, the smaller files have lesser compilation times. 

- How can you assess performance other than compilation speed?
  We can measure other metrics for performance. One primary metric is the execution time, which we can measure using the time command and the perf command. 

  We can also measure memory usage. We can use valgrind and other tools to measure hwo much the memory the code takes, identify memory leaks if there are any and debug them.  
  We can also use perf to identify cache hits and misses, using them to work through our code.


