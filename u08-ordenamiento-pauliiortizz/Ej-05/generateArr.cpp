#include "string.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

void quickSort(int *arr, int first, int last) {
  int i, j, middle;
  int pivot, aux;

  middle = (first + last) / 2;
  pivot = arr[middle];
  i = first;
  j = last;

  do {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
      j--;

    if (i <= j) {
      aux = arr[i];
      arr[i] = arr[j];
      arr[j] = aux;
      i++;
      j--;
    }
  } while (i <= j);

  if (j > first)
    quickSort(arr, first, j);
  if (i < last)
    quickSort(arr, i, last);
}

void generateRandomArrTxt(int size, int from, int to) {
  srand(time(NULL));

  fstream fout, forden, finverso;
  fout.open("./arr.txt", ios::out);

  int arr[size];
  int random = 0;
  for (int i = 0; i < size; i++) {
    random = (rand() % to + from);
    arr[i] = random;
    fout << random << ",";
  }

  quickSort(arr, 0, size - 1);

  forden.open("./arr_ordenado.txt", ios::out);
  finverso.open("./arr_inverso.txt", ios::out);

  int j = size - 1;
  for (int i = 0; i < size; i++) {
      forden << arr[i] << ",";
      finverso << arr[j-i] << ",";
  }
}

int main(int argc, char **argv) {

  int size = 5000, from = 0, to = 1000;
  int tmp = 0;
  for (int i = 1; i < argc; i++) {
    tmp = stoi(argv[i + 1]);
    if (strcmp(argv[i], "-size") == 0) {
      size = tmp;
      i++;
    } else if (strcmp(argv[i], "-from") == 0) {
      from = tmp;
      i++;
    } else if (strcmp(argv[i], "-to") == 0) {
      to = tmp;
      i++;
    }
  }

  generateRandomArrTxt(size, from, to);
  return 0;
}