#include <iostream>
#include <vector>
using namespace std;

int bubbleSort(vector<int> &arr, vector<int> &a)
{
    int n = arr.size();
    bool swapped;
    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                a.push_back(j);
                swapped = true;
                count++;
            }
        }
        if (!swapped)
            break;
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (auto &it : a)
            cin >> it;
        for (auto &it : b)
            cin >> it;

        int count = 0;
        vector<int> a1;
        count += bubbleSort(a, a1);
        vector<int> b1;
        count += bubbleSort(b, b1);

        vector<int> c1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > b[i])
            {
                count++;
                c1.push_back(i);
            }
        }

        cout << count << endl;
        for (int i = 0; i < a1.size(); i++)
        {
            cout << 1 << " " << a1[i] + 1 << endl;
        }
        for (int i = 0; i < b1.size(); i++)
        {
            cout << 2 << " " << b1[i] + 1 << endl;
        }
        for (int i = 0; i < c1.size(); i++)
        {
            cout << 3 << " " << c1[i] + 1 << endl;
        }
    }
}