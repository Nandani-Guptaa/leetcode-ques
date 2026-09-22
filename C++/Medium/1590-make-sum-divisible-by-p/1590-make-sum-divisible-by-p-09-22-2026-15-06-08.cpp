// class Solution {
// public:
//     int minSubarray(vector<int>& nums, int p) {
//         int sum = 0;
//         for(int x : nums){
//             sum += x;

//            int rem = sum %p;

//             if(rem == 0){
//                 return sum;
//             }            
//         }
//         unordered_map<int, int> mp;

        
//         mp[0] = -1;

//         long long prefix = 0;
//         int ans = nums.size();
//         int rem = 0;

//         for(int i = 0; i  <nums.size()-1; i ++) {
//            prefix = (prefix + nums[i]) % p;
//            int needed = (prefix - rem + p)%p;

//             if(mp.find(needed) != mp.end()){
//                 int j = mp[needed];

//              int ans = min(ans,i-j);
//             }
//             mp[prefix] = i;

//             if(prefix == nums.size()){
//                 return -1;
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;

        for (int x : nums) {
            total += x;
        }

        int rem = total % p;

        // Total sum is already divisible by p
        if (rem == 0) {
            return 0;
        }

        unordered_map<int, int> mp;

        // Prefix sum 0 exists before the array starts
        mp[0] = -1;

        long long prefix = 0;
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) {

            prefix = (prefix + nums[i]) % p;

            int needed = (prefix - rem + p) % p;

            if (mp.find(needed) != mp.end()) {
                int j = mp[needed];

                ans = min(ans, i - j);
            }

            // Store the latest index
            mp[prefix] = i;
        }

        // Cannot remove the entire array
        if (ans == nums.size()) {
            return -1;
        }

        return ans;
    }
};