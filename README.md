# HelloThread
Practice work with threads while following the C++ Concurrency in Action book by Anthony Williams. Trying to implement some of the topics
I'm reading about throughout the book, while also trying to learn some c++.

### HelloThread.cpp
This file is my first foray into threads with C++. Basically I was trying to find out the breaking point when threads are actually useful. The first example is calling through a simple addDescending recursive method that adds numbers form the input down to 1. The threads operate slower as calling the thread and joining it take significant time, and not very worth it when the problem can be quickly solved by normal means. However the second part I created a list of 999,999 elements and a method to traverse through it, no additional functions. In the second portion, threads are definitely quicker. First lesson from the book, know when to use threads and when not to!
