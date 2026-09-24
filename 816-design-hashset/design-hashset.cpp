class MyHashSet {
public:
    int M;
    vector<list<int>> b;

    int getindex(int key) { return key % M; }
    MyHashSet() {
        M = 15000;
        b = vector<list<int>>(M, list<int>{});
    }

    void add(int key) {
        int i = getindex(key);

        auto itr = find(b[i].begin(), b[i].end(), key);

        if (itr == b[i].end())
            b[i].push_back(key);
    }

    void remove(int key) {
        int i = getindex(key);

        auto itr = find(b[i].begin(), b[i].end(), key);

        if (itr != b[i].end())
            b[i].erase(itr);
    }

    bool contains(int key) {
        int i = getindex(key);

        auto itr = find(b[i].begin(), b[i].end(), key);

        return itr != b[i].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */