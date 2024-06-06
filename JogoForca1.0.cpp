#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#ifdef _WIN32
    #define COMANDO_LIMPAR "cls"
#else
    #define COMANDO_LIMPAR "clear"
#endif

// Estrutura de representa��o de um n� da palavra
typedef struct No {
    char caractere;
    struct No* proximo;
} No;

// Fun��o para inserir uma letra no final de uma palavra
void inserirLetra(No** cabeca, char letra) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->caractere = letra;
    novoNo->proximo = NULL;

    if (*cabeca == NULL) {
        *cabeca = novoNo;
    } else {
        No* atual = *cabeca;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
    }
}

// Fun��o para imprimir a palavra, mostrando letras descobertas e "?" para letras ocultas
void imprimirPalavra(No* cabeca, int* posicoes, int tamanho) {
    No* atual = cabeca;
    for (int i = 0; i < tamanho; i++) {
        if (posicoes[i] == 1) {
            printf("%c ", atual->caractere);
        } else {
            printf("? ");
        }
        atual = atual->proximo;
    }
    printf("\n");
}

// Fun��o para verificar se uma letra est� presente em uma palavra
bool letraNaPalavra(No* cabeca, char letra, int* posicoes) {
    int indice = 0;
    bool encontrada = false;

    while (cabeca != NULL) {
        if (cabeca->caractere == letra) {
            posicoes[indice] = 1;
            encontrada = true;
        }
        indice++;
        cabeca = cabeca->proximo;
    }
    return encontrada;
}

// Fun��o para verificar se a palavra foi completamente adivinhada
bool palavraAdivinhada(int* posicoes, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (posicoes[i] == 0) {
            return false;
        }
    }
    return true;
}

// Fun��o para limpar a tela do terminal
void limparTela() {
    system(COMANDO_LIMPAR);
}

// Fun��o para comparar duas letras (usada na ordena��o alfab�tica)
int compararLetras(const void* a, const void* b) {
    return (*(const char*)a - *(const char*)b);
}

