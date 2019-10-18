#include <stdio.h>
#include <stdlib.h>

void quick(int *v, int left, int right);
void selection(int *v, int n);
void insertion(int *v, int n);
void bubble(int *v, int n);
void mergeSort(int *v, int l, int r);
void merge(int *v, int l, int m, int r);

int main()
{
int *v,n,i;
printf("Informe o numero de elementos: ");
scanf("%d", &n);

v = (int*)malloc(sizeof(int)*n);

for(i = 0; i < n; i++){

*(v+i) = rand() % 100;    

}
//insertion(v,n);
//selection(v,n);
//bubble(v,n);
mergeSort(v,0,n);
//quick(v,0,n);

for(i = 0; i < n; i++){

printf("%d ",*(v+i));  

}

    return 0;
}
void insertion(int *v, int n)
{
    int i, j, temp, min;

    for (i = 1; i < n; i++)
    {
        temp = v[i];
        j = i - 1;

        while (j >= 0 && v[j] > temp)
        {

            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = temp;
    }
}
void selection(int *v, int n)
{
    int i, j, temp, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {

            if (v[j] < v[min])
            {
                min = j;
            }
        }
        temp = v[i];
        v[i] = v[min];
        v[min] = temp;
    }
}
void bubble(int *v, int n)
{
    int i, j,temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}
void quick(int *v, int left, int right)
{
    int i, j, pivo,temp;

    i = left;
    j = right;
    pivo = v[(left + right) / 2];

    do
    {
        while (v[i] < pivo)
            i++;

        while (v[j] > pivo)
            j--;

        if (i <= j)
        {
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }

    } while (i <= j);

    if (left < j)
    {
        quick(v, left, j);
    }
    if (i < right)
    {

        quick(v, i, right);
    }
}
void merge(int *v, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    int L[n1], R[n2]; 
  
    
    for (i = 0; i < n1; i++) 
        L[i] = v[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = v[m + 1+ j]; 
  
    
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            v[k] = L[i]; 
            i++; 
        } 
        else
        { 
            v[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < n1) 
    { 
        v[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        v[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeSort(int *v, int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 

        mergeSort(v, l, m); 
        mergeSort(v, m+1, r); 
  
        merge(v, l, m, r); 
    } 
} 