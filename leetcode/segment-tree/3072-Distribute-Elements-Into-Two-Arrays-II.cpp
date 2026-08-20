#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr, brr;
        ordered_set<pair<int, int>> st1, st2;
        arr.push_back(nums[0]), brr.push_back(nums[1]);
        st1.insert({nums[0], 0}), st2.insert({nums[1], 1});
        for(int i = 2; i < n; i++) {
            int a = st1.size() - st1.order_of_key({nums[i] + 1, -1}), b = st2.size() - st2.order_of_key({nums[i] + 1, -1});
            if(a > b) {
                arr.push_back(nums[i]);
                st1.insert({nums[i], i});
            } else if(a < b) {
                brr.push_back(nums[i]);
                st2.insert({nums[i], i});
            } else {
                if(st1.size() > st2.size()) {
                    brr.push_back(nums[i]);
                    st2.insert({nums[i], i});
                } else if(st1.size() < st2.size()) {
                    arr.push_back(nums[i]);
                    st1.insert({nums[i], i});
                } else {
                    arr.push_back(nums[i]);
                    st1.insert({nums[i], i});
                }
            }
        }
        arr.insert(arr.end(), brr.begin(), brr.end());
        return arr;
    }
};