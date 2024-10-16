#include <stdio.h>
#include <stdlib.h>


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
* function: prin  
*/
// retun adjency matrix of the graph
int** printAdjMatrix(struct vertice* vertices[], int numofVertices) 
{
   int** matrix = (int **)malloc(sizeof(int*)*numofVertices);

   for (int i =0; i<numofVertices-1; i++)
   {
      for (int j=0; j<numofVertices-1; j++)
      {
         printf("i=%d, j=%d", i,j);
         matrix[i][j]= 0;
      }
   }

   return matrix;
}

int main()
{
   struct vertice* A = newVertice('A');
   struct vertice* B = newVertice('B');

   A->neighbours[0]= B;
   B->neighbours[0]= A;

   struct vertice* vertices[] = {A,B} ;
   printAdjMatrix(vertices, 2);
   return 0;
}



