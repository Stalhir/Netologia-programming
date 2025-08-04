#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>
#include <Windows.h>
#include <random>

using namespace std;

mutex cout_mutex;

class consol_parameter
{
public:
    static void SetColor(int text, int background)
    {
        SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
    }
    static void SetPosition(int x, int y)
    {
        COORD point;
        point.X = x;
        point.Y = y;
        SetConsoleCursorPosition(hStdOut, point);
    }
private:
    static HANDLE hStdOut;
};
HANDLE consol_parameter::hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void ProgresBar(int num, int steps)
{
    auto start = chrono::steady_clock::now();
    
    {
        lock_guard<mutex> lock(cout_mutex);
        consol_parameter::SetPosition(0, num + 2);
        cout << num << " " << this_thread::get_id() << "\n";
    }

    srand(GetCurrentThreadId());
    for (int i = 0; i < steps; i++)
    {
        {
        lock_guard<mutex> lock(cout_mutex);
        consol_parameter::SetPosition(i + 9, num + 2);
        cout << static_cast<char>(219);
        }
        std::chrono::milliseconds sleep(rand()%1000);
            
        this_thread::sleep_for(sleep);
    }

    auto end = chrono::steady_clock::now();
    {
        lock_guard<mutex> lock(cout_mutex);
        consol_parameter::SetPosition(steps+9, num + 2);
        std::chrono::duration<double> elapsed_seconds = end - start;
        cout << elapsed_seconds.count() << "s";
    }
}

void AllProgresBar(int countProgBar, int steps)
{
    cout << "#  ID          Progres Bar        Time" << endl;
    vector<thread> Thrs;
    for(int i = 0; i < countProgBar; i++)
    {
        Thrs.push_back(thread(ProgresBar, i, steps));
    }
    for (int i = 0; i < countProgBar; i++)
    {
        Thrs[i].join();
    }

    cout << "\033[" << countProgBar + 2 << ";0H" << endl;
}


int main()
{
    AllProgresBar(9, 18);
     

}

