// 251 Flatten 2D Vector

// Implement an iterator to flatten a 2d vector.

// For example,
// Given 2d vector =

// [
//   [1,2],
//   [3],
//   [4,5,6]
// ]
// By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].

// Hint:

// How many variables do you need to keep track?
// Two variables is all you need. Try with x and y.
// Beware of empty rows. It could be the first few rows.
// To write correct code, think about the invariant to maintain. What is it?
// The invariant is x and y must always point to a valid point in the 2d vector. Should you maintain your invariant ahead of time or right when you need it?
// Not sure? Think about how you would implement hasNext(). Which is more complex?
// Common logic in two different places should be refactored into a common method.



/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */


class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        rowIt = vec2d.begin(); rowEndIt = vec2d.end();
        if (rowIt != vec2d.end()) colIt = rowIt->begin();
    }

    int next() {
        if (hasNext())
            return *colIt++;
        else return -1;
    }

    bool hasNext() {
        while (rowIt != rowEndIt && colIt == rowIt->end())
        {
            ++rowIt;
            if (rowIt != rowEndIt) colIt = rowIt->begin();
        }
        return rowIt != rowEndIt;
    }

private:
    vector<vector<int>>::iterator rowIt;
    vector<vector<int>>::iterator rowEndIt;
    vector<int>::iterator colIt;
};

class Vector2D {
    vector<vector<int>>::iterator i, iEnd;
    int j = 0;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        i = vec2d.begin();
        iEnd = vec2d.end();
    }

    int next() {
        hasNext();
        return (*i)[j++];
    }

    bool hasNext() {
        while (i != iEnd && j == (*i).size())
            i++, j = 0;
        return i != iEnd;
    }
};