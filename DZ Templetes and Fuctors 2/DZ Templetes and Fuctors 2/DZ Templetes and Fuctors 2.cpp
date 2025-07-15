#include <iostream>

using namespace std;

template<typename T>
class table
{
private:
    int rows;
    int cols;
    T** _ptr;
public: 
    table(int row, int col) : rows(row), cols(col)
    {
        _ptr = new T * [row]; 
        for (int i = 0; i < row; i++) {
            _ptr[i] = new T[col];  
        }
    }

    ~table() 
    {
         
        for (int i = 0; i < rows; i++) {
            delete[] _ptr[i];
        }
        delete[] _ptr;
    }

    class Proxy
    {
    private:
        T* rows;
    public:
   
        Proxy(T* row) : rows(row) {}

 
        T& operator[](int col)
        {
        return rows[col];
        }
       
    };

    class ConstProxy {
    private:
        const T* row_;
    public:
        ConstProxy(const T* row) : row_(row) {}


        const T& operator[](int col) const
        {
            return row_[col];
        }
    };

   
    Proxy operator[](int row)
    {
        return Proxy(_ptr[row]);
    }
    ConstProxy operator[](int row) const {
        return ConstProxy(_ptr[row]);
    }
    
};








int main()
{
    table<int> T(5, 4);
    T[1][3] = 12;
    cout << T[1][3];

}
