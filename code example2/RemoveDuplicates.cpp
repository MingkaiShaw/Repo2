#include<iostream>

class Solution
{
    public:
        int removeDuplicates(&num[]);
        void print();
        int length;
       
        
};

int Solution::removeDuplicates(int *nums[])
    {
        int i,j;
        j = 0;
        for(i =0;i<15;i++)
        {
            if(nums[j] != nums[i])
            {
                nums[j++] = nums[i];
            }
        }
        return j;
    }

void Solution::print()
{
    std::cout <<"新数组长度为" << length <<"\n\n";
    std::cout <<"[";
    for(int i=0 ;i<length-1;i++)
    {
      std::cout <<  num[i] <<",";
    }
    std::cout << num[length-1] <<"]\n\n";
}

int main()
{
    Solution solution;
    int num[15] = {2,2,2,3,3,3,4,4,4,4,5,5,5,5,5};
    solution.length =solution.removeDuplicates(num);
    solution.print();

    return 0;
}

