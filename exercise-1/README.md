# Exercise 1

**Update this README with your answers to the questions below.**

## How to Approach This Exercise

Before you scroll down to the questions, try this:

1. **Don't peek at the questions yet.** Pretend you've just been handed a brief
   that says: *"Learn these topics as deeply as you can — g++ CLI, Make, Git,
   sockets, and memory management in C++."* That's the whole assignment.
   How would you go about it? What would you read, what would you try, in what
   order, and how would you know when you've understood something well enough?
   Write that plan down in this README, then actually follow it.

2. **Now go through the questions below and answer them like you're an LLM.**
   No live Googling, no Stack Overflow, no asking ChatGPT mid-question. You may
   refer to notes *you* took during step 1 — that's your context window. Answer
   from what you've internalised.

3. **Reflect on how it went.** Honestly:
   - Did your self-directed learning actually prepare you for the questions, or
     did you over-study things that never came up?
   - Which questions blindsided you? Why — was the topic missing from your
     plan, or did you skim past it?
   - Map your experience onto the *known knowns / known unknowns / unknown
     unknowns* idea. The interesting category is usually the last one: things
     you didn't even realise you should have learned. What were yours, and how
     could a better learning plan have surfaced them earlier?

The point of this exercise isn't to get the questions "right" — it's to notice
the gap between how you *think* you learn and how you actually do, so you can
close it.

## Plan
I already know the basics for much of these. I just need to solidify my understanding, idenfity gaps in my learning and fill those. I have started by googling these topics and then asking AI to make a resource list of everything I need to read. Then, I choose the best resources from the resource list
### MakeFiles
What I already know:
1) How to create a makefile and basic syntax
What I need to know
2) Syntax and rules

How to learn:
GNU make documentation
https://makefiletutorial.com/

### Sockets
What I already know:
1) Beej's guide 

What to learn:
skim through
https://man7.org/linux/man-pages/man7/socket.7.html

https://cs.dartmouth.edu/~campbell/cs60/socketprogramming.html

### G++
I have already worked fairly well with G++, so just need to review the documentation

https://man7.org/linux/man-pages/man1/g++.1.html

G++

### GIT
Skim through chapters that I dont understand or are new to me
https://git-scm.com/book/en/v2

### C++ memory management
While learning C++ through cppcon I had read multiple articles regarding memory management. So I will just skim over the cppreference documentation on memory management



## Learning How to Learn

- Answer the following questions in this file and commit and push your changes.
- Bonus sections are more difficult and optional.
- How can you find the information required to complete these tasks?
- How can you tell if the source of your information is good?
- How would you define "good" in this situation?

## Learn Basics of g++ CLI

- Compile the TCP client and server using `g++` from command line.
  g++ src/tcp_echo_client.cc -o client
   g++ src/tcp_echo_server.cc -o server
- What are the most important command line arguments to learn for `g++`?

 The names of the source files (.cpp or .c ) files, the name of the output files and along with some compiler flags

- What is the difference between debug vs release versions?

Debug version of software refers to the executables that have some information that can be used to debug the code using debuggers, like gdb. Release versions are more optimized as they need ot have maximum performance and efficiency

- What are the tradeoffs between debug and release versions?

Debug versions need to ensure that any error or bug in the final output is identified and solved, while release versions need to ensure that they have maximum performance and efficiency. 
Debug versions of the output, especially binary, are generally larger, as they have more information and they tend to have a decreased performance due to keeping track of any undefined behaviour. Meanwhile, release versions are heavily optimized while not having the ability to identify errors. 

- What arguments would you use in a debug build?
  The compiler flags to be used alongside G++ would be -Wall -Wextra and -g

- What about for release?
  -02 - for optimization
- What other kinds of build types are useful?

## Learn Basics of Make

