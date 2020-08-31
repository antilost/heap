using namespace std;

#include <vector>
#include <iostream>

vector<int> combine(const vector<int>& a, const vector<int>& b) {
    vector<int> res;

    int iA, iB;
    iA = iB = 0;
    while ( iA < a.length() && iB < b.length() )
    {
        if (a[iA] == b[iB]) {
            res.push
        }
    }



}


main()
{
    vector<int> v1() {  2,   3,5,7};
    vector<int> v2() {1,2,   2,5};
    vector<int> v3() {2,5};
    
    assert( combine(v1, v2) ==  v3);
    cout << "Done" << endl;
}