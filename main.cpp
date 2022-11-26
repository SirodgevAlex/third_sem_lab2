#include <iostream>
#include "Menu.h"
#include "RectangularMatrix.h"
#include "Element.h"
#include "Tree.h"
#include "Test.h"

using namespace std;

template<typename T>
void Mainfunc() {
    Element<T> Rucksack;
    Element<T> *Elements;
    int CountOfElements = 0;
    int Command;
    //Sequence<Element<T>> *Elements = new ArraySequence<Element<T>>();
    while (Command != 0) {
        CommandMenu();
        cin >> Command;
        if (Command == 1) {
            cin >> Rucksack;
        } else if (Command == 2) {
            cout << "Input count of elements please\n";
            if (CountOfElements != 0) delete Elements;
            cin >> CountOfElements;
            Elements = Elements->ReadArray(Elements, CountOfElements);
            //*Elements = new ArraySequence<Element<T>>();
        } else if (Command == 3) {
            Rucksack.Print();
        } else if (Command == 4) {
            Elements->PrintArray(Elements, CountOfElements);
        } else if (Command == 5) {
            Tree<T> *tree = new Tree<T>();
            tree->Solve(Rucksack, Elements, CountOfElements, CheckBackpackA);
            tree->GetAnswer(MaxA).Print();
            tree->DelTree(tree->Get1PtrRoot());
        } else if (Command == 6) {
            Tree<T> *tree = new Tree<T>();
            tree->Solve(Rucksack, Elements, CountOfElements, CheckBackpackB);
            tree->GetAnswer(MaxB).Print();
            //tree->DelTree(tree->Get1PtrRoot());
        } else if (Command == 7) {
            Tree<T> *tree = new Tree<T>();
            tree->Solve(Rucksack, Elements, CountOfElements, CheckBackpackC);
            tree->GetAnswer(MaxC).Print();
            //tree->DelTree(tree->Get1PtrRoot());
        } else if (Command == 8) {
            Tree<T> *tree = new Tree<T>();
            tree->Solve(Rucksack, Elements, CountOfElements, CheckBackpackE);
            tree->GetAnswer(MaxE).Print();
        } else if (Command == 9) {
            Test();
        } else if (Command == 0) {
            Elements->DelElement();
        }
    }
}

int main() {
    DataTypeMenu();
    int DataType = 0;
    cin >> DataType;
    cout << "first of all input sequence please" << '\n';
    if (DataType == 1) {
        Mainfunc<int>();
    } else if (DataType == 2) {
        Mainfunc<float>();
    } else if (DataType == 3) {
        //Mainfunc<Complex<int>>();
    }
}
