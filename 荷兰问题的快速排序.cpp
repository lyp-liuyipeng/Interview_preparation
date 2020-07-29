/** \brief 关于荷兰国旗问题实现的快排
 *
 * \param 比较一下经典排序和使用荷兰国旗问题改进后的经典排序，
 *        不难发现，后者一次partition能去除一个以上的元素（等于arr[endIndex]的区域），
          而前者每次partition只能去除一个元素，这里的去除相当于安排（排序）好了对应元素的位置。
          因此后者比经典排序更优，但是优化不大，只是常数时间内的优化，实质上的效率还是要看数据状况
          （最后的情况为O(nlogn)，最坏的情况为O(n^2)）。
 * \param
 *
 */
#include<iostream>
#include<vector>
using namespace std;

class sort_imporve_classical_quick{
public:
    vector<int> imporve_partition(vector<int>&arr,int pos_begin,int pos_end);
    void imporve_sortquick(vector<int>&arr,int pos_begin,int pos_end);
};

vector<int> sort_imporve_classical_quick::imporve_partition(vector<int>& arr,int pos_begin,int pos_end)
{
    vector<int> range(2,0);
    int small = pos_begin-1 , great = pos_end+1;
    int i = pos_begin;
    while(i <= pos_end -1 )
    {
        if(arr[i]<arr[pos_end])
        {
            std::swap(arr[++small],arr[i++]);
        }

        else if (arr[i]>arr[pos_end]) std::swap(arr[--great],arr[i]);
        else i++;
    }
    for(auto item : arr) cout<<" " << item <<" ";
            cout<<endl;
    cout<<endl<< small << " "<< great<<endl;
    range[0] = small;
    range[1] = great;
    return range;
}
void sort_imporve_classical_quick::imporve_sortquick(vector<int>&arr,int pos_begin,int pos_end)
{
   // std::cout<<std::endl<<"--荷兰国旗问题改进过的经典快排-"<<std::endl;
    if(pos_begin > pos_end) return ;
    vector<int>range = imporve_partition(arr,pos_begin,pos_end);
    imporve_sortquick(arr,pos_begin,range[0]);
    imporve_sortquick(arr,range[1],pos_end);
}

int main()
{
    sort_imporve_classical_quick obj;
    vector<int> nums = {5,7,6,3,2,1,11,4};
    obj.imporve_sortquick(nums,0,nums.size()-1);
    for(int i = 0; i < nums.size() ; i++)
        cout<<" "<<nums[i] ;
    return 0;
}
