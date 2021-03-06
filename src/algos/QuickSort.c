/*
 * Copyright (c) 2015 Kostas Lekkas
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "QuickSort.h"
#include "Utils.h"

void quickSort(int *A, int lo, int hi) {
  if (lo < hi) {
    int p = partition(A, lo, hi);
    quickSort(A, lo, p - 1);
    quickSort(A, p + 1, hi);
  }
}

int partition(int *A, int lo, int hi) {
  int i;
  int pivotIndex = choosePivot(lo, hi);
  int pivotValue = A[pivotIndex];
  int position = lo;

  swap(&A[hi], &A[pivotIndex]);

  for (i = lo; i < hi; i++) {
    if (A[i] < pivotValue) {
      swap(&A[i], &A[position]);
      position++;
    }
  }
  swap(&A[position], &A[pivotIndex]);
  return position;
}

int choosePivot(int lo, int hi) {
  return hi;
}
