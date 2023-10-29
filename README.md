# TO-DO-LIST-
In this project, I built a simple to-do list using Stack in the C language.
Project Title: TO - DO LIST 
Concepts Used: STACK
Language : C

In this project, we implemented the real-world application of the data structure "STACKS". 
The code is divided into different functions in order to increase code reusability and the optimal functionality of the code.
Functions and methods used in this code are:
           1.initializeStack()
           2.push()
           3.pop()
           4.displayTasks()
           5. main()
1.initializeStack():
    void initializeStack(struct Stack *stack)
     {
       stack->top = -1;
     }
The purpose of this function is to intilize the stack top with -1.

2.push():
void push(struct Stack *stack, const char *description)
 {
    if (stack->top < MAX_TASKS - 1) {
        stack->top++;
        strcpy(stack->tasks[stack->top].description, description);
        printf("Task added: %s\n", description);
    } else {
printf("Task list is full. Cannot add more tasks.\n");
    }
}
Here, this function performs the operation of adding the elements to the stack.
Example: If the user want to add a new task ( solving an assignment), after entering his details , the task is added to the stack

3.pop():

void pop(struct Stack *stack)
 {
    if (stack->top >= 0) {
        printf("Task removed: %s\n", stack->tasks[stack->top].description);
        stack->top--;
    } else {
printf("Task list is empty. Nothing to remove.\n");
    }
}

pop() function performs operations like deletion of tasks. It prompts the user to choose the necessary option; if the user chooses the description of the task, this pop-up function gets activated.
It is the most recently added task as it follows the principal of [LIFO]

4.void displayTasks(struct Stack *stack) {
    if (stack->top >= 0) {
        printf("Tasks:\n");
        for (int i = stack->top; i >= 0; i--) {
            printf("%d. %s\n", stack->top - i + 1, stack->tasks[i].description);
        }
    } else {
        printf("No tasks in the list.");
    }
}

The display function is used to display the list of tasks available in STCAK so far.

5.
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
It prompts the user to choose the correct option like , ading , deleting , displaying and exit hte from the application.
