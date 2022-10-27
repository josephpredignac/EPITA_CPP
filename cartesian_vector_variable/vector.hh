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
    Vector(const Vector&);
    Vector& operator=(const Vector&);
    ~Vector() = default;
//

// Add suitable constructors
    Vector(size_t N);
    Vector(std::initializer_list<value> l);

    size_t size() const;

// Public Member functions here
    Vector& operator+=(const Vector& rhs);
    // More to go
    Vector& operator-=(const Vector& rhs);
    Vector& operator+=(value v);
    Vector& operator*=(value v);

    Vector operator+(const Vector& rhs) const;
    Vector operator+(value v) const;
    value operator*(const Vector& rhs) const;
    Vector operator*(value v) const;

    value& operator[](size_t idx);
    value operator[](size_t idx) const;

private:
// Private Member functions here (if necessary)

// Member variables are ALWAYS private, and they go here
};

// Nonmember function operators go here
Vector operator*(const value& s, const Vector& v);
Vector operator+(const value& s, const Vector& v);
std::ostream& operator<<(std::ostream& o, const Vector& v);