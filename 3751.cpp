class Solution {
public:
    int waviness(int n) {
        int count = 0, prev = -1, curr = n % 10;
        n /= 10;
        while (n > 0) {
            int next = n % 10;
            if (prev != -1) // curr has both neighbors
                if ((curr > prev && curr > next) || (curr < prev && curr < next))
                    count++;
            prev = curr;
            curr = next;
            n /= 10;
        }
        return count;
    }

    int totalWaviness(int num1, int num2) {
        // All nums till 100 have waviness 0
        if(num2 <= 100)
            return 0;

        int count = 0;
        for(int i = num1; i <= num2; i++) {
            count += waviness(i);
        }

        return count;
    }
};
