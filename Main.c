//Nawfal Cherkaoui Elmalki, 11/12/21 

/* This program demonstrates the use of structures, pointers, and linked lists.
It prompts the user for information on a person and stores the parameters in a linked list node.
Then, the user can enter more information or sort the preexisting individuals alphabetically.
*/

//pre-processor directives
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//Each Node of the linked list will point to a PERSON struct
typedef struct PERSON {
	char name[100];
	int age;
	float weight;
	struct PERSON* next;
} PERSON;

void Main_Menu(int* choice);
PERSON* Node_Maker(PERSON* head);
void Census_Printer(PERSON* head);


int main() {
	char choice;
	PERSON* head = NULL; //head of the linked list

	do {
		Main_Menu(&choice);

		switch (choice) {
		case '1':
			head = Node_Maker(head);
			break;
		case '2':
			Census_Printer(head);
			break;
		case '3':
			printf("\nSuccessfully quit.\n");
			break;
		default:
			printf("\nInvalid Choice\n\n");
			return -1;
		}
	} while (choice != '3'); //Menu system

	system("pause");
} //End of main


// Prints the User Menu and takes the user's input
void Main_Menu(char* choice) {
	printf("Main Menu\n"
		"1. Add a Record\n"
		"2. Sort and Display All Records\n"
		"3. Quit\n\n");

	printf("Choice (1,2,3): ");
	scanf(" %c", choice);
}

//This function creates individual nodes and appends them to the linked list
PERSON* Node_Maker(PERSON* head) {
	char temp_Name[100];
	int temp_Age;
	float temp_Weight;
	PERSON* p = NULL;

	printf("\nEnter Name: \n");
	scanf(" %[^\n]", temp_Name);
	printf("\nEnter Age: \n");
	scanf("%i", &temp_Age);
	printf("\nEnter Weight (in lbs.): \n");
	scanf("%f", &temp_Weight);

	PERSON* temp = malloc(sizeof(PERSON));
	strcpy(temp->name, temp_Name);
	temp->age = temp_Age;
	temp->weight = temp_Weight;
	temp->next = NULL;

	//This if statement creates the node
	if (head == NULL) {
		head = temp;
	}
	else {
		p = head;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = temp;
	} 

	printf("\nRecord added successfully\n\n---------------------------------------------------\n\n");
	return head;
} 

//Node sorting and display function
void Census_Printer(PERSON* head) {
	int count = 1;
	PERSON temp;

	int swapped, i;
	struct PERSON* node = NULL;
	struct PERSON* lptr = NULL;

	if (head == NULL) {
		printf("\n");
		return;
	}

	node = head;
	do
	{
		swapped = 0;

		//This loop sorts the nodes alphabetically by name
		while (node->next != NULL) {
			if (strcmp(node->name, node->next->name) > 0)
			{
				strcpy(temp.name, node->name); temp.age = node->age; temp.weight = node->weight;
				strcpy(node->name, node->next->name); node->age = node->next->age; node->weight = node->next->weight;
				strcpy(node->next->name, temp.name); node->next->age = temp.age; node->next->weight = temp.weight;
				swapped = 1;
			}
			node = node->next;
		}
	} while (swapped);
	node = head; 

	//This loop prints the nodes
	while (node != NULL) {
		printf("\nRecord %i:\n", count);
		count++;
		printf("Name: %s\n", node->name);
		printf("Age: %i\n", node->age);
		printf("Weight: %.2f lbs.\n\n---------------------------------------------------\n", node->weight);
		node = node->next;
	} 
	printf("\n");

} 
