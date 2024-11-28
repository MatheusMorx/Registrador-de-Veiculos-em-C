#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define N 50
#define P 9
#define MAX_CARROS 10

typedef struct{
    char marca[N];
    char modelo[N];
    char placa[P];
    int ano;
} ListaCarros;

void cadastrarCarro(ListaCarros carros[], int *contador);
void listarCarros(ListaCarros carros[], int contador);
void buscarPorModelo(ListaCarros carros[], int contador);
void buscarPorAno(ListaCarros carros[], int contador, int anoExato);
void buscarPorAnoMaior(ListaCarros carros[], int contador, int anoMin);

int main()
{
    
    setlocale(LC_ALL, "Portuguese");

    ListaCarros carros[MAX_CARROS];
    int contador = 0, escolha;

    do {
    printf("--------- SISTEMA DE VEICULOS ---------\n");
    printf("---------------- MENU ----------------\n");
    printf("1 - Cadastrar\n");
    printf("2 - Veiculos registrados\n");
    printf("3 - Buscar modelo\n");
    printf("4 - Buscar ano de fabricacao\n");
    printf("5 - Buscar por ano acima do valor definido\n");
    printf("6 - Sair\n");
    printf("Digite a Opcao: ");
    scanf("%d", &escolha);
    getchar();

    switch (escolha) {
    case 1:
        cadastrarCarro(carros, &contador);
        break;
    case 2:
        listarCarros(carros, contador);
        break;
    case 3:
        buscarPorModelo(carros, contador);
        break;
    case 4:
        printf("Digite o ano para buscar: ");
        int ano;
        scanf("%d", &ano);
        buscarPorAno(carros, contador, ano);
        break;
    case 5:
        printf("Digite o ano mínimo: ");
        int anoMin;
        scanf("&d", &anoMin);
        buscarPorAnoMaior(carros, contador, anoMin);
        break;
    case 6:
        printf("Saindo...\n");
        break;
    default:
        printf("Opção Inválida!\n");
        }
    } while (escolha != 6);

    return 0;
}

void cadastrarCarro(ListaCarros carros[], int *contador) {
    if (*contador >= MAX_CARROS) {
        printf("Limite de veículos cadastrados atingido (%d).\n", MAX_CARROS);
        return;
    
}

printf("\n--------- Cadastro de Carros ---------\n");

printf("Marca do veiculo:\n");
fgets(carros[*contador].marca, N, stdin);
strtok(carros[*contador].marca, "\n");

printf("Modelo do veiculo:\n");
fgets(carros[*contador].modelo, N, stdin);
strtok(carros[*contador].modelo, "\n");

printf("Ano de fabricacao:\n");
scanf("%d", &carros[*contador].ano);
getchar();

printf("Placa do veiculo:\n");
fgets(carros[*contador].placa, P, stdin);
strtok(carros[*contador].placa, "\n");

(*contador)++;
printf("Veículo registrado com sucesso!\n");
}

void listarCarros(ListaCarros carros[], int contador) {
    if (contador == 0) {
        printf("\nNenhum veículo registado.\n");
        return;
    }

    for (int i = 0; i < contador; i++) {
        printf("\n--------- Veículo n%d ---------\n", i + 1);
        printf("Marca: %s\n", carros[i].marca);
        printf("Modelo: %s\n", carros[i].modelo);
        printf("Ano de Fabricacao: %d\n", carros[i].ano);
        printf("Placa: %s\n", carros[i].placa);
        printf("---------------------------------\n");

    }
}


void buscarPorModelo(ListaCarros carros[], int contador) {
    if (contador == 0) {
        printf("\nNenhum veículo registrado.\n");
        return;
    }

    char modelo[N];
    printf("Informe o modelo do veículo: ");
    fgets(modelo, N, stdin);
    strtok(modelo, "\n");

    int encontrado = 0;
    for (int i = 0; i < contador; i++) {
        if (strcmp(carros[i].modelo, modelo) == 0) {
            printf("\n--------- Veículo n°%d ---------\n", i + 1);
            printf("Marca: %s\n", carros[i].marca);
            printf("Modelo: %s\n", carros[i].modelo);
            printf("Ano de Fabricação: %d\n", carros[i].ano);
            printf("Placa: %s\n", carros[i].placa);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Nenhum veículo encontrado com o modelo informado.\n");
    }
}

void buscarPorAno(ListaCarros carros[], int contador, int anoExato) {
    if (contador == 0) {
        printf("\nNenhum veículo registrado.\n");
        return;
    }

    int encontrado = 0;
    for (int i = 0; i < contador; i++) {
        if (carros[i].ano == anoExato) {
            printf("\n--------- Veículo n°%d ---------\n", i + 1);
            printf("Marca: %s\n", carros[i].marca);
            printf("Modelo: %s\n", carros[i].modelo);
            printf("Ano de Fabricação: %d\n", carros[i].ano);
            printf("Placa: %s\n", carros[i].placa);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Nenhum veículo encontrado com o ano informado.\n");
    }
}

void buscarPorAnoMaior(ListaCarros carros[], int contador, int anoMin) {
    if (contador == 0) {
        printf("\nNenhum veículo registrado.\n");
        return;
    }

    int encontrado = 0;
    for (int i = 0; i < contador; i++) {
        if (carros[i].ano > anoMin) {
            printf("\n--------- Veículo n°%d ---------\n", i + 1);
            printf("Marca: %s\n", carros[i].marca);
            printf("Modelo: %s\n", carros[i].modelo);
            printf("Ano de Fabricação: %d\n", carros[i].ano);
            printf("Placa: %s\n", carros[i].placa);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Nenhum veículo encontrado com ano maior que o informado.\n");
    }
}