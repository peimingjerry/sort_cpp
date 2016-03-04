
template <typename Key_Tp, typename Value_Tp>
void BasicQuickSort(DataList<Key_Tp, Value_Tp>& list, 
        const int left, const int right) {
    if (left < right) { // skip when left==right
        int pivotpos = list.Partition(left, right);
#ifdef _DEBUG
        cout<<"list.Partition("<<left<<", "<<right<<"):\n";
        DEBUG_PRINT
#endif
        BasicQuickSort(list, left, pivotpos-1);
        BasicQuickSort(list, pivotpos+1, right);
    }
}

// Turn to insert sort when the scale of sort becomes small in recursions.
#define M 2
template <typename Key_Tp, typename Value_Tp>
void QuickSort_Insert(DataList<Key_Tp, Value_Tp>& list,
        const int left, const int right) {
    if (right - left <= M) {
#ifdef _DEBUG
        cout<<"Direct insert sort: left="<<left<<", right="<<right<<":\n";
#endif
        BasicInsertSort(list, left, right);
    } else {
        int pivotpos = list.Partition(left, right);
#ifdef _DEBUG
        cout<<"list.Partition("<<left<<", "<<right<<"):\n";
        DEBUG_PRINT
#endif
        QuickSort_Insert(list, left, pivotpos-1);
        QuickSort_Insert(list, pivotpos+1, right);
    }
}
