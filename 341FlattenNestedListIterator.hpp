// 341. Flatten Nested List Iterator
// Given a nested list of integers, implement an iterator to flatten it.
// Each element is either an integer, or a list -- whose elements may also be integers or other lists.
// Example 1:
// Given the list [[1,1],2,[1,1]],
// By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
// Example 2:
// Given the list [1,[4,[6]]],
// By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        auto itCur = nestedList.begin();
        auto itEnd = nestedList.end();
        itStack.push(make_pair(itCur, itEnd));
    }

    int next() {
        auto &curIterPair = itStack.top();
        return (*curIterPair.first++).getInteger();
    }

    bool hasNext() {
        while (!itStack.empty()) {
            while (itStack.top().first != itStack.top().second) {
                if ((*itStack.top().first).isInteger()) {
                    return true;
                }
                else {
                    auto itCur = (*itStack.top().first).getList().begin();
                    auto itEnd = (*itStack.top().first).getList().end();
                    ++itStack.top().first;
                    itStack.push(make_pair(itCur, itEnd));
                }
            }
            itStack.pop();
        }
        return false;
    }
private:
    stack<pair<vector<NestedInteger>::const_iterator, vector<NestedInteger>::const_iterator>> itStack;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

 class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }

    int next() {
        hasNext();
        return (begins.top()++)->getInteger();
    }

    bool hasNext() {
        while (begins.size()) {
            if (begins.top() == ends.top()) {
                begins.pop();
                ends.pop();
            } else {
                auto x = begins.top();
                if (x->isInteger())
                    return true;
                begins.top()++;
                begins.push(x->getList().begin());
                ends.push(x->getList().end());
            }
        }
        return false;
    }

private:
    stack<vector<NestedInteger>::iterator> begins, ends;
};