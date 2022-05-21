
#include <iostream>
#include <clocale>
#include "Sequence.h"
#include "SquareMatrix.h"
#include "DynamicArray.h"
#include "LinkedList.h"
#include "Complex.h"
#include "RectangularMatrix.h"

using namespace std;

void menu() {
    cout << "1 - write matrices" << '\n';
    cout << "2 - sum of matrices" << '\n';
    cout << "3 - multiplying a matrix by a scalar" << '\n';
    cout << "4 - get string norm" << '\n';
    cout << "5 - get column norm" << '\n';
    cout << "6 - swap strings" << '\n';
    cout << "7 - swap columns" << '\n';
    cout << "8 - multiplying a string by a scalar" << '\n';
    cout << "9 - multiplying a column by a scalar" << '\n';
    cout << "10 - sum of string and string multiplying by a scalar" << '\n';
    cout << "11 - sum of columns and column multiplying by a scalar" << '\n';
    cout << "12 - end" << '\n';
}

void DataTypeMenu() {
    cout << "What data type you want?" << '\n';
    cout << "1 - int" << '\n';
    cout << "2 - float" << '\n';
    cout << "3 - complex" << '\n';
}

void MatrixMenu() {
    cout << "What type do of matrix you want to choose?" << '\n';
    cout << "1 - Square" << '\n';
    cout << "2 - Rectangular" << '\n';
}

template<typename T>
SquareMatrix<T> SquareMatrixRead() {
    int n;
    cout << "input size of square matrix" << '\n';
    cin >> n;
    SquareMatrix<T> matrix = SquareMatrix<T>();
    int i;
    for (i = 0; i < n * n; i++) {
        T data;
        cin >> data;
        matrix.Append(data);
    }
    return matrix;
}

template<typename T>
RectangularMatrix<T> RectangularMatrixRead() {
    int n;
    int m;
    cout << "input string and column sizes of rectangular matrix" << '\n';
    cin >> n;
    cin >> m;
    int i;
    int g;
    T *items = new T[n * m];
    for (i = 0; i < n; i++) {
        for (g = 0; g < m; g++) {
            T data;
            cin >> data;
            items[i * m + g] = data;
        }
    }
    RectangularMatrix<T> matrix = RectangularMatrix<T>(items, n, m);
    return matrix;
}

template <typename T>
void RectangularWrite(RectangularMatrix<T> m) {
    int i, g;
    for (i = 0; i < int(m.GetStringsCount()); i++){
        for (g = 0; g < int(m.GetColumnsCount()); g++) {
            cout << m.Get(i * m.GetColumnsCount() + g) << " ";
        }
        cout << '\n';
    }
}

template <typename T>
void SquareWrite(SquareMatrix<T> m) {
    int i, g;
    for (i = 0; i < sqrt(m.GetLength()); i++){
        for (g = 0; g < sqrt(m.GetLength()); g++) {
            cout << m.Get(i * sqrt(m.GetLength()) + g) << " ";
        }
        cout << '\n';
    }
}

template <typename T>
void SquareMainFunc(SquareMatrix<T> m1, SquareMatrix<T> m2) {
    int flag = 0;
    while (flag == 0) {
        menu();
        int command = 0;
        cin >> command;
        if (command == 1) {
            SquareWrite(m1);
        } else if (command == 2) {
            m1 = m1 + m2;
        } else if (command == 3) {
            float ratio;
            cout << "Input ratio please" << '\n';
            cin >> ratio;
            m1.ScalarMult(ratio);
        } else if (command == 4) {
            cout << m1.StringNorm() << '\n';
        } else if (command == 5) {
            cout << m1.ColumnNorm() << '\n';
        } else if (command == 6) {
            int index1, index2;
            cout << "input indexes please" << '\n';
            cin >> index1;
            cin >> index2;
            m1.SwapStrings(index1, index2);
        } else if (command == 7) {
            int index1, index2;
            cout << "input indexes please" << '\n';
            cin >> index1;
            cin >> index2;
            m1.SwapColumns(index1, index2);
        } else if (command == 8) {
            int index;
            float ratio;
            cout << "input index and ratio" << '\n';
            m1.StringScalarMult( index, ratio);
        } else if (command == 9) {
            int index;
            float ratio;
            cout << "input index and ratio" << '\n';
            m1.ColumnScalarMult( index, ratio);
        } else if (command == 10) {
            int index1, index2;
            float ratio;
            cout << "input indexes and ratio" << '\n';
            m1.StringSum( index1, index2, ratio);
        } else if (command == 11) {
            int index1, index2;
            float ratio;
            cout << "input indexes and ratio" << '\n';
            m1.ColumnSum( index1, index2, ratio);
        } else {
            flag = 1;
        }
    }
}

