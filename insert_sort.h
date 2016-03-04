
template <typename Key_Tp, typename Value_Tp>
void BasicInsertSort(DataList<Key_Tp, Value_Tp>& list, 
        const int left, const int right) {
    int i, j;
    for (i=left+1;i<=right;i++) {
        if (list[i]<list[i-1]) {
            Element<Key_Tp, Value_Tp> tmp = list[i];
            j=i-1;
            do {
                list[j+1] = list[j];
                j--;
            } while (j>=left && tmp<list[j]);
            list[j+1] = tmp;
        }
#ifdef _DEBUG
        DEBUG_PRINT
#endif
    }
}

template <typename Key_Tp, typename Value_Tp>
void BinaryInsertSort(DataList<Key_Tp, Value_Tp>& list,
        const int left, const int right) {
    int i, j, low, high, mid;
    for (i=left+1;i<=right;i++) {
        low = left;
        high = i-1;
        while (low<=high ) {
            mid = (low+high)/2;
            if (list[i]<list[mid]) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        Element<Key_Tp, Value_Tp> tmp = list[i];
        for (j=i-1;j>=low;j--)
            list[j+1]=list[j];
        list[low] = tmp;
#ifdef _DEBUG
        DEBUG_PRINT
#endif
    }
}

template <typename Key_Tp, typename Value_Tp>
void ShellInsertSort(DataList<Key_Tp, Value_Tp>& list,
        const int left, const int right) {
    int gap = right-left+1;
    do {
        gap = gap/3 + 1;
        for (int i=0;i<gap;i++) {
            for (int j=i+gap;j<=right;j+=gap) {
                if (list[j]<list[j-gap]) {
                    Element<Key_Tp, Value_Tp> tmp = list[j];
                    int k = j-gap;
                    do {
                        list[k+gap] = list[k];
                        k = k-gap;
                    } while (k>=left && tmp<list[k]);
                    list[k+gap] = tmp;
                }
            }
        }
#ifdef _DEBUG
        DEBUG_PRINT
#endif
    } while (gap>1);
}

