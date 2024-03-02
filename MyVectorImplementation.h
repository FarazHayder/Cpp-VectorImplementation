/*FarazHayder*/
#if !defined(MyVectorImplementation)
#define MyVectorImplementation

#include "Header.h"

template <typename T>
struct MyVector
{
    T *arr;
    int size;
    int elements;

    MyVector()
    {
        this->size = 1;
        arr = new T[size];
        elements = 0;
    }
    MyVector(int size)
    {
        arr = new T[size];
        this->size = size;
        elements = 0;
    }
    void addElement(T value)
    {
        if (elements == size)
        {
            T *newArr = new T[size + 1];
            for (int i = 0; i < size; i++)
            {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = nullptr;
            arr = newArr;
            size += 1;
        }
        arr[elements] = value;
        elements++;
    }
    auto getElement(int index)
    {
        while (index >= size || index >= elements)
        {
            throw out_of_range("Index out of bounds");
        }
        for (int i = 0; i < size; i++)
        {
            if (i == index)
            {
                return arr[i];
            }
        }
    }
    void changeElement(int index, T value)
    {
        while (index >= size || index >= elements)
        {
            throw out_of_range("Index out of bounds");
        }
        for (int i = 0; i < size; i++)
        {
            if (i == index)
            {
                arr[i] = value;
            }
        }
    }
    void removeElement(int index)
    {
        while (index >= size || index >= elements)
        {
            throw out_of_range("Index out of bounds");
        }
        T *newArr = new T[size - 1];
        for (int i = 0; i < size; i++)
        {
            if (i != index)
            {
                newArr[i] = arr[i];
            }
        }
        delete[] arr;
        arr = nullptr;
        arr = newArr;
        size -= 1;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i];
        }
    }
    // Operator Overloading
    T &operator[](int index)
    {
        while (index >= size || index >= elements)
        {
            throw out_of_range("Index out of bounds");
        }
        return arr[index];
    }
};

#endif // MyVectorImplementation
