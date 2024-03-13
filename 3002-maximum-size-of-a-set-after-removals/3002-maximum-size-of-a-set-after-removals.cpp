class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s1,s2,combined;
        int n = nums1.size();
        for(auto it : nums1) s1.insert(it);
        for(auto it : nums2) s2.insert(it);
        for(auto it : s1) combined.insert(it);
        for(auto it : s2) combined.insert(it);
        int a,b; 
      
        if(s1.size()< n/2) a = s1.size(); 
        else a = n/2;                     
        
        if(s2.size() < n/2) b = s2.size();
        else b = n/2;
        int combined_size = combined.size();
     
        return min(combined_size,a+b); 
       
    }
};