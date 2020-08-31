/*
 * Взять числа, встречающиеся в обоих векторах целых чисел a, b и составить из них новый вектор.
 * Исходные векторы a, b отсортированы по возрастанию.
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> combine(const vector<int>& a, const vector<int>& b)
{
    vector<int> res;
    if(a.empty() || b.empty())
        return res;
    
    int iA = 0;
    int iB = 0;
    while(iA < a.size() && iB < b.size())
    {
        if(a[iA] == b[iB])
        {
            res.push_back(a[iA]);
            ++iA;
            ++iB;
        }
        else
        {
            if(a[iA] < b[iB])
               ++iA;
            else
                ++iB;
        }
    }
    return res;
}



main()
{
    int v1_size, v2_size;
    vector<int> v1, v2, result;

    cin >> v1_size;
    v1.resize(v1_size);
    for (int i = 0; i < v1.size(); i++)
        cin >> v1[i];
    cin >> v2_size;
    v2.resize(v2_size);
    for (int i = 0; i < v2.size(); i++)
        cin >> v2[i];

    result = combine(v1, v2);
    cout << "result: ";
    for (int n : result)
        cout << n << " ";
    cout << endl;
}
