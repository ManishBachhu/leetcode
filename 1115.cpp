class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    bool foo_printed = false;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] {return foo_printed == false;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            foo_printed = true;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] {return foo_printed == true;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            foo_printed = false;
            cv.notify_all();
        }
    }
};
