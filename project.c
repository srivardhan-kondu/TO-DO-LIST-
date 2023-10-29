#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX_TASKS 100

// Structure to represent a task
struct Task {
    char description[100];
};

// Stack structure to store tasks
struct Stack {
    struct Task tasks[MAX_TASKS];
    int top;
};

// Function to initialize the stack
void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

// Function to push a task onto the stack
void push(struct Stack *stack, const char *description) {
    if (stack->top < MAX_TASKS - 1) {
        stack->top++;
        strcpy(stack->tasks[stack->top].description, description);
        printf("Task added: %s\n", description);
    } else {
        printf("Task list is full. Cannot add more tasks.\n");
    }
}

// Function to pop (remove) the top task from the stack
void pop(struct Stack *stack) {
    if (stack->top >= 0) {
        printf("Task removed: %s\n", stack->tasks[stack->top].description);
        stack->top--;
    } else {
        printf("Task list is empty. Nothing to remove.\n");
    }
}

// Function to display all tasks in the stack
void displayTasks(struct Stack *stack) {
    if (stack->top >= 0) {
        printf("Tasks:\n");
        for (int i = stack->top; i >= 0; i--) {
            printf("%d. %s\n", stack->top - i + 1, stack->tasks[i].description);
        }
    } else {
        printf("No tasks in the list.\n");
    }
}

int main() {
    struct Stack taskStack;
    initializeStack(&taskStack);

    int choice;
    char description[100];

    while (1) {
        printf("\nTo-Do List Application\n");
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. Display Tasks\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task description: ");
                scanf(" %[^\n]s", description);
                push(&taskStack, description);
                break;

            case 2:
                if (taskStack.top >= 0) {
                    int taskNumber;
                    displayTasks(&taskStack);
                    printf("Enter the task number to remove: ");
                    scanf("%d", &taskNumber);
                    if (taskNumber >= 1 && taskNumber <= taskStack.top + 1) {
                        printf("Removing task %d: %s\n", taskNumber, taskStack.tasks[taskStack.top - taskNumber + 1].description);
                        // Move tasks above the removed task down
                        for (int i = taskStack.top - taskNumber; i < taskStack.top; i++) {
                            strcpy(taskStack.tasks[i].description, taskStack.tasks[i + 1].description);
                        }
                        taskStack.top--;
                    } else {
                        printf("Invalid task number.\n");
                    }
                } else {
                    printf("Task list is empty. Nothing to remove.\n");
                }
                break;

            case 3:
                displayTasks(&taskStack);
                break;

            case 4:
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
