 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
typedef int bool;

typedef struct Arvorenodo {

    char  nome ;
    int cor;
    char tempo;
    struct Arvorenodo *esquerda;
    struct Arvorenodo *direita;
}Arvorenodo;

Arvorenodo *cores (Arvorenodo *nodo, int cor, char tempo){

     printf("Digite um numero para determinar o estado do paciente: (1,2,3,4,5)");
    switch (cor){
    case 1:
        printf("Vermelho");
        printf("Tempo de espera é 0");
    case 2:
        printf("Laranja");
        printf("Tempo de espera é de 10 minutos");
    case 3:
        printf("Amarelo");
        printf("Tempo de espera é de 60 minutos");
    case 4:
        printf("Verde");
        printf("Tempo de espera é de 120 minutos");
    case 5:
        printf("Azul");
        printf("Tempo de espera é de 240 minutos");
    default:
        printf("Já era! Morreuuuuuuu!");
    }


}

Arvorenodo *Inserir(Arvorenodo *nodo, char nome, int cor, char tempo){
    Arvorenodo *temp;
    if (nodo == NULL){
        temp = (Arvorenodo*)malloc(sizeof(Arvorenodo));
        strcpy(temp->nome,nome);
        strcpy(temp->cor, cor);
        strcpy(temp->tempo, tempo);
        temp->esquerda = temp->direita = NULL;
        return temp;
    }
    if (cor <= temp->cor){
        nodo->esquerda = Inserir(nodo->esquerda, nome, cor, tempo);
    }
    if (cor > temp->cor){
        nodo->direita = Inserir(nodo->direita, nome, cor, tempo);
    }
}

Arvorenodo *inserirPaciente(Arvorenodo *nodo, char nome, int cor, char tempo){

    printf("Difite o nome do paciente: ");
    scanf(nome);
    printf("Digite a cor de preferencia do paciente: ");
    scanf(cor);
    printf("Digite o tempo em minutos :");
    scanf(tempo);
    Inserir(nodo, nome,cor,tempo);
}

void ImprimirArvore (Arvorenodo *nodo){
    if (nodo == NULL){
        return;
    }
    ImprimirArvore(nodo->esquerda);
    printf("\n%s ", nodo->nome);
    printf("\n%s ", nodo->cor);
    printf("\n%s", nodo->tempo);
    ImprimirArvore(nodo->direita);
}
Arvorenodo *Ficha(char *ficha1, char *ficha2){
    char i;
    int aux;
    bool exercicio = true;
    if ( strlen(ficha1) == strlen (ficha2)){
        for (i =0; ((i <strlen(ficha1))&& exercicio == true);i ++){
            if (ficha1 == ficha2)
                aux = 0;
           else  if (ficha1 > ficha2)
           {
               aux = 1;
               exercicio = true;
           }else{
               aux = -1;
               exercicio = false;
           }
        }
    }
   return aux;
}
Arvorenodo *Cor(Arvorenodo*cores, char cor, char tempo){
    int Vermelho =0;
    int Laranja =1;
    int Amarelo =2;
    int Verde =3;
    int Azul =4;
    char num [3];

    printf( "Digite um numero que represente a cor: 0-Vermelho, 1-Laranja, 2-Amarelo, 3-Verde, 4-Azul");
    scanf(num);

        if (num  < 0 || num  >4){
        printf("Numero errdo! Digite novamente: ");
    }
    if (cores->cor == Vermelho){
        printf("Terá prioridade maxima, ou morrerá hahaha!!!");
    }else
    if (cores->cor == Laranja){
        printf("Terá menos prioridade");
    }else
    if (cores->cor == Amarelo ){
        printf("Não possui preferência, pode deixar morrer!!!");
    }else
    if (cores->cor == Verde || Azul){
        printf("Já era, vai morrer sozinho!!!");
    }
}
Arvorenodo *ChamarPaciente (Arvorenodo *nodo){
    if (nodo == NULL){
        return;
    }
    ChamarPaciente(nodo->esquerda);
    printf("\n%s",nodo->tempo);
    ChamarPaciente(nodo->direita);
}
Arvorenodo *PreOrdem (Arvorenodo *nodo){
    if (nodo != NULL){
        printf("%s",nodo->tempo);
        PreOrdem(nodo->esquerda);
        PreOrdem(nodo->direita);
    }
}
Arvorenodo *NumAleatorio (Arvorenodo *nodo){
    int i;
    printf("Intervalo do tempo: [5, %d]\n", RAND_MAX);
    for (i =5; i <= 14; i++);
    printf("Número %d: %d\n",i,rand());
}

int main()
{
   Arvorenodo *raiz;
   char nome='M';
   int cor=1;
   char tempo='t';
   char ficha;
   int validacao;
   bool aux = true;
   int opcao;
   while (aux){
        printf("1- Inserir na arvore.\n");
        printf("2- Classificar paciente.\n");
        printf("3- Informacoes do paciente.\n");
        printf("4- Comparar fichas dos pacientes.\n");
        printf("5- Pacientes mais perto da morte.\n");
        printf("6- Inserir mais pacientes.\n");
        printf("7- Chamar Paciente.\n");
        printf("8- Imprimir arvore.\n");
        printf("9- Tempo de consulta.\n");
        printf("10 - Sair.\n");
        scanf("%d", opcao);

        switch (opcao){
        case 1:
            inserirPaciente(raiz, nome, cor, tempo);
            break;
        case 2:
            raiz = inserir(raiz, nome, cor, tempo);
            break;
        case 3:
            Ficha(ficha, ficha);
            break;
        case 4:
            Cor(raiz, cor, tempo);
            break;
        case 5:
            PreOrdem(raiz);
            break;
        case 6:
            inserirPaciente(raiz, nome, cor, tempo);
            break;
        case 7:
            ChamarPaciente(raiz);
            break;
        case 8:
            ImprimirArvore(raiz);
            break;
        case 9:
            NumAleatorio(raiz);
            break;
        case 10:
            exit(0);
            break;
        default:
            printf("Opcao Invalida!!!");

        }
        system("pause");
        return 0;

   }

}

