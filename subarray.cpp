class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int len = nums.size();// calculating the length of the array
         // firstly wew ill create a prefix array
         vector<int>prefixar(len);
        prefixar[0]=nums[0]; // in order to create a prefix array we store the first elment of prefix array with nums first eleemnt
        // nums[]=[23(0),2(1),4(2),6(3),7(4)]
        // prefix sum[]=[23(0),25(1),29(2),35(3),42(4)]
        // since the first index already know so starting the loop from first ele
        for(int i=1;i<len;i++)
        { 
            // means in order to calculate the sum of prefix array .. so prefix[1]=prefix[1-1]+nums[1]=25... an everytime the value of the i will be incrementing
            prefixar[i]=prefixar[i-1]+nums[i];
        }
        //now we will find whether its multiple of k or not
        // so prefix array%k
        for(int i=0;i<len;i++) // iterating through the loop
        {
            prefixar[i]=prefixar[i]%k; // % by k  to check the divisibility
        }
        // now we will create a map to store the % k values
        map<int,int>kk; // map 
        kk[0]=-1; // (0,-1).. ..for not considering 0
        // now the loop to iterate over the elements
        for(int i=0;i<len;i++)
        {
            if(kk.find(prefixar[i])!=kk.end())  // if the the element is present in the map
            {
                int index = kk[prefixar[i]]; // storing the index of prefix array
                int diff_twoindex= i-index; // calculating the difference between the two indexes ..to check the length 
                if(diff_twoindex>=2) // here we are checking for those elements whpose lenghth is 2..if so yes we will return true since satisfying all the required conditions
                {
                    return true; // will return true satisfing all condition of good subarray
                }
            }
            else
            {
                kk[prefixar[i]]=i; // if it is not present we will insert it in the map
            }
        }
        return false; // in the other cases
        
    }
};
