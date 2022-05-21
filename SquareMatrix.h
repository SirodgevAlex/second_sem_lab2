#include <iostream>
#include "Sequence.h"
#include <stdexcept>
#include <cmath>

#pragma once
#define WRONG_SIZE_MESSAGE "sizes of matrix not equal"
#define NEGATIVE_SIZE_MESSAGE "size is negative"
#define INDEX_OUT_OF_RANGE_MESSAGE "index out of range"
#define NOT_SQUARE_MATRIX_MESSAGE "not square matrix"
#define ZERO_SIZE_MESSAGE "size is 0"
#define ZERO_RATIO_MESSAGE "ratio is 0"

using namespace std;

template<class T>
class SquareMatrix {
private:
    Sequence<T> *matrix;
    int size = 0;
public:
    /*const T &operator[](int index) {
        return this->matrix->Get(index);
    }*/

    SquareMatrix() {
        this->matrix = new ArraySequence<T>();
        this->size = 0;
    }

    SquareMatrix(int n) {
        this->matrix = new ArraySequence<T>();
        int i;
        for (i = 0; i < n * n; i++) {
            this->matrix->Append(0);
        }
        this->size = n * n;
    }

    SquareMatrix(Sequence<T> *sequence) {
        this->matrix = new ArraySequence<T>();
        int i;
        int length = sequence->GetSize();
        for (i = 0; i < length; i++) {
            this->matrix->Append(sequence->Get(i));
        }
        this->size = length;
    }

    SquareMatrix(T* items, int count) {
        int i;
        this->matrix = new ArraySequence<T>();
        for (i = 0; i < count; i++){
            this->matrix->Append(items[i]);
        }
        this->size = count;
    }

    virtual T Get(int index) const {
        if ((index < 0) or (index >= this->size)) throw INDEX_OUT_OF_RANGE_MESSAGE;
        return this->matrix->Get(index);
    }

    virtual void Set(const T& item, int index) {
        if ((index < 0) or (index >= this->size)) throw INDEX_OUT_OF_RANGE_MESSAGE;
        this->matrix->Set(item, index);
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
        this->matrix->PrintArray();
    }

    int GetLength() {
        return this->size;
    }

    int GetStringLength() {
        return sqrt(this->size);
    }

    void ScalarMult(float ratio) {
        if (sqrt(this->size) * sqrt(this->size) != this->size) throw NOT_SQUARE_MATRIX_MESSAGE;
        int i;
        for (i = 0; i < this->size; i++) {
            this->matrix->Set(ratio * this->matrix->Get(i), i);
        }
    }

    T StringNorm() {
        if (this->size == 0) throw ZERO_SIZE_MESSAGE;
        if (this->size < 0) throw NEGATIVE_SIZE_MESSAGE;
        if (sqrt(this->size) * sqrt(this->size) != this->size) throw NOT_SQUARE_MATRIX_MESSAGE;
        T maxi;
        int i;
        T now = 0;
        for (i = 0; i < this->size; i++) {
            if (this->size == i * i) {
                maxi = now;
                now = 0;
            } else if ((i % int(sqrt(this->size)) == 0) and (i != 0)) {
                if (maxi < now) {
                    maxi = now;
                }
                now = 0;
            }
            now = now + this->matrix->Get(i);
        }
        if (now > maxi) {
            maxi = now;
        }
        return maxi;
    }

    T ColumnNorm() {
        if (this->size == 0) throw ZERO_SIZE_MESSAGE;
        if (this->size < 0) throw NEGATIVE_SIZE_MESSAGE;
        if (sqrt(this->size) * sqrt(this->size) != this->size) throw NOT_SQUARE_MATRIX_MESSAGE;
        T maxi;
        int i;
        int g;
        T now = 0;
        for (i = 0; i < sqrt(this->size); i++) {
            for (g = 0; g < sqrt(this->size); g++) {
                now = now + this->matrix->Get(i + g * sqrt(this->size));
            }
            if (i == 0) {
                maxi = now;
                now = 0;
            } else {
                if (maxi < now) {
                    maxi = now;
                }
                now = 0;
            }
        }
        return maxi;
    }

    void SwapStrings(int index1, int index2) {
        if (sqrt(this->size) * sqrt(this->size) != this->size) throw NOT_SQUARE_MATRIX_MESSAGE;
        if ((index1 < 0) or (index1 >= sqrt(this->size))) throw INDEX_OUT_OF_RANGE_MESSAGE;
        if ((index2 < 0) or (index2 >= sqrt(this->size))) throw INDEX_OUT_OF_RANGE_MESSAGE;
        int i;
        for (i = 0; i < sqrt(this->size); i++){
            T a = this->matrix->Get(i + index1 * sqrt(this->size));
            this->matrix->Set(this->matrix->Get(i + index2 * sqrt(this->size)), i + index1 * sqrt(this->size));
            this->matrix->Set(a , i + index2 * sqrt(this->size));
        }
    }

