// 604. Design Compressed String Iterator

// Design and implement a data structure for a compressed string iterator. It should support the following operations: next and hasNext.

// The given compressed string will be in the form of each letter followed by a positive integer representing the number of this letter existing in the original uncompressed string.

// next() - if the original string still has uncompressed characters, return the next letter; Otherwise return a white space.
// hasNext() - Judge whether there is any letter needs to be uncompressed.

// Note:
// Please remember to RESET your class variables declared in StringIterator, as static/class variables are persisted across multiple test cases. Please see here for more details.

// Example:

// StringIterator iterator = new StringIterator("L1e2t1C1o1d1e1");

// iterator.next(); // return 'L'
// iterator.next(); // return 'e'
// iterator.next(); // return 'e'
// iterator.next(); // return 't'
// iterator.next(); // return 'C'
// iterator.next(); // return 'o'
// iterator.next(); // return 'd'
// iterator.hasNext(); // return true
// iterator.next(); // return 'e'
// iterator.hasNext(); // return false
// iterator.next(); // return ' '

class StringIterator {
    queue<pair<char, size_t>> m;
public:
    StringIterator(string compressedString) {
        stringstream ss(compressedString);
        char c; 
        size_t n;
        while (ss >> c >> n) m.emplace(c, n);
    }
    
    char next() {
        if (m.empty()) return ' ';
        char ret = m.front().first;
        --m.front().second;
        while (m.size() && !m.front().second) m.pop();
        return ret;
    }
    
    bool hasNext() {
        return m.size();
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */

class StringIterator {
public:
    StringIterator(string cs) : cs(cs), i(0), rep(0), ch(' ') { }

    char next() {
        if (rep > 0) {
            rep--;
            return ch;
        }
        else if (i < cs.size()) {
            ch = cs[i];
            int j = i + 1;
            while (j < cs.size() && isdigit(cs[j])) { j++; }
            string num = cs.substr(i + 1, j - 1 - i);
            rep = atoi(num.c_str()) - 1;
            i = j;
            return ch;
        }
        else {
            return ' ';
        }
    }

    bool hasNext() {
        return rep > 0 || i < cs.size();
    }

private:
    string cs;
    int i;
    long rep;
    char ch;
};