#pragma once

#include <assert.h>
#include "Element.h"
#include "Tree.h"

using namespace std;

void TestSetHeight() {
    Element<int> CurrentBackpack;
    CurrentBackpack.SetHeight(5);
    assert(CurrentBackpack.GetHeight() == 5);
    CurrentBackpack.DelElement();
}

void TestSetWidth() {
    Element<int> CurrentBackpack;
    CurrentBackpack.SetWidth(5);
    assert(CurrentBackpack.GetWidth() == 5);
    CurrentBackpack.DelElement();
}

void TestSetMatrix() {
    Element<int> CurrentBackpack;
    CurrentBackpack.SetHeight(2);
    CurrentBackpack.SetWidth(3);
    RectangularMatrix<int> Matrix;
    Matrix = RectangularMatrix<int>(2, 3);
    int *Data = nullptr;
    Data = new int[6];
    Data[0] = 1;
    Data[1] = 2;
    Data[2] = 3;
    Data[3] = 4;
    Data[4] = 5;
    Data[5] = 6;
    Matrix = RectangularMatrix<int>(Data, 2, 3);
    CurrentBackpack.SetMatrix(Matrix);
    assert(CurrentBackpack.GetDataFromMatrix(0) == 1);
    assert(CurrentBackpack.GetDataFromMatrix(1) == 2);
    assert(CurrentBackpack.GetDataFromMatrix(2) == 3);
    assert(CurrentBackpack.GetDataFromMatrix(3) == 4);
    assert(CurrentBackpack.GetDataFromMatrix(4) == 5);
    assert(CurrentBackpack.GetDataFromMatrix(5) == 6);
    delete Data;
    CurrentBackpack.DelElement();
}

void TestSetWeight() {
    Element<int> CurrentBackpack;
    CurrentBackpack.SetWeight(5);
    assert(CurrentBackpack.GetWeight() == 5);
    CurrentBackpack.DelElement();
}

void TestSetMoney() {
    Element<int> CurrentBackpack;
    CurrentBackpack.SetMoney(5);
    assert(CurrentBackpack.GetMoney() == 5);
    CurrentBackpack.DelElement();
}

void TestSetVolume() {
    Element<int> CurrentBackpack;
    CurrentBackpack.SetVolume(5);
    assert(CurrentBackpack.GetVolume() == 5);
    CurrentBackpack.DelElement();
}

void TestCheckBackpack() {
    Element<int> CurrentBackpack;
    int *Data = nullptr;
    Data = new int[9];
    Data[0] = 0;
    Data[1] = 0;
    Data[2] = 0;
    Data[3] = 0;
    Data[4] = 0;
    Data[5] = 0;
    Data[6] = 0;
    Data[7] = 0;
    Data[8] = 0;
    RectangularMatrix<int> Matrix = RectangularMatrix<int>(Data, 3, 3);
    CurrentBackpack.SetAllValues( 3, 3, Matrix, 3, 3, 3);
    Tree<int> *ptr;
    assert(ptr->CheckBackpack(CurrentBackpack) == true);
    CurrentBackpack.SetWeight(-1);
    assert(ptr->CheckBackpack(CurrentBackpack) == false);
    CurrentBackpack.SetWeight(3);
    CurrentBackpack.SetMoney(-1);
    assert(ptr->CheckBackpack(CurrentBackpack) == false);
    CurrentBackpack.SetMoney(3);
    CurrentBackpack.SetVolume(-1);
    assert(ptr->CheckBackpack(CurrentBackpack) == false);
    CurrentBackpack.SetVolume(3);
    Data[1] = 1;
    Matrix.DelRectangularMatrix();
    Matrix = RectangularMatrix<int>(Data, 3, 3);
    CurrentBackpack.SetMatrix(Matrix);
    assert(ptr->CheckBackpack(CurrentBackpack) == true);
    Data[1] = 2;
    Matrix.DelRectangularMatrix();
    Matrix = RectangularMatrix<int>(Data, 3, 3);
    CurrentBackpack.SetMatrix(Matrix);
    assert(ptr->CheckBackpack(CurrentBackpack) == false);
    Matrix.DelRectangularMatrix();
    delete Data;
}

