#include <iostream>

using namespace std;

struct No {
	int num;
	No *next;
};

void printList(No *head){
	No *atual = head;
	printf("\n[");
	
	while (atual != NULL){
		cout << atual -> num << " ";
		atual = atual -> next;
	}
	printf("]");
}

void inverterList(No *&head){
	No *anterior = NULL;
	No *atual = head;
	No *next = NULL;
	
	while (atual != NULL){
		next = atual -> next;
		atual -> next = anterior;
		anterior = atual;
		atual = next;
	}
	
	head = anterior;
}



int main () {
	
	int vetor[3] = {1, 2, 3};
		
	No *head = new No;
	
	head -> num = vetor[0];
	head -> next = NULL;
	
	No *segundoNum = new No;
	segundoNum -> num = vetor[1];
	segundoNum -> next = NULL;
	
	segundoNum -> next = head;
	
	No *terceiroNum = new No;
	terceiroNum -> num = vetor[2];
	terceiroNum -> next = NULL;
	
	terceiroNum -> next = segundoNum;
	
	cout << "Lista invertida: ";
	printList(terceiroNum);
	
	inverterList(terceiroNum);
	
	cout << endl << "Lista original: ";
	printList(terceiroNum);
	
	
	return 0;
	
}
