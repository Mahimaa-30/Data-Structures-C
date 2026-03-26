#include <stdio.h>
#define MAX 10

int undoStack[MAX], redoStack[MAX];
int topUndo = -1, topRedo = -1;

void performAction(int x) {
    undoStack[++topUndo] = x;
    topRedo = -1; // clear redo
}

void undo() {
    if(topUndo == -1) return;
    redoStack[++topRedo] = undoStack[topUndo--];
}

void redo() {
    if(topRedo == -1) return;
    undoStack[++topUndo] = redoStack[topRedo--];
}

void display() {
    printf("Current State: ");
    for(int i = 0; i <= topUndo; i++)
        printf("%d ", undoStack[i]);
}

int main() {
    performAction(1);
    performAction(2);
    performAction(3);

    undo();
    redo();

    display();
    return 0;
}
