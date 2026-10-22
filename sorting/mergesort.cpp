#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int s, int e)
{

    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    // create 2 arrays to store values of first and second half of main array
    int *first = new int[len1];
    int *second = new int[len2];

    // copy values
    // first loop se start se mid tak ke values ko first array me copy karenge
    int mainArrayIdex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIdex++];
    }

    // second loop se mid+1 se end tak ke values ko second array me copy karenge
    mainArrayIdex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIdex++];
    }

    // merge 2 sorted arrays
    // index1 for first array and index2 for second array-----ye do arrays ko merge karne ke liye use karenge
    int index1 = 0;
    int index2 = 0;
    mainArrayIdex = s; // ye main array me merge karne ke liye use karenge

    // dono arrays ke elements ko compare karenge aur jo chota hoga usko main array me dalenge
    while (index1 < len1 && index2 < len2)
    {
        // agar first array ka element chota hoga toh usko main array me dalenge aur index1 ko increment karenge
        if (first[index1] <= second[index2])
        {
            arr[mainArrayIdex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIdex++] = second[index2++];
        }
    }

    // agar koi array zyada hoga toh usko main array me copy karenge
    while (index1 < len1)
    {
        arr[mainArrayIdex++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[mainArrayIdex++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}

void mergesort(int *arr, int s, int e)
{

    // base case
    if (s >= e)
    {
        return;
    }

    int mid = s + (e - s) / 2;
    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);

    merge(arr, s, e);
}

int main()
{
    int arr[10] = {54, 7, 78, 12, 3, 9, 45, 23, 67, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergesort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}