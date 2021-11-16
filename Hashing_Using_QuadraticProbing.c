#include <stdio.h>
#include <stdlib.h>
#define SIZE 11

struct HashTable
{
    int *HT;
	int size;
	int ne;	
};

void I(struct HashTable *H)
{
	int i;
	H->size=SIZE;
	H->ne=0;
	H->HT=(int *)malloc(SIZE*sizeof(int));
	for(i=0;i<SIZE;i++)
	    *(H->HT+i)=-1;
}

int Hash(int key)
{
	return(key%SIZE);
}

int Probe(struct HashTable *H,int key)
{
	int index=Hash(key);
	int i=0;
	
	while(*(H->HT+(index+i*i)%SIZE)!=-1)
	    i++;
	return(index+i*i)%SIZE;
}

void Insert(struct HashTable *H,int key)
{
	int index=Hash(key);
	
	if(*(H->HT+index)!=-1)
	    index=Probe(H,key);
	    
	*(H->HT+index)=key;
	H->ne++;
}

int Search(struct HashTable *H,int key)
{
	int index=Hash(key);
	int i=0;
	
	if(*(H->HT+index)!=key)
	{
		while(*(H->HT+(index+i*i)%SIZE)!=-1)
		{
		    if(*(H->HT+(index+i*i)%SIZE)==-1)
		        return(-1);
			i++;
        }
	}
	return(index+i*i)%SIZE;
}

void Display(struct HashTable H)
{
	int i;
	
	printf("\n-----------------------------------------------------------------------------\n\n");
	printf("Size Of The Hash Table Is As Follows : %d\n",H.size);
    printf("Total Number Of Elements In The Hash Table Are As Follows : %d\n",H.ne);
	printf("\nHash Table Created By Using Quadratic Probing Is As Follows :\n");
	for(i=0;i<H.size;i++)
	{
	    printf("\nElement At Index %d Is As Follows : ",i);
		if(*(H.HT+i)!=-1)
		    printf("%d",*(H.HT+i));
		printf("\n");
	}
	printf("\n-----------------------------------------------------------------------------\n\n");
}

int main()
{
    struct HashTable H;
	
	I(&H);
	
	Insert(&H,26);	
	Insert(&H,36);	
	Insert(&H,46);	
	Insert(&H,56);
	Insert(&H,86);	
	
	Display(H);
	
	return(0);
}





