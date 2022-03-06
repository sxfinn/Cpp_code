#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

namespace sx
{
	template<class T>
	class list_node
	{
	public:
		list_node(const T& data = T())
			:
			_data(data),
			_next(nullptr),
			_prev(nullptr)
		{}
		list_node(list_node<T>& l)
			:
			_data(l._data),
			_next(nullptr),
			_prev(nullptr)
		{}
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;
	};
	template<class T>
	class list_iterator
	{
	public:
		typedef list_node<T> node;
		typedef list_iterator<T> self;

		list_iterator(node* pnode = nullptr)
		{
			_pnode = pnode;
		}
		list_iterator(const self& s)
			:
			_pnode(s._pnode)
		{}
		T& operator*()
		{
			return _pnode->_data;
		}
		T* operator->()
		{
			return &(_pnode->_data);
		}
		self& operator++()
		{
			_pnode = _pnode->_next;
			return *this;
		}
		self operator++(int)
		{
			self tmp(*this);
			_pnode = _pnode->_next;
			return tmp;
		}
		self& operator--()
		{
			_pnode = _pnode->_prev;
			return *this;
		}
		self operator--(int)
		{
			self tmp(*this);
			_pnode = _pnode->_prev;
			return tmp;
		}
		bool operator!=(const self& s)const
		{
			return _pnode != s._pnode;
		}
		bool operator==(const self& s)const
		{
			return _pnode == s._pnode;
		}
		node* _pnode;
	};
	template<class T>

	class list
	{
	public:
		typedef list_node<T> node;
		typedef list_iterator<T> iterator;
		list()		
			:
			_head(new node)
		{
			_head->_next = _head;
			_head->_prev = _head;
		}
		list(list<T>& l)
		{

		}
		void push_back(T data)
		{
			node* n = new node(data);
			node* tail = _head->_prev;
			tail->_next = n;
			n->_prev = tail;
			n->_next = _head;
			_head->_prev = n;
		}
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
	private:
		node* _head;

	};
}
void test2()
{
	sx::list<int> l1;
	for (int i = 0; i < 10; i++)
	{
		l1.push_back(i);
	}
	for (auto& e : l1)
	{
		e += 1;
		cout << e << " ";
	}
}
void test1()
{
	sx::list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	sx::list<int>::iterator it = l1.begin();
	for (auto e : l1)
	{
		cout << e << " ";
	}
}
typedef int i;
int main()
{
	
	
	//test1();
	test2();
	return 0;
}
//struct S
//{
//	S(int data)
//		:
//		x(data)
//	{}
//	int x;
//};
//int main()
//{
//	S* data = new S(1);
//	cout << data->x;
//	//test1();
//	return 0;
//}
//class Solution 
//{
//public:
//    int FindGreatestSumOfSubArray(vector<int> array) 
//    {
//        int max = -100;
//        int sum = 0;
//        for (int i = 0; i < array.size(); i++)
//        {
//            if (sum < 0)
//                sum = 0;
//            sum += array[i];
//            if (max < sum)
//                max = sum;
//        }
//        return max;
//    }
//};
//class Solution 
//{
//public:
//    vector<string> letterCombinations(string digits) 
//    {
//        const char* arr[] = { "abc", "def", "ghi", "jkl", "mno","pqrs", "tuv", "wxyz" };
//        vector<string> v1;
//        size_t num = 1;
//        for (auto e : digits)
//        {
//            num *= strlen(arr[e - '0' - 2]);
//        }
//        v1.resize(num);
//        int len = digits.size();
//        
//        
//    }
//};
//出现次数超过一半的的数字
//class Solution
//{
//public:
//    int MoreThanHalfNum_Solution(vector<int> numbers)
//    {
//        int cnt = 1;
//        int cur = numbers[0];
//        for (int i = 1; i < numbers.size(); i++)
//        {
//            if (cnt <= 0)
//                cur = numbers[i];
//            if (cur != numbers[i])
//                cnt--;
//            else
//                cnt++;
//        }
//        return cur;
//    }
//};

//class Solution 
//{
//public:
//    vector<int> singleNumber(vector<int>& nums) 
//    {
//        int orsum = 0;
//        for (auto& e : nums)
//            orsum ^= e;
//        int lowpos = orsum - (orsum & (orsum - 1));
//        int ans1 = 0, ans2 = 0;
//        for (auto& e : nums)
//        {
//            if (lowpos & e)
//                ans1 ^= e;
//            else
//                ans2 ^= e;
//        }
//        nums.resize(2);
//        nums[0] = ans1;
//        nums[1] = ans2;
//        return nums;
//    }
//};
//
//int main()
//{
//    int arr[] = { 1,1,0,-2147483648 };
//    vector<int> v1(arr, arr + 4);
//    Solution().singleNumber(v1);
//    cout << v1[0] << endl << v1[1];
//    return 0;
//}
//只出现一次的数ii

//class Solution 
//{
//public:
//    int singleNumber(vector<int>& nums) 
//    {
//        sort(nums.begin(), nums.end());
//        
//        for (int i = 0; i < nums.size() - 2; i++)
//        {
//            if (nums[i] != nums[i + 1])
//                return nums[i];
//        }
//        return nums[nums.size() - 1];
//    }
//};
//删除重复元素
//class Solution 
//{
//public:
//    int removeDuplicates(vector<int>& nums) 
//    {
//        int cur = 0;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (nums[cur] == nums[i])
//                continue;
//            else
//            {
//                nums[++cur] = nums[i];
//            }
//        }
//        return cur + 1;
//    }
//};

//class Solution 
//{
//public:
//	vector<vector<int>> generate(int numRows)
//	{
//		vector<vector<int>> ret;
//		ret.resize(numRows);
//		for (int i = 0; i < numRows; ++i)
//		{
//			ret[i].resize(i + 1);
//		}
//		for (int i = 0; i < numRows; ++i)
//		{
//			for (int j = 0; j <= i; ++j)
//			{
//				if (j == 0 || i == j)
//					ret[i][j] = 1;
//				else
//					ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
//			}
//		}
//		return ret;
//	}
//};
//int main()
//{
//	vector<vector<int>> ret = Solution().generate(3);
//	for (auto e1 : ret)
//	{
//		for (auto e2 : e1)
//		{
//			cout << e2 << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}
//class Solution
//{
//public:
//	int singleNumber(vector<int>&nums) 
//	{
//		int orsum = 0;
//		for (auto& e : nums)
//		{
//			orsum ^= e;
//		}
//		return orsum;
//	}
//};
//使用迭代器初始化就是将迭代器所指向的内容，一个一个pushback到对象中
//template<class T>
//void print(T& l)
//{
//	for (auto e : l)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//void test1()
//{
//	int arr[4] = { 1,2,3,4 };
//	vector<int> l1(arr , arr + 4);
//	print(l1);
//	//cout << &l1[0] << endl << &l1[1];
//}
//
//int main()
//{
//	test1();
//	return 0;
//}