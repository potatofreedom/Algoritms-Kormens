// Сортировка динамического массива вставкой
#include <stdio.h>
#include <stdlib.h>
void insert_sort(int block[], int n) // функция сортировки
{
    for(int i = 1; i<n; ++i)
    {
        int k = i;
        //элемент двигается влево до тех пор пока не встретит меньший по значению эелемент
        while(k>0 && block[k-1]>block[k])
        {
            int tmp = block[k-1]; //создаем третью переменную для обмена
            block[k-1] = block[k];
            block[k] = tmp;
            k -= 1;
        }
    }
}
int main (int argc, char* argv[])
{
    int *block; // указатель блока памяти
    int n; // число элементов массива
    printf("Size of array=");
    scanf("%d", &n);
    //выделяем память для массива
    block = malloc(n* sizeof(int));//функция malloc возвращает указатель типа void*
    //который автоматически преобразуется в тип int*
    //вводим числа в массив
    for(int i=0; i<n; ++i)
    {
        printf("block[%d]=", i);
        scanf("%d", &block[i]);
    }
    printf("\n");
    insert_sort(block,n); // сортировка введенных чисел
    for(int i=0;i<n;++i)
    {
        printf("%d \t", block[i]); //вывод введенных чисел
    }
    free(block); //освобождаем память
    return 0;
}

