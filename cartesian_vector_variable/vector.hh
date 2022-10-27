#pragma once

#include <ostream>
#include <initializer_list>
#include <cassert>
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

    Vector(std::size_t size)
    {
        _list = std::make_shared<InternalContainer<value>>(size);
    }

// Add suitable constructors
    Vector() : _list(std::make_shared<InternalContainer<value>>())
    {
    }

    Vector(std::initializer_list<value> list)
    {
        _list = std::make_shared<InternalContainer<value>>(list);
    }
    // possibly more

// Public Member functions here
    Vector& operator+=(const Vector& rhs)
    {
        if (rhs.size() != size())
            throw std::runtime_error("Incompatible size");

        for (std::size_t i = 0; i < rhs.size(); i++) {
            (*_list)[i] += rhs[i];

            // _list->push_back(rhs[i]);
        }
            

        return *this;
    }

    Vector& operator+=(value value)
    {
        _list->push_back(value);

        return *this;
    }

    Vector& operator-=(const Vector& rhs)
    {
        if (rhs.size() != size())
            throw std::runtime_error("Incompatible size");

        for (int i = 0; i < _list->size(); i++)
            (*_list)[i] -= rhs[i];
        return *this;
    }

    value &operator[](int index) const
    {
        return (*_list)[index];
    }

    value &operator[](int index)
    {
        return (*_list)[index];
    }

    Vector operator+(const Vector &other)
    {
        Vector x{};
        int idx = 0;

        if (other.size() != size())
            throw std::runtime_error("Incompatible size");

        for (int i = 0; i < other.size(); i++, idx++) { 
            int l = other[i], r;

            if (idx >= _list->size())
                r = 0;
            else
                r = (*_list)[idx];

            x += (l + r);
        }

        return x;
    }

    Vector operator*(const int n)
    {
        Vector x{};
        
        for (std::size_t i = 0; i < _list->size(); i++) 
            x += (*_list)[i] * n;

        return x;
    }

    Vector &operator*=(const int n)
    {
        for (std::size_t i = 0; i < _list->size(); i++) 
            (*_list)[i] *= n;

        return *this;
    }

    int operator*(const Vector &other)
    {
        int idx = 0;
        int res = 0;
        
        if (other.size() != size())
            throw std::runtime_error("Incompatible size");

        for (std::size_t i = 0; i < _list->size(); i++, idx++) 
            res += (other[i] * (*_list)[idx]);

        return res;
    }

    bool isEmpty() const
    {
        return _list->isEmpty();
    }

    std::size_t size() const
    {
        return _list->size();
    }

    // More to go

private:
// Private Member functions here (if necessary)

    template<class T>
    struct InternalContainer
    {
        public:
            InternalContainer(std::initializer_list<T> list) : _size(list.size())
            {
                int i = 0;
                _list = std::unique_ptr<T[]>(new T[_size]);

                for (const auto &x : list)
                    _list[i++] = x;
            }

            InternalContainer() : _size(0), _list(nullptr)
            {
            };

            InternalContainer(std::size_t size) : _size(size)
            {
                _list.reset(new T[_size]);
                for (auto i = 0; i < size; i += 1)
                    _list[i] = static_cast<value>(0);
            };
            
            ~InternalContainer()
            {
            };

            void resize(int newSize)
            {
                auto oldSize = _size;
                _size = newSize;

                if (_list == nullptr)
                    _list.reset(new T[_size]);
                else {
                    T* tmp = _list.release();
                    _list.reset(new T[_size]);

                    for (auto i = 0; i < oldSize; i++)
                        _list[i] = tmp[i];
                    delete[] tmp;
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

            std::size_t size() const
            {
                return _size;
            }

            bool isEmpty() const
            {
                return _size == 0;
            }

        private:
            std::unique_ptr<T[]> _list;
            std::size_t _size;
    };

// Member variables are ALWAYS private, and they go here
    std::shared_ptr<InternalContainer<value>> _list;

};

std::ostream& operator<<(std::ostream& os, const Vector& vector)
{
    if (vector.isEmpty())
    {
        os << "{}";
        return os;
    }

    os << "{";

    for (int i = 0; i < vector.size(); i++) 
    {
        os << vector[i];
        if (i + 1 != vector.size()) os << ",";
    }

    os << "}";

    return os;
}

// Nonmember function operators go here
