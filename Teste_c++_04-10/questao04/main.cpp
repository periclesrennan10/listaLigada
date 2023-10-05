#include <iostream>

using namespace std;

struct No {
    int data;
    No* next;

    No (int data){
    	this -> data = data;
    	this -> next = NULL;
	}
};

void printList(No* head) {
    No* atual = head;
    cout << "[";

    while (atual != NULL) {
        cout << atual->data << " ";
        atual = atual->next;
    }
    cout << "]" << endl;
}

int buscaBinaria(No* head, int valorBuscado) {
    int index = 0;
    No* atual = head;

    while (atual != NULL) {
        if (atual->data == valorBuscado) {
            return index; 
        }
        atual = atual->next;
        index++;
    }

    return -1;
}

int main() {
    No* head = NULL;

    head = new No(1);
    head->next = new No(2);
    head->next->next = new No(3);
    head->next->next->next = new No(4);
    head->next->next->next->next = new No(5);

    cout << "Lista: ";
    printList(head);

    int valorBuscado = 4;
    int index = buscaBinaria(head, valorBuscado);

    if (index != -1) {
        cout << "Numero " << valorBuscado << " encontrado no indice " << index << "." << endl;
    } else {
        cout << "Numero " << valorBuscado << " nao encontrado na lista." << endl;
    }

    No* current = head;
    while (current != NULL) {
        No* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}

