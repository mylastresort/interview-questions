class MyHashMap {
public:
    std::vector<int> map;
    MyHashMap() {}

    void put(int key, int value) {
        if (key >= this->map.size())
            this->map.resize(key + 1, -1);
        this->map[key] = value;
    }

    int get(int key) { return !this->has(key) ? -1 : this->map[key]; }

    bool has(int key) {
        if (key >= this->map.size())
            return false;
        return this->map[key] != -1;
    }

    void remove(int key) {
        if (this->has(key))
            this->map[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */