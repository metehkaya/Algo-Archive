class LRUCache {
public:
    LRUCache(int capacity) {
        remaining = capacity;
    }
    int get(int key) {
        auto iter = cache.find(key);
        if(iter == cache.end())
            return -1;
        touch(iter);
        return iter->second.first;
    }
    void put(int key, int value) {
        auto iter = cache.find(key);
        if(iter != cache.end()) {
            iter->second.first = value;
            touch(iter);
        }
        else {
            if(remaining == 0) {
                cache.erase(numbers.back());
                numbers.pop_back();
            }
            else
                remaining--;
            numbers.push_front(key);
            cache[key] = make_pair(value, numbers.begin());
        }
    }
private:
    int remaining;
    list<int> numbers;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    void touch(unordered_map<int, pair<int, list<int>::iterator>>::iterator iter) {
        int key = iter->first;
        numbers.erase(iter->second.second);
        numbers.push_front(iter->first);
        iter->second.second = numbers.begin();
    }
};