/**<
Problem:
　　生成窗口最大值数组
　　【题目】
　　　　有一个整型数组arr和一个大小为w的窗口从数组的最左边滑到最右边，窗口每次向右边滑一个位置。
　　　　例如，数组为[4, 3, 5, 4, 3, 3, 6, 7]，窗口大小为3时：
　　　　[4 3 5] 4 3 3 6 7 窗口中最大值为5
　　　　4[3 5 4] 3 3 6 7 窗口中最大值为5
　　　　4 3[5 4 3] 3 6 7 窗口中最大值为5
　　　　4 3 5[4 3 3] 6 7 窗口中最大值为4
　　　　4 3 5 4[3 3 6] 7 窗口中最大值为6
　　　　4 3 5 4 3[3 6 7] 窗口中最大值为7
　　　　如果数组长度为n，窗口大小为w，则一共产生n - w + 1个窗口的最大值。
　　　　请实现一个函数。
　　　　输入：整型数组arr，窗口大小为w。
　　　　输出：一个长度为n - w + 1的数组res，res[i]表示每一种窗口状态下的最大值。
　　　　以本题为例，结果应该返回{ 5,5,5,4,6,7 }。
Solution:
　　使用左右指针L, R，
　　R移一步，一个数进入窗口，L向右移动一步，一个数出窗口
　　L, R只能向右移动，且R > L
【求一个窗口的实时最大值】
　　　使用双向链表，或双向队进行存储
　　　R移动：
　　　　保证对列中从左向右维持为从大到小的排序，那么头数永远为最大
　　　　每进一个数从尾部压入，一旦发现新的数比队列的末尾数大，即一旦压入进去，
　　　　则打破了从大到小的顺序，故需要将队列末尾的数弹出，压入的新数比队列末尾的数小，则入栈，否则一直从末尾弹出。
　　　　切记，每次从尾部压入的数都必须记住其在原数组中的下标值。
　　　　故双向队列中存数据在数组中的下标值就行，不用真的存实际的值，因为可以根据下角标找值。
　　　L移动：
　　　　每一次L，就验证出窗口的数是不是队列的头，即队列头的数的下角标是不是原数组的下角标，是的话从头部弹出，否则L继续移
*/
#pragma
#include<iostream>
#include<vector>
#include<deque>

using namespace std;

vector<int> getWindowsMax(const vector<int> arr,const int w) //w表示窗口大小
{
    if(w <= 0 || w > arr.size()) //窗口小于等于0，或者大于数组长度
        return {-1};
    vector<int> res_max;
    deque <int> index;   //双端队列存储的是数组的下标
    for(int L = 0, R = 0; R < arr.size(); ++R)
    {
        index.push_back(R);
        if(R - L >= w)  //窗口滑动
        {
            if(L == index[0]  ) //对头的数组小标数等于左边界
                index.pop_front();
            ++L;//继续右移
        }
        while(!index.empty() && arr[index.back()] <= arr[R])  //队不空且新的数比队尾的数大
            index.pop_back();  //队尾出来
        index.push_back(R);  //新下标数进
        if(R - L == w - 1)  //形成一个窗口
            res_max.push_back(arr[index.front()]);

    }
        return res_max;

}
void Test()
{
    vector<int>v;
    v = {4,3,5,4,3,3,6,7};
    vector<int> vs;
    vs = getWindowsMax(v,3);
    int i = 0;
    for(auto a : vs)
    {

        cout<<"第"<<++i<<"个窗口大小是:"<<a<<endl;
    }
    cout<<endl;
}
int main()
{
    Test();
    return 0;
}

















