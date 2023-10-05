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

int qtsVzsOcorrem(No *head, int numBuscado){
	int soma = 0;
	No *atual = head;
	
	while (atual != NULL){
		if (atual -> num == numBuscado){
			soma++;
		}
		atual = atual -> next;
	}
	return soma;
}

int main () {
	int vetor[5] = {1, 2, 5, 2, 2};
	
	No *head = NULL;
	
	for (int i = 0; i < 6; i++) {
        No* newNode = new No;
        newNode->num = vetor[i];
        newNode->next = head;
        head = newNode;
    }
	
	int valor = 2;
	
	int ocorrem = qtsVzsOcorrem(head, valor);
	
	cout << "O numero " << valor << " ocorrem " << ocorrem << " vezes";
	
	return 0;
}
