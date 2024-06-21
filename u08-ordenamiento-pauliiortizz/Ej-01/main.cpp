#include <iostream>

using namespace std;

void bubbleSort(int *arr, int size) {
    int aux;
    bool band = true;

    for (int i = 0; i < size && band; i++) {
        band = false;
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                band = true;
                aux = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

void quicksort(int *arr, int inicio, int fin){
    int medio=(inicio+fin)/2;
    int pivot=arr[medio];
    int i=inicio, j=fin, aux;

    do{
        while(arr[i]<pivot)i++;
        while(arr[j]>pivot)j--;

        if(i<=j){
            aux=arr[i];
            arr[i]=arr[j];
            arr[j]=aux;
            i++;
            j--;
        }

    }while(i<=j);

    if(j>inicio)quicksort(arr, inicio, j);
    if(i<fin)quicksort(arr,i,fin);

}

void shellSort(int *arr, int size){
    for(int gap=size/2; gap>0; gap/=2){
        for (int i = gap; i <size ; i++) {
            int temp=arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}


void print(int *arr, int size){

    for (int i=0; i<size; i++){
        cout << "[" << arr[i] << "]";
    }
}

int main() {
    std::cout << "Ejercicio 05/01\n" << std::endl;

    int x[]={200, 11, 10, 3,7, 500, 150, 8, 3, 6};
    int size=sizeof(x)/sizeof(x[0]);

    cout << "Arreglo a ordenar: ";
    print(x, size);

    cout << endl;

    cout << size;
    cout << endl;

    //bubbleSort(x, size);
    //quicksort(x, 0, size-1);
    shellSort(x, size);
    cout << "Arreglo Ordenado: ";
    print(x, size);

    return 0;
}
