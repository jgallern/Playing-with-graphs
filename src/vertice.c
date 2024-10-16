#include "vertice.h"

/*
* structure: vertice
*/

struct vertice 
{
   char name;

   struct vertice *neighbours[4];
};

struct vertice* newVertice(char c)
{
   struct vertice* New = (struct vertice*)malloc(sizeof(struct vertice)) ;
   New->name = c;
   for (int i = 0; i < 4; i++) {
     New->neighbours[i] = NULL;
   }
   return New;
}

/*
* function: returnAdjMatrix
*
* retun adjency matrix of the graph
*/
int** returnAdjMatrix(struct vertice* vertices[], int numofVertices) 
{
   int** matrix = (int **)malloc(sizeof(int*) * numofVertices);
   for (int i = 0; i < numofVertices; i++) {
      matrix[i] = (int*)malloc(sizeof(int) * numofVertices);
   }

   // Initialize the matrix with 0
   for (int i = 0; i < numofVertices; i++) 
   {
      for (int j = 0; j < numofVertices; j++) 
      {
         matrix[i][j] = 0;
      }
   }

   for (int i = 0; i < numofVertices; i++) 
   {
      struct vertice* current = vertices[i];
      for (int k = 0; k < 4; k++) // Check up to 4 neighbors
      {
         if (current->neighbours[k] != NULL) 
         {
            for (int j = 0; j < numofVertices; j++) 
            {
               if (vertices[j] == current->neighbours[k]) 
               {
                  matrix[i][j] = 1; // Set adjacency to 1
                  break;
               }
            }
         }
      }
   }

   return matrix;
}


void printMatrix(int** matrix, int numofVertices) {
   for (int i = 0; i < numofVertices; i++) {
      for (int j = 0; j < numofVertices; j++) {
         printf("%d ", matrix[i][j]);
      }
      printf("\n");
   }
}
