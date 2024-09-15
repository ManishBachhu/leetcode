class H2O {
    int oxygen_printed = 0;
    mutex print_mtx;
    condition_variable cv;

public:
    H2O() { 
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> print_lock(print_mtx);
        cv.wait(print_lock, [this] {return oxygen_printed > 0;});
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        oxygen_printed--;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        
        unique_lock<mutex> print_lock(print_mtx);
        cv.wait(print_lock, [this] {return (oxygen_printed == 0);});
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        oxygen_printed = 2;
        cv.notify_all(); 
    }
};
