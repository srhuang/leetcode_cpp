#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void rotate(vector<int> &nums, int k){
        int temp[nums.size()];
        int pos;
        for(int i=0; i<nums.size(); i++){
            pos = (i+k)%nums.size();
            temp[pos] = nums[i];
        }

        //copy to nums
        for(int i=0; i<nums.size(); i++){
            nums[i] = temp[i];
        }
    }

    void rotate2(vector<int> &nums, int k){
        k %= nums.size();
        //reverse all
        reverse(&nums[0], nums.size());
        reverse(&nums[0], k);
        reverse(&nums[k], nums.size()-k);
    }
private:
    void reverse(int *nums, int n){
        for(int i=0; i<n/2; i++){
            nums[i] ^= nums[n-i-1];
            nums[n-i-1] ^= nums[i];
            nums[i] ^= nums[n-i-1];
        }
    }
};

int main()
{
    int ary[] = {1,2,3,4,5,6,7};
    int amount = sizeof(ary) / sizeof(ary[0]);
    vector<int> data(ary, ary+amount);

    Solution s;
    //s.rotate(data, 3);
    s.rotate2(data, 3);

    cout << "Answer : ";
    for(int i=0; i<amount; i++){
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}