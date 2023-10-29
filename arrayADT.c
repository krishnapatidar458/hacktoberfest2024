#include <stdio.h>
#include <stdlib.h>
struct myarray
{
    int totalsize;
    int usedsize;
    int *ptr;
};
void createarray(struct myarray *a, int tsize, int usize)
{
    // (*a).totalsize = tsize;
    // (*a).usedsize = usize;
    // (*a).ptr = (int *) malloc(tsize*sizeof(int));

    a->totalsize = tsize;
    a->usedsize = usize;
    a->ptr = (int *)malloc(tsize * sizeof(int));
}
void show(struct myarray *a)
{
    for (int i = 0; i < a->usedsize; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}
void setval(struct myarray *a)
{
    int n;
    for (int i = 0; i < a->usedsize; i++)
    {
        printf("Enter element %d ", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}
int insertarray(struct myarray *a, int in , int n)
{
    if (a->usedsize >= a->totalsize)
    {
        return -1;
    }
    for (int i=a->usedsize-1; i>= in; i--)
   {
    (a->ptr)[i+1]=(a->ptr)[i];
   }
   (a->ptr)[in]=n;
   return 1;
   
}

int main()
{
    struct myarray marks;
    createarray(&marks, 100, 3);
    printf ("Setting the value of the array\n");
    setval(&marks);
    printf ("This is the value inside the array\n");
    //show(&marks);
    insertarray(&marks, 1 , 35);
    marks.usedsize ++;
    show(&marks);

    return 0;
}
