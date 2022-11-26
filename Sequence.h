#include <iostream>
#include <cmath>
#include "DynamicArray.h"
#include "LinkedList.h"

#pragma once
#ifndef SECOND_SEM_LAB2_ARRAYSEQUENCE_H
#define SECOND_SEM_LAB2_ARRAYSEQUENCE_H
#define INDEX_OUT_OF_RANGE_MESSAGE "index out of range"
#define NEGATIVE_SIZE_MESSAGE "size is negative"
#define ZERO_SIZE_MESSAGE "size is 0"
using namespace std;

template<typename T>
class Sequence {
protected:
    int size = 0;
public:
    virtual T GetFirst() const = 0;
    virtual T GetLast() const = 0;
    virtual T Get(int index) const = 0;
    virtual int GetSize() const { return this->size; }
    virtual Sequence<T>* GetSubSequence(int startIndex, int endIndex) const = 0;
    virtual void Set(const T &value, int index) = 0;
    virtual void Append(const T &item) = 0;
    virtual void Prepend(const T &item) = 0;
    //virtual void DelArraySequence() const = 0;
    virtual void InsertAt(const T &item, int index) = 0;
    virtual Sequence<T>* Concat(const Sequence<T>& seq) const = 0;
    virtual bool operator==(const Sequence<T> &seq){
        if(this->size != seq.size) return false;

        for(int i = 0; i < this->size; i++){
            if(this->Get(i) != seq.Get(i)) return false;
        }
        return true;
    }
};

template<typename T>
class ArraySequence : public Sequence<T> {
protected:
    DynamicArray<T> *data;
public:
    ArraySequence(){
        this->data = new DynamicArray<T>();
        this->size = 0;
    }

    ArraySequence(T *items, int count) {
        this->data = new DynamicArray<T>(items, count);
        this->size = count;
    }

    ArraySequence(const DynamicArray<T> &seq) {
        this->data = new DynamicArray<T>(*seq.array);
        this->size = seq.size;
    }

    ArraySequence(const ArraySequence<T> &seq) {
        this->size = seq.size;
        this->data = new DynamicArray<T>(this->size);
        for (int i = 0; i < this->size; i++) {
            this->data->Set(seq.Get(i), i);
        }
    }

    ArraySequence(DynamicArray<T>* array) {
        this->data = array;
        this->size = array->GetSize();
    }

    ArraySequence(int size) {
        this->data = new DynamicArray<T>(size);
        this->size = size;
    }

    virtual ~ArraySequence(){
        delete this->data;
        this->size = 0;
    }

    virtual T GetFirst() const override {
        if (this->size == 0) throw out_of_range(ZERO_SIZE_MESSAGE);
        return this->data->Get(0);
    }

    virtual T GetLast() const override {
        if (this->size == 0) throw out_of_range(ZERO_SIZE_MESSAGE);
        return this->data->Get(this->size - 1);
    }

    virtual T Get(int index) const override{
        if (this->size == 0) throw out_of_range(ZERO_SIZE_MESSAGE);
        if ((index < 0) or (index >= this->size)) throw out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
        return this->data->Get(index);
    }

    virtual void Set(const T &item, int index) {
        if ((index < 0) or (index >= this->size)) throw INDEX_OUT_OF_RANGE_MESSAGE;
        this->data->Set(item, index);
    }

    virtual ArraySequence<T> *GetSubSequence(int startIndex, int endIndex) const override{
        if ((startIndex < 0) or (startIndex >= this->size)) throw out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
        if ((endIndex < 0) or (endIndex >= this->size)) throw out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
        if (startIndex > endIndex) throw out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
        DynamicArray<T> *newList = new DynamicArray<T>();
        int i;
        T subArray[endIndex - startIndex];
        for (i = startIndex; i < endIndex; i++) {
            subArray[i - startIndex] = this->data->Get(startIndex + i);
        }
        ArraySequence<T> *SubSequence = new ArraySequence<T>(subArray, endIndex - startIndex);
        return SubSequence;
    }

    int GetLength() {
        return this->size;
    }

    virtual void Append(const T &item) override{
        T NewArray[this->size + 1];
        int i;
        for (i = 0; i < this->size; i++) {
            NewArray[i] = this->data->Get(i);
        }
        NewArray[i] = item;
        DynamicArray<T> *Sequence = new DynamicArray<T>(NewArray, this->size + 1);
        this->data = Sequence;
        this->size++;
    }

    virtual void Prepend(const T &item) override{
        T NewArray[this->size + 1];
        int i;
        for (i = 1; i < this->size + 1; i++) {
            NewArray[i] = this->data->Get(i - 1);
        }
        NewArray[0] = item;
        DynamicArray<T> *Sequence = new DynamicArray<T>(NewArray, this->size + 1);
        this->data = Sequence;
        this->size++;
    }

