#include "vertice.c"

int main()
{
   struct vertice* A = newVertice('A');
   struct vertice* B = newVertice('B');

   A->neighbours[0] = B;
   B->neighbours[0] = A;

   struct vertice* vertices[] = {A, B};

   int** adjMatrix = returnAdjMatrix(vertices, 2);

   // Print the adjacency matrix
   printMatrix(adjMatrix, 2);

   // Free the allocated memory
   for (int i = 0; i < 2; i++) {
      free(adjMatrix[i]);
   }
   free(adjMatrix);

   return 0;
}

