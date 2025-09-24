#include <iostream>
#include "thread_pool/safe_queue/SafeQueue.h"
#include "thread_pool/threadpool.h"

void task1() {
    std::cout << "Task 1 executed by thread: " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void task2() {
    std::cout << "Task 2 executed by thread: " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
}

void task3(const std::string& name) {
    std::cout << "Task " << name << " executed by thread: " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

int main() {

    ThreadPool pool;

    std::cout << "Thread pool created with " << std::thread::hardware_concurrency() << " threads" << std::endl;

    for (int i = 0; i < 5; ++i) {
        std::cout << "\n=== Iteration " << i + 1 << " ===" << std::endl;


        pool.submit(task1);
        pool.submit(task2);
        pool.submit([]()
        {
            std::cout << "Lambda task executed by thread: " << std::this_thread::get_id() << std::endl;
        });
    }
    return 0;
}