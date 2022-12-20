#pragma once

#include <iostream>
#include "Element.h"
#include "Menu.h"

using namespace std;


template<class T>
bool CheckBackpack(Element<T> CurrentBackpack, ArraySequence<int> *Sequence) {
    int n = CurrentBackpack.GetHeight();
    int m = CurrentBackpack.GetWidth();
    if (Sequence->Get(0) != -1) {
        for (int i = 0; i < n; i++) {
            for (int g = 0; g < m; g++) {
                if (CurrentBackpack.GetDataFromMatrix(i * m + g) > 1) return false;
            }
        }
    }
//        if (n < CurrentElement.GetHeight()) return false;
//        if (m < CurrentElement.GetWidth()) return false;
    if (Sequence->Get(1) != -1) {
        if (CurrentBackpack.GetWeight() < 0) return false;
    }
    if (Sequence->Get(2) != -1) {
        if (CurrentBackpack.GetMoney() < 0) return false;
    }
    if (Sequence->Get(3) != -1) {
        if (CurrentBackpack.GetVolume() < 0) return false;
    }
    return true;
    //функция для проверки существования данного рюкзака
}

template<class T>
bool CheckBackpackA(Element<T> CurrentBackpack, ArraySequence<int> *Sequence) {
    return CheckBackpack(CurrentBackpack, Sequence);
    //функция для проверки существования данного рюкзака
}

template<class T>
bool CheckBackpackB(Element<T> CurrentBackpack, ArraySequence<int> *Sequence) {
    return CheckBackpack(CurrentBackpack, Sequence);
    //функция для проверки существования данного рюкзака
}

template<class T>
bool CheckBackpackC(Element<T> CurrentBackpack, ArraySequence<int> *Sequence) {
    return CheckBackpack(CurrentBackpack, Sequence);
    //функция для проверки существования данного рюкзака
}

template<class T>
bool CheckBackpackE(Element<T> CurrentBackpack, ArraySequence<int> *Sequence) {
    return CheckBackpackC(CurrentBackpack, Sequence);
}

template<class T>
bool CustomCheckBackpack(Element<T> CurrentBackpack, ArraySequence<int> *Sequence) {
    return CheckBackpack(CurrentBackpack, Sequence);
}

template<class T>
Element<T> MaxA(Element<T> element1, Element<T> element2) {
    if (element1.GetMoney() <= element2.GetMoney()) return element1;
    return element2;
}

template<class T>
Element<T> MaxB(Element<T> element1, Element<T> element2) {
    return MaxA(element1, element2);
}

template<class T>
Element<T> MaxC(Element<T> element1, Element<T> element2) {
    if (element1.GetMoney() > element2.GetMoney()) return element1;
    else if (element1.GetMoney() < element2.GetMoney()) return element2;
    else {
        if (element1.GetVolume() > element2.GetVolume()) return element1;
        else return element2;
    }
}

template<class T>
Element<T> MaxE(Element<T> element1, Element<T> element2) {
    if (element1.GetMoney() > element2.GetMoney()) return element1;
    else if (element1.GetMoney() < element2.GetMoney()) return element2;
    else {
        if (element1.GetVolume() < element2.GetVolume()) return element1;
        else return element2;
    }
}

template<class T>
Element<T> MaxCustom(Element<T> element1, Element<T> element2) {
    if (element1.GetMoney() > element2.GetMoney()) return element1;
    else if (element1.GetMoney() < element2.GetMoney()) return element2;
    else {
        if (element1.GetVolume() > element2.GetVolume()) return element1;
        else if (element1.GetVolume() < element2.GetVolume()) return element2;
        else {
            if (element1.GetWeight() > element2.GetWeight()) return element1;
            else if (element1.GetWeight() < element2.GetWeight()) return element2;
        }
    }
}

template<class T>
T Min(T a, T b){
    if (a <= b) return a;
    return b;
}

template <class T>
class Tree {
private:
    struct Node {
        int Num = 0;
        Element<T> CurrentBackpack; //текущмй рюкзак
        ArraySequence<Node *> *Child = new ArraySequence<Node *>(); //дети этого узла
        ArraySequence<int> *UsedElements = new ArraySequence<int>(); //элементы из рюкзака
        //bool Use = false;
    };
    Node *root = nullptr;
public:
    Tree() : root(nullptr) {

    }

