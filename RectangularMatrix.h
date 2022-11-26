#include <iostream>
#include "Sequence.h"
#include <stdexcept>
#include <cmath>

#pragma once
#ifndef SECOND_SEM_LAB2_MATRIX_H
#define SECOND_SEM_LAB2_MATRIX_H
#define WRONG_SIZE_MESSAGE "sizes of matrix not equal"
#define NEGATIVE_SIZE_MESSAGE "size is negative"
#define INDEX_OUT_OF_RANGE_MESSAGE "index out of range"
#define ZERO_SIZE_MESSAGE "size is 0"
#define ZERO_RATIO_MESSAGE "ratio is 0"
#endif //SECOND_SEM_LAB2_MATRIX_H

using namespace std;

template<class T>
class RectangularMatrix {
private:
    T *matrix = nullptr;
    int size = 0;
    int n = 0;
    int m = 0;
public:
    /*T &operator[](int index) {
        return this->matrix->Get(index);
    }*/

    RectangularMatrix() {}

    RectangularMatrix(int n, int m) {
        this->matrix = new T[n * m];
        int i;
        int g;
        for (i = 0; i < n; i++) {
            for (g = 0; g < m; g++){
                this->matrix[i * this->m + g] = 0;
            }
        }
        this->size = n * m;
        this->n = n;
        this->m = m;
    }

    void DelRectangularMatrix() {
        this->size = 0;
        this->n = 0;
        this->m = 0;
        delete this->matrix;
    }

    /*RectangularMatrix(Sequence<T> *sequence) { // не можем найти размеры стобцов и строк
        this->matrix = new Sequence<T>();
        int i;
        int length = sequence->GetSize();
        for (i = 0; i < length; i++) {
            this->matrix->append(sequence->Get(i));
        }
        this->size = length;
    }*/

    RectangularMatrix(T* items, int n, int m) {
        int i;
        int g;
        if (this->matrix != nullptr) delete this->matrix;
        this->matrix = new T[n * m];
        for (i = 0; i < n; i++) {
            for (g = 0; g < m; g++) {
                this->matrix[i * m + g] = items[i * m + g];
            }
        }
        this->n = n;
        this->m = m;
        this->size = n * m;
    }

    RectangularMatrix(RectangularMatrix<T> Items, int n, int m) {
        DelRectangularMatrix();
        this->matrix = new T[n * m];
        for (int i = 0; i < n; i++) {
            for (int g = 0; g < m; g++) {
                this->matrix[i * m + g] = Items.Get(i * m + g);
            }
        }
        this->n = n;
        this->m = m;
        this->size = n * m;
    }

    T Get(int index) {
        if ((index < 0) or (index >= this->size)) throw INDEX_OUT_OF_RANGE_MESSAGE;
        return this->matrix[index];
    }

    void Set(const T& value, int index) {
        if ((index < 0) or (index >= this->size)) throw out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
        this->matrix[index] = value;
    }

    void Append(T value) {
        this->size++;
        this->matrix->Append(value);
    }

    void Prepand(T value) {
        this->size++;
        this->matrix->Prepand(value);
    }

    void Print() {
        for (int i = 0; i < this->n; i++) {
            for (int g = 0; g < this->m; g++) {
                cout << this->matrix[i * this->m + g] << ' ';
            }
            cout << '\n';
        }
    }

    int GetLength() {
        return this->size;
    }

    int GetStringsCount() {
        return this->n;
    }

    int GetColumnsCount() {
        return this->m;
    }

    void ScalarMult(float ratio) {
        int i;
        for (i = 0; i < this->size; i++) {
            this->matrix->Set(ratio * (this->matrix->Get(i)), i);
        }
    }

    void ReadRectangularMatrix() {
        //cout << this->n << ' ' << this->m << '\n';
        for (int i = 0; i < this->n; i++) {
            for (int g = 0; g < this->m; g++) {
                T Data;
                cin >> Data;
                //cout << Data << '\n';
                this->matrix[i * this->m + g] = Data;
                //cout << this->matrix->Get(i * this->m + g) << ' ';
            }
        }
    }

    void PrintRectangularMatrix() {
        for (int i = 0; i < this->n; i++) {
            for (int g = 0; g < this->m; g++) {
                cout << this->matrix[i * this->m + g] << ' ';
            }
            cout << '\n';
        }
    }

    T StringNorm() {
        if (this->size == 0) throw ZERO_SIZE_MESSAGE;
        if (this->size < 0) throw NEGATIVE_SIZE_MESSAGE;
        T maxi;
        int i;
        int g;
        T now = 0;
        for (i = 0; i < this->n; i++) {
            now = 0;
            for (g = 0; g < this->m; g++) {
                now = now + this->matrix->Get(i * (this->m) + g);
            }
            if (i == 0) {
                maxi = now;
            }
            if (maxi < now) {
                maxi = now;
            }
        }
        return maxi;
    }

    T ColumnNorm() {
        if (this->size == 0) throw ZERO_SIZE_MESSAGE;
        if (this->size < 0) throw NEGATIVE_SIZE_MESSAGE;
        T maxi;
        int i;
        int g;
        T now = 0;
        for (g = 0; g < this->m; g++) {
            now = 0;
            for (i = 0; i < this->n; i++) {
                now = now + this->matrix->Get(i * (this->m) + g);
            }
            if (g == 0) {
                maxi = now;
            }
            if (now > maxi) {
                maxi = now;
            }
        }
        return maxi;
    }

