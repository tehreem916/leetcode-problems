class MyHashMap {
    static const int SIZE = 1009;   // prime number
    vector<list<pair<int,int>>> buckets;

    int hash(int key) { return key % SIZE; }

public:
    MyHashMap() : buckets(SIZE) {}

    void put(int key, int value) {
        int h = hash(key);
        for (auto& p : buckets[h]) {
            if (p.first == key) {
                p.second = value;  // update existing
                return;
            }
        }
        buckets[h].push_back({key, value});  // insert new
    }

    int get(int key) {
        int h = hash(key);
        for (auto& p : buckets[h])
            if (p.first == key) return p.second;
        return -1;
    }

    void remove(int key) {
        int h = hash(key);
        buckets[h].remove_if([key](const pair<int,int>& p) {
            return p.first == key;
        });
    }
};