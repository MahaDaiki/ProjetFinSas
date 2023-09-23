#include <stdio.h>
#include <string.h>
#include <time.h>
// Integer constants for task status values
#define Status_ToDo 0
#define Status_InProgress 1
#define Status_Completed 2
// Structure for a task
typedef struct {
	char title[100];
	char description[200];
	int status;
	int ID;
	struct tm deadline;
} Task;
int n = 0;
// Function to add tasks
int AddTasks(Task tasks[], int n) {
	int tasknum;
    printf("\t\tHow many tasks do you want to enter?\n");
    scanf("%d", &tasknum);

    if (n + tasknum > 100) {
        printf("Error: the maximum number of tasks (100).\n");
        return n;
    }

    printf("Enter your tasks:\n");
    for (int i = n; i < tasknum + n; i++) {
        tasks[i].ID = i + 1; //the task ID
        printf("Task %d:\n", tasks[i].ID);
        printf("Title: ");
        scanf(" %[^\n]", tasks[i].title);
        printf("Description: ");
        scanf(" %[^\n]", tasks[i].description);
        printf("Status (0 for 'To Do', 1 for 'In Progress', 2 for 'Completed'): ");
	scanf("%d", &tasks[i].status);
	if (tasks[i].status < Status_ToDo || tasks[i].status > Status_Completed) {
	printf("Invalid status. Setting status to 'To Do'.\n");
	tasks[i].status = Status_ToDo;
	}
	 if ( tasks[i].status == 0 ){
                        printf("\t\t\tTo Do\n");}
                else if ( tasks[i].status == 1 ){
                        printf("\t\t\tIn Progress\n");}
                else if ( tasks[i].status == 2 ){
                        printf("\t\t\tCompleted\n");}
                else {
                        printf("\t\t\tInvalid\n");}
	printf("Deadline 'DD/MM/YYYY':\n");
	scanf("%d/%d/%d",&tasks[i].deadline.tm_mday, &tasks[i].deadline.tm_mon, &tasks[i].deadline.tm_year);
    }
	n+= tasknum;
    printf("=====Task Added=====\n");
    return n;
}

// Function modify a task by its ID
void ModifyTask(Task tasks[], int n) {
    int ID, h;
    printf("Enter the ID of the task you want to modify: ");
    scanf("%d", &ID);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (tasks[i].ID == ID) {
            found = 1;
            printf("Current Task %d Details:\n", tasks[i].ID);
            printf("Title: %s\n", tasks[i].title);
            printf("Description: %s\n", tasks[i].description);
            printf("Status: %d\n", tasks[i].status);
            printf("\t \t 1- To change title.\n\t \t 2- To change description.\n\t \t 3-To change status.\n\t \t 4-To change deadline.\n");
            scanf("%d", &h);
            if (h == 1) {
                printf("New Title: ");
                scanf(" %[^\n]", tasks[i].title);
            }
		 else if (h == 2) {
                	printf("New Description: ");
                	scanf(" %[^\n]", tasks[i].description);
            } 
		else if (h == 3) {
                        printf("Status (0 for 'To Do', 1 for 'In Progress', 2 for 'Completed'): ");
        		scanf("%d", &tasks[i].status);
        		if (tasks[i].status < Status_ToDo || tasks[i].status > Status_Completed) {
        		printf("Invalid status. Setting status to 'To Do'.\n");
       			 tasks[i].status = Status_ToDo;
       		 }
		}
		else if (h == 4) {
			printf("New Deadline:");
			scanf("%d/%d/%d",&tasks[i].deadline.tm_mday, &tasks[i].deadline.tm_mon, &tasks[i].deadline.tm_year);
			}
		else {
                	printf("Invalid choice\n");
            }

            printf("Task %d has been modified.\n", tasks[i].ID);
            break;
        }
    }

    if (!found) {
        printf("Task with ID %d not found.\n", ID);
    }
}

