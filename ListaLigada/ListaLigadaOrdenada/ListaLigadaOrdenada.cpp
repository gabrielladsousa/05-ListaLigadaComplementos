#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	int temp; 

	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: \n";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL) {
		primeiro = novo;
	}
	else {

		NO* aux = primeiro;
		while (aux->prox != NULL) {
			if (aux->valor == novo->valor) {
				cout << "O elemento ja existe!\n";
				free(novo);
				return;
			}
			aux = aux->prox;
		}

		if (aux->valor == novo->valor) {
			cout << "O elemento ja existe!\n";
			free(novo);
			return;
		}

		aux->prox = novo;

		NO* atual = primeiro;
		while (atual->prox != NULL) {
			NO* proximo = atual->prox;
			while (proximo != NULL) {
				if (atual->valor > proximo->valor) {
					temp = atual->valor;
					atual->valor = proximo->valor;
					proximo->valor = temp;
				}
				proximo = proximo->prox;
			}
			atual = atual->prox;
		}
	}
}

void excluirElemento()
{
	int elemento;

	if (primeiro == NULL)
	{
		cout << "Lista vazia\n";
		return;
	}

	cout << "Qual elemento deseja excluir?\n";
	cin >> elemento;

	NO* atual = primeiro;
	NO* anterior = NULL;

	while (atual != NULL && atual->valor < elemento) {
		anterior = atual;
		atual = atual->prox;
	}

	if (atual != NULL && atual->valor == elemento) {
		if (anterior == NULL) {
			primeiro = atual->prox;
		}
		else {
			anterior->prox = atual->prox;
		}
		cout << "ELEMENTO EXCLUIDO!\n";
		free(atual);
	}
	else {
		cout << "ELEMENTO NAO ENCONTRADO\n";
	}
}

void buscarElemento()
{
	int elemento;

	if (primeiro == NULL)
	{
		cout << "Lista vazia\n";
		return;
	}

	cout << "Qual elemento deseja buscar? \n";
	cin >> elemento;

	NO* atual = primeiro;
	while (atual != NULL && atual->valor < elemento){
		atual = atual->prox;
	}

	if (atual != NULL && atual->valor == elemento){
		cout << "ELEMENTO ENCONTRADO!\n";
	}
	else{
		cout << "ELEMENTO NAO ENCONTRADO!\n";
	}
}


