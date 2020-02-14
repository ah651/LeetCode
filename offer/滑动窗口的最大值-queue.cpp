class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        //list / priority-queue
        vector<int> result;
        if (num.size() < size || size == 0) {
            return result;
        }
        //use a list to store idx is ok
        list<int> l;
        for (int i = 0; i < size-1; i++) {
            while (!l.empty() && num[*(l.rbegin())] <= num[i]) {
                l.pop_back();
            }
            l.push_back(i);
        }
        for (int i = size-1; i < num.size(); i++) {
            while (!l.empty() && num[*(l.rbegin())] <= num[i]) {
                l.pop_back();
            }
            l.push_back(i);
            if ((i - l.front()) >= size) {
                l.pop_front();
            }
            result.push_back(num[l.front()]);
        }
        return result;
    }
};