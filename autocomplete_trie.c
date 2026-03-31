#include <stdio.h>
#include <stdlib.h>

struct Trie {
    struct Trie* child[26];
    int isEnd;
};

struct Trie* create() {
    struct Trie* node = (struct Trie*)malloc(sizeof(struct Trie));
    for(int i = 0; i < 26; i++)
        node->child[i] = NULL;
    node->isEnd = 0;
    return node;
}

void insert(struct Trie* root, char* word) {
    for(int i = 0; word[i]; i++) {
        int index = word[i] - 'a';
        if(root->child[index] == NULL)
            root->child[index] = create();
        root = root->child[index];
    }
    root->isEnd = 1;
}

int search(struct Trie* root, char* word) {
    for(int i = 0; word[i]; i++) {
        int index = word[i] - 'a';
        if(root->child[index] == NULL)
            return 0;
        root = root->child[index];
    }
    return root->isEnd;
}

int main() {
    struct Trie* root = create();

    insert(root, "hello");
    insert(root, "help");

    if(search(root, "help"))
        printf("Found\n");
    else
        printf("Not Found\n");

    return 0;
}