// Function to display the tasks
void Display(Task tasks[], int n) {
    for (int i = 0; i < n; i++) {
        printf("  > Task %d:\n", tasks[i].ID);
        printf("  > Title: %s\n", tasks[i].title);
        printf("  > Description: %s\n", tasks[i].description);
        printf("  > Status : %d\n", tasks[i].status);
		if ( tasks[i].status == 0 ){
			printf("\t\t\tTo Do\n");}
		else if ( tasks[i].status == 1 ){
			printf("\t\t\tIn Progress\n");}
		else if ( tasks[i].status == 2 ){
			printf("\t\t\tCompleted\n");}
		else {
			printf("\t\t\tInvalid\n");}
	printf("  >Deadline: %02d/%02d/%04d\n", tasks[i].deadline.tm_mday, tasks[i].deadline.tm_mon , tasks[i].deadline.tm_year);
    }
}

// Function to sort tasks by title using Bubble Sort
void sorting(Task tasks[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (strcmp(tasks[j].title, tasks[j + 1].title) > 0) {
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }
}

// Function to search tasks by title ( search linear)
void Search(Task tasks[], char s2[100], int n) {
    printf("Search for your task by title:");
    scanf(" %[^\n]", s2);
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(s2, tasks[i].title) == 0) {
            found = 1;
            printf("Task %d: %s\n %s. '%d'\n", tasks[i].ID, tasks[i].title, tasks[i].description, tasks[i].status);
      			  if ( tasks[i].status == 0 ){
                        printf("\t\t\tTo Do\n");}
                else if ( tasks[i].status == 1 ){
                        printf("\t\t\tIn Progress\n");}
                else if ( tasks[i].status == 2 ){
                        printf("\t\t\tCompleted\n");}
               
 }
    }

    if (!found) {
        printf("Task with title '%s' not found.\n", s2);
    }
}

// Function to search tasks by ID
void Search1(Task tasks[], int s1, int n) {
    printf("Search for your task by ID:");
    scanf("%d", &s1);
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (tasks[i].ID == s1) {
            found = 1;
            printf("Task %d: %s\n %s. '%d'\n", tasks[i].ID, tasks[i].title, tasks[i].description, tasks[i].status);
       			 if ( tasks[i].status == 0 ){
                        printf("\t\t\tTo Do\n");}
                else if ( tasks[i].status == 1 ){
                        printf("\t\t\tIn Progress\n");}
                else if ( tasks[i].status == 2 ){
                        printf("\t\t\tCompleted\n");}

	 }
    }

    if (!found) {
        printf("Task with ID %d not found.\n", s1);
    }
}

// Function to delete a task by ID
int Delete(Task tasks[], int d, int n) {
    printf("Which task do you want to delete ?");
    scanf("%d", &d);
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (tasks[i].ID == d) {
            found = 1;

            for (int j = i; j < n - 1; j++) {
                tasks[j] = tasks[j + 1];
            }

            printf("Task %d is deleted.\n", d);
            break;
        }
    }

    if (!found) {
        printf("Task with ID %d is not found.\n", d);
    }

    return n - 1;
}
//	days remaining
Task taches[100];
void daysRemaining(Task tasks[], int n) {
    time_t now;
    time(&now);
    double srem;
    int drem, hrem;
    
   for (int i = 0; i < n; i++) {
        
        struct tm deadline = tasks[i].deadline;
        deadline.tm_year -= 1900;
        deadline.tm_mon -= 1;
        time_t taskTime = mktime(&deadline);

        if (taskTime == -1) {
            printf("Error converting deadline to time.\n");
            continue;
        }



        srem = difftime(taskTime, now);
        int mrem = (int)(srem / (60));
        int hrem = (int)(srem / (60 * 60));
        drem = (int)(srem / (60 * 60 * 24));
    
        printf("> Task %d:\n", tasks[i].ID);
        printf("> Title: %s\n", tasks[i].title);
        printf("> days remaining : %d\n", drem);
        printf("> hours remaining: %d\n", hrem);
}

}
//3days remaining 
void threedays(Task tasks[], int n) {
    time_t now;
    time(&now);
    double srem;
    int drem, hrem;
    
   for (int i = 0; i < n; i++) {
        
        struct tm deadline = tasks[i].deadline;
        deadline.tm_year -= 1900;
        deadline.tm_mon -= 1;
        time_t taskTime = mktime(&deadline);

        if (taskTime == -1) {
            printf("Error converting deadline to time.\n");
            continue;
        }

        srem = difftime(taskTime, now);
        
        int mrem = (int)(srem / (60));
        int hrem = (int)(srem / (60 * 60));
        drem = (int)(srem / (60 * 60 * 24));
        
        if ( drem <= 3){ //3days
        printf("> Task : %d\n", tasks[i].ID);
        printf("> Title: %s\n", tasks[i].title);
        printf("> days remaining : %d\n", drem);
        printf("> hours remaining: %d\n", hrem);
        }
	else {
		printf("======NO TASK AVAILABLE=====\n");
}
}

}

