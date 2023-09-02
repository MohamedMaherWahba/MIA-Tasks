#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 100

typedef struct {
    int id;
    char description[100];
    int completed;
} Task;

int count = 0;
Task tasks[MAX_TASKS];

void addTask() {
    if (count >= MAX_TASKS) {
        printf("Task limit reached. Cannot add more tasks.\n");
        return;
    }

    Task newTask;

    newTask.id = count + 1;

    printf("Enter task description: ");
    scanf(" %[^\n]", newTask.description);

    newTask.completed = 0;

    tasks[count++] = newTask;

    printf("Task added successfully.\n");
}

void markTaskAsCompleted() {
    if (count == 0) {
        printf("No tasks to mark as completed.\n");
        return;
    }

    int taskId;

    printf("Enter the ID of the task to mark as completed: ");
    scanf("%d", &taskId);

    int found = 0;

    for (int i = 0; i < count; i++) {
        if (tasks[i].id == taskId) {
            found = 1;

            if (tasks[i].completed == 1) {
                printf("Task is already marked as completed.\n");
            } else {
                tasks[i].completed = 1;
                printf("Task marked as completed.\n");
            }

            break;
        }
    }

    if (!found) {
        printf("Task with the given ID not found.\n");
    }
}

void viewCompleteTasks() {
    int found = 0;

    printf("Completed Tasks:\n");
    printf("ID\tDescription\n");

    for (int i = 0; i < count; i++) {
        if (tasks[i].completed == 1) {
            printf("%d\t%s\n", tasks[i].id, tasks[i].description);
            found = 1;
        }
    }

    if (!found) {
        printf("No completed tasks.\n");
    }
}

void viewIncompleteTasks() {
    int found = 0;

    printf("Incomplete Tasks:\n");
    printf("ID\tDescription\n");

    for (int i = 0; i < count; i++) {
        if (tasks[i].completed == 0) {
            printf("%d\t%s\n", tasks[i].id, tasks[i].description);
            found = 1;
        }
    }

    if (!found) {
        printf("No incomplete tasks.\n");
    }
}

void removeTask() {
    if (count == 0) {
        printf("No tasks to remove.\n");
        return;
    }

    int taskId;

    printf("Enter the ID of the task to remove: ");
    scanf("%d", &taskId);

    int found = 0;

    for (int i = 0; i < count; i++) {
        if (tasks[i].id == taskId) {
            found = 1;

            // Shift remaining tasks to fill the gap
            for (int j = i; j < count - 1; j++) {
                tasks[j] = tasks[j + 1];
            }

            count--;
            printf("Task removed successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Task with the given ID not found.\n");
    }
}

void displayTasks() {
    if (count == 0) {
        printf("No tasks to display.\n");
        return;
    }

    printf("Task List:\n");
    printf("ID\tDescription\t\tStatus\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%-20s\t%s\n", tasks[i].id, tasks[i].description, tasks[i].completed == 1 ? "Completed" : "Incomplete");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nTask Manager\n");
        printf("1. Add Task\n");
        printf("2. Mark Task as Completed\n");
        printf("3. View Complete Tasks\n");
        printf("4. View Incomplete Tasks\n");
        printf("5. Remove Task\n");
        printf("6. View All Tasks\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                markTaskAsCompleted();
                break;
            case 3:
                viewCompleteTasks();
                break;
            case 4:
                viewIncompleteTasks();
                break;
            case 5:
               removeTask();
                break;
            case 6:
                displayTasks();
                break;
            case 7:
                printf("Exiting Task Manager.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
