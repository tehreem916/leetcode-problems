class MyStack {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int size = q.size();

        // rotate all elements before x to behind x
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};