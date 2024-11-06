#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char* Name;
    char* Address;
    int Id;
    struct student* ptr;
};

void swapStudentsByName(struct student** head, char* name1, char* name2) {
    if (strcmp(name1, name2) == 0) {
        printf("The names are the same; no swap needed.\n");
        return;
    }
    struct student *prev1 = NULL, *curr1 = *head;
    struct student *prev2 = NULL, *curr2 = *head;
    while (curr1 && strcmp(curr1->Name, name1) != 0) {
        prev1 = curr1;
        curr1 = curr1->ptr;
    }
    while (curr2 && strcmp(curr2->Name, name2) != 0) {
        prev2 = curr2;
        curr2 = curr2->ptr;
    }
    if (!curr1 || !curr2) {
        printf("One or both students not found.\n");
        return;
    }
    if (prev1) {
        prev1->ptr = curr2;
    } else {
        *head = curr2;
    }
    if (prev2) {
        prev2->ptr = curr1;
    } else {
        *head = curr1;
    }
    struct student* temp = curr1->ptr;
    curr1->ptr = curr2->ptr;
    curr2->ptr = temp;
    printf("Students %s and %s swapped successfully.\n", name1, name2);
}

void sortStudentsByName(struct student** head) {
    if (*head == NULL) return;
    struct student* i = *head;
    while (i->ptr != NULL) {
        struct student* j = i->ptr;
        while (j != NULL) {
            if (strcmp(i->Name, j->Name) > 0) {

                char* tempName = i->Name;
                char* tempAddress = i->Address;
                int tempId = i->Id;

                i->Name = j->Name;
                i->Address = j->Address;
                i->Id = j->Id;

                j->Name = tempName;
                j->Address = tempAddress;
                j->Id = tempId;
            }
            j = j->ptr;
        }
        i = i->ptr;
    }
    printf("Students sorted by name.\n");
}

void sortStudentsById(struct student** head) {
    if (*head == NULL) return;
    struct student* i = *head;
    while (i->ptr != NULL) {
        struct student* j = i->ptr;
        while (j != NULL) {
            if (i->Id > j->Id) {

                char* tempName = i->Name;
                char* tempAddress = i->Address;
                int tempId = i->Id;

                i->Name = j->Name;
                i->Address = j->Address;
                i->Id = j->Id;

                j->Name = tempName;
                j->Address = tempAddress;
                j->Id = tempId;
            }
            j = j->ptr;
        }
        i = i->ptr;
    }
    printf("Students sorted by ID.\n");
}

int main() {
    int choice, count = 1, pos, pos1, n;
    struct student *head, *newnode, *temp, *temp1, *temp2;
    head = NULL;
    while (1) {
        printf("Enter 1 to Add Student\n2 to Swap Students by Name\n3 to Display\n4 to Insert Student\n5 to Delete Student\n6 to Sort by Name\n7 to Sort by ID\n 8 to exit");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            newnode = (struct student*)malloc(sizeof(struct student));
            newnode->Name = (char*)malloc(50 * sizeof(char));
            printf("Enter name: ");
            scanf("%s", newnode->Name);
            printf("Enter ID: ");
            scanf("%d", &newnode->Id);
            newnode->Address = (char*)malloc(100 * sizeof(char));
            printf("Enter Address: ");
            scanf("%s", newnode->Address);
            newnode->ptr = NULL;
            if (head == NULL) {
                head = newnode;
                temp = newnode;
            } else {
                temp->ptr = newnode;
                temp = newnode;
            }
            count++;
            break;
        case 2: {
            char name1[50], name2[50];
            printf("Enter the first student's name to swap: ");
            scanf("%s", name1);
            printf("Enter the second student's name to swap: ");
            scanf("%s", name2);
            swapStudentsByName(&head, name1, name2);
            break;
        }
        case 3:
            printf("Student Details:\npos\tId\tName\t\tAddress\n");
            temp1 = head;
            int k = 1;
            while (temp1 != NULL) {
                printf("%d\t%d\t%s\t\t%s\n", k++, temp1->Id, temp1->Name, temp1->Address);
                temp1 = temp1->ptr;
            }
            break;
        case 4:
            printf("Enter position after which you want to insert\n");
            scanf("%d", &pos);
            if (pos > count) {
                printf("Enter Valid position\n");
            } else {
                temp2 = head;
                int i = 1;
                while (i < pos) {
                    temp2 = temp2->ptr;
                    i++;
                }
                newnode = (struct student*)malloc(sizeof(struct student));
                newnode->Name = (char*)malloc(50 * sizeof(char));
                printf("Enter name: ");
                scanf("%s", newnode->Name);
                printf("Enter ID: ");
                scanf("%d", &newnode->Id);
                newnode->Address = (char*)malloc(100 * sizeof(char));
                printf("Enter Address: ");
                scanf("%s", newnode->Address);
                newnode->ptr = temp2->ptr;
                temp2->ptr = newnode;
            }
            break;
        case 5:
            printf("Enter Position of student to delete\n");
            scanf("%d", &pos1);
            struct student *temp3, *frontnode;
            temp3 = head;
            int i = 1;
            while (i < pos1 - 1) {
                temp3 = temp3->ptr;
                i++;
            }
            frontnode = temp3->ptr;
            temp3->ptr = frontnode->ptr;
            free(frontnode);
            break;
        case 6:
            sortStudentsByName(&head);
            break;
        case 7:
            sortStudentsById(&head);
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }
    return 0;
}
