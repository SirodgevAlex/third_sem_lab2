//
// Created by Acer on 11.04.2022.
//
#pragma once
#ifndef SECOND_SEM_LAB2_DYNAMICARRAY_H
#define SECOND_SEM_LAB2_DYNAMICARRAY_H
#define INDEX_OUT_OF_RANGE_MESSAGE "index out of range"
#define NEGATIVE_SIZE_MESSAGE "size is negative"
#define ZERO_SIZE_MESSAGE "size is 0"

#include <iostream>

using namespace std;

template<class T>
class DynamicArray {
private:
    T *data = nullptr;
    int size = 0;
public:
    DynamicArray() { //создание массива для нулевой длины

    }

    DynamicArray(int size) { //создание массива дл длины size
        if (size < 0) throw length_error(NEGATIVE_SIZE_MESSAGE);

        this->data = new T[size];
        this->size = size;
    }

    DynamicArray(T *items, int count) {
        int i;
        this->data = new T[count];
        for (i = 0; i < count; i++) {
            this->data[i] = items[i];
        }
        this->size = count;
    }

    DynamicArray(const DynamicArray <T> &array, int size) : DynamicArray(size) {
        if (size > array.size) throw out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
        int i;
        for (i = 0; i < size; i++) {
            this->data[i] = array.data[i];
        }
    }

    DynamicArray(const DynamicArray<T> &array) :
            DynamicArray(array.data, array.size) {}

    virtual ~DynamicArray(){
        delete[] this->data;
        this->size = 0;
    }

    T Get(int index) {
        if ((index < 0) or (index >= this->size)) throw out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);

        return this->data[index];
    }

    int GetSize() {
        return this->size;
    }

    void Set(const T& value, int index) {
        if ((index < 0) or (index >= this->size)) throw out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
        this->data[index] = value;
    }

    void Resize(int newSize) {
        int i;
        if (newSize < 0) throw out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
        T *newData = new T[newSize];
        for (i = 0; i < newSize; i++) {
            newData[i] = this->data[i];
        }
        this->data = newData;
        this->size = newSize;
    }

    bool operator==(const DynamicArray<T> &array) {
        if (this->size != array.size()) {
            return false;
        }
        int i;
        for (i = 0; i < this->size; i++) {
            if (array[i] != this->data[i]) {
                return false;
            }
        }
        return true;
    }

    DynamicArray<T>& operator=(const DynamicArray &array){
        delete this->data;
        this->data = array.size;
        this->data = new T[this->data];
        int i;
        for (i = 0; i < this->size; i++) {
            this->data[i] = array.data[i];
        }
        return *this;
    }

};


#endif //SECOND_SEM_LAB2_DYNAMICARRAY_H
