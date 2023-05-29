class KthLargest {
public:
    int k2;
    priority_queue<int,vector<int>,greater<int>>all;
    KthLargest(int k, vector<int>& nums) {
        k2=k;
        for(int i=0;i<nums.size();i++)
        {
            all.push(nums[i]);
            if(all.size()>k2)all.pop();
        }
    }

    int add(int val) {
        all.push(val);
        if(all.size()>k2)all.pop();
        return all.top();
    }
};
