#include<iostream>
#include<vector>
using namespace std;
class Sort{
public:
    void classical_quick_sort_quick_slow_index(vector<int>& nums,int left,int right);//经典快速排序，快慢指针法
    int classical_quick_sort_quick_slow_index_partition(vector<int>& nums, int left, int right);//快慢指针法partition

    void classical_quick_sort_left_right_index(vector<int>& nums,int left,int right);//经典快速排序，左右指针法
    int classical_quick_sort_left_right_index_partition(vector<int>& nums, int left, int right);//左右指针法partition
};

int Sort::classical_quick_sort_quick_slow_index_partition(vector<int>& nums, int left, int right)//快慢指针法partition
{

    int slow_index = left - 1;  //慢指针
    int quick_index = left ; //快指针
    int pivot = nums[right];    //基准，把小于基准的放左边，大于基准的放右边
    while(quick_index < right)
    {
        if(nums[quick_index] < pivot && ++slow_index != quick_index)  //当快指针的nums值小于基准，进行交换，如果是快慢指向同一个就不交换
              swap(nums[quick_index], nums[slow_index]);  //慢指针的值进行交换，
        ++quick_index;
    }
    cout<<endl << pivot<< "   "<<nums[right]<<endl;
    swap(nums[++slow_index], nums[right]); //最后将基准放到中心位置，也就是说，慢指针所指的都是小于基准pivot的
    // ！！！！！！！！！！！！！！！！！！这里不是和 pivot 交换！！！！！！
    return slow_index;
}
void Sort::classical_quick_sort_quick_slow_index(vector<int>& nums,int left,int right)//经典快速排序，快慢指针法
{
    if(left >= right)  return;
    int pivot_index = classical_quick_sort_quick_slow_index_partition(nums,left,right);
    classical_quick_sort_quick_slow_index(nums,left,pivot_index-1);//左部分
    classical_quick_sort_quick_slow_index(nums,pivot_index+1,right);//右部分

}


int Sort::classical_quick_sort_left_right_index_partition(vector<int>& nums, int left, int right)//左右指针法partition
{

    int pivot = nums[left];
    int left_index = left;
    int right_index = right;
    while(left_index < right_index)
    {
        if(nums[right_index] >= pivot)
        {
            right_index--;
            continue;
        }
        if(nums[left_index] <= pivot)
        {
            left_index++;
            continue;
        }
        swap(nums[left_index], nums[right_index]);
    }
    swap(nums[left_index],nums[left]);
    return left_index;
}

void Sort::classical_quick_sort_left_right_index(vector<int>&nums, int left, int right)
{
    if(left >= right) return;
    int pivot_index = classical_quick_sort_left_right_index_partition(nums,left,right);
    classical_quick_sort_left_right_index_partition(nums,left,pivot_index-1);
    classical_quick_sort_left_right_index_partition(nums,pivot_index+1,right);


}
/** \brief 经典快速排序
 *
 * \param
 * \param
 * \return
 *
 */
 /*
 class sort_classical_quick{
 public:
     int partition(int arr[], int pos_begin,int pos_end);
     void quickSort(int arr[],int pos_begin,int pos_end);
 };
int sort_classical_quick::partition(int arr[],int pos_begin,int pos_end)
{

    int small=pos_begin-1;  //small就是慢指针， i就是快指针
    for(int i = pos_begin;i < pos_end; i++)
    {
       if(arr[i] < arr[pos_end])   //这里的pos_end就相当于pivot基准
       {

           if(small+1 != i)
             std::swap(arr[++small],arr[i]);

           else small++;
       }

    }
    cout<<endl<<"arr[pos_end]"<<arr[pos_end]<<endl;
    std::swap(arr[++small],arr[pos_end]);
    return small;
}
void  sort_classical_quick::quickSort(int arr[],int pos_begin,int pos_end)
{

    if(pos_begin > pos_end) return;
    int index = partition(arr,pos_begin,pos_end);
    partition(arr,pos_begin,index-1);
    partition(arr,index+1,pos_end);

}
*/
void Test()
{
   /* class sort_classical_quick obj;
    int arr[] = {9, 1, 3, 4, 7, 6, 5,10};
    int num_arr = sizeof(arr)/sizeof(arr[0]);  //获得数组大小
    cout<<"数组长度"<<num_arr<<endl;
    for(int i = 0; i < num_arr; i++)
    {
        cout<<arr[i] <<" ";
    }
    cout<<endl;
    obj.quickSort(arr,0,num_arr-1);
    for(int i = 0; i < num_arr; i++)
    {
        cout<<arr[i] <<" ";
    }

   */
    class Sort obj1;
    vector<int> nums = {5,8,4,3,7,6};
    vector<int> nums2 = {5,8,4,3,7,6};
    cout<<endl<<"-----------快慢-----------"<<endl;

    for(auto item : nums)
    {
        cout<<" "<<item;
    }
    cout<<endl;

    obj1.classical_quick_sort_quick_slow_index(nums,0,nums.size()-1);
    for(auto item : nums)
    {
        cout<<" "<<item;
    }
    cout<<endl<<"-----------左右-----------"<<endl;
     for(auto item : nums2)
    {
        cout<<" "<<item;
    }
    cout<<endl;

    obj1.classical_quick_sort_left_right_index(nums2,0,nums2.size()-1);
     for(auto item : nums2)
    {
        cout<<" "<<item;
    }
    cout<<endl;
}
int main()
{
    Test();
    return 0;
}
