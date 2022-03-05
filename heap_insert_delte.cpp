#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &heap, int value)
{
    heap.push_back(value);
    int i = heap.size() - 1;
    int parent;
    while (i > 1)
    {
        parent = i / 2;
        if (heap[parent] < heap[i])
        {
            swap(heap[parent], heap[i]);
        }
        else
            return;

        i = parent;
    }
}

void deleteNode(vector<int> &heap)
{
    heap[1] = heap.back();
    heap.pop_back();
    int i = 1;
    int left;
    int right;
    while ((2 * i) <= (heap.size() - 1))
    {
        left = 2 * i;
        right = 2 * i + 1;
        int larger;

        if (right > heap.size() - 1)
        {
            larger = left;
        }
        else
        {
            larger = heap[left] > heap[right] ? left : right;
        }

        if (heap[larger] > heap[i])
        {
            swap(heap[larger], heap[i]);
            i=larger;
        }
        else
            return;
    }
}

int main()
{
    vector<int> heap({-1, 50, 30, 40, 10, 5, 20, 30});
    vector<int> heap2({-1,40,30,10,20,15});
    insert(heap, 60);
    insert(heap, 45);
    deleteNode(heap);
    for (auto it : heap)
    {
        cout << it << " ";
    }
    cout<<"\n";
    for (auto it : heap2)
    {
        cout << it << " ";
    }
    deleteNode(heap2);
    cout<<"\n";
    for (auto it : heap2)
    {
        cout << it << " ";
    }
    return 0;
}