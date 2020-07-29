#include<iostream>
#include<vector>
using namespace std;

class insert_Sort{
public:
    void sort_insert(vector<int>& nums);
};
void insert_Sort::sort_insert(vector<int>& nums)
{
    int n = nums.size();
    int j;
    for(int i = 1; i < n; i++)
    {
        int temp = nums[i];
        for(j = i - 1; j >= 0; j--)  //找到插入的空
        {
            if(temp < nums[j]) //往前走
                nums[j + 1] = nums[j];
            else break;
        }
        nums[j + 1] = temp;  //找到了，插入

    }
}

void Test()
{
    insert_Sort obj;
    vector<int> nums = {5,4,6,7,3,2,8};
    for(auto item : nums)
        cout<<item;
    cout<<endl;
    obj.sort_insert(nums);
    for(auto item : nums)
        cout<<item;
}
int main()
{
    Test();
    return 0;
}
