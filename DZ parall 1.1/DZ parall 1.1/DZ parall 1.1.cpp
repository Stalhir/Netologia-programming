#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void Client(int& client_count, int maxclient)
{
    for(int i = 0; i < maxclient; i++)
    {
        client_count++;
        this_thread::sleep_for(1s);
        //cout << "Client_Func: " << client_count << "\t";
    } 
}

void Operator(int& client_count)
{
    while(client_count != 0)
    {
        client_count--;
        this_thread::sleep_for(2s); 
        //cout << "Operator_Func: " << client_count << "\t";
    }
}


int main()
{
    int client_count = 5;
    thread t1(Client, ref(client_count), 8);
    thread t2(Operator, ref(client_count));

    t1.join();
    t2.join();
    return 0;
}

