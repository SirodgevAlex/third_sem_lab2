#include <iostream>
#include "Sequence.h"
#include "RectangularMatrix.h"
#include <vector>

#pragma once

using namespace std;

template<class T>
class Element {
private:
    int Height = 0;
    int Width = 0;
    RectangularMatrix<T> Matrix;
    T Weight = 0;
    T Money = 0;
    T Volume = 0;
public:

//    Element(Element<T>& el) {
//        this->Height = el.Height;
//        this->Width = el.Width;
//        this->Weight = el.Weight;
//        this->Money = el.Money;
//        this->Volume = el.Volume;
//        for (int i = 0; i < this->Height; i++) {
//            for (int g = 0; g < this->Width; g++) {
//                this->Matrix.Set( el.Matrix.Get(i * this->Width + g), i * this->Width + g);
//            }
//        }
//    }

//    friend std::ostream& operator<< (std::ostream &out, const Element<T> &El);
//    friend std::istream& operator>> (std::istream &in, Element<T> &El);

    Element() {
        Matrix = RectangularMatrix<T>();
    }

    Element(const Element<T> &El) {
        this->Height = El.Height;
        this->Width = El.Width;
        this->Weight = El.Weight;
        this->Volume = El.Volume;
        this->Money = El.Money;
        this->Matrix = RectangularMatrix<T>(El.Matrix, this->Height, this->Width);
    }

    void DelElement() {
        this->Height = 0;
        this->Width = 0;
        this->Weight = 0;
        this->Money = 0;
        this->Volume = 0;
        this->Matrix.~RectangularMatrix();
    }

/*    void Read() {
        cout << "Input height please\n";
        cin >> this->Height;
        cout << "Input Width please\n";
        cin >> this->Width;
        this->Matrix = RectangularMatrix<T>(this->Height, this->Width);
        (this->Matrix).ReadRectangularMatrix();
        cout << "Input weight please\n";
        cin >> this->Weight;
        cout << "Input amount of money please\n";
        cin >> this->Money;
        cout << "Input volume of your backpack please\n";
        cin >> this->Volume;
    }
    */

    void Print() {
        cout << "Height is " << this->Height << '\n';
        cout << "Width is " << this->Width << '\n';
        cout << "Your element looks like this: \n";
        (this->Matrix).PrintRectangularMatrix();
        cout << "Weight is " << this->Weight << '\n';
        cout << "Money is " << this->Money << '\n';
        cout << "Volume is " << this->Volume << '\n';
    }

    void SetHeight(T Height) {
        this->Height = Height;
    }

    T GetHeight() {
        return this->Height;
    }

    void SetWidth(T Width) {
        this->Width = Width;
    }

    T GetWidth() {
        return this->Width;
    }

    void SetAllValues(T Height, T Width, RectangularMatrix<T> Matrix, T Weight, T Money, T Volume) {
        SetHeight(Height);
        SetWidth(Width);
        SetMatrix(Matrix);
        SetWeight(Weight);
        SetMoney(Money);
        SetVolume(Volume);
    }

    void SetMatrix(RectangularMatrix<T> Matrix) {
        int n = this->Height;
        int m = this->Width;
        //if (this->Matrix.GetLength() != 0) delete Matrix;
        this->Matrix = RectangularMatrix<T>(Matrix, n, m);
    }

    void SetOneValueInMatrix(int index, T value) {
        this->Matrix.Set(value, index);
    }

    void SetAllValuesFromOneElement(Element<T> CurrentElement) {
        SetHeight(CurrentElement.GetHeight());
        SetWidth(CurrentElement.GetWidth());
        SetMatrix(CurrentElement.GetMatrix());
        SetWeight(CurrentElement.GetWeight());
        SetMoney(CurrentElement.GetMoney());
        SetVolume(CurrentElement.GetVolume());
    }

    RectangularMatrix<T> GetMatrix() {
        return this->Matrix;
    }


    T GetDataFromMatrix(int index){
        return this->Matrix.Get(index);
    }

    void SetWeight(T Weight) {
        this->Weight = Weight;
    }

    T GetWeight() {
        return this->Weight;
    }

    void SetMoney(T Money) {
        this->Money = Money;
    }

    T GetMoney() {
        return this->Money;
    }

    void SetVolume(T Volume) {
        this->Volume = Volume;
    }

    T GetVolume() {
        return this->Volume;
    }

    Element<T> *ReadArray(Element<T> *Elements, int Size) {
        Elements = new Element<T>[Size];
        for (int i = 0; i < Size; i++) {
            cin >> Elements[i];
        }
        return Elements;
    }

    void PrintArray(Element<T> *Elements, int Size) {
        for (int i = 0; i < Size; i++) {
            Elements[i].Print();
        }
    }

    Element<T> operator =(Element<T> El) {
        //El.Matrix.Print();
        this->Height = El.GetHeight();
        this->Weight = El.GetWeight();
        this->Volume = El.GetVolume();
        this->Money = El.GetMoney();
        this->Width = El.GetWidth();
        //this->Matrix.DelRectangularMatrix();
        this->Matrix = RectangularMatrix<T>(El.Matrix, this->Height, this->Width);
        return *this;
    }

