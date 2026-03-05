class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        
       int n = nums1.size();
       map<int, int> mp1, mp2;
       int cnt1 = 0, cnt2 = 0;
        
       for(int it: nums1) ++mp1[it];
       for(int it: nums2) ++mp2[it];
        
        //delete duplicate elements having cnt greater than 1 in nums1
        for(int i = 0; i < n; ++i) {
            if(nums1[i] == -1 || mp1[nums1[i]] == 0) continue;
            if(cnt1 == n / 2) break;
            if(mp1[nums1[i]] > 1) {--mp1[nums1[i]]; ++cnt1; nums1[i] = -1;}
        }
        
        //delete duplicate elements having cnt greater than 1 in nums2
        for(int i = 0; i < n; ++i) {
            if(nums2[i] == -1 || mp2[nums2[i]] == 0) continue;
            if(cnt2 == n / 2) break;
            if(mp2[nums2[i]] > 1) {--mp2[nums2[i]]; ++cnt2; nums2[i] = 1;}
        }
        
        // delete elements in nums1 which are present in nums2
        for(int i = 0; i < n; ++i) {
            if(mp1[nums1[i]] == 0 || nums1[i] == -1) continue;
            if(cnt1 == n / 2) break;
            if(mp2[nums1[i]] > 0) {--mp1[nums1[i]]; ++cnt1; nums1[i] = -1;}
        }
        
        //delete elements in nums2 which are present in nums1
        for(int i = 0; i < n; ++i) {
            if(mp2[nums2[i]] == 0 || nums2[i] == -1) continue;
            if(cnt2  == n / 2) break;
            if(mp1[nums2[i]] > 0) {--mp2[nums2[i]]; ++cnt2; nums2[i] = -1;}
        }
    
        
        set<int> st;
        
        //insert elements into set
        for(int i = 0; i < n; ++i) {
            if(nums1[i] != -1 && mp1[nums1[i]] > 0) st.insert(nums1[i]);
            if(nums2[i] != -1 && mp2[nums2[i]] > 0) st.insert(nums2[i]);
        }
        
        // check how many elements remaining to be removed
        int remain = n - (cnt1 + cnt2);
        
        //remove those elements from the set
        return st.size() - remain;
    }
};