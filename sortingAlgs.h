void quickSort(int v[], int esq, int dir)
{
    int aux;
    int i = esq;
    int j = dir;
    int x = v[(i + j) / 2];
    do
    {
        while (x > v[i])
        {
            i = i + 1;
        }
        while (x < v[j])
        {
            j = j - 1;
        }
        if (i <= j)
        {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    } while (!(i > j));
    if (esq < j)
    {
        quickSort(v, esq, j);
    }
    if (dir > i)
    {
        quickSort(v, i, dir);
    }
}

void quickSortWrapper(int v[], int tam)
{
    quickSort(v, 0, tam - 1);
}

void insertionSort(int vetor[], int tam)
{
    int chave, i;
    for (int j = 1; j < tam; j++)
    {
        chave = vetor[j];
        i = j - 1;
        while (i >= 0 && vetor[i] > chave)
        {
            vetor[i + 1] = vetor[i];
            i--;
        }
        vetor[i + 1] = chave;
    }
}

void selectionSort(int vet[], int tam)
{
    for (int i = 0; i < tam - 1; i++)
    {
        int pos_menor = i;
        for (int j = i + 1; j < tam - 1; j++)
        {
            if (vet[j] < vet[pos_menor])
            {
                pos_menor = j;
            }
        }
        int temp = vet[i];
        vet[i] = vet[pos_menor];
        vet[pos_menor] = temp;
    }
}

void bubbleSortPlus(int vetor[], int tam)
{
    bool troca = true;
    int lim = tam - 1;
    int k = lim;
    while (troca)
    {
        troca = false;
        for (int i = 0; i < lim; i++)
        {
            if (vetor[i] > vetor[i + 1])
            {
                int temp = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = temp;
                k = i;
                troca = true;
            }
        }
        lim = k;
    }
}

void mesclar(int v[], int comeco, int meio, int fim)
{
    int com1 = comeco;
    int com2 = meio + 1;
    int tam = fim - comeco + 1;
    int comAux = 0;
    int *vetAux = new int[tam];
    while (com1 <= meio && com2 <= fim)
    {
        if (v[com1] < v[com2])
        {
            vetAux[comAux] = v[com1];
            com1++;
        }
        else
        {
            vetAux[comAux] = v[com2];
            com2++;
        }
        comAux++;
    }
    while (com1 <= meio)
    {
        vetAux[comAux] = v[com1];
        comAux++;
        com1++;
    }
    while (com2 <= fim)
    {
        vetAux[comAux] = v[com2];
        comAux++;
        com2++;
    }
    for (comAux = comeco; comAux <= fim; comAux++)
    {
        v[comAux] = vetAux[comAux - comeco];
    }
    delete[] vetAux;
}

void mergeSort(int v[], int comeco, int fim)
{
    if (comeco == fim)
        return;
    int meio = (comeco + fim) / 2;

    mergeSort(v, comeco, meio);
    mergeSort(v, meio + 1, fim);

    mesclar(v, comeco, meio, fim);
}

// Função para realizar Shell Sort
void shellSort(int vetor[], int tam)
{
    // Inicializa o intervalo (gap)
    for (int gap = tam / 2; gap > 0; gap /= 2)
    {
        // Realiza uma ordenação por inserção para esse intervalo
        for (int i = gap; i < tam; i++)
        {
            int temp = vetor[i];
            int j;
            for (j = i; j >= gap && vetor[j - gap] > temp; j -= gap)
            {
                vetor[j] = vetor[j - gap];
            }
            vetor[j] = temp;
        }
    }
}

void mergeSortWrapper(int v[], int tam)
{
    mergeSort(v, 0, tam - 1);
}
