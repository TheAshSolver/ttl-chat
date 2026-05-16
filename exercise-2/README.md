# Exercise 2

**Update this README with your answers to the questions below.**

## Sources of Information for Questions from Before

### Socket 
- https://man7.org/linux/man-pages/man2/socket.2.html - System call reference
  for creating communication endpoints
- Or type `man socket` in terminal
- https://man7.org/linux/man-pages/man7/socket.7.html - Socket interface 
  overview and protocol families
- Or type `man 7 socket` in terminal
- When would you want to use a `SOCK_RAW` stream?
When we do not want to use a transport layer protocol and manually work wiht the header. This gives us more flexibility to deal with.

### TCP and IP Protocols
- [IPv4](https://www.rfc-editor.org/info/rfc791) - Internet Protocol 
  specification defining packet structure and routing
- [IPv6](https://www.rfc-editor.org/info/rfc8200) - Next-generation Internet 
  Protocol with expanded address space
- [TCP](https://datatracker.ietf.org/doc/html/rfc9293) - Transmission Control 
  Protocol providing reliable, ordered data delivery
    
### C++
- [C++23 ISO standard draft](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2023/n4950.pdf) - 
  Working draft of the C++ language specification
- Is the above the official C++23 spec? 
No it is the draft
- Where is the official C++23 spec?
It should be behind a paywall at ISO
- Why was this link chosen instead?

It is free and very similar to the actual ISO

- Is this a helpful reference for learning C++?

I would say no. This document is a bit too terse and is very long, so is not a suitable way to learn C++. However, it does function as a reference, while I would prefer other sources like cppreference.com

- Can the various implementations of C++ compilers be different from the
  C++ standard?

While compilers mostly follow the standard, they also have significant leeway in how they implement and some compilers add extra features

- What are the most widely used and most significant C++ compilers?
GCC g++, Clang
- Where is the equivalent spec for C++26?
It is still being developed on github. 

  - Where do you find the spec for the HTTP protocol?
  There is a family of RFCs, the 9110 series that contains information regarding the HTTP protocol. 
  - What about HTTPS? Is there a spec for that protocol?
  HTTPs is basically HTTP with TLS so it does not have a spec of its own.
  ## Introduction to C++ and Sockets Programming

  - Read the code in `src/`
  - Are there any bugs in this code? 
  We need to set each option in setsockopt individually and cannot use a bitwise or.
  - What can you do to identify if there are bugs in the code?
  Firstly, is to try running the app multiple times and seeing if there is anything going wrong or not. Then would be to use debuggers to check the output.


## Refactoring: Extract Function

- What is different in this code compared to exercise-1?
The code is refactored into various functions
- Is this code better or worse than exercise-1?
I would say this is better. It is easier to read and understand and debugging is also easier. 

- What are the tradeoffs compared to exercise-1?

The number of lines of code increases as each function will have to be defined separately, so more code needs to be written. 

- Are you able to spot any mistakes or inconsistencies in the changes?
Yes, I think there is one major inconsistency in the implementation. While we have defined each function to do one particular task, the start_listening_on_socket alone does multiple functions, including binding, setting socket options and listening. We are also redundantly doing create address twice, once inside handle connections and once inside the main. 


  
## Thinking About Performance

- Does writing code this way have any impact on performance?

While there will be small performances misses thanks to stuff like function overheads, thanks to modern compiler optmizations, these will be very minimal. So any effect on performance will be small. 

- What do we mean when we say performance?

When we say performance, we talk about the time it takes for the program to execute a task along with other factors like memory usage. So this could refer to the time taken for the program to finish executing, or the time taken to do a particular task. 

- How do we measure performance in a program?
We can use C++ libraries like chrono and inbuilt functions to keep track of the elapsed time or we can use profilers as well. Profiles take a snapshot of the CPU's working to keep tracking of where the CPU spends its time. 


## Play with Git

- There isn't necessarily a single correct answer for how to abstract the 
  code from exercise-1 into functions
- Try different ways to refactor the code from exercise-1 to make it more
  readable.
- Make sure to commit each change as small and self-contained commit
- This will make it easier to revert your code if you need to
- What is `git tag`? How is `git tag` different from `git branch`?

Git tag is used to mark commits that indicate a special edition or version of the software. On the other hand, git branch is used to allow users to work independently on repositories. While tagging is used to indicate release versions, branch is a way of allowing people to work independently. 

- How can you use `git tag` and `git branch` to make programming easier and
  more fun?
  We can use tagging to indicate when something is working or to ensure we remember when our app did something special, a special timeliene if you will. Git branch can allow multiple people to collaborate and enable teams to experiment with features without having to sacrifice the stability of working editions. 


## Learn Basics of Debugging in Your IDE

- How do you enable debug mode in your IDE?
In VScode, run tab, there is an option to start debugging, that allows you to view your program in debug mode. 
- In debug mode, how do you add a watch?

There is a watch panel on the left side of the window where one can view all the variables to monitor. He or she can also type in an expression and see what it returns

- In debug mode, how do you add a breakpoint?

In the code editor, we can scroll over the line number to get a red circle indicating the option to add a breakpoint. 

- In debug mode, how do you step through code?
There is a step over button at the top or we can click F10


### Memory Management and Debug Mode in Your IDE

- How do you see the memory layout of a `std::string` from your IDE debug mode?
We can set a breakpoint and then in the watch section, add the reference to the string. Then, we can expand to see the various attributes of the string and where they come from. We can also then click on the binary symbol next to it to open it in the memory view.
- How do you see the memory layout of a struct from your IDE debug mode?
Similar to the string method, we can open it in the watch section and then expand it in the variables or the watch section to see its properties and what else it has. We can also open it in the memory view to see how it is in memory. 

