#ifndef BST_H
#define BST_H

#include <iostream>
#include <string.h>
using namespace std;

class task
{
public:
    string description;
    int duration;
    string category;
    task()
    {
        description = "";
        duration = 0;
        category = "";
    }
    task(string dsc, int dur, string cat)
    {
        description = dsc;
        duration = dur;
        category = cat;
    }
};

class node
{
public:
    task data;
    node* right;
    node* left;
    node(task d)
    {
        data = d;
        right = left = nullptr;
    }
};

class BST
{
public:
    node* root;
    BST()
    {
        root = nullptr;
    }

    node* Insert(node* root, const task& t)
    {
        if (root == nullptr)
        {
            return new node(t);
        }
        if (t.duration < root->data.duration)
        {
            root->left = Insert(root->left, t);
        }
        else
        {
            root->right = Insert(root->right, t);
        }
        return root;
    }

    void insert(const task& item)
    {
        root = Insert(root, item);
        cout << "task is added" << endl;
    }
    void Search(int dur)
    {
        int counter = 0, taskcount = 100;
        task tsk[taskcount]; //array of tasks to store the matched nodes
        node* temp = root;
        while(temp != nullptr)
        {
            if(temp->data.duration==dur)
            {
                if(counter<taskcount)
                {
                    tsk[counter]=temp->data;
                    counter++;
                }
                temp = temp->right;

            }
            else if(temp->data.duration>dur)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        if(counter == 0)
        {
            cout<<dur<<" Not found..."<<endl;
        }
        else
        {
            cout<<counter<<" tasks are found."<<endl;
            for(int i=0; i<counter; i++)
            {
                cout<<"Description: "<<tsk[i].description<<endl;
                cout<<"Duration: " <<tsk[i].duration<<endl;
                cout<<"Category: "<<tsk[i].category<<endl;
            }
        }
    }
    char lower_char(char c)
    {
        if (c >= 'A' && c <= 'Z')
            return c + 32;
        return c;
    }

    bool is_substring(const char* des, const char* sub)
    {
        int dlen = strlen(des);
        int slen = strlen(sub);
        if (slen > dlen) return false;

        for (int i = 0; i <= dlen - slen; i++)
        {
            bool check = true;
            for (int j = 0; j < slen; j++)
            {
                if (lower_char(des[i + j]) != lower_char(sub[j]))
                {
                    check = false;
                    break;
                }
            }
            if (check)
                return true;
        }
        return false;
    }
    node* search_dur_des(node* current, int dur, const string& des)
    {
        if (current == nullptr)
            return nullptr;

        node* found = nullptr;

        found = search_dur_des(current->left, dur, des);
        if (found != nullptr) return found;

        if (current->data.duration == dur)
        {
            if (is_substring(current->data.description.c_str(), des.c_str()))
            {
                return current;
            }
        }
        found = search_dur_des(current->right, dur, des);
        return found;
    }


    void displayLessthan(int dur)
    {
        node* temp = root;
        if (temp == nullptr)
            return;
        while(temp->data.duration>dur)
        {
            temp=temp->left;
        }
        if(temp->data.duration <=dur)
        {
            display(temp);
        }
    }
    void displayMorethan(node* root,int dur)
    {
        if (root == nullptr)
            return;

        if(root->data .duration>=dur)
        {
            cout<<"Description: "<<root->data.description<<endl;
            cout<<"Duration: "<<root->data.duration<<endl;
            cout<<"category: "<<root->data.category<<endl;
            displayMorethan(root->left,dur);
            displayMorethan(root->right,dur);
        }

    }
    void Remove (int dur)
    {
        bool removedAny = false;
        int counter = 0;
        while (true)
        {
            node* temp = root;
            node* prev = nullptr;

            //search for a node with the given duration
            while (temp != nullptr && temp->data.duration != dur)
            {
                prev = temp;
                if (dur < temp->data.duration)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }
            // node not found exit
            if (temp == nullptr)
            {
                if (!removedAny)
                {
                    cout<<"Invalid duration..."<<endl;
                }
                break;
            }
            removedAny = true;
            if (temp->left == nullptr && temp->right == nullptr)
            {
                if (prev == nullptr)
                {
                    root = nullptr;  //root node
                    counter++;
                }
                else if (prev->left == temp)
                {
                    prev->left = nullptr;
                    counter++;
                }
                else
                {
                    prev->right = nullptr;
                    counter++;
                }
                delete temp;
            }
            else if (temp->left == nullptr)
            {
                if (prev == nullptr)
                {
                    root = temp->right;  //root node
                    counter++;
                }
                else if (prev->left == temp)
                {
                    prev->left = temp->right;
                    counter++;
                }
                else
                {
                    prev->right = temp->right;
                    counter++;
                }
                delete temp;
            }
            //has only a left child
            else if (temp->right == nullptr)
            {
                if (prev == nullptr)
                {
                    root = temp->left;  //root node
                    counter++;
                }
                else if (prev->left == temp)
                {
                    prev->left = temp->left;
                    counter++;
                }
                else
                {
                    prev->right = temp->left;
                    counter++;
                }
                delete temp;
            }
            else if (temp->left != nullptr && temp->right != nullptr) // has two children
            {
                node* copied = temp->right;
                node* copiedParent = temp;

                while (copied->left != nullptr)
                {
                    copiedParent = copied;
                    copied = copied->left;
                }
                temp->data = copied->data;
                if (copiedParent->left == copied)
                {
                    copiedParent->left = copied->right;
                    counter++;
                }
                else
                {
                    copiedParent->right = copied->right;
                    counter++;
                }
                delete copied;
            }
        }
        if (removedAny)
        {
            if(counter==1)
            {
                cout<<counter<<" task is removed."<<endl;
            }
            else
            {
                cout<<counter<<" tasks are removed."<<endl;
            }
        }
    }
    void Remove_dur_des(int dur, string desc)
    {
        bool removedAny = false;
        int counter = 0;
        while (true)
        {
            node* temp = root;
            node* prev = nullptr;

            while (temp != nullptr && (temp->data.duration !=dur || temp->data.description != desc))
            {
                prev = temp;
                if (dur < temp->data.duration)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }

            // node not found, exit
            if (temp == nullptr)
            {
                if (!removedAny)
                {
                    cout << "No task found with the given duration and description." << endl;
                }
                break;
            }

            removedAny = true;

            // Leaf node
            if (temp->left == nullptr && temp->right == nullptr)
            {
                if (prev == nullptr)
                {
                    root = nullptr;
                }
                else if (prev->left == temp)
                {
                    prev->left = nullptr;
                }
                else
                {
                    prev->right = nullptr;
                }
                delete temp;
                counter++;
            }
            //Only right child
            else if (temp->left == nullptr)
            {
                if (prev == nullptr)
                {
                    root = temp->right;
                }
                else if (prev->left == temp)
                {
                    prev->left = temp->right;
                }
                else
                {
                    prev->right = temp->right;
                }
                delete temp;
                counter++;
            }
            //Only left child
            else if (temp->right == nullptr)
            {
                if (prev == nullptr)
                {
                    root = temp->left;
                }
                else if (prev->left == temp)
                {
                    prev->left = temp->left;
                }
                else
                {
                    prev->right = temp->left;
                }
                delete temp;
                counter++;
            }
            // Two children
            else
            {
                node* copied = temp->right;
                node* copiedParent = temp;

                while (copied->left != nullptr)
                {
                    copiedParent = copied;
                    copied = copied->left;
                }

                temp->data = copied->data;

                if (copiedParent->left == copied)
                {
                    copiedParent->left = copied->right;
                }
                else
                {
                    copiedParent->right = copied->right;
                }
                delete copied;
                counter++;
            }
        }
        if (removedAny)
        {
            if (counter == 1)
            {
                cout<<counter<<" task is removed."<<endl;
            }

        }
    }

    void display(node* root)
    {
        if (root == nullptr)
            return;
        display(root->left);
        cout<<"Description: "<< root->data.description<<endl;
        cout<<"Duration: "<< root->data.duration<<endl;
        cout<<"Category: "<<root->data.category<<endl;
        display(root->right);
    }
};

#endif