    virtual void InsertAt(const T &item, int index) override{
        if ((index < 0) or (index > this->size)) throw out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
        T NewArray[this->size + 1];
        int i;
        NewArray[index - 1] = item;
        for (i = 0; i < this->size; i++) {
            if (i < index - 1) {
                NewArray[i] = this->data->Get(i);
            } else if (i > index - 1) {
                NewArray[i + 1] = this->data->Get(i);
            }
        }
        DynamicArray<T> *Sequence = new DynamicArray<T>(NewArray, this->size + 1);
        this->data = Sequence;
        this->size++;
    }

    void Print() {
        cout << this->size << '\n';
        for (int i = 0; i < this->size; i++) {
            cout << this->data->Get(i) << ' ';
        }
        cout << '\n';
    }

    virtual ArraySequence<T>* Concat(const Sequence<T>& seq) const override{
        DynamicArray<T> *array = new DynamicArray<T>(this->size + seq.GetSize());
        ArraySequence<T> *newSequence = new ArraySequence<T>(array);
        for(int i = 0; i < this->size; i++)
            newSequence->Set(this->Get(i), i);

        for(int i = 0; i < seq.GetSize(); i++)
            newSequence->Set(seq.Get(i), i + this->size);

        return newSequence;
    }

    ArraySequence<T> operator =(ArraySequence<T> &Seq) {
        delete this->data;
        this->size = Seq->GetLength();
        data = new DynamicArray<T>(this->size);
        for (int i = 0; i < this->size; i++) {
            this->data->Set(Seq.Get(i), i);
        }
        return *this;
    }

    /*virtual void PrintArray() const override{
        for (int i = 0; i < this->size; i++){
            if ((i % sqrt(this->size) == 0) and (i != 0)) {
                cout << '\n';
            }
            cout << this->data->Get(i) << " ";
        }
        cout << endl;
    }*/
};

//template<typename T>
//ArraySequence<T>::ArraySequence(const ArraySequence<T> &Seq) {
//    delete this->data;
//    this->size = Seq->GetLength();
//    data = new ArraySequence<T>(this->size);
//    for (int i = 0; i < this->size; i++) {
//        this->data->Set(Seq.Get(i), i);
//    }
//    return *this;
//}

template<typename T>
class LinkedListSequence : public Sequence<T> {
protected:
    LinkedList<T> *list;
public:
    LinkedListSequence() { //создаем пустой список
        this->list = new LinkedList<T>();
        this->size = 0;
    }

    LinkedListSequence(const LinkedListSequence<T> &seq){
        this->list = new LinkedList<T>(*seq.list);
        this->size = seq.size;
    }

    explicit LinkedListSequence(LinkedList<T> *list) { // создаем список на sizeof(T* list) элементов, значения знаем
        this->list = list;
        this->size = list->GetLength();
    }

    LinkedListSequence(T *items, int count) { //создаем список на коунт элементов, знаем значения
        this->list = new LinkedList<T>(items, count);
        this->size = count;
    }

    explicit LinkedListSequence(int length) {
        this->list = new LinkedList<T>(length);
        this->size = length;
    }

    virtual ~LinkedListSequence(){
        delete this->list;
        this->size = 0;
    }

    virtual T GetFirst() const override { //Получить первый элемент в списке
        return this->list->GetFirst();
    }

    virtual T GetLast() const override {
        return this->list->GetLast();
    }

    virtual T Get(int index) const override {
        return this->list->Get(index);
    }

    virtual LinkedListSequence<T> *GetSubSequence(int startIndex, int endIndex) const override{
        LinkedList<T> *subList = this->list->GetSublist(startIndex, endIndex);
        LinkedListSequence<T> *sequence = new LinkedListSequence<T>(subList);
        return sequence;
    }

    virtual void Set(const T &value, int index) override {
        this->list->Set(value, index);
    }

    virtual T GetLength() {
        return this->list->GetLength();
    }

    virtual void Append(const T &item) override {
        this->list->Append(item);
        this->size++;
    }

    virtual void Prepend(const T &item) override {
        this->list->Prepend(item);
        this->size++;
    }

    virtual void InsertAt(const T &item, int index) override {
        this->list->InsertAt(item, index);
        this->size++;
    }

    virtual LinkedListSequence<T>* Concat(const Sequence<T>& seq) const override {
        LinkedListSequence<T>* newSequence = new LinkedListSequence<T>();
        int i;
        for (i = 0; i < this->size; i++) {
            newSequence->Append(this->Get(i));
        }
        for (i = 0; i < seq.GetSize(); i++) {
            newSequence->Append(seq.Get(i));
        }
        return newSequence;
    }

    bool operator==(const LinkedListSequence<T> &list) const {
        if(this->size != list.size) return false;

        for(int i = 0; i < this->size; i++){
            if(this->Get(i) != list.Get(i)) return false;
        }

        return true;
    }
};





#endif //SECOND_SEM_LAB2_ARRAYSEQUENCE_H
