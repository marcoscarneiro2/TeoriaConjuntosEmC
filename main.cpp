#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


void Imprime(int conjunto[200], int Tam){
    for(int i=0;i<Tam;i++){
        cout<<conjunto[i]<<", ";
    }
}

int Altera(int conjunto[100]){
    int contador=0;
    int valor;
    do{
        cout<<"\n\nDigite um valor ou -1 para sair: ";
        cin>>valor;

        if(valor>=0){
            conjunto[contador]=valor;
            contador++;
            cout<<"\n\nValor inserido!\n\n";
        }else{
            cout<<"\n\nValor invalido!\n\n";
        }
        system("cls");
    }while(valor!=-1 && contador<100);

    if(contador==100){
        cout<<"\n\nTamanho do conjunto foi atingido!\n\n";
    }
    return contador;
}

bool Existe(int valor, int conjunto[200], int Tam){
    for(int i=0;i<Tam;i++){
        if(conjunto[i]==valor){
            return true;
        }
    }
    return false;
}

int Uniao(int ConjA[100], int ElemA, int ConjB[100], int ElemB, int ConjU[200]){
    int TamU;
    for(int i=0;i<ElemA;i++){
        ConjU[i]=ConjA[i];
    }
    TamU=ElemA;

    for(int i=0;i<ElemB;i++){
        if( ! Existe(ConjB[i],ConjU,TamU)){
            ConjU[TamU]=ConjB[i];
            TamU++;
        }
    }
    return TamU;
}

int Intersecao(int ConjA[100], int ElemA, int ConjB[100], int ElemB, int ConjI[100]){
    int ContI=0;
    for(int i=0;i<ElemA;i++){
        if( Existe(ConjA[i],ConjB,ElemB) ){
            ConjI[ContI]=ConjA[i];
            ContI++;
        }
    }
    return ContI;
}

int Diferenca(int ConjA[100], int ElemA, int ConjB[100], int ElemB, int ConjD[100]){
 
    int contador=0;
    for(int i=0;i<ElemA;i++){
        if( ! Existe(ConjA[i],ConjB,ElemB) ){
            ConjD[contador] = ConjA[i];
            contador++;
        }
    }
    return contador;
}

int Cartesiano(int ConjA[100], int ElemA, int ConjB[100], int ElemB, int ConjC[200]){
	int i=0;
	int j=0;
	for(int i = 0; i < ElemA; i++)
	for(int j = 0; j < ElemB; j++)
  	printf("(%d,%d)\n", ConjA[i], ConjB[j]);

 		printf("\n\n");			
}

int main(){
    int opcao;

    int A[100], B[100];
    int ContA=0, ContB=0;

    int UNIAO[200];
    int ContU=0;

    int INTERSEC[100];
    int ContI=0;

    int DIFERENCA[100];
    int ContD=0;
    
    int PCARTESIANO[200];
    int ContC=0;
    
    while(1){
        system("cls");
        cout<<"\n\n Conjuntos \n\n";

        cout<<"A = {";
        if(ContA!=0) Imprime(A,ContA);
        else cout<<"VAZIO";
        cout<<"}\n";

        cout<<"B = {";
        if(ContB!=0) Imprime(B,ContB);
        else cout<<"VAZIO";
        cout<<"}\n\n";

        cout<<"   --- MENU --- \n\n";

        cout<<" 1 - Alterar conjunto A\n";
        cout<<" 2 - Alterar conjunto B\n";
        cout<<" 3 - Uniao dos conjuntos\n";
        cout<<" 4 - Intersecao dos conjuntos\n";
        cout<<" 5 - Diferenca A - B\n";
        cout<<" 6 - Diferenca B - A\n";
        cout<<" 7 - Produto Cartesiano\n";
        cout<<" 8 - Comprimento de A\n";
        cout<<" 9 - Comprimento de B\n";
        cout<<" 10 - Sair\n";
        

        cout<<"\nOpcao desejada: ";
        cin>>opcao;

        switch(opcao){
            case 1: //Alterar A
                system("cls");
                cout<<"\n\nAlterar o conjunto A\n\n";
                ContA = Altera(A);
                break;
            case 2: //Alterar B
                system("cls");
                cout<<"\n\nAlterar o conjunto B\n\n";
                ContB = Altera(B);
                break;
            case 3://Uni�o
                system("cls");
                cout<<"\n\nUniao\n\n";
                ContU = Uniao(A,ContA,B,ContB,UNIAO);
                cout<<"U = {";
                Imprime(UNIAO,ContU);
                cout<<"}\n\n";
                system("pause");
                break;
            case 4://Interse��o
                system("cls");
                cout<<"\n\nIntersecao\n\n";
                ContI = Intersecao(A,ContA,B,ContB,INTERSEC);
                cout<<"I = {";
                Imprime(INTERSEC,ContI);
                cout<<"}\n\n";
                system("pause");
                break;
            case 5://Diferen�a de A para B
                system("cls");
                cout<<"\n\nDiferenca A - B\n\n";
                ContD = Diferenca(A,ContA,B,ContB,DIFERENCA);
                cout<<"I = {";
                Imprime(DIFERENCA,ContD);
                cout<<"}\n\n";
                system("pause");
                break;
            case 6://Diferen�a de B para A
                system("cls");
                cout<<"\n\nDiferenca B - A\n\n";
                ContD = Diferenca(B,ContB,A,ContA,DIFERENCA);
                cout<<"I = {";
                Imprime(DIFERENCA,ContD);
                cout<<"}\n\n";
                system("pause");
                break;
            case 7://Plano Cartesiano de A para B
                system("cls");
                cout<<"\n\nCartesiano A-B\n\n";
                ContC = Cartesiano(A,ContA,B,ContB,PCARTESIANO);
                cout<<"C = {";
                Imprime(PCARTESIANO,ContC);
                cout<<"}\n\n";
                system("pause");
                break;
			case 8://Comprimento de A
                system("cls");
                cout<<"\n\nComprimento de A\n\n";
                system("pause");
                break; 
			case 9://Comprimento de B
                system("cls");
                cout<<"\n\nComprimento de B\n\n";
                system("pause");
                break;   	    
            case 10:
                cout<<"\nFinalizando...\n\n";
                system("pause");
                exit(0);
                break;
            
            default:
                cout<<"Opcao invalida! Tente novamente\n\n";
                system("pause");
        }


    }
    return 0;
}
