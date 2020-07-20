// 时间复杂度：O(nlogn)
int binary_search(vector<int>& arr, int start, int end, const int key) {
	int ret = -1;  // 未搜索到数据返回-1下标
	while (start <= end)
	{
		const int mid = start + (end - start) / 2;
		if (arr[mid] < key)
			start = mid + 1;
		else if (arr[mid] > key)
			end = mid - 1;
		else
		{
			ret = mid;
			break;
		}
	}
	return ret;
}

vector<int> twoSum(vector<int>& numbers, int target)
{
	vector<int> res;
	for (size_t i = 0; i < numbers.size(); i++)
	{
		int right = binary_search(numbers, i + 1, numbers.size() - 1, target - numbers[i]);
		if (right != -1)
		{
			res.push_back(i + 1);
			res.push_back(right + 1);
		}
	}
	return res;
}