- Create a Makefile that will speed up the process.
- [Quickstart tutorial to make](https://makefiletutorial.com/) - Learn make 
  fundamentals with practical examples and common patterns.
- How else can you learn about make?
  There is make documentation available at GNU's main website.
- How can you tell if the resource you are using is correct?
  I personally do the following. Check to see if the resource is of an official entity or organization instead of a single user, like the GNU, or see if they have cited sources. I also use cross referencing to identify good sources
- Create a makefile such that when you run `make` with no arguments, it will:
  - Create `build/` directory if it does not exist
  - Create executables **client** and **server** in `build/`, if needed
  - How does make know when it needs to rebuild the executables?
  Make checks the timestamps to see if any of the prerequisites have been updated after the last creation of the target file
  - Change your Makefile such that `make clean` will remove `build/` and all
    its contents

- What are the most important command line arguments to learn for make?
From my current research, make only accepts the targets as command line arguments, using them to specify exactly which commands need to run
- What are the most important directives to learn about in Makefile?

- What are the most important commands to implement in your Makefile?
- Which ones are essential, which ones are nice to haves?

## Learn Basics of Git

- Read through the code in `src/`
- Answer any `#Questions` as a comment
- Commit and push your changes to git
- Each commit should be responding to a single task or question
- Why is it important to keep your commit to a single task or question?

This is best practice to ensure the readability and maintainability of the codebase is improved. This ensures that others can see exactly when each question was solved and how, and also allows individuals to revert back in case of any errors.

- Is it better to have a lot of very small commits, or one big commit when 
  everything is working?

  It is better to have many small commits, as we can easily identify exactly, where each change was made, how it was implemented and in case of any errors, we can go back to a codebase that is not too different from the current one. 

- What are the most important commands to know in git?
  add, commit, push, restore, pull, init, merge, rm

## Introduction to Sockets

- Read the code in `src/tcp-echo-client.cc` and add a way to change the 
  message sent using command line arguments
- **Example**: `./client "hello message from the command prompt"` should send
  `"hello message from the command prompt"` to the server
- Commit your changes into git
- What do all these headers do?

Header files help improve the modularity of the codebase. The working of header files, as far as I know, is to simply copy paste code from one .cpp file to another. In our example, what these do is that they take functions and structs defined in other files (like netisd) and help them be used in our own files. This ensures that we do not have to manually write all the functions needed and can simply use already defined tools

- How do you find out which part of the below code comes from which header?
From what I know, documentation, like cppreference.com
- How do you change the code so that you are sending messages to servers
  other than localhost?
  We mention the IP address of the server and the appropriate port in our client code, specifically, in the sock_addr struct we pass into the connect function
- How do you change the code to send to a IPv6 address instead of IPv4?
We replace AF_INET with AF_INET6 in all places.,
- **Bonus**: How do you change the client code to connect by hostname instead
  of IP address?
  This requires a doman name lookup. From my reading of Beej's guide, there are two ways of doing this, first is to use getaddrinfo, and passing in the name to the first argument. This will eventually give us the right socket address to connect to. Or else, we can use the gethostname function to get the right IP address.
  
## Introduction to Memory Management

- What is happening in line 26 of `tcp-echo-client.cc`? 
  `if (inet_pton(AF_INET, kServerAddress.c_str(), &address.sin_addr) <= 0) {`

  So there are actually two things this line is doing. First is that it is trying to get the ip address in kServerAddress.c_str(), which is basically a string, convert that to the right format and data type , which is an in_addr if I recall correctyl, format it as IPv4 and store that in address.sin_addr. The comparison with 0 is to check if that fails. 

- What is happening in line 31 of `tcp-echo-client.cc`?
  `if (connect(my_sock, (sockaddr *)&address, sizeof(address)) < 0) {`

Here we are attempting to connect our client socket to the correct socket address in the server. We have already filled the address struct with the right port and IP and we now simply try to connect. The comparison with 0 is once again to check if the connection fails or succeeds. 

- What is the difference between a pointer and a reference?

A pointer is a data type itself that is used to store a memory address. It stores the memory address of a variable so that it could be used to modify the variable and use its data. A reference is similar, however, it doesn't explicity store the memory address. Rather, it is used to refer to the same data as an another variable. So when we ahve a reference to a variable, we are using another variable to access the same data as the original variable without creating copies of the data. 

- When is it better to use a pointer?
Pointers are incredibly useful if we need to work with memory addresses or if our pointer itself is more important than the variable. An example is going over a linked list, whcih is much more suited to pointers as references can only ever refer to one variable while we will need our pointer to go and point to many different locations. 

- When is it better to use a reference?
References are much more suited if we are going to perform computation iwht the data and not the memory address itself. Since it does not allow copying, we can use it to take in arguments to functions. 

- What is the difference between `std::string` and a C-style string?
std::string is an abstraction over the C -style strings, using classes to add more functions and attributes. They are a data type built using object oriented principles as opposed to the primitive types used in C.

- What type is a C-style string?

A C style string is an array of characters
- What happens when you iterate a pointer?
When we increment pointers, the address the pointer is pointing to changes by a number decided by the type of pointer.

- What are the most important safety tips to know when using pointers?
We need to ensure that our pointer is always pointing to defined locations in the memory, we never free a pointer twice and that we do not dereference a null pointer. 

## Learn Basics of Creating a C++ Project in Your IDE

- How do you compile and run your project in your IDE?
While there may be build tools in Vscode, (I think CMake), the most convenient options are to use the run button on the top right that comes alongside the C++ extension and the terminal

## Improving Interactions with LLMs

- What is the most authoritative source of information about `socket()`
  from `<sys/socket.h>`?
The man pages of socket available at man7.org if I remember right. 

- What is the most authoritative source of information about the TCP and IP
  protocols?
The respective RFCs. 

- What is the most authoritative source of information about the C++
  programming language?
  The ISO standard of C++
- What information can you find about using Markdown when structuring prompts 
  to LLMs?


- What is the difference between LLM and AI?


AI is a much broader concept that refers to a wide range of techniques, including LLMs, Machine learning and neural networks, while LLMs refer to one particular implementation that predicts the next token in a series of tokens. 
- Is it grammatically correct in English to say "a LLM" or "an LLM"? Why?
I think a LLM because L is not a vowel




