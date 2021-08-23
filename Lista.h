//Autor: Thiago Riquelmo Marques Nascimento

#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <iostream>

using namespace std;

#define MAX_VALORES 101

class Lista
{
public:
    int valores[MAX_VALORES];
    unsigned tamanho, acessos, quantidade;

    Lista()
    {
        tamanho = 0;
        quantidade = 0;
        acessos = 0;
    }
    ~Lista() {}

    void insere(int valor)
    {
        //!erro: nao tem mais espaco
        if (tamanho == MAX_VALORES)
        {
            cout << "Sem espaço" << endl;
            return;
        }

        else
        {
            valores[tamanho + 1] = valor;
            tamanho++;
            quantidade++;
        }
    }

    void imprime()
    {
        cout << endl
             << "Do inicio ao fim" << endl;
        for (unsigned i = 1; i <= tamanho; i++)
        {
            cout << "<" << valores[i] << "> ";
        }
        cout << "\n";
    }

    //função para retornar o pai
    int parent(int pos)
    {
        return pos/2;
    }

    //função para retornar o filho da esquerda
    int left(int pos)
    {
        return 2*pos; 
    }

    //função para retornar o filho da direita 
    int right(int pos)
    {
        return 2*pos+1;
    }

    void heapify(int *vetor, int pos)
    {
        int l,r,g;

        l = left(pos);
        r = right(pos);

        //verifica se o filho da esquerda é maior que o valor da posição recebida pela função
        if((l <= quantidade) && (vetor[l] > vetor[pos]))
        {
            g = l;
        }
        else
        {
            g = pos;
        }

        /*  
            verifica se o filho da direita é maior que o valor da posição no auxiliar "g", 
            que pode ser o valor do filho da esquerda ou o valor da posição recebida pela função
        */
        if((r <= quantidade) && (vetor[r] > vetor[g]))
        {
            g = r;
        }

        /*
            caso o filho da direita ou o filho da esquerda seja maior que a posição recebida pela função, 
            deve ser feito uma troca de posição entre os valores que estão na posição recebida pela função 
            e a posição do auxiliar "g"
        */
        if(g != pos)
        {
            swap(vetor[pos], vetor[g]);
            acessos++;
            heapify(vetor, g);
        }
    }

    void createHeap(int *vetor)
    {
        int m;
        //calcula o indice do meio da lista
        m = quantidade/2;

        //chama a função heapify para a metade da lista, começando do meio ate o inicio
        for(int i = m; i >= 1 ; i--){
            heapify(vetor, i);
        }
    }

    void heapSort(int *vetor, bool interacoes, bool imprimir)
    {
        int f;
        createHeap(vetor);
        f = quantidade;

        /*
            o for ordena a lista percorrendo e jogando o valor da primeiro posição 
            para a ultima posição da lista e chama a função heapify pra corrigir 
            a árvore, assim sempre o valor da posição 1 é o que deve ser jogado pro final
        */
        for(int i = f; i >= 2; i--)
        {
            quantidade--;
            swap(vetor[1],vetor[i]);
            acessos++;

            //opcao 1 do menu
            if (imprimir)
            {
                imprime();
            }    

            heapify(vetor, 1);
        }
        quantidade = f;
        
        //opcao 2 do menu
        if(interacoes)
        {
            cout<< "O numero de acessos foi de "<< acessos <<" vezes!"<<endl;
        }
    }


};

#endif
