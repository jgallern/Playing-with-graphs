#include "vertice.c"

int main()
{
    printf("creation des sommets A et B\n\n");
    struct vertice* A = newVertice('A');
    struct vertice* B = newVertice('B');

    printf("le sommet A est voisin adjacent avec le sommet B\n\n");
    A->neighbours[0] = B;
    printf("le sommet B est voisin adjacent avec le sommet A\n\n");
    B->neighbours[0] = A;

    struct vertice* vertices[] = {A, B};

    int** adjMatrix = returnAdjMatrix(vertices, 2);

    // Print the adjacency matrix
    printf("Matrice Adjacente du graph composé des sommets A et B:\n");
    printMatrix(adjMatrix, 2);

    // Free the allocated memory
    for (int i = 0; i < 2; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);

    return 0;
}

