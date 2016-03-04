
#include "sort.h"

#define size 6
#define DISPLAY {\
    int _k;\
    cout<<"Print this array:\n";\
    for (_k=0;_k<size;_k++)\
        cout<<_k<<": key="<<myList[_k].key<<" value="<<myList[_k].value<<"\t";\
    cout<<"\n\n";\
}


int main() {
    DataList<int, int> myList(size);

    myList[0].key = 3; myList[0].value = 1;
    myList[1].key = myList[1].value = 1;
    myList[2].key = myList[2].value = 2;
    myList[3].key = myList[3].value = 5;
    myList[4].key = myList[4].value = 0;
    myList[5].key = 3; myList[5].value = 2;

    DISPLAY

    //BasicSort(myList, 0, size-1);

    //BinaryInsertSort(myList, 0, size-1);

    ShellInsertSort(myList, 0, size-1);

    //BasicQuickSort(myList, 0, size-1);

    //QuickSort_Insert(myList, 0, size-1);

    //BasicSelectSort(myList, 0, size-1);

    //HeapSort(myList, 0, size-1);

    //DataList<int, int> localList(myList.length());
    //MergeSort(myList, localList, 0, size-1);

    cout<<"After sorting:\n";
    DISPLAY

    return 0;
}
