#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Nó da Árvore de Expressão
typedef struct Node {
    char data;          // Operador ('+', '*', etc.) ou dígito ('3')
    struct Node *left;  // Filho esquerdo
    struct Node *right; // Filho direito
} Node;

// Cria um novo nó na árvore
Node* create_node(char data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Avalia a árvore recursivamente e calcula o resultado
int evaluate(Node *root) {
    if (root == NULL) return 0;

    // Se for folha (número), converte de char para int
    if (root->left == NULL && root->right == NULL) {
        return root->data - '0';
    }

    int left_val = evaluate(root->left);
    int right_val = evaluate(root->right);

    // Aplica a operação do nó atual
    switch (root->data) {
        case '+': return left_val + right_val;
        case '-': return left_val - right_val;
        case '*': return left_val * right_val;
        case '/': return right_val != 0 ? left_val / right_val : 0;
        default: return 0;
    }
}

int main() {
    // Montando manualmente a árvore para a expressão: (3 + 5) * 2
    //       *
    //      / \
    //     +   2
    //    / \
    //   3   5
    
    Node *root = create_node('*');
    root->left = create_node('+');
    root->right = create_node('2');
    
    root->left->left = create_node('3');
    root->left->right = create_node('5');

    printf("Expressao: (3 + 5) * 2\n");
    int resultado = evaluate(root);
    printf("Resultado calculado pela arvore: %d\n", resultado);

    return 0;
}
