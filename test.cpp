
#include <iostream>
#include "DynamicArray.h"
#include "LinkedList.h"
#include "Sequence.h"
#include "SquareMatrix.h"
#include "RectangularMatrix.h"
#include <cassert>

using namespace std;

void testDynamicArray() {
    int initArr1[] = {1, 2, 3, 4, 5};
    DynamicArray<int> arr1(initArr1, 5);
    assert(arr1.Get(0) == 1);
    assert(arr1.Get(3) == 4);
    assert(arr1.Get(4) == 5);
    assert(arr1.GetSize() == 5);
    arr1.Resize(6);
    arr1.Set(0, 0);
    arr1.Set(5, 5);
    assert(arr1.GetSize() == 6);
    assert(arr1.Get(0) == 0);
    assert(arr1.Get(5) == 5);
}

void testLinkedList() {
    int initArr1[] = {1, 2, 3, 5};
    int initArr2[] = {-1, 0, 1, 2, 3, 4, 5, 6, 7};
    LinkedList<int> list1(initArr1, 4);
    assert(list1.Get(0) == 1);
    assert(list1.GetFirst() == 1);
    assert(list1.Get(2) == 3);
    assert(list1.Get(3) == 5);
    assert(list1.GetLast() == 5);
    assert(list1.GetLength() == 4);
    list1.Prepend(0);
    list1.Append(6);
    list1.InsertAt(-1, 0);
    list1.InsertAt(7, 7);
    list1.InsertAt(4, 5);
    assert(list1 == LinkedList<int>(initArr2, 9));
}

void testLinkedListSequence() {
    int initArr1[] = {1, 2, 3, 5};
    int initArr2[] = {-1, 0, 1, 2, 3, 4, 5, 6, 7};
    LinkedListSequence<int> seq1(initArr1, 4);
    assert(seq1 == LinkedListSequence<int>(seq1));
    assert(seq1.Get(0) == 1);
    assert(seq1.GetFirst() == 1);
    assert(seq1.Get(2) == 3);
    assert(seq1.Get(3) == 5);
    assert(seq1.GetLast() == 5);
    assert(seq1.GetSize() == 4);
    seq1.Prepend(0);
    seq1.Append(6);
    seq1.InsertAt(-1, 0);
    seq1.InsertAt(7, 7);
    seq1.InsertAt(4, 5);
    assert(seq1 == LinkedListSequence<int>(initArr2, 9));
}

void testArraySequence() {
    int initArr1[] = {1, 2, 3, 4, 5};
    ArraySequence<int> arr1(initArr1, 5);
    assert(arr1.Get(0) == 1);
    assert(arr1.Get(3) == 4);
    assert(arr1.Get(4) == 5);
    assert(arr1.GetSize() == 5);
    arr1.Append(6);
    assert(arr1.Get(5) == 6);
    arr1.Prepend(0);
    assert(arr1.GetSize() == 7);
    assert(arr1.Get(0) == 0);
    assert(arr1.Get(6) == 6);
}

void testSquareMatrix() {
    int initArr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    SquareMatrix<int> matrix(initArr1, 9);
    assert(matrix.Get(1) == 2);
    assert(matrix.Get(8) == 9);
    assert(matrix.GetLength() == 9);
    assert(matrix.StringNorm() == 24);
    assert(matrix.ColumnNorm() == 18);
    matrix.ScalarMult(5);
    assert(matrix.StringNorm() == 120);
    assert(matrix.ColumnNorm() == 90);
    matrix.ScalarMult(0.2);
    matrix.SwapStrings(0, 1);
    assert(matrix.Get(0) == 4);
    assert(matrix.Get(1) == 5);
    assert(matrix.Get(2) == 6);
    assert(matrix.Get(3) == 1);
    assert(matrix.Get(4) == 2);
    assert(matrix.Get(5) == 3);
    matrix.SwapStrings(0, 1);
    matrix.SwapColumns(0, 1);
    assert(matrix.Get(0) == 2);
    assert(matrix.Get(1) == 1);
    assert(matrix.Get(3) == 5);
    assert(matrix.Get(4) == 4);
    assert(matrix.Get(6) == 8);
    assert(matrix.Get(7) == 7);
    matrix.SwapColumns(0, 1);
    matrix.StringScalarMult(0, 2);
    assert(matrix.Get(0) == 2);
    assert(matrix.Get(1) == 4);
    assert(matrix.Get(2) == 6);
    matrix.StringScalarMult(0, 0.5);
    matrix.ColumnScalarMult(0, 2);
    assert(matrix.Get(0) == 2);
    assert(matrix.Get(3) == 8);
    assert(matrix.Get(6) == 14);
    matrix.ColumnScalarMult(0, 0.5);
    matrix.StringSum(0, 1, 2);
    assert(matrix.Get(3) == 6);
    assert(matrix.Get(4) == 9);
    assert(matrix.Get(5) == 12);
    matrix.StringSum(0, 1, -2);
    matrix.ColumnSum(0, 1, 2);
    assert(matrix.Get(1) == 4);
    assert(matrix.Get(4) == 13);
    assert(matrix.Get(7) == 22);
    matrix.ColumnSum(0, 1, -2);
}

