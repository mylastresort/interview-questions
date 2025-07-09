class MyHashSet {
public:
    std::vector<bool>map;
    
    MyHashSet() {
        
    }
    
    void add(int key) {
        if (key >= this->map.size()) {
            this->map.resize(key + 1);
        }
        this->map[key] = true;
    }
    
    void remove(int key) {
        if (this->contains(key))
            this->map[key] = false;
    }
    
    bool contains(int key) {
        return key < this->map.size() && this->map[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */