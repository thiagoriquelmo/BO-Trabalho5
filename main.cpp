//Autor: Thiago Riquelmo Marques Nascimento

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string.h>
#include <stdio.h>

#include "Lista.h"

using namespace std;

#define MAX_DADOS 20

int main()
{
    srand(10);
    Lista loe;
    int tamanho, escolha, dados[MAX_DADOS], aux;
    char op;

    ifstream arquivo("dados.txt");
    char linha[255 + 1];

    if (arquivo.fail())
    {
        cout << "ERRO AO ABRIR ARQUIVO!";
        abort();
    }

    //lendo o arquivo e salvando os dados em um vetor
    arquivo.getline(linha, 255);
    aux = atoi(strtok(linha, " "));
    for (int i = 0; i < MAX_DADOS; i++)
    {
        dados[i] = aux;
        aux = atoi(strtok(NULL, " "));
    }

    arquivo.close();

    //inserindo os dados lidos do arquivo na lista loe
    for (int i = 0; i < MAX_DADOS; i++)
    {
        loe.insere(dados[i]);
    }


    //imprime a lista desordenada
    cout << "\n - Lista Desordenada - " << endl;
    loe.imprime();

    
    cout << "\n -> Escolha a opcao desejada :" << endl ;
    cout << "\n 1. Mostrar o estado da lista a cada iteracao do algoritmo!" << endl ;
    cout << "\n 2. Mostrar o numero de acessos a estrutura de dados!" << endl ;
    cin>>escolha;
    
    //ordena a lista
    cout << "\n - Ordenando a lista - " << endl ;
    if(escolha==1){
        loe.heapSort(loe.valores, false, true);
    }
    else if(escolha==2){
        loe.heapSort(loe.valores, true, false);
    }
    else{
        cout << "\n A OPCAO DIGITADA NAO EXISTE! " << endl ;
    }
    //imprime a lista ja ordenada
    cout << "\n - Lista ordenada - " << endl ;
    loe.imprime();    

    cout << "\n xxx Lista Aleatoria xxx " << endl ;
    
    system("pause");
    
    for(int j=1; j<=100 ; j++){
        int clientesAleatorios[j];
        for(unsigned i=0; i< j; i++){
            clientesAleatorios[i] = (rand()%1000 + 1);
        }

        Lista aleatoria;
        //inserindo dados aleatorios na lista
        for(unsigned i=0; i<j ; i++){
            aleatoria.insere(clientesAleatorios[i]);
        }

        cout << "\n Lista com "<< j << " elementos:"<< endl ;
        aleatoria.heapSort(aleatoria.valores,true,false);
        
    }

    return 0;
}