    void SwapColumns(int index1, int index2) {
        if (sqrt(this->size) * sqrt(this->size) != this->size) throw NOT_SQUARE_MATRIX_MESSAGE;
        if ((index1 < 0) or (index1 >= sqrt(this->size))) throw INDEX_OUT_OF_RANGE_MESSAGE;
        if ((index2 < 0) or (index2 >= sqrt(this->size))) throw INDEX_OUT_OF_RANGE_MESSAGE;
        int i;
        for (i = 0; i < sqrt(this->size); i++){
            T a = this->matrix->Get(index1 + i * sqrt(this->size));
            this->matrix->Set(this->matrix->Get(index2 + i * sqrt(this->size)), index1 + i * sqrt(this->size));
            this->matrix->Set(a , index2 + i * sqrt(this->size));
        }
    }

    void StringScalarMult(int index, float ratio) {
        if (sqrt(this->size) * sqrt(this->size) != this->size) throw NOT_SQUARE_MATRIX_MESSAGE;
        if (ratio == 0) throw ZERO_RATIO_MESSAGE;
        if ((index < 0) or (index >= sqrt(this->size))) throw INDEX_OUT_OF_RANGE_MESSAGE;
        int i;
        for (i = 0; i < sqrt(this->size); i++) {
            this->matrix->Set(ratio * this->matrix->Get(i + index * sqrt(this->size)), i + index * sqrt(this->size));
        }
    }

    void ColumnScalarMult(int index, float ratio) {
        if (sqrt(this->size) * sqrt(this->size) != this->size) throw NOT_SQUARE_MATRIX_MESSAGE;
        if (ratio == 0) throw ZERO_RATIO_MESSAGE;
        if ((index < 0) or (index >= sqrt(this->size))) throw INDEX_OUT_OF_RANGE_MESSAGE;
        int i;
        for (i = 0; i < sqrt(this->size); i++) {
            this->matrix->Set(ratio * this->matrix->Get(index + i * sqrt(this->size)), index + i * sqrt(this->size));
        }
    }

    void StringSum(int index1, int index2, float ratio) {
        if (sqrt(this->size) * sqrt(this->size) != this->size) throw NOT_SQUARE_MATRIX_MESSAGE;
        if ((index1 < 0) or (index1 >= sqrt(this->size))) throw INDEX_OUT_OF_RANGE_MESSAGE;
        if ((index2 < 0) or (index2 >= sqrt(this->size))) throw INDEX_OUT_OF_RANGE_MESSAGE;
        if (ratio == 0) throw ZERO_RATIO_MESSAGE;
        int i;
        int n = sqrt(this->size);
        for (i = 0; i < n; i++) {
            T scalar = ratio * this->matrix->Get(i + index1 * n); // умножаем на строку с индексом 1
            T AddTo = this->matrix->Get(i + index2 * n); // к чему добавлять
            this->matrix->Set(scalar +  AddTo, i + index2 * n); // делаем
        }
    }

    void ColumnSum(int index1, int index2, float ratio) {
        if (sqrt(this->size) * sqrt(this->size) != this->size) throw NOT_SQUARE_MATRIX_MESSAGE;
        if ((index1 < 0) or (index1 >= sqrt(this->size))) throw INDEX_OUT_OF_RANGE_MESSAGE;
        if ((index2 < 0) or (index2 >= sqrt(this->size))) throw INDEX_OUT_OF_RANGE_MESSAGE;
        if (ratio == 0) throw ZERO_RATIO_MESSAGE;
        int i;
        int n = sqrt(this->size);
        for (i = 0; i < n; i++) {
            T scalar = ratio * this->matrix->Get(index1 + i * n);
            T AddTo = this->matrix->Get(index2 + i * n);
            this->matrix->Set(scalar +  AddTo, index2 + i * n);
        }
    }
};

template<typename T>
SquareMatrix<T> operator+(SquareMatrix<T> matrix1, SquareMatrix<T> matrix2) {
    if (matrix1.GetLength() != matrix2.GetLength()) throw WRONG_SIZE_MESSAGE;
    int i;
    SquareMatrix<T> matrix3 = SquareMatrix<T>();
    for (i = 0; i < matrix1.GetLength(); i++) {
        matrix3.Append(matrix1.Get(i) + matrix2.Get(i));
    }
    return matrix3;
}

