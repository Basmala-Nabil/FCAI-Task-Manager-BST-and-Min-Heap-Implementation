#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include "BST.h"
using namespace std;

class Heap
{
public:
    node* arr[200];
    node* root;
    int sizee;

    Heap()
    {
        root = nullptr;
        sizee=0;
    }
    void Mark_task_complete(task d)
    {


        node* newnode = new node(d);
        if (sizee >= 200)
        {
            cout<<"Heap is full!"<<endl;
            return;
        }
        arr[sizee] = newnode;
        heapifyUp(sizee);
        sizee++;

    }
    void heapifyUp(int index)
    {
        if (index == 0)
            return;
        int parent = (index - 1) / 2;
        if (arr[index]->data.duration < arr[parent]->data.duration)
        {
            swap(arr[index], arr[parent]);
            heapifyUp(parent);
        }
    }
    void heapifyDown(int index)
    {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        if (index == 0)
            return;

        if (left < sizee && arr[left]->data.duration < arr[smallest]->data.duration)
        {
            smallest = left;
        }
        if (right < sizee && arr[right]->data.duration < arr[smallest]->data.duration)
        {
            smallest = right;
        }
        if (smallest != index)
        {
            swap(arr[index], arr[smallest]);
            heapifyDown(smallest);
        }
    }
    void fixHeap()
    {
        for (int i = sizee / 2 - 1; i >= 0; i--)
        {
            heapifyDown(i);
        }
    }

    void displaycompleted()                // display  completed tasks sorted by duration from the least
    {
        cout << "Completed Tasks:"<<endl;
        for (int i = 0; i < sizee; i++)
        {
            cout << "Description: " << arr[i]->data.description << endl;
            cout << "Duration: " << arr[i]->data.duration << endl;
            cout << "Category: " << arr[i]->data.category << endl;
            cout << endl;
        }

        // display  number of tasks completed per category & thier number
        cout << "Tasks completed per category"<<endl;
        for (int i = 0; i < sizee; i++)
        {
            int count = 1;
            for (int j = i + 1; j < sizee; j++)
            {
                if (arr[i]->data.category == arr[j]->data.category)
                {
                    count++;
                    arr[j]->data.category = "";  //  to avoid duplicate counting

                }
            }
            if (!arr[i]->data.category.empty())   // for counting tasks per category
            {
                cout << arr[i]->data.category << ": " << count << " tasks" << endl;
            }
        }
    }
};

#endif // HEAP_H
