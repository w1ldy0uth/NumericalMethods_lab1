#include "vector.h"

Vector::Vector() {
    this->size = 0;
    this->vector = std::vector<double>(this->size);
}

Vector::Vector(int _size) {
    this->size = _size;
    this->vector = std::vector<double>(this->size, 0.);
}

Vector::Vector(Vector &_vector) {
    this->size = _vector.size;
    this->vector = _vector.vector;
}

Vector::~Vector() {
    this->size = 0;
    this->vector.clear();
    this->vector.shrink_to_fit();
}

int Vector::getSize() const {
    return this->size;
}

void Vector::resize(int newSize) {
    this->size = newSize;
    this->vector.resize(this->size, 0);
}

vector<double> Vector::getVector() {
    return this->vector;
}

double Vector::mod() {
    double modulo = abs(this->vector[0]);
    for (auto number: this->vector) {
        if (abs(number) > modulo)
            modulo = abs(number);
    }
    return modulo;
}

Vector Vector::operator+(Vector& _vector) const {
    if (this->size != _vector.size)
        throw std::length_error("Incompatible size");

    Vector newVector(this->size);
    for (size_t i = 0; i < this->size; ++i) {
        newVector.vector[i] = this->vector[i] + _vector.vector[i];
    }
    return newVector;
}

Vector Vector::operator-(Vector& _vector) const {
    if (this->size != _vector.size)
        throw std::length_error("Incompatible size");

    Vector newVector(this->size);
    for (size_t i = 0; i < this->size; ++i) {
        newVector.vector[i] = this->vector[i] - _vector.vector[i];
    }
    return newVector;
}

Vector Vector::operator*(double number) const {
    Vector newVector(this->size);
    for (size_t i = 0; i < this->size; ++i) {
        newVector.vector[i] = this->vector[i] * number;
    }
    return newVector;
}

double Vector::operator*(Vector& _vector) {
    if (this->size != _vector.size)
        throw std::length_error("Incompatible size");

    double dotProduct = 0;
    for (size_t i = 0; i < this->size; ++i) {
        dotProduct += this->vector[i] * _vector.vector[i];
    }
    return dotProduct;
}

Vector& Vector::operator=(const Vector& _vector) {
    if (this == &_vector)
        return *this;

    this->~Vector();
    this->size = _vector.size;
    this->vector = _vector.vector;
    return *this;
}

ostream& operator<<(ostream& out, const Vector& _vector) {
    out << "(";
    for (size_t i = 0; i < _vector.size - 1; ++i) {
        out << _vector.vector[i] << ", ";
    }
    out << _vector.vector[_vector.size-1] << ")";
    return out;
}

istream& operator>>(istream& in, Vector& _vector) {
    double num;
    for (size_t i = 0; i < _vector.size; ++i) {
        in >> num;
        _vector.vector[i] = num;
    }
    return in;
}
