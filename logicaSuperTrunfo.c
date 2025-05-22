#include <stdio.h>
#include <string.h>

// ---------- Estrutura da Carta ----------
typedef struct {
    char nome[50];
    int forca;
    int magia;
    int agilidade;
} Carta;

// ---------- Exibe os atributos de uma carta ----------
void exibirCarta(Carta c) {
    printf("\nCarta: %s\n", c.nome);
    printf("Força: %d\n", c.forca);
    printf("Magia: %d\n", c.magia);
    printf("Agilidade: %d\n", c.agilidade);
}

// ---------- Retorna o valor de um atributo baseado no índice ----------
int obterValorPorAtributo(Carta c, int atributo) {
    return (atributo == 1) ? c.forca :
           (atributo == 2) ? c.magia :
           (atributo == 3) ? c.agilidade : 0;
}

// ---------- Compara as cartas usando dois atributos escolhidos ----------
void compararCartas(Carta c1, Carta c2, int atributo1, int atributo2) {
    int soma1 = obterValorPorAtributo(c1, atributo1) + obterValorPorAtributo(c1, atributo2);
    int soma2 = obterValorPorAtributo(c2, atributo1) + obterValorPorAtributo(c2, atributo2);

    printf("\n--- Resultado da Comparação ---\n");
    printf("%s: %d pontos\n", c1.nome, soma1);
    printf("%s: %d pontos\n", c2.nome, soma2);

    // Operador ternário encadeado para decisão
    (soma1 > soma2) ? printf("🏆 Vencedora: %s\n", c1.nome) :
    (soma2 > soma1) ? printf("🏆 Vencedora: %s\n", c2.nome) :
                      printf("🤝 Empate!\n");
}

// ---------- Menu dinâmico para seleção de atributos ----------
int selecionarAtributo(const char* ordem) {
    int escolha;
    printf("\nEscolha o %s atributo para comparação:\n", ordem);
    printf("1 - Força\n2 - Magia\n3 - Agilidade\n> ");
    scanf("%d", &escolha);
    return escolha;
}

// ---------- Função principal ----------
int main() {
    Carta carta1, carta2;
    int atributo1, atributo2;

    // Cadastro da carta 1
    printf("Cadastro da Carta 1\n");
    printf("Nome: ");
    fgets(carta1.nome, 50, stdin);
    carta1.nome[strcspn(carta1.nome, "\n")] = '\0'; // Remove o '\n'
    printf("Força: "); scanf("%d", &carta1.forca);
    printf("Magia: "); scanf("%d", &carta1.magia);
    printf("Agilidade: "); scanf("%d", &carta1.agilidade);
    getchar(); // Limpa o '\n' do buffer

    // Cadastro da carta 2
    printf("\nCadastro da Carta 2\n");
    printf("Nome: ");
    fgets(carta2.nome, 50, stdin);
    carta2.nome[strcspn(carta2.nome, "\n")] = '\0';
    printf("Força: "); scanf("%d", &carta2.forca);
    printf("Magia: "); scanf("%d", &carta2.magia);
    printf("Agilidade: "); scanf("%d", &carta2.agilidade);

    // Exibição das cartas
    printf("\n--- Cartas Cadastradas ---");
    exibirCarta(carta1);
    exibirCarta(carta2);

    // Menu dinâmico com validação
    do {
        atributo1 = selecionarAtributo("primeiro");
        atributo2 = selecionarAtributo("segundo");

        if (atributo1 < 1 || atributo1 > 3 || atributo2 < 1 || atributo2 > 3 || atributo1 == atributo2) {
            printf("\n⚠️ Atributos inválidos ou repetidos. Tente novamente.\n");
        }
    } while (atributo1 < 1 || atributo1 > 3 || atributo2 < 1 || atributo2 > 3 || atributo1 == atributo2);

    // Realiza comparação
    compararCartas(carta1, carta2, atributo1, atributo2);

    return 0;
}