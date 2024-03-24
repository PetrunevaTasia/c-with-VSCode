#pragma once

template<typename T>
class ScopedPointer {
    T* pointer;
    public:
        ScopedPointer(T* raw): pointer(raw) { };
        ScopedPointer(const ScopedPointer& other){
            T sth = *other.pointer;
            pointer = new T(sth);
        };
        ScopedPointer(ScopedPointer&& other){
            pointer = other.pointer;
            other.pointer = nullptr;
        };
        T& get() { return *pointer; };
        const T& get() const { return *pointer; };
        ~ScopedPointer() { delete pointer; };
};

struct Point{
    double x;
    double y;
    Point(double x_, double y_): x(x_), y(y_){}
};