#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Vector {
    int size;
    vector<double> vector;

public:
    Vector();
    explicit Vector(int _size);
    Vector(Vector& _vector);
    ~Vector();

    [[nodiscard]] int getSize() const;
    void resize(int newSize);
    std::vector<double> getVector();

    double mod();
    Vector operator+(Vector& _vector) const;
    Vector operator-(Vector& _vector) const;
    Vector operator*(double num) const;
    double operator*(Vector& _vector);

    Vector& operator=(const Vector& _vector);

    friend ostream& operator<<(ostream& out, const Vector& _vector);
    friend istream& operator>>(istream& in, Vector& _vector);
};

