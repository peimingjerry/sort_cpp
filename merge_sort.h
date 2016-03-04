
// Function used in MergeSort
template <typename Key_Tp, typename Value_Tp>
void merge(DataList<Key_Tp, Value_Tp>& list,
        DataList<Key_Tp, Value_Tp>& localList,
        const int left1, const int right1, 
        const int left2, const int right2) {
    ASSERT(left2 == right1+1);

    int k;
    for(k=left1;k<=right2;k++) {
        localList[k] = list[k];
    }

    int i=left1, j=left2;
    k=left1;
    while (i<=right1 && j<=right2) {
        if (localList[i]<=localList[j]) {
            list[k++] = localList[i++];
        } else {
            list[k++] = localList[j++];
        }
    }
    for(;i<=right1;i++)
        list[k++] = localList[i];
    for(;j<=right2;j++)
        list[k++] = localList[j];
    ASSERT(k == right2+1);

#ifdef _DEBUG
    {   int left=left1, right=right2;
        cout<<"Merge (["<<left1<<"],["<<right1<<"]) ";
        cout<<"and (["<<left2<<"],["<<right2<<"]):"<<endl;
        DEBUG_PRINT
    }
#endif
}

template <typename Key_Tp, typename Value_Tp>
void MergeSort(DataList<Key_Tp, Value_Tp>& list,
        DataList<Key_Tp, Value_Tp>& localList,
        const int left, const int right) {
    if (left<right) {
        // divide
        int mid = (right+left)/2;
        MergeSort(list, localList, left, mid);
        MergeSort(list, localList, mid+1, right);
        // merge
        merge(list, localList, left, mid, mid+1, right);
    }
}
