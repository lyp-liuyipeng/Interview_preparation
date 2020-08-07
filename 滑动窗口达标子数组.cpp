/**< 求达标的子数组个数
给你一个整型数组，判断其所有子数组中最大值和最小值的差值不超过num（如果满足则称该数组达标）的个数。
（子数组指原数组中任意个连续下标上的元素组成的数组）

暴力解：遍历每个元素，再遍历以当前元素为首的所有子数组，再遍历子数组找到其中的最大值和最小值以判断
其是否达标。很显然这种方法的时间复杂度为o(N^3)，但如果使用最大值更新结构，则能实现O(N)级别的解。

如果使用L和R两个指针指向数组的两个下标，且L在R的左边。当L~R这一子数组达标时，可以推导出以L开头的长度
不超过R-L+1的所有子数组都达标；当L~R这一子数组不达标时，无论L向左扩多少个位置或者R向右扩多少个位置，
L~R还是不达标。

O(N)的解对应的算法是：L和R都从0开始，R先向右移动，R每右移一个位置就使用最大值更新结构和最小值更新结构
记录一下L~R之间的最大值和最小值的下标，当R移动到如果再右移一个位置L~R就不达标了时停止，这时以当前L开头
的长度不超过R-L+1的子数组都达标；然后L右移一个位置，同时更新一下最大值、最小值更新结构（L-1下标过期了），
再右移R至R如果右移一个位置L~R就不达标了停止（每右移R一次也更新最大、小值更新结构）……；直到L到达数组尾元素
为止。将每次R停止时，R-L+1的数量累加起来就是O(N)的解，因为L和R都只向右移动，并且每次R停止时，以L开头的达标
子串的数量直接通过R-L+1计算，所以时间复杂度就是将数组遍历了一遍即O(N)。
*/

/**< 用到滑动窗口最大值最小值更新 */
#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int getNum_ok_subArr(vector<int> arr, int num)
{
    deque<int> max_num;//存储最大值
    deque<int> min_num;//存储最小值
    max_num.push_back(0);
    min_num.push_back(0);
    int R = 0;
    int L = 0;
    int res = 0;
    while(L < arr.size())
    {
        while(R < arr.size()-1)
        {
            //更新最大值
            while(!max_num.empty() && arr[max_num.front()] < arr[R+1])
                max_num.pop_back();
            max_num.push_back(R+1);
            //更新最小值
            while(!min_num.empty() && arr[min_num.front()] > arr[R+1])
                min_num.pop_back();
            min_num.push_back(R+1);

            if(max_num.front() - min_num.front() > num)
                break;
            R++;
        }

        res += (R - L + 1);
        if(max_num.front() == L)   //此时左边到界
            max_num.pop_front();
        if(min_num.front() == L)
            min_num.pop_front();

        L++;
    }
    return res;
}
void Test()
{
    vector<int> v;


    v = {1, 2,3,5};
    cout<<getNum_ok_subArr(v,3);//10
}

int main()
{
    Test();
    return 0;
}