void Test1UseElementInBackpack() {
    Element<int> CurrentBackpack;
    Element<int> CurrentElement;
    int *Data = nullptr;
    Data = new int[4];
    Data[0] = 0;
    Data[1] = 1;
    Data[2] = 1;
    Data[3] = 1;
    // 0 1
    // 1 1 this thing
    RectangularMatrix<int> Matrix = RectangularMatrix<int>(Data, 2, 2);
    CurrentElement.SetAllValues(2, 2, Matrix, 2, 2, 2);
    delete Data;
    Data = new int[9];
    Data[0] = 0;
    Data[1] = 0;
    Data[2] = 0;
    Data[3] = 0;
    Data[4] = 0;
    Data[5] = 0;
    Data[6] = 0;
    Data[7] = 0;
    Data[8] = 0;
    Matrix.DelRectangularMatrix();
    Matrix = RectangularMatrix<int>(Data, 3, 3);
    CurrentBackpack.SetAllValues( 3, 3, Matrix, 3, 3, 3);
    Tree<int> *tree = new Tree<int>();
    tree->SetCurrentBackpack(tree->Get2PtrRoot(), CurrentBackpack);
    //tree->GetCurrentBackpack(tree->Get1PtrRoot());
    Element<int> ReturningBackpack = tree->GetTwoPtrCurrentBackpack(tree->Get2PtrRoot());
    assert(ReturningBackpack == CurrentBackpack);
    ReturningBackpack = tree->UseElementInBackpack(ReturningBackpack, CurrentElement, 0, 0);
    //ReturningBackpack.Print();
    CurrentBackpack.SetAllValues(3, 3, Matrix, 1, 1, 1);
    Data[1] = 1;
    Data[3] = 1;
    Data[4] = 1;
    Matrix.DelRectangularMatrix();
    Matrix = RectangularMatrix<int>(Data, 3, 3);
    CurrentBackpack.SetMatrix(Matrix);
//    ReturningBackpack.Print();
    CurrentBackpack.Print();
    ReturningBackpack.Print();
    assert(CurrentBackpack == ReturningBackpack);
    //tree->delTree(tree->Get1PtrRoot());
}

void Test2UseElementInBackpack() {
    Element<int> CurrentBackpack;
    Element<int> Element1;
    Element<int> Element2;
    int *Data = nullptr;
    Data = new int[9];
    Data[0] = 0;
    Data[1] = 0;
    Data[2] = 0;
    Data[3] = 0;
    Data[4] = 0;
    Data[5] = 0;
    Data[6] = 0;
    Data[7] = 0;
    Data[8] = 0;
    RectangularMatrix<int> Matrix;
    Matrix = RectangularMatrix<int>(Data, 3, 3);
    CurrentBackpack.SetAllValues(3, 3, Matrix, 3, 3, 3);
    //Matrix.Print();
    Matrix.DelRectangularMatrix();
    Data[0] = 1;
    Data[1] = 1;
    Data[2] = 1;
    Matrix = RectangularMatrix<int>(Data, 3, 3);
    Element1.SetAllValues(3, 3, Matrix, 3, 3, 3);
    Data[3] = 1;
    Data[4] = 1;
    Data[5] = 1;
    Data[6] = 1;
    Data[7] = 1;
    Data[8] = 1;
    Matrix.DelRectangularMatrix();
    Matrix = RectangularMatrix<int>(Data, 3, 3);
    Element2.SetAllValues(3, 3, Matrix, 3, 3, 3);
    Tree<int> tree = Tree<int>();
    CurrentBackpack = tree.UseElementInBackpack(CurrentBackpack, Element1, 0, 0);
    //CurrentBackpack.Print();
    CurrentBackpack = tree.UseElementInBackpack(CurrentBackpack, Element2, 0, 0);
    //CurrentBackpack.Print();
    Element<int> TestElement;
    Data[0] = 2;
    Data[1] = 2;
    Data[2] = 2;
    Matrix.DelRectangularMatrix();
    Matrix = RectangularMatrix<int>(Data, 3, 3);
    TestElement.SetAllValues(3, 3, Matrix, -3, -3, -3);
    assert(CurrentBackpack == TestElement);
}



