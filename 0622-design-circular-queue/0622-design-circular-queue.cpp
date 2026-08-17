class MyCircularQueue {
    vector<int> data;
    int head;    
    int tail;    
    int size;   
    int cap;   

public:
    MyCircularQueue(int k) {
        data.resize(k);
        head = 0;
        tail = 0;
        size = 0;
        cap  = k;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        data[tail] = value;
        tail = (tail + 1) % cap;   // move tail forward circularly
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % cap;   // move head forward circularly
        size--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return data[head];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return data[(tail - 1 + cap) % cap];   // last inserted element
    }

    bool isEmpty() { return size == 0; }
    bool isFull()  { return size == cap; }
};