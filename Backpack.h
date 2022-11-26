#include <iostream>
#include "Sequence.h"
#include "RectangularMatrix.h"
#include <vector>
#include "Tree.h"

#pragma once

using namespace std;

template<class T>
class Backpack {
private:
    Element<T> BackpackA(Element<T> CurrentBackpack, Element<T> *Elements, int CountOfElements) {

    }
};

//template<class T>
//class Backpack {
//
//public:
//
//    ArraySequence<T> *BackpackA() {
//        int n, m;
//        cin >> n >> m;
//        T volume;
//        cin >> volume;
//        //RectangularMatrix<pair<T, T>> matrix = RectangularMatrix<pair<T, T>>(n, m);
//        vector<vector<pair<int, int>>> matrix(n, vector<pair<int, int>> (m, make_pair(0, 0)));
//        RectangularMatrix<T> DynamicProgramming = RectangularMatrix<T>(n + m + 1, volume);
//        cout << "Input please zero int you data type\n";
//        int Zero;
//        cin >> Zero;
//        cout << "Input please data(first - weight, second - cost)'\n'";
//        for (int i = 0; i < n; i++) {
//            for (int g = 0; g < m; g++) {
//                T a, b;
//                cin >> a >> b;
//                //matrix->Set(i, g, make_pair(a, b));
//                matrix[i][g] = make_pair(a, b);
//            }
//        }
//        //cout << "Input please value
//        DynamicProgramming->Fill(Zero);
//        //if (matrix->Get(0, 0) < volume)
//        for (int i = 0; i < n; i++) {
//            for (int g = 0; g < volume; g++) {
//                if (volume > matrix[i][0]) DynamicProgramming->Set(i + 1, g, max(DynamicProgramming->Get(i, g), DynamicProgramming->Get(i, g - matrix[i][0].first) + matrix[i][0].second));
//                else DynamicProgramming->Set(i + 1, g, DynamicProgramming->Get(i, g));
//            }
//        }
//        for (int i = 1; i < m; i++) {
//            for (int g = 0; g < volume; g++) {
//                if (volume > matrix[0][i]) DynamicProgramming->Set(i + 1, g, max(DynamicProgramming->Get(i, g), DynamicProgramming->Get(i, g - matrix[0][i].first) + matrix[0][i].second));
//                else DynamicProgramming->Set(i + 1, g, DynamicProgramming->Get(i, g));
//            }
//        }
//        return DynamicProgramming.Get();
//        //дописать
//    }
//
//};

//template <typename T>
//ArraySequence<T> *BackpackA() {
//    int n, m;
//    cin >> n >> m;
//    T volume;
//    cin >> volume;
//    //RectangularMatrix<pair<T, T>> matrix = RectangularMatrix<pair<T, T>>(n, m);
//    vector<vector<pair<int, int>>> matrix(n, vector<pair<int, int>> (m, make_pair(0, 0)));
//    RectangularMatrix<T> DynamicProgramming = RectangularMatrix<T>(n + m + 1, volume);
//    cout << "Input please zero int you data type\n";
//    int Zero;
//    cin >> Zero;
//    cout << "Input please data(first - weight, second - cost)'\n'";
//    for (int i = 0; i < n; i++) {
//        for (int g = 0; g < m; g++) {
//            T a, b;
//            cin >> a >> b;
//            //matrix->Set(i, g, make_pair(a, b));
//            matrix[i][g] = make_pair(a, b);
//        }
//    }
//    //cout << "Input please value
//    DynamicProgramming->Fill(Zero);
//    //if (matrix->Get(0, 0) < volume)
//    for (int i = 0; i < n; i++) {
//        for (int g = 0; g < volume; g++) {
//            if (volume > matrix[i][0]) DynamicProgramming->Set(i + 1, g, max(DynamicProgramming->Get(i, g), DynamicProgramming->Get(i, g - matrix[i][0].first) + matrix[i][0].second));
//            else DynamicProgramming->Set(i + 1, g, DynamicProgramming->Get(i, g));
//        }
//    }
//    for (int i = 1; i < m; i++) {
//        for (int g = 0; g < volume; g++) {
//            if (volume > matrix[0][i]) DynamicProgramming->Set(i + 1, g, max(DynamicProgramming->Get(i, g), DynamicProgramming->Get(i, g - matrix[0][i].first) + matrix[0][i].second));
//            else DynamicProgramming->Set(i + 1, g, DynamicProgramming->Get(i, g));
//        }
//    }
//    return DynamicProgramming.Get()
//}


