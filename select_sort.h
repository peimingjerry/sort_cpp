
template <typename Key_Tp, typename Value_Tp>
void BasicSelectSort(DataList<Key_Tp, Value_Tp>& list, 
        const int left, const int right) {

    for (int i=left;i<right;i++) {
        int min_index = i;
        for(int j=i+1;j<=right;j++) { // left from (i+1) is enough
            if (list[j]<list[min_index])
                min_index = j;
        }
        if (min_index != i) {
            list.swap(list[min_index], list[i]);
        }
#ifdef _DEBUG
        DEBUG_PRINT
#endif
    }
}

// Function used in HeapSort.
template <typename Key_Tp, typename Value_Tp>
void shiftUp(DataList<Key_Tp, Value_Tp>& list,
        const int left, const int right) {
    int i=left;
    int j=2*i+1;

    while (j<=right) {
        if (j<right && list[j]<list[j+1])
            j=j+1; // go to the right son
        if (list[i]<list[j]) {
            list.swap(list[i], list[j]);
            i = j;
            j = 2*j+1;
        } else {
            break;
        }
    }
}

template <typename Key_Tp, typename Value_Tp>
void HeapSort(DataList<Key_Tp, Value_Tp>& list,
        const int left, const int right) {
    for (int i=((right-left+1)-2)/2 + left;i>=left;i--) {
        shiftUp(list, i, right);
#ifdef _DEBUG
        cout<<"Adjusted Heap with root node ["<<i<<"]:"<<endl;
        DEBUG_PRINT
#endif
    }

    for (int i=right;i>left;i--) {
#ifdef _DEBUG
        {   int right = i;
            cout<<"+++++++++++ Heap after adjusting: +++++++++++"<<endl;
            DEBUG_PRINT
        }
#endif
        list.swap(list[left], list[i]);
#ifdef _DEBUG
        {   int right = i;
            cout<<"+++++++++++ Array after exchange: +++++++++++"<<endl;
            DEBUG_PRINT
        }
#endif
        shiftUp(list, left, i-1);
    }
}
