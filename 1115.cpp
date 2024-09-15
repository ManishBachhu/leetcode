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

    void run(function<bool()> condition, function<void()> printFunc) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, condition);
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFunc();
            foo_printed = (foo_printed)?false:true; // alternate between false and true
            cv.notify_all();
        }
    }

    void foo(function<void()> printFoo) {
        run([this] {return foo_printed == false;}, printFoo);
    }

    void bar(function<void()> printBar) {
        run([this] {return foo_printed == true;}, printBar);
    }
};
