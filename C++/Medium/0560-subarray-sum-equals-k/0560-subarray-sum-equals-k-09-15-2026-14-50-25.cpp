// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int count =0;
//         int n = nums.size();
        
//         for (int i= 0;i<=n-1;i++){
//             for(int j =i;j<=n-1;j++){
//                 int sum = 0;
//                 for(int k=i;k<=j;k++){
//                     sum = sum+nums[k];
//                     if(sum==k)
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int sum = 0;

            for (int j = i; j < n; j++) {
                sum += nums[j];

                if (sum == k) {
                    count++;
                }
            }
        }

        return count;
    }
};