    Element<T> Rotate() {
        Element<T> NewElement;
        NewElement.Weight = this->Weight;
        NewElement.Money = this->Money;
        NewElement.Volume = this->Volume;
        ArraySequence<T> *seq = new ArraySequence<T>();
        for (int g = 0; g < this->Width; g++) {
            for (int i = 0; i < this->Height; i++) {
                seq->Append(this->Matrix.Get(i * this->Width + g));
            }
        }
        NewElement.Height = this->Width;
        NewElement.Width = this->Height;
        NewElement.Matrix = RectangularMatrix<T>(this->Width, this->Height);
        int count = 0;
        for (int i = 0; i < this->Width; i++) {
            for (int g = this->Height - 1; g > -1; g--) {
                NewElement.Matrix.Set(seq->Get(count), i * this->Height + g);
                count++;
            }
        }
        delete seq;
        return NewElement;
    }

    void AlternativeWiew(Element<T> Backpack, ArraySequence<int> *sequence) {
//        if (sequence.Get(0) == 0) {
//            for (int i = 0; i < Backpack.Height; i++) {
//                for (int g = 0; g < Backpack.Width; g++) {
//                    this->Matrix.Set(Backpack.Matrix. - this->Matrix.Get(i * this->Height + g))
//                }
//            }
//        }
        if (sequence->Get(1) == -1) this->Weight = Backpack.Weight - this->Weight;
        if (sequence->Get(2) == -1) this->Money = Backpack.Money - this->Money;
        if (sequence->Get(3) == -1) this->Volume = Backpack.Volume - this->Volume;
    }
};

template<typename T>
bool operator ==(Element<T> Element1, Element<T> Element2) {
    if (Element1.GetWidth() != Element2.GetWidth()) return false;
    if (Element1.GetHeight() != Element2.GetHeight()) return false;
    if (Element1.GetWeight() != Element2.GetWeight()) return false;
    if (Element1.GetMoney() != Element2.GetMoney()) return false;
    if (Element1.GetVolume() != Element2.GetVolume()) return false;
    for (int i = 0; i < Element2.GetHeight(); i++) {
        for (int g = 0; g < Element2.GetWidth(); g++) {
            if (Element1.GetDataFromMatrix(i * Element2.GetWidth() + g) != Element2.GetDataFromMatrix(i * Element2.GetWidth() + g)) return false;
        }
    }
    return true;
}

template<typename T>
istream& operator >>(istream& in, Element<T> &El) {
    cout << "Input height please\n";
    int Height;
    in >> Height;
    El.SetHeight(Height);
    cout << "Input Width please\n";
    int Width;
    in >> Width;
    El.SetWidth(Width);
    RectangularMatrix<T> Matrix = RectangularMatrix<T>(Height, Width);
    cin >> Matrix;
    El.SetMatrix(Matrix);
    cout << "Input weight please\n";
    T Weight;
    in >> Weight;
    El.SetWeight(Weight);
    cout << "Input amount of money please\n";
    T Money;
    in >> Money;
    El.SetMoney(Money);
    cout << "Input volume of your backpack please\n";
    T Volume;
    in >> Volume;
    El.SetVolume(Volume);
    return in;
}

template<typename T>
ostream& operator <<(ostream &out, Element<T> &El) {
    out << "Your element looks like this: \n";
    out << "Height is " << El.GetHeight() << '\n';
    out << "Width is " << El.GetWidth() << '\n';
    (El.GetMatrix()).PrintRectangularMatrix();
    out << "Weight is " << El.GetWeight() << '\n';
    out << "Money is " << El.GetMoney() << '\n';
    out << "Volume is " << El.GetVolume() << '\n';
    return out;
}

//template<typename T>
//void operator =(Element<T> Element1, Element<T> Element2) {
//    if (Element1.GetWidth() != Element2.GetWidth()) return false;
//    if (Element1.GetHeight() != Element2.GetHeight()) return false;
//    if (Element1.GetWeight() != Element2.GetWeight()) return false;
//    if (Element1.GetMoney() != Element2.GetMoney()) return false;
//    if (Element1.GetVolume() != Element2.GetVolume()) return false;
//    for (int i = 0; i < Element2.GetHeight(); i++) {
//        for (int g = 0; g < Element2.GetWidth(); g++) {
//            if (Element1.GetDataFromMatrix(i * Element2.GetWidth() + g) != Element2.GetDataFromMatrix(i * Element2.GetWidth() + g)) return false;
//        }
//    }
//    return true;
//}

//    Element(Element<T>& el) {
//        this->Height = el.Height;
//        this->Width = el.Width;
//        this->Weight = el.Weight;
//        this->Money = el.Money;
//        this->Volume = el.Volume;
//        for (int i = 0; i < this->Height; i++) {
//            for (int g = 0; g < this->Width; g++) {
//                this->Matrix.Set( el.Matrix.Get(i * this->Width + g), i * this->Width + g);
//            }
//        }
//    }