// Fun��o para selecionar uma palavra aleat�ria com base na categoria e no n�vel escolhidos
const char* obterPalavraAleatoria(int categoria, int nivel) {
    const char* animaisFase1[] = {"gato", "rato", "sapo", "peixe", "urso", "coelho", "pato", "ovelha", "bode", "cavalo"};
    const char* animaisFase2[] = {"cachorro", "elefante", "girafa", "leopardo", "hipopotamo", "tartaruga", "gorila", "papagaio", "jaguatirica", "pinguim"};
    const char* animaisFase3[] = {"ornitorrinco", "hipopotamo", "chimpanze", "rinoceronte", "camaleao", "ornitorrinco", "tigre", "morcego", "iguana", "ornitorrinco"};

    const char* frutasFase1[] = {"maca", "pera", "uva", "kiwi", "figo", "limao", "ameixa", "pessego", "manga", "caju"};
    const char* frutasFase2[] = {"laranja", "abacaxi", "mamao", "caqui", "cereja", "morango", "melancia", "melao", "framboesa", "nectarina"};
    const char* frutasFase3[] = {"carambola", "maracuja", "pinha", "lichia", "jabuticaba", "acerola", "cupua�u", "graviola", "pitanga", "araca"};

    const char* objetosFase1[] = {"mesa", "cadeira", "cama", "sofa", "porta", "janela", "lampada", "caneta", "copo", "prato"};
    const char* objetosFase2[] = {"computador", "telefone", "geladeira", "fogao", "ventilador", "microondas", "armario", "chuveiro", "piano", "livro"};
    const char* objetosFase3[] = {"ventilador", "microondas", "aspirador", "grampeador", "televisao", "abajur", "bicicleta", "batedeira", "escova", "ferro"};

    const char* paisesFase1[] = {"brasil", "canada", "chile", "peru", "italia", "china", "japao", "india", "egito", "grecia"};
    const char* paisesFase2[] = {"argentina", "australia", "portugal", "mexico", "alemanha", "franca", "inglaterra", "russia", "espanha", "polonia"};
    const char* paisesFase3[] = {"afeganistao", "zimbabue", "madagascar", "uzbequistao", "quirguistao", "azerbaijao", "turquemenistao", "liechtenstein", "luxemburgo", "cazaquistao"};

    const char* profissoesFase1[] = {"medico", "advogado", "engenheiro", "professor", "enfermeiro", "veterinario", "farmaceutico", "arquiteto", "bombeiro", "dentista"};
    const char* profissoesFase2[] = {"pediatra", "ortodontista", "cardiologista", "psiquiatra", "dermatologista", "oncologista", "radiologista", "neurologista", "fisioterapeuta", "anestesista"};
    const char* profissoesFase3[] = {"otorrinolaringologista", "neurocirurgiao", "epidemiologista", "gerontologista", "imunologista", "microbiologista", "paleontologista", "psicofarmacologista", "psiquiatra", "nutricionista"};

    const char* coresFase1[] = {"vermelho", "azul", "verde", "amarelo", "roxo", "rosa", "laranja", "preto", "branco", "cinza"};
    const char* coresFase2[] = {"turquesa", "violeta", "dourado", "prateado", "bronze", "marrom", "bege", "salmao", "magenta", "lavanda"};
    const char* coresFase3[] = {"aqua", "carmin", "esmeralda", "fuchsia", "safira", "ametista", "jade", "bronzeado", "rubor", "mocassin"};

    const char** listaPalavras;
    int numPalavras;

    switch (categoria) {
        case 1: // Animais
            switch (nivel) {
                case 1:
                    listaPalavras = animaisFase1;
                    numPalavras = sizeof(animaisFase1) / sizeof(animaisFase1[0]);
                    break;
                case 2:
                    listaPalavras = animaisFase2;
                    numPalavras = sizeof(animaisFase2) / sizeof(animaisFase2[0]);
                    break;
                case 3:
                    listaPalavras = animaisFase3;
                    numPalavras = sizeof(animaisFase3) / sizeof(animaisFase3[0]);
                    break;
                default:
                    return NULL;
            }
            break;
        case 2: // Frutas
            switch (nivel) {
                case 1:
                    listaPalavras = frutasFase1;
                    numPalavras = sizeof(frutasFase1) / sizeof(frutasFase1[0]);
                    break;
                case 2:
                    listaPalavras = frutasFase2;
                    numPalavras = sizeof(frutasFase2) / sizeof(frutasFase2[0]);
                    break;
                case 3:
                    listaPalavras = frutasFase3;
                    numPalavras = sizeof(frutasFase3) / sizeof(frutasFase3[0]);
                    break;
                default:
                    return NULL;
            }
            break;
        case 3: // Objetos
            switch (nivel) {
                case 1:
                    listaPalavras = objetosFase1;
                    numPalavras = sizeof(objetosFase1) / sizeof(objetosFase1[0]);
                    break;
                case 2:
                    listaPalavras = objetosFase2;
                    numPalavras = sizeof(objetosFase2) / sizeof(objetosFase2[0]);
                    break;
                case 3:
                    listaPalavras = objetosFase3;
                    numPalavras = sizeof(objetosFase3) / sizeof(objetosFase3[0]);
                    break;
                default:
                    return NULL;
            }
            break;
        case 4: // Pa�ses
            switch (nivel) {
                case 1:
                    listaPalavras = paisesFase1;
                    numPalavras = sizeof(paisesFase1) / sizeof(paisesFase1[0]);
                    break;
                case 2:
                    listaPalavras = paisesFase2;
                    numPalavras = sizeof(paisesFase2) / sizeof(paisesFase2[0]);
                    break;
                case 3:
                    listaPalavras = paisesFase3;
                    numPalavras = sizeof(paisesFase3) / sizeof(paisesFase3[0]);
                    break;
                default:
                    return NULL;
            }
            break;
        case 5: // Profiss�es
            switch (nivel) {
                case 1:
                    listaPalavras = profissoesFase1;
                    numPalavras = sizeof(profissoesFase1) / sizeof(profissoesFase1[0]);
                    break;
                case 2:
                    listaPalavras = profissoesFase2;
                    numPalavras = sizeof(profissoesFase2) / sizeof(profissoesFase2[0]);
                    break;
                case 3:
                    listaPalavras = profissoesFase3;
                    numPalavras = sizeof(profissoesFase3) / sizeof(profissoesFase3[0]);
                    break;
                default:
                    return NULL;
            }
            break;
        case 6: // Cores
            switch (nivel) {
                case 1:
                    listaPalavras = coresFase1;
                    numPalavras = sizeof(coresFase1) / sizeof(coresFase1[0]);
                    break;
                case 2:
                    listaPalavras = coresFase2;
                    numPalavras = sizeof(coresFase2) / sizeof(coresFase2[0]);
                    break;
                case 3:
                    listaPalavras = coresFase3;
                    numPalavras = sizeof(coresFase3) / sizeof(coresFase3[0]);
                    break;
                default:
                    return NULL;
            }
            break;
        default:
            return NULL;
    }

    return listaPalavras[rand() % numPalavras];
}

