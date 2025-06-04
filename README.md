# FCAI-Task-Manager-BST-and-Min-Heap-Implementation


Project Description

This project is a Task Manager application designed to help users organize and manage their daily tasks efficiently using two key data structures:

Binary Search Tree (BST): Used to store active tasks, ordered by their duration (in minutes). Tasks with equal durations are inserted as left children.

Min-Heap: Used to store completed tasks, allowing quick retrieval of tasks with the shortest duration.

Task Attributes:

Description: A brief text describing the task (e.g., "Study data structure").

Duration: Time needed to complete the task, measured in minutes.

Category: The category of the task (e.g., Educational, Health, Food).

Functionalities

BST Operations:

Insert a new task.

Display all tasks in ascending order by duration.

Search tasks by exact duration.

Remove all tasks with a given duration.

Display tasks with durations greater than or equal to a given value.

Display tasks with durations less than or equal to a given value.

Min-Heap Operations:

Mark a task as completed (removes from BST and adds to Min-Heap).

Display all completed tasks sorted by duration (ascending).

Show the count of completed tasks per category.

Usage:

Tasks are loaded from an input file.

Users interact via a menu to perform task management operations.

When marking a task completed, the system allows case-insensitive partial description matching.

The system maintains efficient data retrieval and updates through BST and Min-Heap.


Technologies:

Implemented in C++

Uses BST for active tasks management.

Uses Min-Heap for managing completed tasks.

Includes file I/O and string manipulation.

Learning Outcomes:

Implement BST insert, search, delete, and traversal with handling of duplicate keys.

Implement Min-Heap insert and extract operations.

Combine multiple data structures for real-world applications.

Use case-insensitive substring search in C++.

Practice structured programming and file handling.
