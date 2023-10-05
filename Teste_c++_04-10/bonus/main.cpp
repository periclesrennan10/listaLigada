#include <iostream>

using namespace std;

struct No {
    int num;
    No *next;

    No (int data) {
        this->num = data;
        this->next = NULL;
    }
};

void printList(No *head) {
    No *atual = head;
    cout << "[";

    while (atual != NULL) {
        cout << atual->num << " ";
        atual = atual->next;
    }
    cout << "]" << endl;
}

No* reverterPosicao(No *head, int x, int y) {
    if (x == y || head == NULL) {
        return head;
    }

    No *aux = new No(0);
    aux->next = head;
    No *anterior = aux;

    for (int i = 0; i < x - 1; i++) {
        anterior = anterior->next;
    }

    No *atual = anterior->next;
    No *nextNo = NULL;

    for (int i = x; i < y; i++) {
        nextNo = atual->next;
        atual->next = nextNo->next;
        nextNo->next = anterior->next;
        anterior->next = nextNo;
    }

    return aux->next;
}

int main() {
    No *head = NULL;

    head = new No(1);
    head->next = new No(2);
    head->next->next = new No(3);
    head->next->next->next = new No(4);
    head->next->next->next->next = new No(5);

    cout << "Lista Original: ";
    printList(head);

    int x = 2;
    int y = 4;

    head = reverterPosicao(head, x, y);

    cout << "Lista Revertida no Intervalo [" << x << ", " << y << "]: ";
    printList(head);

    No* atual = head;
    while (atual != NULL) {
        No *next = atual->next;
        delete atual;
        atual = next;
    }

    return 0;
}

	

	


