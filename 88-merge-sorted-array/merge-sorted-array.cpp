class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;       // nums1 ke valid last element
        int j = n - 1;       // nums2 ka last element
        int k = m + n - 1;   // nums1 ke last position (total size)

        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // agar nums2 me elements bache hain
        while(j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

/*
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6], n = 3
i = m-1 = 2 (nums1 ka last valid index → 3)

j = n-1 = 2 (nums2 ka last index → 6)

k = m+n-1 = 5 (nums1 ka last index, jaha fill karna hai)
Compare nums1[i] = 3 and nums2[j] = 6

6 bada hai → nums1[k] = 6
nums1 = [1,2,3,0,0,6]
j-- → 1, k-- → 4
Compare nums1[i] = 3 and nums2[j] = 5

5 bada hai → nums1[k] = 5
nums1 = [1,2,3,0,5,6]
j-- → 0, k-- → 3
*/