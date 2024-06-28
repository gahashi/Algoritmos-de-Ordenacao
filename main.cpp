#include <iostream>
#include <cstdlib>
#include <ctime>
#include "testeDeasempenho.cpp"
#include "sortingAlgs.h"

using namespace std;

void menu()
{
    cout << "Bem vindo ao algoritmos de ordenacao" << endl;
    cout << endl;
    cout << "1. Teste automatico de algoritmos de ordenacao" << endl;
    cout << "2. Teste QuickSort" << endl;
    cout << "3. Teste InsertionSort" << endl;
    cout << "4. Teste SelectionSort" << endl;
    cout << "5. Teste BubbleSort" << endl;
    cout << "6. Teste MergeSort" << endl;
    cout << "7. Teste ShellSort" << endl;
    cout << "8. Historico" << endl;
    cout << "9. Configuracoes" << endl;
    cout << "0. Sair" << endl;
    cout << "" << endl;
}

void configuracoes(int &TAM, int &nVetores, bool &exibir)
{
    bool config = true;
    int controle;

    while (config)
    {
        cout << "Menu de configuracoes, digite uma opcao:" << endl;
        cout << "1. Quantidade de vetores: " << nVetores << endl;
        cout << "2. Tamanho dos vetores: " << TAM << endl;
        cout << "3. Exibir vetor: " << (exibir ? "Sim" : "Nao") << endl;
        cout << "4. Limpar historico" << endl;
        cout << "0. Sair" << endl
             << endl;
        cout << "Escolha uma opcao: ";
        cin >> controle;

        switch (controle)
        {
        case 1:
            cout << "Digite a nova quantidade de vetores: ";
            cin >> nVetores;
            cout << "Quantidade de vetores atualizada para: " << nVetores << endl;
            break;
        case 2:
            cout << "Digite o novo tamanho dos vetores: ";
            cin >> TAM;
            cout << "Tamanho dos vetores atualizado para: " << TAM << endl;
            break;
        case 3:
            exibir = !exibir;
            cout << "Exibir vetor configurado para: " << (exibir ? "Sim" : "Nao") << endl;
            break;
        case 4:
            // Limpar histórico
            if (limparHistorico())
            {
                cout << "Historico limpo com sucesso!" << endl;
            }
            else
            {
                cout << "Erro ao limpar historico." << endl;
            }
            break;
        case 0:
            config = false;
            break;
        default:
            cout << "Opcao invalida. Tente novamente." << endl;
            break;
        }
    }
}

int main()
{
    system("cls");
    bool interface = true, exibir = false;
    srand(time(NULL));
    int controle, nVetores = 1, TAM = 100000;

    while (interface)
    {
        menu();
        cout << "Escolha uma opcao: ";
        cin >> controle;

        switch (controle)
        {
        case 1:
            cout << "Teste automatico ainda nao implementado." << endl;
            testeOrdenacao(preencher_aleatorio, "Aleatorio", quickSortWrapper, "QuickSort", TAM, nVetores);
            testeOrdenacao(gerarPiorCasoDecrescente, "Pior caso", quickSortWrapper, "QuickSort", TAM, nVetores);

            testeOrdenacao(preencher_aleatorio, "Aleatorio", insertionSort, "InsertionSort", TAM, nVetores);
            testeOrdenacao(gerarPiorCasoDecrescente, "Pior caso", insertionSort, "InsertionSort", TAM, nVetores);

            testeOrdenacao(preencher_aleatorio, "Aleatorio", selectionSort, "SelectionSort", TAM, nVetores);
            testeOrdenacao(gerarPiorCasoDecrescente, "Pior caso", selectionSort, "SelectionSort", TAM, nVetores);

            testeOrdenacao(preencher_aleatorio, "Aleatorio", bubbleSortPlus, "BubbleSortPlus", TAM, nVetores);
            testeOrdenacao(gerarPiorCasoDecrescente, "Pior caso", bubbleSortPlus, "BubbleSortPlus", TAM, nVetores);

            testeOrdenacao(preencher_aleatorio, "Aleatorio", mergeSortWrapper, "MergeSort", TAM, nVetores);
            testeOrdenacao(gerarPiorCasoDecrescente, "Pior caso", mergeSortWrapper, "MergeSort", TAM, nVetores);

            testeOrdenacao(gerarPiorCasoDecrescente, "Pior caso", shellSort, "ShellSort", TAM, nVetores);

            break;
        case 2:

            testeOrdenacao(preencher_aleatorio, "Aleatorio", quickSortWrapper, "QuickSort", TAM, nVetores);
            break;
        case 3:

            testeOrdenacao(preencher_aleatorio, "Aleatorio", insertionSort, "InsertionSort", TAM, nVetores);
            break;
        case 4:

            testeOrdenacao(preencher_aleatorio, "Aleatorio", selectionSort, "SelectionSort", TAM, nVetores);
            break;
        case 5:

            testeOrdenacao(preencher_aleatorio, "Aleatorio", bubbleSortPlus, "BubbleSortPlus", TAM, nVetores);
            break;
        case 6:

            testeOrdenacao(preencher_aleatorio, "Aleatorio", mergeSortWrapper, "MergeSort", TAM, nVetores);
            break;
        case 7:

            testeOrdenacao(preencher_aleatorio, "Aleatorio", shellSort, "ShellSort", TAM, nVetores);
            break;
        case 8:
            mostrarHistorico();
            break;
        case 9:
            cout << "Configuracoes." << endl;
            configuracoes(TAM, nVetores, exibir);

            break;
        case 0:
            interface = false;
            break;
        default:
            cout << "Opcao invalida. Tente novamente." << endl;
            break;
        }
    }

    return 0;
}
