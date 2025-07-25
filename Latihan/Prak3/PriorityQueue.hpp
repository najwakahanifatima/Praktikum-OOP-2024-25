#ifndef PRIO_QUEUE_HPP
#define PRIO_QUEUE_HPP

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<class T>
class PriorityQueue {
    private:
        int size;
        std::vector<T> content;
    public:
    /*
        Default constructor, size = 0
    */
    PriorityQueue() {
        this->size = 0;
    }
    /*
        Destructor
    */
    ~PriorityQueue() {}   
    /*
        Menambahkan nilai T ke dalam content
    */   
    void Enqueue(T value) {
        if (size = 0) {
            content.push_back(value);
        } else {
            auto it = content.end();
            while (it != content.begin() && value > *(it-1)){
                --it;
            }
            content.insert(it, value);
        }
        size++;
    }

    /*
        Mengembalikan nilai pada posisi paling depan dari queue dan menghapus nilai tersebut
        Dijamin PrioriryQueue tidak kosong
    */
    T Dequeue() {
        T val = Front();
        reverse(content.begin(), content.end());
        content.pop_back();
        reverese(content.begin(), content.end());
        size--;
        return val;
    }

    /*
        Mengembalikan nilai pada posisi paling depan dari queue
        Dijamin PriorityQueue tidak kosong
    */
    T Front() {
        return content.front();
    }

    /*
        Menambahkan elemen pada priority queue pq ke dalam content
    */
    void MergeQueue(PriorityQueue<T> pq) {
        size += pq.GetSize();
        while (!pq.content.empty()){
            T val = pq.Dequeue();
            Enqueue(val);
        }
    }

    /*
        Mengembalikan banyak data dari priority queue ini
    */
    int GetSize() {
        return this->size;
    }

    /*
        Operator overloading untuk mencetak isi priority queue
        Contoh: (3, 2, 1)
        Apabila kosong, tampilkan ()
    */
    friend ostream& operator<<(ostream& os, PriorityQueue<T> pq) {
        os << "(";
        for (vector<T>::iterator it = content.begin(); it != content.end(); ++it){
            os << *it;
            if (it != content.end()){
                os << ",";
            }
        }
        os << ")" << endl;
        return os;
    }
};



#endif