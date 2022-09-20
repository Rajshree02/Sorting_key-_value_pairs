#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void Merge(vector<vector<int>> &arr, int p, int q, int r, int row)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[2][n1 + 1], R[2][n2 + 1];

    for (int i = 0; i < n1; i++)
    {
        L[0][i] = arr[0][p + i];
        L[1][i] = arr[1][p + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[0][i] = arr[0][q + 1 + i];
        R[1][i] = arr[1][q + 1 + i];
    }
    L[0][n1] = 9999;
    R[0][n2] = 9999;
    int i = 0, j = 0;
    if (row == 0)
    {
        for (int k = p; k <= r; k++)
        {
            if (L[0][i] <= R[0][j]) // comparison done on the basis of keys
            {

                arr[0][k] = L[0][i];
                arr[1][k] = L[1][i];
                i++;
            }
            else
            {
                arr[0][k] = R[0][j];
                arr[1][k] = R[1][j];
                j++;
            }
        }
    }
    else
    {
        for (int k = p; k <= r; k++)
        {
            if (L[1][i] <= R[1][j]) // comparison done on the basis of values
            {
                arr[0][k] = L[0][i];
                arr[1][k] = L[1][i];
                i++;
            }
            else
            {
                arr[0][k] = R[0][j];
                arr[1][k] = R[1][j];
                j++;
            }
        }
    }
    cout << "========" << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int k = 0; k <= r; k++)
        {
            cout << arr[i][k] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}
void MergeSort(vector<vector<int>> &arr, int p, int r, int row)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        MergeSort(arr, p, q, row);
        MergeSort(arr, q + 1, r, row);
        cout << "Merging: " << p << q << r << endl;
        Merge(arr, p, q, r, row);
    }
}

int main()
{
    int n, ele;
    vector<vector<int>> arr{
        {1, 0, -1, -2},
        {10, 1, 0, 7}

    };
    cout<<"Size of array"<<arr[0].size()<<endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }

    int choice;
    do
    {
        cout << "Select type of sorting?\n1. key Based\n2. Value Based\n3. exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:

            MergeSort(arr, 0, arr[0].size()-1, 0);
            for (int i = 0; i < arr.size(); i++)
            {
                for (int j = 0; j < arr[i].size(); j++)
                    cout << arr[i][j] << " ";
                cout << "\n";
            }
            break;
        case 2:
            MergeSort(arr, 0, arr[0].size()-1, 1);
            for (int i = 0; i < arr.size(); i++)
            {
                for (int j = 0; j < arr[i].size(); j++)
                    cout << arr[i][j] << " ";
                cout << "\n";
            }
            break;
        case 3:
            break;
        default:
            break;
        }

    } while (choice != 3);
}
