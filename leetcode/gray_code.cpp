// https://leetcode.com/problems/gray-code/

#include <iostream>
#include <vector>
#include <bitset> // https://en.cppreference.com/w/cpp/utility/bitset

/*
n=0
    0
    1

n=1
  1 1
  1 0

n=2
1 0 0
1 0 1
1 1 1
1 1 0

 */





class Solution {
public:
    std::vector<int> grayCode(int n)
    {
        std::vector<int> v;

        // 1 << n => 1, 2, 4, etc.
        for(int i = 0; i < (1 << n); i++)
            v.push_back(i ^ (i >> 1));

        return v;

        //std::vector<int> result;
        //result.push_back(0);
        //if (n == 0)
        //    return result;
        //
        //result.push_back(1);
        //if (n == 1)
        //    return result;
        //
        //for (int i = 2; i <= n; i++)
        //{
        //    int high_bit = 1 << (i - 1);
        //    for (int j = result.size()-1; j >= 0; j--)
        //        result.push_back( high_bit | result[j] );
        //}
        //
        //return result;
    }
};

int main()
{
    Solution s;
    for (int n = 0; n < 4; n++)
    {
        std::vector<int> result;
        result = s.grayCode(n);
        std::cout << "n=" << n << '\n';
        for (int i = 0; i < result.size(); i++)
            std::cout << result[i] << '\n';
    }

    return 0;
}