#include "Vector.h"
Vector::Vector(int s) : size(s) {
    values = new double[s];
}

Vector::Vector(const Vector& other) : size(other.size) {
    values = new double[size];
    for (int i = 0; i < size; ++i) {
        values[i] = other.values[i];
    }
}

Vector::~Vector() {
    delete[] values;
}

Vector& Vector::operator=(const Vector& other) {
    if (this == &other) {
        return *this;
    }
    delete[] values;
    size = other.size;
    values = new double[size];
    for (int i = 0; i < size; ++i) {
        values[i] = other.values[i];
    }
    return *this;
}

Vector Vector::operator+(const Vector& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Vectors must be of the same size");
    }
    Vector result(size);
    for (int i = 0; i < size; ++i) {
        result.values[i] = values[i] + other.values[i];
    }
    return result;
    result.~Vector();
}

Vector Vector::operator-(const Vector& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Vectors must be of the same size");
    }
    Vector result(size);
    for (int i = 0; i < size; ++i) {
        result.values[i] = values[i] - other.values[i];
    }
    return result;
    result.~Vector();
}

double& Vector::operator[](int i) {
    if (i < 0 || i >= size) {
        throw std::out_of_range("Index out of range");
    }
    return values[i];
}

int Vector::GiveSize() const {
    return size;
}

void Vector::Generate(double lg, double ug) {
    for (int i = 0; i < size; ++i) {
        double random_value = lg + (rand() * (ug - lg) / RAND_MAX);
        values[i] = random_value;
    }
}

void Vector::NullVector() {
    for (int i = 0; i < size; ++i) {
        values[i] = 0;
    }
}

std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    for (int i = 0; i < vec.size; ++i) {
        os << vec.values[i] << " "<<endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Vector& vec) {
    for (int i = 0; i < vec.size; ++i) {
        is >> vec.values[i];
    }
    return is;
}
