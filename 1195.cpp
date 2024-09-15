class FizzBuzz {
private:
    int n;
    int counter = 1;
    mutex mtx;
    condition_variable cv;

public:
    FizzBuzz(int n) : n(n) {}

    // Common function to handle waiting and printing
    void run(function<bool()> condition, function<void()> printFunc) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this, &condition] {
                return counter > n || condition();
            });

            // Exit condition
            if (counter > n) {
                cv.notify_all();
                return;
            }

            printFunc();
            counter++;
            cv.notify_all();
        }
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        run([this] { return (counter % 3 == 0) && (counter % 5 != 0); }, printFizz);
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        run([this] { return (counter % 5 == 0) && (counter % 3 != 0); }, printBuzz);
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        run([this] { return (counter % 3 == 0) && (counter % 5 == 0); }, printFizzBuzz);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        run([this] { return (counter % 3 != 0) && (counter % 5 != 0); }, 
            [this, &printNumber] { printNumber(counter); });
    }
};