void TestAdd() {
    Element<int> CurrentElement;
    int *Data = nullptr;
    Data = new int[4];
    Data[0] = 0;
    Data[1] = 1;
    Data[2] = 1;
    Data[3] = 1;
    // 0 1
    // 1 1 this thing
    RectangularMatrix<int> Matrix = RectangularMatrix<int>(Data, 2, 2);
    CurrentElement.SetAllValues(2, 2, Matrix, 2, 2, 2);
    ArraySequence<int> *seq = new ArraySequence<int>();
    Tree<int> *tree = new Tree<int>();
    ArraySequence<int> *sequence = new ArraySequence<int>();
    tree->AddRoot(CurrentElement);
    tree->Add(tree->Get1PtrRoot(), CurrentElement, sequence, 1);
    assert(tree->GetChildSize(tree->Get1PtrRoot()) == 1);
    assert(tree->GetOnePtrCurrentBackpack(tree->GetPtrChild(tree->Get1PtrRoot(), 0)) == CurrentElement);
}

void TestSolve1() {
    Element<int> CurrentBackpack;
    Element<int> CurrentElement;
    int *Data = nullptr;
    Data = new int[4];
    Data[0] = 0;
    Data[1] = 1;
    Data[2] = 1;
    Data[3] = 1;
    // 0 1
    // 1 1 this thing
    RectangularMatrix<int> Matrix = RectangularMatrix<int>(Data, 2, 2);
    CurrentElement.SetAllValues(2, 2, Matrix, 2, 2, 2);
    delete Data;
    Data = new int[9];
    Data[0] = 0;
    Data[1] = 0;
    Data[2] = 0;
    Data[3] = 0;
    Data[4] = 0;
    Data[5] = 0;
    Data[6] = 0;
    Data[7] = 0;
    Data[8] = 0;
    Matrix.DelRectangularMatrix();
    Matrix = RectangularMatrix<int>(Data, 3, 3);
    CurrentBackpack.SetAllValues( 3, 3, Matrix, 3, 3, 3);
    Element<int> *Elements = new Element<int>[1];
    Elements[0] = CurrentElement;
    Tree<int> *tree = new Tree<int>;
    tree->Solve(CurrentBackpack, Elements, 1, CheckBackpack);
    assert(tree->Get1PtrRoot()->Child->GetSize() == 4);
}

void TestSolve2() {
    Element<int> CurrentBackpack;
    Element<int> Element1;
    Element<int> Element2;
    int *Data = nullptr;
    Data = new int[9];
    Data[0] = 0;
    Data[1] = 0;
    Data[2] = 0;
    Data[3] = 0;
    Data[4] = 0;
    Data[5] = 0;
    Data[6] = 0;
    Data[7] = 0;
    Data[8] = 0;
    RectangularMatrix<int> Matrix;
    Matrix = RectangularMatrix<int>(Data, 3, 3);
    CurrentBackpack.SetAllValues(3, 3, Matrix, 3, 3, 3);
    //Matrix.Print();
    Matrix.DelRectangularMatrix();
    Data[0] = 1;
    Data[1] = 1;
    Data[2] = 1;
    Matrix = RectangularMatrix<int>(Data, 3, 3);
    Element1.SetAllValues(3, 3, Matrix, 0, 3, 0);
    Data[3] = 1;
    Data[4] = 1;
    Data[5] = 1;
    Data[6] = 1;
    Data[7] = 1;
    Data[8] = 1;
    Matrix.DelRectangularMatrix();
    Element<int> *Elements = new Element<int>[2];
    Matrix = RectangularMatrix<int>(Data, 3, 3);
    Element2.SetAllValues(3, 3, Matrix, 0, 3, 0);
    Elements[0] = Element1;
    Elements[1] = Element2;
    int CountOfElements = 2;
    Tree<int> tree = Tree<int>();
    tree.Solve(CurrentBackpack, Elements, CountOfElements, CheckBackpackA);
    tree.GetAnswer(MaxA).Print();
}