void testRectangularMatrix() {
    int initArr[] = {1, 2, 3, 4, 5 , 6, 7, 8, 9, 10, 11, 12};
    RectangularMatrix<int> matrix(initArr, 3, 4);
    assert(matrix.Get(1) == 2);
    assert(matrix.Get(8) == 9);
    assert(matrix.GetLength() == 12);
    assert(matrix.StringNorm() == 42);
    assert(matrix.ColumnNorm() == 24);
    matrix.ScalarMult(5);
    assert(matrix.StringNorm() == 210);
    assert(matrix.ColumnNorm() == 120);
    matrix.ScalarMult(0.2);
    matrix.SwapStrings(0, 1);
    assert(matrix.Get(0) == 5);
    assert(matrix.Get(1) == 6);
    assert(matrix.Get(2) == 7);
    assert(matrix.Get(3) == 8);
    assert(matrix.Get(4) == 1);
    assert(matrix.Get(5) == 2);
    assert(matrix.Get(6) == 3);
    assert(matrix.Get(7) == 4);
    matrix.SwapStrings(0, 1);
    assert(matrix.GetLength() == 12);
    matrix.ScalarMult(5);
    assert(matrix.Get(0) == 5);
    assert(matrix.Get(1) == 10);
    assert(matrix.Get(2) == 15);
    assert(matrix.Get(3) == 20);
    assert(matrix.Get(4) == 25);
    matrix.ScalarMult(0.2);
    matrix.SwapColumns(0, 1);
    assert(matrix.Get(0) == 2);
    assert(matrix.Get(1) == 1);
    assert(matrix.Get(4) == 6);
    assert(matrix.Get(5) == 5);
    assert(matrix.Get(8) == 10);
    assert(matrix.Get(9) == 9);
    matrix.SwapColumns(0, 1);
    matrix.StringScalarMult(0, 5);
    assert(matrix.Get(0) == 5);
    assert(matrix.Get(1) == 10);
    assert(matrix.Get(2) == 15);
    assert(matrix.Get(3) == 20);
    assert(matrix.Get(4) == 5);
    matrix.StringScalarMult(0, 0.2);
    matrix.ColumnScalarMult(0, 5);
    assert(matrix.Get(0) == 5);
    assert(matrix.Get(4) == 25);
    assert(matrix.Get(8) == 45);
    assert(matrix.Get(2) == 3);
    matrix.ColumnScalarMult(0, 0.2);
    matrix.StringSum(0, 1, 5);
    assert(matrix.Get(4) == 10);
    assert(matrix.Get(5) == 16);
    assert(matrix.Get(6) == 22);
    assert(matrix.Get(7) == 28);
    matrix.StringSum(0, 1, -5);
    matrix.ColumnSum(0, 1, 5);
    assert(matrix.Get(1) == 7);
    assert(matrix.Get(5) == 31);
    assert(matrix.Get(9) == 55);
}
/*
int main() {
    testDynamicArray();
    cout << "Functions for dynamic array work correct" << '\n';
    testLinkedList();
    cout << "Functions for linked list work correct" << '\n';
    testArraySequence();
    cout << "Functions for array sequence work correct" << '\n';
    testLinkedListSequence();
    cout << "Functions for linked list sequence work correct" << '\n';
    testSquareMatrix();
    cout << "Functions for square matrix work correct" << '\n';
    testRectangularMatrix();
    cout << "Functions for rectangular matrix work correct" << '\n';
}

*/