int main() {
    srand(time(NULL)); // Inicializar a semente do gerador de n�meros aleat�rios

    int categoria, nivel = 1;
    char palavraSecreta[50]; // Corrigindo o tipo de palavraSecreta para um array de caracteres de tamanho fixo
    No* palavra = NULL;
    char chute;
    int tentativas;
    char letrasErradas[26]; // Inicializar o array de letras incorretas
    int contadorErros;

    printf("Jogo da Forca\n");
    printf("Escolha uma categoria:\n");
    printf("1 - Animais\n");
    printf("2 - Frutas\n");
    printf("3 - Objetos\n");
    printf("4 - Paises\n");
    printf("5 - Profissoes\n");
    printf("6 - Cores\n");
    printf("Digite o numero da categoria: ");
    scanf("%d", &categoria);

    while (nivel <= 3) {
        const char* palavraAleatoria = obterPalavraAleatoria(categoria, nivel); // Selecionar uma palavra aleat�ria da categoria e n�vel escolhidos

        if (palavraAleatoria == NULL) {
            printf("Categoria ou n�vel invalido!\n");
            return 1;
        }

        strcpy(palavraSecreta, palavraAleatoria); // Copiar a palavra aleat�ria para palavraSecreta

        limparTela(); // Limpar a tela do terminal

        // Inicializar vari�veis de jogo
        palavra = NULL;
        tentativas = 6;
        contadorErros = 0;
        memset(letrasErradas, 0, sizeof(letrasErradas));

        // Inserir letras na lista encadeada
        for (int i = 0; i < strlen(palavraSecreta); i++) {
            inserirLetra(&palavra, palavraSecreta[i]);
        }

        int* posicoes = (int*)malloc(strlen(palavraSecreta) * sizeof(int)); // Array para armazenar as posi��es das letras corretas
        memset(posicoes, 0, strlen(palavraSecreta) * sizeof(int));

        // Loop principal do jogo
        while (tentativas > 0 && !palavraAdivinhada(posicoes, strlen(palavraSecreta))) {
            printf("nivel: %d\n", nivel);
            printf("Palavra: ");
            imprimirPalavra(palavra, posicoes, strlen(palavraSecreta)); // Imprimir a palavra oculta

            printf("Letras incorretas: ");
            qsort(letrasErradas, contadorErros, sizeof(char), compararLetras); // Ordenar as letras incorretas em ordem alfab�tica
            for (int i = 0; i < contadorErros; i++) {
                printf("%c ", letrasErradas[i]); // Imprimir as letras incorretas
            }
            printf("\n");

            printf("Tentativas restantes: %d\n", tentativas);

            printf("Digite uma letra: ");
            scanf(" %c", &chute);

            if (letraNaPalavra(palavra, chute, posicoes)) { // Verificar se a letra est� na palavra
                printf("Letra correta!\n");
            } else {
                printf("Letra incorreta!\n");
                tentativas--;
                letrasErradas[contadorErros] = chute; // Adicionar a letra incorreta ao array
                contadorErros++;
            }

            printf("\n");
        }

        // Fim do jogo para o n�vel atual
        if (tentativas == 0) {
            printf("Voce perdeu! A palavra secreta era: %s\n", palavraSecreta);
            break;
        } else {
            printf("Parabens! Voce acertou a palavra secreta!\n");
            nivel++;
        }

        free(posicoes); // Liberar a mem�ria alocada para o array de posi��es
    }

    if (nivel > 3) {
        printf("Parabens! Voce completou todos os niveis!\n");
    }

    return 0;
}

