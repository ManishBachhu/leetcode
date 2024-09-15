// Explanation for below code at: https://leetcode.com/problems/print-zero-even-odd/solutions/5790659/c-beats-100-elegant-solution-with-only-1-mutex-counter
class ZeroEvenOdd {
private:
    int n, counter = 1;
    mutex mtx;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    void run(function<bool()> condition, function<void(int)> printNumber) {
        while(true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this, &condition] {
                return counter > 2*n || condition();
            });

            //Exit condition
            if(counter > 2*n) {
                cv.notify_all();
                return;
            }

            if(counter % 2)
                printNumber(0);
            else
                printNumber(counter/2);

            counter++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        run([this]{return counter % 2 == 1;}, printNumber);
    }

    void even(function<void(int)> printNumber) {
        run([this]{return (counter % 2 == 0) && ((counter/2)%2 == 0);}, printNumber);
    }

    void odd(function<void(int)> printNumber) {
        run([this]{return (counter % 2 == 0) && ((counter/2)%2 == 1);}, printNumber);
    }
};
