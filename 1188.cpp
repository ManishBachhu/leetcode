class BoundedBlockingQueue {
    int capacity;
    queue<int> bbq;
    mutex mtx;
    condition_variable cv;

public:
    BoundedBlockingQueue(int capacity) :
        capacity(capacity)
    {}
    
    void enqueue(int element) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this] {return bbq.size() <= capacity;});
        bbq.push(element);
        cv.notify_all(); // notify dequeue threads waiting at empty
    }
    
    int dequeue() {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this] {return bbq.size() > 0;});
        int val = bbq.front();
        bbq.pop();
        cv.notify_all(); // notify enqueue threads waiting at full cap
        return val;
    }
    
    int size() {
        lock_guard<mutex> lock(mtx);
        return bbq.size();
    }
};
