//</code
/** \brief 归并排序相关类
 *
 * \param int merge(int arr[],int helpArr[], int startIndex, int midIndex,int endIndex);
 * \param int mergeSort(int arr[],int helpArr[], int startIndex, int endIndex);
 * \return
 *
 */
#include<iostream>
#include<vector>
using namespace std;
class sort_merger{
public:
    void merge(vector<int>& arr,vector<int>& helpArr, int startIndex, int midIndex,int endIndex);
    void mergeSort(vector<int>& arr,vector<int>& helpArr, int startIndex, int endIndex);

};
void sort_merger::merge(vector<int>& arr,vector<int>& helpArr, int startIndex, int midIndex,int endIndex)
{

    int L = startIndex, R = midIndex + 1, i = startIndex;
    int res=0;
    while (L <= midIndex && R <= endIndex ) { //只要没有指针没越界就逐次比较
        res += arr[L] < arr[R] ? arr[L] * (endIndex - R + 1) : 0;
        helpArr[i++] = arr[L] < arr[R] ? arr[L++] : arr[R++];
    }
    while (L != midIndex + 1) {
        helpArr[i++] = arr[L++];
    }
    while (R != endIndex + 1) {
        helpArr[i++] = arr[R++];
    }
    for (i = startIndex; i <= endIndex; i++) {
        arr[i] = helpArr[i];
    }

}
void sort_merger::mergeSort(vector<int>& arr,vector<int>& helpArr, int startIndex, int endIndex)
{
    int midIndex;
    if (startIndex < endIndex) {  //当子序列只含一个元素时，不再进行此子过程
        midIndex = startIndex + ((endIndex - startIndex) >> 1);       //找到中间的位置
               mergeSort(arr, helpArr, startIndex, midIndex) ;        //对左半部分排序
               mergeSort(arr, helpArr, midIndex + 1, endIndex) ;     //对右半部分排序
               merge(arr, helpArr, startIndex, midIndex, endIndex);  //使整体有序
    }

}
int main()
{
    sort_merger obj;
    vector<int> nums = {5,7,6,3,2,1,11,13,4};
    vector<int> helpnums(nums.size()); //要初始化
    obj.mergeSort(nums,helpnums,0,nums.size()-1);
    for(int i = 0; i < nums.size() ; i++)
        cout<<" "<<nums[i] ;
    return 0;
}
