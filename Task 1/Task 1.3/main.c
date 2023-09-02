#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 100

typedef struct {
    int id;
    char description[100];
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

    tasks[count++] = newTask;

    printf("Task added successfully.\n");
}

void viewTasks() {
    if (count == 0) {
        printf("No tasks to display.\n");
        return;
    }

    printf("Task List:\n");
    printf("ID\tDescription\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%s\n", tasks[i].id, tasks[i].description);
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

int main() {
    int choice;

    while (1) {
        printf("\nTask Manager\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Remove Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                removeTask();
                break;
            case 4:
                printf("Exiting Minions Task Manager. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
