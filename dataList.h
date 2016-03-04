
#ifndef DATALIST_H
#define DATALIST_H

#define MAX_SIZE 100

template <typename Key_Tp, typename Value_Tp>
class Element {
public:
    typedef Element<Key_Tp, Value_Tp> Self;

    Key_Tp key;
    Value_Tp value;

    Self& operator=(const Self & el) {
        key = el.key;
        value = el.value;
        return *this;
    }
    bool operator==(const Self& el) { return key == el.key; }
    bool operator<=(const Self& el) { return key <= el.key; }
    bool operator>(const Self& el) { return key > el.key; }
    bool operator<(const Self& el) { return key < el.key; }
};

template <typename Key_Tp, typename Value_Tp>
class DataList {
public:
    typedef Element<Key_Tp, Value_Tp> Elem;

    DataList(unsigned maxSize=MAX_SIZE): maxSize(maxSize), currentSize(maxSize) {
        Vector = new Elem[maxSize];
    }

    ~DataList() {
        if (Vector)
            delete[] Vector;
        Vector = 0;
    }

    void swap(Elem &el1, Elem &el2) {
        Elem tmp = el1;
        el1 = el2;
        el2 = tmp;
    }

    unsigned length() { return currentSize; }

    Elem& operator[] (int i) { return Vector[i]; }

    int Partition(int left, int right);

private:
    Element<Key_Tp, Value_Tp> *Vector;
    unsigned maxSize;
    unsigned currentSize;
};

// Used in quick sort, to partition into two region
template <typename Key_Tp, typename Value_Tp>
int DataList<Key_Tp, Value_Tp>::Partition(int left, int right) {
    int pivotpos = left;
    Element<Key_Tp, Value_Tp> pivot = Vector[left];
    for (int i=left+1;i<=right;i++) {
        if (Vector[i]<pivot) {
            pivotpos++;
            if (i!=pivotpos)
                swap(Vector[i], Vector[pivotpos]);
        }
    }
    Vector[left] = Vector[pivotpos];
    Vector[pivotpos] = pivot;

    return pivotpos;
}

#endif
