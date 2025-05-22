// Queue.java
import java.util.*;

public class Queue<T> {
    private static final int MAX_CAPACITY = 20;
    private final T[] data;
    private int head, tail;

    // Ctor queue (kosong) dengan alokasi kapasitas maksimum
    public Queue() {
        this.data = (T[]) new Object[MAX_CAPACITY];
        this.head = 0;
        this.tail = 0;
    }

    // Ctor queue terisi dari array dengan alokasi kapasitas maksimum.
    // Copy array dari indeks ke-0 hingga terakhir (data.length)
    // Boleh dilakukan secara copy reference object (bukan reference array)
    public Queue(T[] data) {
        this.data = (T[]) new Object[MAX_CAPACITY];
        for (int i = 0; i < data.length; i++) {
            this.data[i] = data[i];
        }
        this.head = 0;
        this.tail = data.length;
    }

    // Mengintip element paling depan pada queue.
    // Jika queue kosong, return null
    public T peek() { 
        if (tail == 0) {
            return null;
        }
        return data[head];
     }

    // Mengeluarkan elemen paling depan dari queue.
    // Jika queue kosong, return null
    public T pop() { 
        if (tail == 0) {
            return null;
        }
        T val = data[0];
        for (int i = 1; i < tail; i++) {
            data[i-1] = data[i];
        }
        data[tail-1] = null;
        head = 0;
        tail--;
        return val;
     }

    // Menambahkan elemen ke dalam queue.
    // Prekondisi: tail < MAX_CAPACITY - 2 (tidak perlu divalidasi)
    public void push(T o) { 
        data[tail] = o;
        tail++;
    }

    // Getter attribute
    public T[] getData() { 
        return data;
    }
    public int getHead() {
        return head;
     }
    public int getTail() { 
        return tail;
    }
        // Menghitung panjang queue.
    public int size() { 
        return tail;
     }


    // public static void main(String[] args){
    //     Queue<Integer> q = new Queue();
    //     q.push(2);
    //     q.push(3);
    //     System.out.println(q.peek());
    //     System.out.println(q.pop());
    //     System.out.println(q.peek());
    // }
}