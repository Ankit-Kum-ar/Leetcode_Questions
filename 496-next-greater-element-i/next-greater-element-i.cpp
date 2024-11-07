class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;
        st.push(nums2[nums2.size() - 1]);
        mp[nums2[nums2.size() - 1]] = -1;
        for(int i=nums2.size() - 2;i>=0;i--) {
            while(st.size() > 0 and nums2[i] >= st.top()) st.pop();

            if(st.size() == 0) mp[nums2[i]] = -1;
            else mp[nums2[i]] = st.top();

            st.push(nums2[i]);

        }

        int n = nums1.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++) {
            if(mp.find(nums1[i]) != mp.end()) {
                ans[i] = mp[nums1[i]];
            }
        }        

        return ans;
    }
};