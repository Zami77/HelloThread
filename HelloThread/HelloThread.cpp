#include <thread>
#include <iostream>
#include <chrono>
#include <list>
#include <iterator>

unsigned long addDescending(unsigned long num)
{
    if (num < 0)
        return -1;
    if (num == 1)
        return 1;
    return num + addDescending(num - 1);
}
void traverseList(std::list<int> travList)
{
    for (int i = 0; i < travList.size(); i++)
    {
        //Do nothing, traverse list 
    }
}
int main()
{
    //***Bad example of threading***
    unsigned long const num_threads = std::thread::hardware_concurrency();
    std::cout << "Number of hardware threads: " << num_threads << "\n";
    std::cout << "\nTraditional vs. Threads on adding descending numbers";
    clock_t timeElapsed;
    timeElapsed = clock();
    for (int i = 0; i < 1000; i++)
    {
        addDescending(4600);
    }
    timeElapsed = clock() - timeElapsed;
    std::cout << "\nTraditional Time: " << (float)timeElapsed / CLOCKS_PER_SEC;

    timeElapsed = clock();
    for (int i = 0; i < 1000; i++)
    {
        std::thread t (addDescending,4600);
        t.join();
    }
    timeElapsed = clock() - timeElapsed;
    std::cout << "\nThread Time: " << (float)timeElapsed / CLOCKS_PER_SEC;
    std::cout << "\n******************************************************";

    //Good example of threading
    std::cout << "\nTraditional vs. Threads on traversing a list of 999,999 elements";
    std::list <int> numList;
    for (int i = 0; i < 999999; i++)
    {
        numList.push_back(i);
    }
    //Traverse list 5 times traditional
    timeElapsed = clock();

    for (size_t i = 0; i < 5; i++)
    {
        traverseList(numList);
    }

    timeElapsed = clock() - timeElapsed;
    std::cout << "\nTraditional Time: " << (float)timeElapsed / CLOCKS_PER_SEC;

    //Traverse list 5 times with threads
    timeElapsed = clock();
 
    std::thread t1(traverseList,numList);
    std::thread t2(traverseList, numList);
    std::thread t3(traverseList, numList);
    std::thread t4(traverseList, numList);
    std::thread t5(traverseList, numList);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    timeElapsed = clock() - timeElapsed;
    std::cout << "\nThread Time: " << (float)timeElapsed / CLOCKS_PER_SEC;
}