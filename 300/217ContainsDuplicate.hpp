// 217 Contains Duplicate 
// Given an array of integers, find if the array contains any duplicates. Your function should return true if any value
// appears at least twice in the array, and it should return false if every element is distinct.

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto n : nums){
            if(s.count(n)) return true;
            s.insert(n);
        }
        return false;
    }
};

// this solution process the whole input, slower.
class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
        return set<int>(nums.begin(), nums.end()).size() < nums.size();
    }
};


// C solution with in house hashSet
struct Node
{
    int val;
    struct Node *next;
};

struct Set
{
    int bucketSize;
    struct Node **table;
};

void initSet(struct Set *set, int bucketSize)
{
    set->bucketSize = bucketSize;
    set->table = malloc(sizeof(struct Node*) * bucketSize);
    memset(set->table, 0, sizeof(struct Node*) * bucketSize);
}

bool addValue(struct Set *s, int val)
{
    int idx = val > 0 ? val : -val;
    idx %= s->bucketSize;
    struct Node *ptr = s->table[idx];
    while(ptr != NULL)
    {
        if(ptr->val == val)
        {
            return false;
        }

        ptr = ptr->next;
    }
    ptr = malloc(sizeof(struct Node));
    ptr->val = val;
    ptr->next = s->table[idx];
    s->table[idx] = ptr;
    return true;
}
void releaseSet(struct Set *s)
{
    struct Node *ptr, *tmp;
    for(int i = 0; i < s->bucketSize; ++i)
    {
        ptr = s->table[i];
        while(ptr != NULL)
        {
            tmp = ptr;
            ptr = ptr->next;
            free(tmp);
        }
    }
    free(s->table);
    s->table = NULL;
    s->bucketSize = 0;
}
bool containsDuplicate(int* nums, int numsSize) {
    if(numsSize < 2)
    {
        return false;
    }
    struct Set set;
    initSet(&set, numsSize / 2);
    for(int i = 0; i < numsSize; ++i)
    {
        if(!addValue(&set, nums[i]))
        {
            releaseSet(&set);
            return true;
        }
    }
    releaseSet(&set);
    return false;
}