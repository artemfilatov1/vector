#ifndef vector_hpp
#define vector_hpp

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

template <class T>
class Vector{
    T* elements;
    unsigned int size;
    unsigned int length;
public:
    Vector();
    ~Vector();
    
    unsigned int getLength(){return length;}
    
    void pushBack(const T& data);
    void sort(char s);
    void show();
    
    T & operator[](unsigned int idx);
};

template <class T>
Vector<T>::Vector(){
    length = 0;
    size = 4;
    elements = (T*)(malloc(sizeof(T)*size));
}

template <class T>
Vector<T>::~Vector(){
    for (int i = 0; i < length; i++){
        elements[i].~T();
    }
    free(elements);
}

template <class T>
void Vector<T>::pushBack(const T& data){
    if (length > size){
        size *= 2;
        T* tmp = (T*)(malloc(sizeof(T)*size));
        for (int i = 0; i < length; i++){
            new (&tmp[i])T(elements[i]);
            elements[i].~T();
        }
        free(elements);
        elements = tmp;
    }
    new (&elements[length])T(data);
    length++;
}

template <class T>
void Vector<T>::sort(char s){
    if (s == '<'){
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++){
                if (elements[i] < elements[j]){
                    swap(elements[i], elements[j]);
                }
            }
        }
    }
    else if (s == '>'){
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++){
                if (elements[i] > elements[j]){
                    swap(elements[i], elements[j]);
                }
            }
        }
    }

    else{
        cout << "vector.sort()  error: use '>' or  '<'" << endl;
    }
}

template <class T>
void Vector<T>::show(){
    for (int i = 0; i < length; i++) {
        cout << elements[i] << " ";
    }
    cout << endl;
}

template <class T>
T & Vector<T>::operator[](unsigned int idx){
    if (idx > length) throw "idx > length";
    return elements[idx];
}

#endif /* vector_hpp */
