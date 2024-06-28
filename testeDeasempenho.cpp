#include <iostream>
#include <chrono>
#include <cstdlib>
#include <fstream>

using namespace std;

// Função que retorna o clock atual em segundos como double
double marcaClock()
{
    auto now = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(now.time_since_epoch());
    return duration.count();
}

double calcularTempo(double start, double end)
{
    return end - start;
}

void mostrar_array(int vetor[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        cout << vetor[i] << ", ";
    }
    cout << endl;
}

void preencher_aleatorio(int vetor[], int tam)
{
    // Preenche o vetor com valores de 1 até tam
    for (int i = 0; i < tam; ++i)
    {
        vetor[i] = i + 1;
    }

    // Embaralha os valores no vetor para garantir que sejam únicos
    for (int i = tam - 1; i > 0; --i)
    {
        int j = rand() % (i + 1); // Gera um índice aleatório entre 0 e i
        // Troca vetor[i] com vetor[j]
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
}

// usar pior daso -->  InsertionSort / SelectionSort / BubbleSort / MergeSort / shellSort / QuickSort
void gerarPiorCasoDecrescente(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        v[i] = n - i;
    }
    // Pior caso para InsertionSort, SelectionSort, BubbleSort e MergeSort
}

void salvarResultado(const string &nomePreencherVetor, const string &nomeAlgOrdenacao, int nVetores, double media)
{
    ofstream arquivo("resultados.txt", ios::app);
    if (arquivo.is_open())
    {
        arquivo << "Tipo de preenchimento do vetor: " << nomePreencherVetor << endl;
        arquivo << "Algoritmo de ordenacao: " << nomeAlgOrdenacao << endl;
        arquivo << "Quantidade de testes: " << nVetores << endl;
        arquivo << "Media de tempo: " << media << " segundos" << endl;
        arquivo << "------------------------------------------------------------" << endl;
        arquivo.close();
    }
    else
    {
        cout << "Nao foi possivel abrir o arquivo de resultados." << endl;
    }
}

void mostrarHistorico()
{
    ifstream historico("resultados.txt");
    string linha;
    if (historico.is_open())
    {
        while (getline(historico, linha))
        {
            cout << linha << endl;
        }
        historico.close();
    }
    else
    {
        cout << "Nao foi possivel abrir o arquivo de historico." << endl;
    }
}

bool limparHistorico()
{
    ofstream historico("resultados.txt", ios::trunc);
    if (historico.is_open())
    {
        historico.close();
        return true;
    }
    else
    {
        cout << "Não foi possível abrir o arquivo de resultados para limpar." << endl;
        return false;
    }
}

void testeOrdenacao(void (*tipoPreenchereVetor)(int[], int), string nomePreencherVetor, void (*algOrdenacao)(int[], int), string nomeAlgOrdenacao, int TAM, int nVetores)
{
    double start, end, timeClock;
    double somaTempos = 0.0;

    cout << "Ordenacao: " << nomePreencherVetor << endl;
    cout << "Algoritimo de ordenacao: " << nomeAlgOrdenacao << endl
         << endl;
    cout << "______________________________________________________________\n"
         << endl;

    for (int i = 0; i < nVetores; i++)
    {
        int *vetor = new int[TAM];
        tipoPreenchereVetor(vetor, TAM);

        start = marcaClock();
        algOrdenacao(vetor, TAM);
        end = marcaClock();
        timeClock = calcularTempo(start, end);
        cout << "Vetor " << i + 1 << " tempo de execucao: " << timeClock << " segundos" << endl
             << endl;

        somaTempos += timeClock;
        delete[] vetor;
    }

    double media = somaTempos / nVetores;

    cout << "tempo medio: " << media << endl;
    salvarResultado(nomePreencherVetor, nomeAlgOrdenacao, nVetores, media);
}