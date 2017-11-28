// 379. Design Phone Directory

// Design a Phone Directory which supports the following operations:

// get: Provide a number which is not assigned to anyone.
// check: Check if a number is available or not.
// release: Recycle or release a number.
// Example:

// // Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
// PhoneDirectory directory = new PhoneDirectory(3);

// // It can return any available phone number. Here we assume it returns 0.
// directory.get();

// // Assume it returns 1.
// directory.get();

// // The number 2 is available, so return true.
// directory.check(2);

// // It returns 2, the only number that is left.
// directory.get();

// // The number 2 is no longer available, so return false.
// directory.check(2);

// // Release number 2 back to the pool.
// directory.release(2);

// // Number 2 is available again, return true.
// directory.check(2);

class PhoneDirectory {
public:
    PhoneDirectory(int maxNumbers) {
        n = maxNumbers;
        available = new int[n];
        isAvailable = new bool[n];
        for (int i=0; i<n; i++) {
            available[i] = i;
            isAvailable[i] = true;
        }
    }
    
    ~PhoneDirectory() {
        delete available;
        delete isAvailable;
    }

    int get() {
        if (!n)
            return -1;
        int number = available[--n];
        isAvailable[number] = false;
        return number;
    }
    
    bool check(int number) {
        return isAvailable[number];
    }
    
    void release(int number) {
        if (!isAvailable[number]) {
            isAvailable[number] = true;
            available[n++] = number;
        }
    }
private:
    int n;
    int *available;
    bool *isAvailable;
};

class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        p = maxNumbers - 1;
        nums = new int[maxNumbers + 1];
        isUsed = new char[maxNumbers + 1];
        memset(nums, 0, sizeof(int) * (maxNumbers + 1));
        memset(isUsed, 0, maxNumbers + 1);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (p == -1) return -1;
        int r = p + nums[p];
        isUsed[r] = 1;
        --p;
        return r;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return !isUsed[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (isUsed[number]) {
            ++p;
            nums[p] = number - p;
            isUsed[number] = 0;
        }
    }
private:
    int * nums;
    char * isUsed;
    int p;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */

 Set<Integer> used = new HashSet<Integer>();
    Queue<Integer> available = new LinkedList<Integer>();
    int max;
    public PhoneDirectory(int maxNumbers) {
        max = maxNumbers;
        for (int i = 0; i < maxNumbers; i++) {
            available.offer(i);
        }
    }
    
    public int get() {
        Integer ret = available.poll();
        if (ret == null) {
            return -1;
        }
        used.add(ret);
        return ret;
    }
    
    public boolean check(int number) {
        if (number >= max || number < 0) {
            return false;
        }
        return !used.contains(number);
    }
    
    public void release(int number) {
        if (used.remove(number)) {
            available.offer(number);
        }
    }