// code start
int main() {
    int choice;
    
    Task tasks[100];
    while (1) {
        printf("\t\t\t=========Welcome to your 'To Do list'=========\n");
        printf("\t1-Add tasks.\n");
        printf("\t2-Modify Your Tasks.\n");
        printf("\t3-Your tasks.\n");
        printf("\t4-Search.\n");
        printf("\t5-Delete.\n");
        printf("\t6-statistics\n");
        printf("\t7-Exit.\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
		 // Add tasks
                n = AddTasks(tasks, n);
                break;
            case 2:
                // Modify tasks
                ModifyTask(tasks, n);
                break;
            case 3:
                // Display tasks
		int sort;
		printf("   \t\t-----Show tasks:-----\n1-Sort alphabetically.\n2-Sort by Deadline.\n3-Deadline less than 3days.\n");
		scanf("%d",&sort);
		if ( sort == 1){
                	sorting(tasks, n);
                	Display(tasks, n);
		}
		else if ( sort == 2 ){
			for (int i = 0; i < n - 1; i++) {
				for (int j = 0; j < n - i - 1; j++) {
					time_t deadline1 = mktime(&tasks[j].deadline);
					time_t deadline2 = mktime(&tasks[j + 1].deadline);
					if (deadline1 > deadline2) {
					Task temp = tasks[j];
					tasks[j] = tasks[j + 1];
					tasks[j + 1] = temp;
           				 }
       				 }
   			 }
			Display(tasks, n);
			}
		else if ( sort == 3){
				
			threedays(tasks, n);
				}
		else {
			printf("Invalid choice");
        }
                break;
        
            case 4:
                // Search tasks
                int s;
                sorting(tasks, n);
                printf(" 1- to search by 'ID' \n 2- to search by 'Title':\n");
                scanf("%d", &s);
                if (s == 1) {
                    int s1;
                    Search1(tasks, s1, n);
                } else if (s == 2) {
                    char s2[100];
                    Search(tasks, s2, n);
                } else {
                    printf("Invalid choice\n");
                }
                break;
            case 5:
                // Delete tasks
		int d;
                n = Delete(tasks, d, n);
                break;
            case 6:
                // Statistics
		int t;
		printf("\t 1-Total tasks.\n\t 2-Total tasks completed and incompleted.\n\t 3-Days Remaining.\n");
		scanf("%d",&t);
		if ( t == 1 ){
			printf("You have %d task totally ", n);
		}
		if ( t == 2 ){
			int completedCount = 0;
			int inProgressCount = 0;
			int todoCount = 0;

		for (int i = 0; i < n; i++) {
    			switch (tasks[i].status) {
        			case Status_Completed:
            					completedCount++;
            					break;
        			case Status_InProgress:
            					inProgressCount++;
           					 break;
       				case Status_ToDo:
						todoCount++;
						break;
        			default:
            				printf("Invalid status");
            				break;
    		}
			printf("Completed tasks: %d\n", completedCount);
			printf("In Progress tasks: %d\n", inProgressCount);
			printf("To Do tasks: %d\n", todoCount);

		}
		}
		if ( t == 3 ){
		printf("\t            \t======Tasks======\n");
            daysRemaining(tasks,n);
              }
		  break;
            
            case 7:
               // Exit
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}
