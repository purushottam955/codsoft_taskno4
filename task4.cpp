/*TO DO LIST*/
/*Task Input: Allow users to input tasks they want to add to the list.
Add Task: Implement a function to add tasks to the list.
View Tasks: Display the list of tasks with their status (completed or
pending).
Mark Task as Completed: Allow users to mark tasks as completed.
Remove Task: Provide an option to remove tasks from the list.*/
#include<iostream>
#include<string>
using namespace std;

string tasks[100];
bool completed[100];
int taskCount = 0;

void addTask() {
    cin.ignore();

    cout << "Enter Task: ";
    getline(cin, tasks[taskCount]);

    completed[taskCount] = false;
    taskCount++;

    cout << "Task Added Successfully!\n";
}

void viewTask() {
    if (taskCount == 0) {
        cout << "No Tasks Available!\n";
        return;
    }

    cout << "\n----- TASK LIST -----\n";

    for (int i = 0; i < taskCount; i++) {
        cout << i + 1 << ". " << tasks[i];

        if (completed[i])
            cout << " [Completed]";
        else
            cout << " [Pending]";

        cout << endl;
    }
}

void markTask() {
    int num;

    viewTask();

    if (taskCount == 0)
        return;

    cout << "Enter Task Number: ";
    cin >> num;

    if (num >= 1 && num <= taskCount) {
        completed[num - 1] = true;
        cout << "Task Marked as Completed!\n";
    }
    else {
        cout << "Invalid Task Number!\n";
    }
}

void removeTask() {
    int num;

    viewTask();

    if (taskCount == 0)
        return;

    cout << "Enter Task Number to Delete: ";
    cin >> num;

    if (num >= 1 && num <= taskCount) {

        for (int i = num - 1; i < taskCount - 1; i++) {
            tasks[i] = tasks[i + 1];
            completed[i] = completed[i + 1];
        }

        taskCount--;

        cout << "Task Deleted Successfully!\n";
    }
    else {
        cout << "Invalid Task Number!\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== TO DO LIST =====\n";
        cout << "1. ADD TASK\n";
        cout << "2. VIEW TASK\n";
        cout << "3. MARK COMPLETED\n";
        cout << "4. DELETE TASK\n";
        cout << "5. EXIT\n";
        cout << "ENTER CHOICE: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;

            case 2:
                viewTask();
                break;

            case 3:
                markTask();
                break;

            case 4:
                removeTask();
                break;

            case 5:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "INVALID CHOICE\n";
        }

    } while (choice != 5);

    return 0;
}