#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

using namespace std;

void Client(atomic<int>& client_count, int maxclient)
{
    for (int i = 0; i < maxclient; i++)
    {
        client_count.fetch_add(1, memory_order_seq_cst);
        this_thread::sleep_for(1s);
        //cout << "Client_Func: " << client_count.load(memory_order_seq_cst) << "\t";
    }
}

void Operator(atomic<int>& client_count)
{
    while (client_count != 0)
    {
        client_count.fetch_sub(1, memory_order_seq_cst);
        this_thread::sleep_for(2s);
        //cout << "Operator_Func: " << client_count.load(memory_order_seq_cst) << "\t";
    }
}


int main()
{
    atomic<int> client_count = 5;
    thread t1(Client, ref(client_count), 8);
    thread t2(Operator, ref(client_count));

    t1.join();
    t2.join();
    return 0;
}
