#include <iostream>
#include <thread>

// clear && g++ -pthread -o thread thread.cpp && ./thread

void for_thread_1() {
   std::cout << "1 is executing concurrently...\n";
}

void for_thread() {
   std::cout << " is executing concurrently...\n";
}


int main() {
   std::thread thread_1 ( for_thread_1 );
   std::thread thread ( for_thread );

   std::cout << "main, 1 and 2 execute concurrently...\n";

   thread_1.join();
   thread.join();

   std::cout << "and completed.\n";

   return 0;
}