void TestGetAnswerA() {
    Element<int> CurrentBackpack;
    int *Data = nullptr;
    Data = new int[9];
    Data[0] = 0;
    Data[1] = 0;
    Data[2] = 0;
    Data[3] = 0;
    Data[4] = 0;
    Data[5] = 0;
    Data[6] = 0;
    Data[7] = 0;
    Data[8] = 0;
    RectangularMatrix<int> Matrix;
    Matrix = RectangularMatrix<int>(Data, 3, 3);
    CurrentBackpack.SetAllValues( 3, 3, Matrix, 3, 3, 3);
    Element<int> *Elements;
    int CountOfElements = 2;
    Elements = new Element<int>[CountOfElements];
    delete Data;
    Data = new int[4];
    Data[0] = 0;
    Data[1] = 1;
    Data[2] = 1;
    Data[3] = 1;
    // 0 1
    // 1 1 this thing
    Matrix = RectangularMatrix<int>(Data, 2, 2);
    Elements[0].SetAllValues(2, 2, Matrix, 2, 2, 2);
    delete Data;
    Data = new int[2];
    Data[0] = 1;
    Data[1] = 1;
    Matrix = RectangularMatrix<int> (Data, 1, 2);
    Elements[1].SetAllValues(1, 2, Matrix, 1, 1, 1);
    delete Data;
    Data = new int[1];
    Data[0] = 1;
    Matrix = RectangularMatrix<int> (Data, 1, 1);
    //Elements[2].SetAllValues(1, 1, Matrix, 0, 0, 0);
    delete Data;
    Data = new int[4];
    Data[0] = 1;
    Data[1] = 1;
    Data[2] = 1;
    Data[3] = 1;
    Matrix = RectangularMatrix<int> (Data, 2, 2);
    //Elements[3].SetAllValues(2, 2, Matrix, 1, 1, 1);
    delete Data;
    Data = new int[2];
    Data[0] = 1;
    Data[1] = 1;
    Matrix = RectangularMatrix<int> (Data, 2, 1);
    //Elements[4].SetAllValues(2, 1, Matrix, 0, 0, 0);
    Tree<int> tree = Tree<int>();
    tree.Solve(CurrentBackpack, Elements, CountOfElements, CheckBackpackA);
    Element<int> Answer = tree.GetAnswer(MaxA);
    Answer.Print();
}

void Test() {
    TestSetHeight();
    cout << "SetHeight() function works correct\n";
    TestSetWidth();
    cout << "SetWidth() function works correct\n";
    TestSetMatrix();
    cout << "SetHeight() function works correct\n";
    TestSetWeight();
    cout << "SetWeight() function works correct\n";
    TestSetMoney();
    cout << "SetMoney() function works correct\n";
    TestSetVolume();
    cout << "SetVolume() function works correct\n";
    TestCheckBackpack();
    cout << "CheckBackpack() function works correct\n";
    Test1UseElementInBackpack();
    Test2UseElementInBackpack();
    cout << "UseElementInBackpack() and SetCurrentBackpack() functions work correct\n";
    TestAdd();
    cout << "Add() and GetChildSize() functions work correct\n";
    //TestSolve1();
    TestSolve2();
    cout << "Solve() function works correct\n";
    TestGetAnswerA();
    cout << "GetAnswerA() function works correct\n";
}