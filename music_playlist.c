#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char name[50];
    struct Song* next;
};

struct Song* head = NULL;

void addSong(char name[]) {
    struct Song* newNode = (struct Song*)malloc(sizeof(struct Song));
    strcpy(newNode->name, name);

    if(head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Song* temp = head;
    while(temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

void display() {
    if(head == NULL) return;

    struct Song* temp = head;
    do {
        printf("%s -> ", temp->name);
        temp = temp->next;
    } while(temp != head);

    printf("(start)\n");
}

int main() {
    addSong("Song1");
    addSong("Song2");
    addSong("Song3");

    display();
    return 0;
}
