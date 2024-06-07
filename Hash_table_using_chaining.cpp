#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 11
#define STRING_LEN 100

typedef struct Node{
	char string[STRING_LEN];
	Node* next;
}Node;

Node* hash_table[TABLE_SIZE] = {NULL};

int hash(char string[]){
	int sum = 0;
	int len = strlen(string);
	
	for(int i = 0; i < len; i++){
		sum += string[i];
	}
	return sum % TABLE_SIZE;
}

void insert(char string[]){
	Node* new_node = (Node*)malloc(sizeof(Node));
	strcpy(new_node->string, string);
	new_node->next = NULL;	
	
	int key = hash(string);
	
	if(hash_table[key] == NULL){
		hash_table[key] = new_node;
	}else{
		Node *temp = hash_table[key];
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = new_node;
	}
	
}

void view_hash_table(){
	printf("HASH TABLE\n");
	for(int i = 0; i < TABLE_SIZE; i++){
		printf("%d: ", i+1);
		Node* temp = hash_table[i];
		if(temp == NULL){
			printf("Empty");
		}else{
			while(temp != NULL){
				printf("%s->", temp->string);
				temp = temp->next;
			}
		}
		puts("");
	}
	puts("");
}

Node* search(char string[]){
	int key = hash(string);
	if(!hash_table[key]){
		return NULL;
	}
	
	Node* temp = hash_table[key];
	while(temp){
		if(strcmp(temp->string, string) == 0){
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

void delete_node(char string[]){
	int key = hash(string);
	
	// kalo kosong
	if(!hash_table[key]){
		puts("Data doesn't exist");
		return;
	}
	
	// kalo berisi
	Node* curr = hash_table[key];
	// kalo gaada next
	if(curr->next == NULL && strcmp(curr->string, string) == 0){
		hash_table[key] = NULL;
		free(curr);
		return;
	}else if(curr->next != NULL && strcmp(curr->string, string) == 0){
		hash_table[key] = curr->next;
		free(curr);
		return;
	}else{
		while(curr->next != NULL){
			if(strcmp(curr->next->string, string) == 0){
				Node* del = curr->next;
				curr->next = curr->next->next;
				free(del);
				return;
			}
			curr = curr->next;
		}
	}
}

void view_menu(){
	printf("Choose operations:\n");
	printf("1. Insert\n");
	printf("2. Search\n");
	printf("3. Delete\n");
	printf("4. Exit\n");
	puts("");
}


int main(){
	
	int option;
	do{
		view_hash_table();
		view_menu();
		scanf("%d", &option);
		getchar();
		switch(option){
			char input[STRING_LEN];
			Node* result;
			case 1:
				// insert
				
				printf("Input a string to be inserted:\n");
				
				scanf("%[^\n]", &input);
				getchar();
				insert(input);
				break;
			case 2:
				// search
				printf("Input a string to be searched:\n");
				scanf("%[^\n]", &input);
				getchar();
				result = search(input);
				if(result){
					printf("Found %s\n", result->string);
				}else{
					printf("String not found\n");
				}
				system("pause");
				break;
			case 3:
				// delete
				printf("Input a string to be deleted:\n");
				scanf("%[^\n]", &input);
				getchar();
				delete_node(input);
				break;
			default:
				break;
				
		}
		system("cls");	
	}while(option != 4);

	return 0;
}
