#pragma once

#include <algorithm>
#include <ostream>
#include <initializer_list>
#include <cassert>
#include <cstring>
#include <stdlib.h>

#include <memory>

#include "config.h"

class Vector
{
public:
// DO NOT CHANGE THIS
    Vector(const Vector&) = default;
    Vector& operator=(const Vector&) = default;
    ~Vector() = default;
//

// Add suitable constructors
    Vector() : _list(std::make_shared<InternalContainer<int>>()){}

    Vector(std::initializer_list<int> list){_list = std::make_shared<InternalContainer<int>>(list);}
    // possibly more

// Public Member functions here
    Vector& operator+=(const Vector& a)
    {
        for (std::size_t i = 0; i < a.size(); i++)
            (*_list)[i]+=a[i];

        return *this;
    }

    Vector& operator-=(const Vector& a)
    {
        int i;
        for (i = 0; i < _list->size(); i++)(*_list)[i] -= a[i];
        return *this;
    }

    Vector& operator+=(int value)
    {
        _list->push_back(value);
        return *this;
    }

    Vector operator+(const Vector &other)
    {
        Vector x{};
        int a = 0;
        int i;
        for (i = 0; i < other.size(); i++, a++) { 
            int l = other[i], r;
            if (a >= _list->size())
                r = 0;
            else
                r = (*_list)[a];
            x += (l + r);
        }
        return x;
    }

    Vector operator*(const int a)
    {
        Vector x{};
        std::size_t i;
        for (i = 0; i < _list->size(); i++) 
            x += (*_list)[i] * a;
        return x;
    }

    Vector &operator*=(const int a)
    {
        std::size_t i;
        for (i = 0; i < _list->size(); i++) (*_list)[i] *= a;
        return *this;
    }

    int operator*(const Vector &other)
    {
        int a = 0;
        int res = 0;
        std::size_t i;
        for (i = 0; i < _list->size(); i++, a++) res += (other[i] * (*_list)[a]);
        return res;
    }

    bool isEmpty() const{return _list->isEmpty();}
    std::size_t size() const{return _list->size();}
    int &operator[](int index) const{return (*_list)[index];}
    int &operator[](int index){return (*_list)[index];}

private:
// Private Member functions here (if necessary)

    template<class T>
    struct InternalContainer
    {
        public:
            InternalContainer(std::initializer_list<T> list) : _size(list.size())
            {
                int i = 0;
                _list = static_cast<T *>(std::malloc(sizeof(T) * _size));

                for (const auto &x : list)
                    _list[i++] = x;
            }

            InternalContainer() : _size(0), _list(nullptr)
            {
            };
            
            ~InternalContainer()
            {
                if (_list != nullptr)
                    std::free(_list);
            };

            void resize(int newSize)
            {
                if (_list == nullptr) {
                    _size = newSize;
                    _list = static_cast<T *>(std::malloc(sizeof(T) * newSize));
                    std::memset(_list, 0, sizeof(T) * newSize);
                } else {
                    _list = static_cast<T *>(std::realloc(_list, sizeof(T) * (newSize)));
                    _size = newSize;
                }
            }

            void push_back(T &data)
            {
                resize(_size + 1);
                _list[_size - 1] = data;
            }

            T &operator[](int index) const
            {
                return _list[index];
            }

            T &operator[](int index)
            {
                if (index >= _size) {
                    this->resize(index + 1);
                }
                return _list[index];
            }

            std::size_t size() const{return _size;}
            bool isEmpty() const {return _size == 0;}

        private:
            T *_list;
            std::size_t _size;
    };

// Member variables are ALWAYS private, and they go here
    std::shared_ptr<InternalContainer<int>> _list;

};

std::ostream& operator<<(std::ostream& os, const Vector& vector)
{
    if (!vector.isEmpty())
    {
        os << "{";
        int i;
        for (i = 0; i < vector.size(); i++) 
        {
            os << vector[i];
            if (i + 1 != vector.size()) os << ",";
        }
        os << "}";
        return os;
    }
    else
    {
        os << "{}";
        return os;
    }
}

// Nonmember function operators go here