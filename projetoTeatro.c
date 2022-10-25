/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

#include <locale.h>

#include <string.h>

#include "teatro.h"

using namespace std;

int ultimacadeira = 0, livres = 0, vendidas = 0;
void exibeCadeira(Lista < CadeiraStruct > lista, int tamanho) {
  livres = 0;
  vendidas = 0;
  for (int i = 0; i < tamanho; i++) {
    ultimacadeira = i;
    if (lista.cadeiraVazia(i) == true) {
      livres++;
      cout << lista.getValor(i).numero;
    } else {
      vendidas++;
      cout << "X";
    }

    cout << endl;
  };
}

int main() {

  cout << "Teatro" << endl;
  int tamanho, num;
  cout<<"QUANTIDADE DE CADEIRAS: "; 
  cin>>tamanho;
  Lista <CadeiraStruct> minhalista(tamanho);

  system("cls||clear");
  
  int opc;
  do {
    cout << "1 - Venda" << endl;
    cout << "2 - Devolução" << endl;
    cout << "3 - Exibir" << endl;
    cout << "Selecione: ";
    cin >> opc;
    switch (opc) {

    case 1:
      exibeCadeira(minhalista, tamanho);
      cout << "ESCOLHA UM NUMERO DA CADEIRA" << endl;
      cin >> num;
      if (num > ultimacadeira) {
        cout << "CADEIRA INDISPONIVEL" << endl << endl;
      } else if (minhalista.cadeiraVazia(num) == true) {
        minhalista.ocupaCadeira(num);
        cout << "COMPRA EFETUADA COM SUCESSO" << endl << endl;
      } else {
        cout << "CADEIRA OCUPADA" << endl;
      }
      break;

    case 2:
      for (int i = 0; i < tamanho; i++) {
        if (minhalista.cadeiraVazia(i) == false) {
          cout << minhalista.getValor(i).numero;
          ultimacadeira = i;
          cout << endl;
        }
      };
      if (ultimacadeira > 0) {
        cout << "CADEIRA PARA DEVOLUÇAO " << endl;
        cin >> num;
        if (num > ultimacadeira) {
          cout << "CADEIRA INDISPONIVEL" << endl;
        } else if (minhalista.cadeiraVazia(num) == false) {
          minhalista.desocupaCadeira(num);
          cout << "DEVOLUÇAO EFETUADA COM SUCESSO" << endl << endl;
        } else {
          cout << "CADEIRA VAZIA" << endl;
        }
      } else {
        cout << "NÃO EXISTE CADEIRAS PARA DEVOLUÇAO" << endl;
      }

      break;

    case 3:
      exibeCadeira(minhalista, tamanho);
      cout << "CADEIRAS VENDIDAS: " << vendidas << endl;
      cout << "CADEIRAS LIVRES: " << livres << endl;
      break;
    default:
      cout << "OPÇÃO INCORRETA" << endl;
      break;
    }
  } while (opc != 9);

  return 0;
}