    void DelTree(Node *ptr) { // Удаление дерева
        if (ptr != NULL) {
            for (int i = 0; i < ptr->Child->GetSize(); i++) {
                DelTree(ptr->Child->Get(i));
            }
            if (ptr->UsedElements != nullptr) ptr->UsedElements->~ArraySequence();
            delete ptr;
            ptr = NULL;
        }
    }

    void SetCurrentBackpack(Node **ptr, Element<T> CurrentBackpack) {
        *ptr = new Node;
        (*ptr)->CurrentBackpack.SetAllValuesFromOneElement(CurrentBackpack);
    }

    Element<T> GetTwoPtrCurrentBackpack(Node **ptr) {
        //(*ptr)->CurrentBackpack.Print();
        return (*ptr)->CurrentBackpack;
    }

    Element<T> UseElementInBackpack(Element<T> CurrentBackpack, Element<T> CurrentElement, int NumberOfString, int NumberOfColumn) {
        int n = CurrentBackpack.GetHeight();
        int m = CurrentBackpack.GetWidth();
        int UpBorderOfCurrentElement = NumberOfString;
        int DownBorderOfCurrentElement = UpBorderOfCurrentElement + CurrentElement.GetHeight();
        int LeftBorderOfCurrentElement = NumberOfColumn;
        int RightBorderOfCurrentElement = LeftBorderOfCurrentElement + CurrentElement.GetWidth();
        for (int i = UpBorderOfCurrentElement; i < DownBorderOfCurrentElement; i++) {
            for (int g = LeftBorderOfCurrentElement; g < RightBorderOfCurrentElement; g++) {
                //cout << i << ' ' << g << '_';
                T CurrentValueOfMatrixOfCurrentElement = CurrentElement.GetDataFromMatrix( (i - NumberOfString) * CurrentElement.GetWidth() + g - NumberOfColumn);
                CurrentBackpack.SetOneValueInMatrix(i * m + g, CurrentBackpack.GetDataFromMatrix(i * m + g) + CurrentValueOfMatrixOfCurrentElement);
                //cout << i << ' ' << g << '\n';
            }
        }
        CurrentBackpack.SetWeight(CurrentBackpack.GetWeight() - CurrentElement.GetWeight());
        CurrentBackpack.SetMoney(CurrentBackpack.GetMoney() - CurrentElement.GetMoney());
        CurrentBackpack.SetVolume(CurrentBackpack.GetVolume() - CurrentElement.GetVolume());
        return CurrentBackpack;
        //функция, которая вставит в рюкзак данных элемент
    }

    bool CheckBackpack(Element<T> CurrentBackpack) {
        int n = CurrentBackpack.GetHeight();
        int m = CurrentBackpack.GetWidth();
        for (int i = 0; i < n; i++) {
            for (int g = 0; g < m; g++) {
                if (CurrentBackpack.GetDataFromMatrix(i * m + g) > 1) return false;
            }
        }
//        if (n < CurrentElement.GetHeight()) return false;
//        if (m < CurrentElement.GetWidth()) return false;
        if (CurrentBackpack.GetWeight() < 0) return false;
        if (CurrentBackpack.GetMoney() < 0) return false;
        if (CurrentBackpack.GetVolume() < 0) return false;
        return true;
        //функция для проверки существования данного рюкзака
    }

    bool CheckBackpackA(Element<T> CurrentBackpack) {
        if (CurrentBackpack.GetVolume() < 0) return false;
        return true;
        //функция для проверки существования данного рюкзака
    }

    void CreateBackpackWithThisElement(Node *ptr, Element<T> CurrentBackpack, Element<T> CurrentElement, int NumberOfElement, ArraySequence<int> *Sequence, bool (*check)(Element<T>, ArraySequence<int> *)) {
        int n = CurrentBackpack.GetHeight() - CurrentElement.GetHeight() + 1;
        int m = CurrentBackpack.GetWidth() - CurrentElement.GetWidth() + 1;
        for (int i = 0; i < n; i++) {
            for (int g = 0; g < m; g++) {
                Element<T> ReturningBackpack = Element<T>(CurrentBackpack);
                ReturningBackpack = UseElementInBackpack(ReturningBackpack, CurrentElement, i, g);
                if (check(ReturningBackpack, Sequence) == true) {
                    Add(ptr, ReturningBackpack, (ptr)->UsedElements, NumberOfElement); //дописать
                }
            }
        }
        //функция, которая полностью проходит по данному рюкзаку и пытается вставить в конкретное место тукещий элемент
    }