    void SwapStrings(int index1, int index2) {
        if ((index1 < 0) or (index1 >= this->n)) throw INDEX_OUT_OF_RANGE_MESSAGE;
        if ((index2 < 0) or (index2 >= this->n)) throw INDEX_OUT_OF_RANGE_MESSAGE;
        int i;
        int g;
        for (g = 0; g < this->m; g++) {
            T value = this->matrix->Get(index1 * this->m + g);
            this->matrix->Set(this->matrix->Get(index2 * this->m + g), index1 * this->m + g);
            this->matrix->Set(value, index2 * this->m + g);
        }
    }

    void SwapColumns(int index1, int index2) {
        if ((index1 < 0) or (index1 >= this->m)) throw INDEX_OUT_OF_RANGE_MESSAGE;
        if ((index2 < 0) or (index2 >= this->m)) throw INDEX_OUT_OF_RANGE_MESSAGE;
        int i;
        int g;
        for (i = 0; i < this->n; i++) {
            T value = this->matrix->Get(i * this->m + index1);
            this->matrix->Set(this->matrix->Get(i * this->m + index2), i * this->m + index1);
            this->matrix->Set(value, i * this->m + index2);
        }
    }

    void StringScalarMult(int index, float ratio) {
        if (ratio == 0) throw ZERO_RATIO_MESSAGE;
        if ((index < 0) or (index >= this->n)) throw INDEX_OUT_OF_RANGE_MESSAGE;
        int i;
        int g;
        for (g = 0; g < this->m; g++) {
            this->matrix->Set(ratio * this->matrix->Get(index * this->m + g), index * this->m + g);
        }
    }

    void ColumnScalarMult(int index, float ratio) {
        if (ratio == 0) throw ZERO_RATIO_MESSAGE;
        if ((index < 0) or (index >= this->m)) throw INDEX_OUT_OF_RANGE_MESSAGE;
        int i;
        for (i = 0; i < this->n; i++) {
            this->matrix->Set(ratio * this->matrix->Get(i * this->m + index), i * this->m + index);
        }
    }

    void StringSum(int index1, int index2, float ratio) { //первую умножаем на ратио и прибавляем ко второй
        if ((index1 < 0) or (index1 >= this->n)) throw INDEX_OUT_OF_RANGE_MESSAGE;
        if ((index2 < 0) or (index2 >= this->n)) throw INDEX_OUT_OF_RANGE_MESSAGE;
        if (ratio == 0) throw ZERO_RATIO_MESSAGE;
        int i;
        int g;
        for (g = 0; g < this->m; g++) {
            T scalar = ratio * this->matrix->Get(index1 * this->m + g);
            T AddTo = this->matrix->Get(index2 * this->m + g);
            this->matrix->Set(scalar + AddTo, index2 * this->m + g);
        }
    }

    void Fill(T data) {
        for (int i = 0; i < this->n; i++) {
            for (int g = 0; g < this->m; g++) {
                this->matrix->set(i * this->m + g, data);
            }
        }
    }

    void ColumnSum(int index1, int index2, float ratio) { //первый умножаем на коэффициент и прибавляем
        if ((index1 < 0) or (index1 >= this->m)) throw INDEX_OUT_OF_RANGE_MESSAGE;
        if ((index2 < 0) or (index2 >= this->m)) throw INDEX_OUT_OF_RANGE_MESSAGE;
        if (ratio == 0) throw ZERO_RATIO_MESSAGE;
        int g;
        int i;
        for (i = 0; i < this->n; i++) {
            T scalar = ratio * this->matrix->Get(i * this->m + index1);
            T AddTo = this->matrix->Get(i * this->m + index2);
            this->matrix->Set(scalar + AddTo, i * this->m + index2);
        }
    }
};

template<typename T>
RectangularMatrix<T> operator+(RectangularMatrix<T> matrix1, RectangularMatrix<T> matrix2) {
    if (matrix1.GetLength() != matrix2.GetLength()) throw WRONG_SIZE_MESSAGE;
    if (matrix1.GetStringsCount() != matrix2.GetStringsCount()) throw WRONG_SIZE_MESSAGE;
    if (matrix1.GetColumnsCount() != matrix2.GetColumnsCount()) throw WRONG_SIZE_MESSAGE;
    int i;
    int g;
    RectangularMatrix<T> matrix3 = RectangularMatrix<T>();
    for (i = 0; i < matrix1.GetStringsCount(); i++) {
        for (g = 0; g < matrix2.GetColumnsCount(); g++) {
            matrix3.Append(matrix1.Get(i * matrix1.GetColumnsCount() + g) + matrix2.Get(i * matrix2.GetColumnsCount() + g));
        }
    }
    return matrix3;
}

template<typename T>
istream& operator >>(istream& in, RectangularMatrix<T> &Matrix) {
    cout << "input please data\n";
    for (int i = 0; i < Matrix.GetStringsCount(); i++) {
        for (int g = 0; g < Matrix.GetColumnsCount(); g++) {
            T Data;
            in >> Data;
            //cout << Data << '\n';
            Matrix.Set(Data, i * Matrix.GetColumnsCount() + g);
            //cout << this->matrix->Get(i * this->m + g) << ' ';
        }
    }
    return in;
}