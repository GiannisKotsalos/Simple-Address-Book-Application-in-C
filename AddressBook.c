#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct abEntry {
    int am;
    char lname[20];
    char fname[30];
    char address[40];
    int zip;
    char email[20];
};

struct abEntry Arr[30];
int n;

// Function Declarations
int compare(const void* a, const void* b);
void getAbEntry();
void saveAddressBook();
void loadAddressBook();
void displayAbEntry();
void appendAbEntry();
void Sort();
void findAbEntry();

// Function to compare last names for qsort
int compare(const void* a, const void* b) {
    struct abEntry* pa = (struct abEntry*)a;
    struct abEntry* pb = (struct abEntry*)b;

    return strcmp(pa->lname, pb->lname);
}

void getAbEntry() {
    int i;
    printf("Enter the desired number of entries\n");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter the AM for entry %d\n", i + 1);
        scanf("%d", &Arr[i].am);
        printf("Enter the First Name\n");
        scanf("%s", Arr[i].fname);
        printf("Enter the Last Name\n");
        scanf("%s", Arr[i].lname);
        printf("Enter the Address\n");
        scanf("%s", Arr[i].address);
        printf("Enter the Zip Code\n");
        scanf("%d", &Arr[i].zip);
        printf("Enter the Email\n");
        scanf("%s", Arr[i].email);
    }
}

void saveAddressBook() {
    int i;
    FILE* fpointer;
    fpointer = fopen("AddressBookFile.txt", "w+");

    fprintf(fpointer, "START OF FILE\n");

    if (fpointer == NULL) {
        printf("File does not exist\n");
        return;
    }

    for (i = 0; i < n; i++) {
        fprintf(fpointer, "First Name=%s||", Arr[i].fname);
        fprintf(fpointer, "Last Name=%s||", Arr[i].lname);
        fprintf(fpointer, "AM=%d||", Arr[i].am);
        fprintf(fpointer, "Address=%s||", Arr[i].address);
        fprintf(fpointer, "Email=%s||", Arr[i].email);
        fprintf(fpointer, "Zip Code=%d||", Arr[i].zip);
    }

    fprintf(fpointer, "End of entry\n");
    fclose(fpointer);
    printf("Entry saved successfully\n");
}

void loadAddressBook() {
    int i;
    FILE* filepointer;
    filepointer = fopen("AddressBookFile.txt", "r");

    if (filepointer == NULL) {
        printf("File does not exist\n");
        return;
    }

    for (i = 0; i < n; i++) {
        fscanf(filepointer, "%s", Arr[i].fname);
        fscanf(filepointer, "%s", Arr[i].lname);
        fscanf(filepointer, "%s", Arr[i].address);
        fscanf(filepointer, "%d", &Arr[i].am);
        fscanf(filepointer, "%d", &Arr[i].zip);
        fscanf(filepointer, "%s", Arr[i].email);
    }
    printf("Data has been loaded. Press 2 to display.\n");
}

void displayAbEntry() {
    int i;
    printf("The address entries are as follows:\n");
    for (i = 0; i < n; i++) {
        printf("%d-th entry:\n", i + 1);
        printf("First Name: %s\n", Arr[i].fname);
        printf("Last Name: %s\n", Arr[i].lname);
        printf("Address: %s\n", Arr[i].address);
        printf("AM: %d\n", Arr[i].am);
        printf("Zip Code: %d\n", Arr[i].zip);
        printf("Email: %s\n", Arr[i].email);
    }
}

void appendAbEntry() {
    int numofreg;
    printf("Enter the number of the record to append:\n");
    scanf("%d", &numofreg);
    printf("Enter the AM for the entry\n");
    scanf("%d", &Arr[numofreg].am);
    printf("Enter the First Name\n");
    scanf("%s", Arr[numofreg].fname);
    printf("Enter the Last Name\n");
    scanf("%s", Arr[numofreg].lname);
    printf("Enter the Address\n");
    scanf("%s", Arr[numofreg].address);
}

void Sort() {
    qsort(Arr, n, sizeof(struct abEntry), compare);
    printf("After sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d-th entry:\n", i + 1);
        printf("Last Name: %s\n", Arr[i].lname);
        printf("First Name: %s\n", Arr[i].fname);
        printf("Address: %s\n", Arr[i].address);
        printf("AM: %d\n", Arr[i].am);
        printf("Zip Code: %d\n", Arr[i].zip);
        printf("Email: %s\n", Arr[i].email);
    }
}

void findAbEntry() {
    int i;
    char key[10];
    printf("Enter the last name of the entry to find:");
    scanf("%s", key);

    struct abEntry* result = bsearch(key, Arr, n, sizeof(struct abEntry), compare);

    printf("The entry is:\n");
    if (result != NULL) {
        printf("AM: %d\n", result->am);
        printf("Zip Code: %d\n", result->zip);
        for (i = 0; i < n; i++) {
            printf("First Name: %s\n", result->fname);
            printf("Last Name: %s\n", result->lname);
            printf("Address: %s\n", result->address);
            printf("Email: %s\n", result->email);
        }

        printf("%s is present at index %d", key, result - Arr);
    } else {
        printf("String %s is not present in array\n", key);
    }
}

int main() {
    int number, j;
    for (j = 0; j < 10; j++) {
        printf("Choose the desired action\n");
        printf("1. Enter new entry\n");
        printf("2. Display entries\n");
        printf("3. Append entry\n");
        printf("4. Save entries to file\n");
        printf("5. Load previous entries from file\n");
        printf("6. Sort entries\n");
        printf("7. Search for a specific entry\n");
        printf("8. Exit the program\n");
        scanf("%d", &number);

        if (number != 8) {
            switch (number) {
                case 1:
                    getAbEntry();
                    break;
                case 2:
                    displayAbEntry();
                    break;
                case 3:
                    appendAbEntry();
                    break;
                case 4:
                    saveAddressBook();
                    break;
                case 5:
                    loadAddressBook();
                    break;
                case 6:
                    Sort();
                    break;
                case 7:
                    findAbEntry();
                    break;
            }
        } else {
            break;
        }
    }

    return 0;
}
