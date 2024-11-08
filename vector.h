#pragma once

template <typename T>
struct Myvector 
{
private:

    T* arr;           // Pointer to an array
    int size_of_Vec;
    int memory_size;  // Allocated memory


public:


    Myvector()
    {
        arr = new T[1];
        size_of_Vec = 0;
        memory_size = 1;
    }


    Myvector(const Myvector& other)
    {
        size_of_Vec = other.size_of_Vec;
        memory_size = other.memory_size;
        arr = new T[memory_size];
        for (size_t i = 0; i < size_of_Vec; i++)
        {
            arr[i] = other.arr[i];
        }
    }

    Myvector<T>& operator=(const Myvector& other) {
        if (this != &other) { // Don't we assign the object to ourselves
            delete[] arr;
            size_of_Vec = other.size_of_Vec;
            memory_size = other.memory_size;
            arr = new T[memory_size];
            for (size_t i = 0; i < size_of_Vec; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }


    ~Myvector()
    {
        delete[] arr;
    }


    T* begin() {
        return arr; // ���������� ��������� �� ������ �������
    }


    T* end() {
        return arr + size_of_Vec; // ���������� ��������� �� ������� ����� ����������
    }


    void MPUSH(T name)
    {
        if (size_of_Vec == memory_size)
        {
            T* arr_copy = new T[memory_size * 2];

            for (size_t i = 0; i < size_of_Vec; i++)
            {
                arr_copy[i] = arr[i];
            }
            delete[] arr;
            memory_size *= 2;
            arr = arr_copy;
        }
        arr[size_of_Vec] = name;
        size_of_Vec++;
    }


    void MPUSH(T name, int index)
    {
        if (index < 0 || index > size_of_Vec)
        {
            throw std::out_of_range("Index out of range!!!");
        }

        if (size_of_Vec == memory_size)
        {
            T* arr_copy = new T[memory_size * 2];

            for (size_t i = 0; i < size_of_Vec; i++)
            {
                arr_copy[i] = arr[i];
            }
            delete[] arr;
            memory_size *= 2;
            arr = arr_copy;
        }

        for (size_t i = size_of_Vec; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[index] = name;
        size_of_Vec++;
    }


    void MDEL(int index)
    {
        if (index < 0 || index >= size_of_Vec)
        {
            throw std::out_of_range("Index out of range!!!");
        }

        for (size_t i = index; i < size_of_Vec - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        size_of_Vec--;
    }


    T MGET(int index) const
    {
        if (index <= size_of_Vec && index >= 0)
        {
            return arr[index];
        }
        throw std::out_of_range("Index out of range!!!");
    }


    void MSET(T name, int index)
    {
        if (index < 0 || index >= size_of_Vec)
        {
            throw std::out_of_range("Index out of range!!!");
        }
        arr[index] = name;
    }


    void resize(int new_size)
    {
        T* arr_copy = new T[new_size];
        for (size_t i = 0; i < size_of_Vec; i++)
        {
            arr_copy[i] = arr[i];
        }
        delete[] arr;
        arr = arr_copy;
        memory_size = new_size;
    }


    int size() const
    {
        return size_of_Vec;
    }


    int memory_use() const
    {
        return memory_size;
    }


    void print() const
    {
        for (int i = 0; i < size_of_Vec; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }


    bool contains(const Myvector<T>& vec, const T& value)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec.MGET(i) == value)
            {
                return true; 
            }
        }
        return false;
    }

};