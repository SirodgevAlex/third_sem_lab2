//
// Created by Acer on 11.04.2022.
//
#include <iostream>

#ifndef SECOND_SEM_LAB2_LINKEDLIST_H
#define SECOND_SEM_LAB2_LINKEDLIST_H
using namespace std;
#define INDEX_OUT_OF_RANGE_MESSAGE "index out of range"
#define NEGATIVE_SIZE_MESSAGE "size is negative"
#define ZERO_SIZE_MESSAGE "size is 0"

template<class T>
class LinkedList {
protected:
    struct Record {
        T item;
        Record *next = nullptr;
    };
    Record *head = nullptr;
    int size = 0;
public:

    LinkedList() : size(0) { //пустой список
    }

    LinkedList(T *item, int count) : LinkedList() { //Копировать элементы из переданного массива
        if (count < 0) throw length_error(NEGATIVE_SIZE_MESSAGE);
        Record **ptr = &(this->head);
        int i;
        for (i = 0; i < count; i++) {
            *ptr = new Record;
            (*ptr)->item = item[i];
            ptr = &((*ptr)->next);
        }
        this->size = count;
    }

    explicit LinkedList(int size) { //список на size элементов. каждый из которых пустой
        if (size < 0) throw length_error(NEGATIVE_SIZE_MESSAGE);
        Record **ptr = &(this->head);
        int i;
        for (i = 0; i < size; i++) {
            *ptr = new Record;
            (*ptr)->item = T();
            ptr = &((*ptr)->next);
        }
        this->size = size;
    }

    explicit LinkedList(const LinkedList<T> &list) { //копирующий конструктор (ака создаем точно такой же список)
        Record *ptr = list.head;
        Record **newPtr = &(this->head);
        for (int i = 0; i < list.size; i++, ptr = ptr->next) {
            *newPtr = new Record;
            (*newPtr)->item = ptr->item;
            newPtr = &((*newPtr)->next);
        }
        this->size = list.size;
    }

    T GetFirst() { //получить первый элемент
        if (this->size == 0) throw length_error(ZERO_SIZE_MESSAGE);
        return head->item;
    }

    T GetLast() { //получить последний элемент
        if (this->size == 0) throw length_error(ZERO_SIZE_MESSAGE);
        Record *ptr = this->head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        return ptr->item;
    }

    T Get(int index) const { //получить элемент по индексу
        if ((index < 0) or (index >= this->size)) throw out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
        int i;
        Record *ptr = this->head;
        for (i = 0; i < index; i++) {
            ptr = ptr->next;
        }
        return ptr->item;
    }

    void Set(const T &value, int index) { //присвоить элементу с индексом index значение value
        if ((index < 0) or (index >= this->size)) throw out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
        int i;
        Record *ptr;
        for (i = 0; i < index; i++) {
            ptr = ptr->next;
        }
        ptr->item = value;
    }

    LinkedList<T> *GetSublist(int startIndex, int endIndex) const { //получить список элементов по индексам
        if ((startIndex < 0) or (startIndex >= this->size)) throw out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
        if ((endIndex < 0) or (endIndex >= this->size)) throw out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
        if (startIndex > endIndex) throw out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
        LinkedList<T> *newList = new LinkedList<T>();
        Record *ptr = this->head;
        Record **newPtr = &newList->head;
        int i;
        for (i = startIndex; i < endIndex; i++) {
            *newPtr = new Record;
            (*newPtr)->item = ptr->item;
            newPtr = &((*newPtr)->next);
        }
        newList->size = endIndex - startIndex;
        return newList;
    }

    int GetLength() { //получить длину списка
        return this->size;
    }

    void Append(const T &item) { //добавить элемент в коне списка
        Record **ptr = &(head);
        while (*ptr != nullptr) {
            ptr = &((*ptr)->next);
        }
        (*ptr) = new Record;
        (*ptr)->item = item;
        this->size++;
    }

    void Prepend(const T &item) { //добавить элемент в начало списка
        Record *ptr = new Record{item, this->head};
        this->head = ptr;
        this->size++;
    }

    void InsertAt(const T &item, int index) { //вставить элемент в позицию index
        if (index < 0 || index > (this->size)) throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
        Record preHead = {.next = head};
        Record *ptr;
        int i;
        for (i = 0, ptr = &preHead; i < index; i++) {
            ptr = ptr->next;
        }
        ptr->next = new Record{item, ptr->next};
        this->head = preHead.next;
        this->size++;
    }

    LinkedList<T> *Concat(LinkedList<T> &list) const {
        Record *ptr1 = this->head;
        Record *ptr2 = list.head;
        LinkedList<T> *newList = new LinkedList<T>();
        Record **ptr = &(newList->head);
        while (ptr1 != nullptr) {
            *ptr = new Record{
                    ptr1->item,
                    ptr1->next
            };

            ptr1 = ptr1->next;
            ptr = &((*ptr)->next);
        }
        while (ptr2 != nullptr) {
            *ptr = new Record{
                    ptr2->item,
                    ptr2->next
            };

            ptr2 = ptr2->next;
            ptr = &((*ptr)->next);
        }

        newList->size = this->size + list.size;
        return newList;
    }

    bool operator==(const LinkedList<T> &list) const {
        if(this->size != list.size) return false;

        for(int i = 0; i < this->size; i++){
            if(this->Get(i) != list.Get(i)) return false;
        }

        return true;
    }
};


#endif //SECOND_SEM_LAB2_LINKEDLIST_H
