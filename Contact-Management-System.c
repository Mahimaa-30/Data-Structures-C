#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[15];
    struct Contact* next;
};

struct Contact* head = NULL;

void addContact(char name[], char phone[]) {
    struct Contact* newNode = (struct Contact*)malloc(sizeof(struct Contact));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->next = head;
    head = newNode;
}

void displayContacts() {
    struct Contact* temp = head;
    while(temp != NULL) {
        printf("%s - %s\n", temp->name, temp->phone);
        temp = temp->next;
    }
}

int main() {
    addContact("Alice", "12345");
    addContact("Bob", "67890");

    printf("Contacts:\n");
    displayContacts();

    return 0;
}