    void AddRoot(Element<T> CurrentBackpack) {
        Node **ptr = &(this->root);
        *ptr = new Node;
        (*ptr)->CurrentBackpack = CurrentBackpack;
    }

    void Add(Node *ptr, Element<T> value, ArraySequence<int> *UsedElements, int NumberOfElement) {
        Node *NewPtr = new Node(); //сооздаем указатель, закидываем туда все данные на текущий узел
                // и закидываем в детей текущего элемента. закидываем в конец
        NewPtr->UsedElements = new ArraySequence<int>(*UsedElements);
        NewPtr->UsedElements->Append(NumberOfElement);
        NewPtr->CurrentBackpack = value;
        (ptr)->Child->Append(NewPtr);
        //функция, которая создает версия данного рюкзака с текущим элементом
    }

    Node *Get1PtrRoot() {  // возвращаем указатель на корень
        Node *ptr = this->root;
        return ptr;
    }

    Node **Get2PtrRoot() {  // возвращаем указатель на корень
        Node **ptr = &(this->root);
        return ptr;
    }

    int GetChildSize(Node *ptr) {
        return ptr->Child->GetSize();
    }

    Node* GetPtrChild(Node *ptr, int index) {
        return ptr->Child->Get(index);
    }

    Element<T> GetOnePtrCurrentBackpack(Node *ptr) {
        return ptr->CurrentBackpack;
    }

    void RecursiveGo(Node *ptr, Element<T> CurrentElement, int NumberOfElement, ArraySequence<int> *Sequence, bool (*check)(Element<T>, ArraySequence<int> *)) {
        if (ptr == nullptr) {
            return;
        }
        //cout << ptr->UsedElements->GetLength() << ' ';
        if (ptr != nullptr) {
            if ((ptr)->UsedElements->GetSize() != 0) {
                if ((ptr)->UsedElements->Get((ptr)->UsedElements->GetSize() - 1) != NumberOfElement) {
                    CreateBackpackWithThisElement(ptr, (ptr)->CurrentBackpack, CurrentElement, NumberOfElement, Sequence, check);
                }
            } else {
                CreateBackpackWithThisElement(ptr, (ptr)->CurrentBackpack, CurrentElement, NumberOfElement, Sequence, check);
            }
        }
        int size = ptr->Child->GetSize();
        for (int i = 0; i < size; i++) {
            RecursiveGo(GetPtrChild(ptr, i), CurrentElement, NumberOfElement, Sequence, check);
        }
        // функция, которая полностью проходит по дереву и создает все корректнвые версии рюкзаков с данным элементом
    }

    void RecursiveFind(Node *ptr, Element<T> &Answer, Element<T> (* compare)(Element<T>, Element<T>)) {
        //ptr->CurrentBackpack.Print();
        Answer = MaxA(Answer, ptr->CurrentBackpack);
        int size = ptr->Child->GetSize();
        for (int i = 0; i < size; i++) {
            RecursiveFind(ptr->Child->Get(i), Answer, compare);
        }
        //return ptr->CurrentBackpack;
    }

    void CreateAnswerTree(Element<T> *Elements, int NumberOfElement) {
        RecursiveGo(Get2PtrRoot(), Elements, NumberOfElement);
        //по сути не нужна)
    }

    void Solve(Element<T> CurrentBackpack, Element<T> *Elements, int CountOfElements, ArraySequence<int> *Sequence, bool (*check)(Element<T>, ArraySequence<int> *)) {
        AddRoot(CurrentBackpack);
        //cout << CountOfElements;
        for (int i = 0; i < CountOfElements; i++) {
            RecursiveGo(this->Get1PtrRoot(), Elements[i], i, Sequence, check);
        }
    }

    Element<T> GetAnswer(Element<T> (* compare)(Element<T>, Element<T>), Element<T> Backpack) {
        Node *ptr = Get1PtrRoot();
        Element<T> Answer = ptr->CurrentBackpack;
        RecursiveFind(ptr, Answer, compare);
        return Answer;
    }
};