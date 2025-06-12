#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

template<typename T>
class Dynamic_array {
    T* data;
    int cap;
    int len;

    void resize(int new_cap) {
        T* new_data = new T[new_cap];
        for (int i = 0; i < len; i++)
            new_data[i] = data[i];
        delete[] data;
        data = new_data;
        cap = new_cap;
    }

public:
    Dynamic_array() {
        data = new T[1];
        cap = 1;
        len = 0;
    }

    ~Dynamic_array() {
        delete[] data;
    }

    void push_back(const T& val) {
        if (len >= cap) resize(cap * 2);
        data[len++] = val;
    }

    void delete_at(int index) {
        if (index < 0 || index >= len) return;
        for (int i = index; i < len - 1; i++)
            data[i] = data[i + 1];
        len--;
    }

    T& operator[](int index) {
        return data[index];
    }

    int size() const {
        return len;
    }

    void clear() {
        len = 0; // Corrected from size = 0;
    }
};

#endif


