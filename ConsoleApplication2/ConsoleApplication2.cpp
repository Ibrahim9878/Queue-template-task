#include <iostream>
#include<ostream>
#include <cassert>
using namespace std;
template <typename T>
class Queue
{
    T* _arr = nullptr;
    int _front = -1;
    int _rear = -1;
    int _max;
public:
    Queue(int max) 
    {
        if (max < 0 || max >= 1000)
            assert(!"max menfi ve 100den boyuk ola bilmez");
        _max = max;
        _front = -1;
        _rear = -1;
        _arr = new T[_max];
    }

    bool IsFull()
    {
        return _rear == _max - 1;
    }
    bool IsEmpty()
    {
        return _front == -1;
    }

    void Add(T item)
    {
        if (IsFull()) assert(!"Bos yer yoxdur");
        if (_front == -1) _front = 0;
        _rear++;
        _arr[_rear] = item;
    }
    void Pop()
    {
        if (IsEmpty())
            assert(!"Silinecek bir sey yoxdur");
        if (_front == _rear)
        {
            _front = -1;
            _rear = -1;
            return;
        }
        _front++;
    }

    T Peek()
    {
        if (IsEmpty())
            assert(!"Qaytaracaq bir sey yoxdur");
        return _arr[_front];
    }
    int Size()
    {
        if (IsEmpty()) return 0;
        return _rear - _front + 1;
    }

    void Print()
    {
        if (_front == -1)
        {
            cout << "[]" << endl;
            return;
        }
        cout << "[";
        for (size_t i = _front; i <= _rear; i++)
        {
            cout << _arr[i];
            if (i != _rear)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    template <typename T>
    friend ostream& operator<<(ostream& print, const Queue<T>& other);
};
template <typename T>
ostream& operator<<(ostream& print, const Queue<T>& other)
{
    if (other._front == -1) print << "[]" << endl;
    print << "[";
    for (size_t i = other._front; i < other._rear; i++)
    {
        print << other._arr[i];
        if (i != other._rear)
            print << ", ";
    }
    print << "]" << endl;
    return print;
}
int main()
{
    Queue<int> a(10);
    a.Print();
    a.Add(11);
    a.Add(12);
    a.Add(13);
    cout << a.Size();
    a.Print();
}
