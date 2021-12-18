#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int removeDuplicates(vector<int> &nums){
        int cnt=0;
        if(nums.size() == 0)
            return 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[cnt] != nums[i]){
                nums[++cnt] = nums[i];            
            }
        }
        return cnt+1;
    }
};

int main(int argc, char const *argv[]){
    //input data
    int ary[] = {1,2,3,3,3,4,4,5,5,6,7,8};
    int amount = sizeof(ary)/sizeof(ary[0]);
    int answer;
    vector<int> data(ary, ary+amount);

    //solution
    Solution s;
    answer = s.removeDuplicates(data);

    cout << "Answer : " << answer << endl;
    cout << "Output : ";
    for(int i=0; i<answer; i++){
        cout << data[i] <<" ";
    }
    cout << endl;
    return 0;
}