template <typename T>
void RectangularMainFunc(RectangularMatrix<T> m1, RectangularMatrix<T> m2) {
    int flag = 0;
    while (flag == 0) {
        menu();
        int command = 0;
        cin >> command;
        if (command == 1) {
            RectangularWrite(m1);
        } else if (command == 2) {
            m1 = m1 + m2;
        } else if (command == 3) {
            float ratio;
            cout << "Input ratio please" << '\n';
            cin >> ratio;
            m1.ScalarMult(ratio);
        } else if (command == 4) {
            cout << m1.StringNorm() << '\n';
        } else if (command == 5) {
            cout << m1.ColumnNorm() << '\n';
        } else if (command == 6) {
            int index1, index2;
            cout << "input indexes please" << '\n';
            cin >> index1;
            cin >> index2;
            m1.SwapStrings(index1, index2);
        } else if (command == 7) {
            int index1, index2;
            cout << "input indexes please" << '\n';
            cin >> index1;
            cin >> index2;
            m1.SwapColumns(index1, index2);
        } else if (command == 8) {
            int index;
            float ratio;
            cout << "input index and ratio" << '\n';
            m1.StringScalarMult( index, ratio);
        } else if (command == 9) {
            int index;
            float ratio;
            cout << "input index and ratio" << '\n';
            m1.ColumnScalarMult( index, ratio);
        } else if (command == 10) {
            int index1, index2;
            float ratio;
            cout << "input indexes and ratio" << '\n';
            m1.StringSum( index1, index2, ratio);
        } else if (command == 11) {
            int index1, index2;
            float ratio;
            cout << "input indexes and ratio" << '\n';
            m1.ColumnSum( index1, index2, ratio);
        } else {
            flag = 1;
        }
    }
}

int main() {
    int flag = 0;
    int ForMatrix = 0;
    int ForData = 0;
    MatrixMenu();
    cin >> ForMatrix;
    DataTypeMenu();
    cin >> ForData;
    if (ForMatrix == 1) {
        if (ForData == 1) {
            SquareMatrix<int> m1;
            SquareMatrix<int> m2;
            m1 = SquareMatrixRead<int>();
            m2 = SquareMatrixRead<int>();
            SquareMainFunc(m1, m2);
        } else if (ForData == 2) {
            SquareMatrix<float> m1;
            SquareMatrix<float> m2;
            m1 = SquareMatrixRead<float>();
            m2 = SquareMatrixRead<float>();
            SquareMainFunc(m1, m2);
        } else {
            /*
            SquareMatrix<Complex<int>> m1;
            SquareMatrix<Complex<int>> m2;
            m1 = SquareMatrixRead<Complex<int>>();
            m2 = SquareMatrixRead<Complex<int>>();
            SquareMainFunc(m1, m2);
             */
        }
    } else {
        if (ForData == 1) {
            RectangularMatrix<int> m1;
            RectangularMatrix<int> m2;
            m1 = RectangularMatrixRead<int>();
            m2 = RectangularMatrixRead<int>();
            RectangularMainFunc(m1, m2);
        } else if (ForData == 2) {
            RectangularMatrix<float> m1;
            RectangularMatrix<float> m2;
            m1 = RectangularMatrixRead<float>();
            m2 = RectangularMatrixRead<float>();
            RectangularMainFunc(m1, m2);
        } else {
            /*
            RectangularMatrix<Complex<int>> m1;
            RectangularMatrix<Complex<int>> m2;
            m1 = RectangularMatrixRead<Complex<int>>();
            m2 = RectangularMatrixRead<Complex<int>>();
            RectangularMainFunc(m1, m2);
             */
        }
    }

}
