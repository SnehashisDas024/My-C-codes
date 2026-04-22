#include <iostream>
#include <vector>
using namespace std;
int count = 0;
void merge(vector<int> &a, vector<int> &b, vector<int> &res)
{
    int i = 0, j = 0, k = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] >= b[j])
        {
            res[k++] = a[i++];
        }
        else
        {
            res[k++] = b[j++];
            count += a.size() - i;
        }
    }
    if (i < a.size())
        while (i < a.size())
            res[k++] = a[i++];
    else if (j < b.size())
        while (j < b.size())
            res[k++] = b[j++];
    return;
}
void merge_sort(vector<int> &v)
{
    int nv = v.size();
    if (nv == 1)
        return;
    int n1 = nv / 2;
    int n2 = nv - n1;
    vector<int> v1(n1), v2(n2);
    for (int i = 0; i < n1; i++)
        v1[i] = v[i];
    for (int i = 0; i < n2; i++)
        v2[i] = v[n1 + i];

    merge_sort(v1);
    merge_sort(v2);
    merge(v1, v2, v);
}
int main()
{
    int arr[] = {2, 3, 4, 1, 6, 5, 7, 9, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr + n);
    merge_sort(v);
    for (int ele : v)
        cout << ele << " ";
    cout << "total inversions : " << count;
}