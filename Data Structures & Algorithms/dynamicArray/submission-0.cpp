#include <cstring>

class DynamicArray {
private:
    int *arr;
    int size;
    int filled;

public:

    DynamicArray(int capacity) {
        arr = new int[capacity];
        size = capacity;
        filled = 0;
        //memset(arr, 0, capacity);
    }

    int get(int i) {
        return *(arr+i);
    }

    void set(int i, int n) {
        *(arr+i) = n;
    }

    void pushback(int n) {
        if(filled == size)
        {
            resize();
        }
        *(arr+filled) = n;
        filled++;
    }

    int popback() {
        int val = *(arr+filled-1);
        filled--;

        return val;
    }

    void resize() {
        int *arrBkp = arr;
        size*= 2;
        int *arrNew = new int[size];
        memcpy(arrNew, arr, size/2 * sizeof(int));
        delete [] arrBkp;
        arr = arrNew;
        arrNew = NULL;
    }

    int getSize() {
        return filled;
    }

    int getCapacity() {
        return size;
    }
};
