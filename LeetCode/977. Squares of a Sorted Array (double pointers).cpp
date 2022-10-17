vector<int> Solution::sortedSquares(vector<int>& nums)
{
    vector<int> res(nums.size(), 0); //这里要初始化一下，不然如果nums全为0的话会被卡
    int k = nums.size() - 1;
    for (int i = 0, j = nums.size() - 1; i <= j;)
    {
        if (nums[i] * nums[i] < nums[j] * nums[j])
        {
            res[k--] = nums[j] * nums[j];
            j--;
        }
        else
        {
            res[k--] = nums[i] * nums[i];
            i++;
        }
    }
    return res;
}
