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
    int Command = -1;
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
            cout << Rucksack;
        } else if (Command == 4) {
            Elements->PrintArray(Elements, CountOfElements);
        } else if (Command == 5) {
            Tree<T> *tree = new Tree<T>();
            ArraySequence<int> *sequence = new ArraySequence<int>;
            sequence = sequence->SequenceABackpack();
            tree->Solve(Rucksack, Elements, CountOfElements, sequence, CheckBackpackA);
            Element<T> Answer = tree->GetAnswer(MaxA, Rucksack);
            Answer.AlternativeWiew(Rucksack, sequence);
            Answer.Print();
        } else if (Command == 6) {
            Tree<T> *tree = new Tree<T>();
            ArraySequence<int> *sequence = new ArraySequence<int>;
            sequence = sequence->SequenceBBackpack();
            tree->Solve(Rucksack, Elements, CountOfElements, sequence, CheckBackpackB);
            Element<T> Answer = tree->GetAnswer(MaxB, Rucksack);
            Answer.AlternativeWiew(Rucksack, sequence);
            Answer.Print();
            //tree->DelTree(tree->Get1PtrRoot());
        } else if (Command == 7) {
            Tree<T> *tree = new Tree<T>();
            ArraySequence<int> *sequence = new ArraySequence<int>;
            sequence = sequence->SequenceCBackpack();
            tree->Solve(Rucksack, Elements, CountOfElements, sequence, CheckBackpackC);
            Element<T> Answer = tree->GetAnswer(MaxC, Rucksack);
            Answer.AlternativeWiew(Rucksack, sequence);
            Answer.Print();
            //tree->DelTree(tree->Get1PtrRoot());
        } else if (Command == 8) {
            Tree<T> *tree = new Tree<T>();
            ArraySequence<int> *sequence = new ArraySequence<int>;
            sequence = sequence->SequenceEBackpack();
            tree->Solve(Rucksack, Elements, CountOfElements, sequence, CheckBackpackE);
            tree->GetAnswer(MaxE, Rucksack).Print();
        } else if (Command == 9) {
            Test();
        } else if (Command == 10) {
            ArraySequence<int> *sequence = new ArraySequence<int>;
            sequence = sequence->SequenceCustomBackpack();
            Tree<T> *tree = new Tree<T>();
            tree->Solve(Rucksack, Elements, CountOfElements, sequence, CustomCheckBackpack);
            Element<T> Answer = tree->GetAnswer(MaxCustom, Rucksack);
            Answer.AlternativeWiew(Rucksack, sequence);
            Answer.Print();
        } else if (Command == 0) {
            //delete Elements;
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
