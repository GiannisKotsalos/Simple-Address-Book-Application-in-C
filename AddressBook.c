#include <stdio.h>
#include <stdlib.h>

struct AddressEntry {
    int id;
    char last_name[20];
    char first_name[30];
    char address[40];
    int zip_code;
    char email[20];
};

struct AddressEntry Entries[30];
int n;

int compare(const void* a, const void* b) {
    struct AddressEntry* pa = (struct AddressEntry*)a;
    struct AddressEntry* pb = (struct AddressEntry*)b;

    return strcmp(pa->last_name, pb->last_name);
}

void getAddressEntry() {
    int i;
    printf("Enter the desired number of entries\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the ID of entry %d\n", i + 1);
        scanf("%d", &Entries[i].id);
        printf("Enter the First Name\n");
        scanf("%s", Entries[i].first_name);
        printf("Enter the Last Name\n");
        scanf("%s", Entries[i].last_name);
        printf("Enter the Address\n");
        scanf("%s", Entries[i].address);
        printf("Enter the Zip Code\n");
        scanf("%d", &Entries[i].zip_code);
        printf("Enter the Email\n");
        scanf("%s", Entries[i].email);
    }
}

void saveAddressBook() {
    int i;
    FILE* file_pointer;
    file_pointer = fopen("AddressBookFile.txt", "w+");

    fprintf(file_pointer, "START OF FILE\n");

    if (file_pointer == NULL) {
        printf("File does not exist\n");
        return;
    }

    for (i = 0; i < n; i++) {
        fprintf(file_pointer, "First Name=%s||", Entries[i].first_name);
        fprintf(file_pointer, "Last Name=%s||", Entries[i].last_name);
        fprintf(file_pointer, "ID=%d||", Entries[i].id);
        fprintf(file_pointer, "Address=%s||", Entries[i].address);
        fprintf(file_pointer, "Email=%s||", Entries[i].email);
        fprintf(file_pointer, "Zip Code=%d||", Entries[i].zip_code);
    }

    fprintf(file_pointer, "End of entry\n");
    fclose(file_pointer);
    printf("Entry saved successfully\n");
}


int main() {
    int choice, j;

    for (j = 0; j < 10; j++) {
        printf("Choose the desired action\n");
        printf("1. Enter new entry\n");
        printf("2. Display entries\n");
        printf("3. Modify entry\n");
        printf("4. Save entries to file\n");
        printf("5. Load previous entries from file\n");
        printf("6. Sort entries\n");
        printf("7. Search for a specific entry\n");
        printf("8. Exit the program\n");

        scanf("%d", &choice);

        if (choice != 8) {
            switch (choice) {
                case 1:
                    getAddressEntry();
                    break;
                case 2:
                    displayAddressEntry();
                    break;
                case 3:
                    modifyAddressEntry();
                    break;
                case 4:
                    saveAddressBook();
                    break;
                case 5:
                    loadAddressBook();
                    break;
                case 6:
                    sortEntries();
                    break;
                case 7:
                    searchAddressEntry();
                    break;
            }
        } else {
            break;
        }
    }

    return 0;
}
