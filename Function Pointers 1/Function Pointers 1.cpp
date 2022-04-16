#include <stdio.h>
#include <string.h>

#define   MAX_NAME_LEN  20
#define   asize(a)      (sizeof(a) / sizeof(*a))

typedef struct{
    char name[MAX_NAME_LEN];
    int no;
}Person; 

typedef unsigned char Byte; 
typedef int(*Cmpfn)(const void*, const void*);

void* g_max(const void* pa, size_t size, size_t sz, Cmpfn fp)
{
    Byte* pb = (Byte*)pa;
    const void* pmax = (void*)pa;    
    for (size_t k = 1; k < size; ++k)
        if (fp(pb + k * sz, pmax) > 0)
            pmax = pb + k * sz;    
    return pmax;
}

int cmp_int(const void* vp1, const void* vp2)
{
    if (*(const int*)vp1 > *(const int*)vp2)
        return 1;
    return *(const int*)vp1 < *(const int*)vp2 ? -1 : 0;
}

int cmp_person_by_name(const void* vp1, const void* vp2)
{
    return strcmp(((const Person*)vp1)->name,
        ((const Person*)vp2)->name);
}

int cmp_person_by_no(const void* vp1, const void* vp2)
{
    return ((const Person*)vp1)->no - ((const Person*)vp2)->no;
}

int main()
{
    int a[] = { 3, 8, 4, 7, 6, 9, 12, 1, 9, 10 };    Person pa[] = {
    { "Oguz Karan", 12 },{ "Kaan Can", 56 },{ "Ali Orak", 31 },
    { "Emre Koc", 19 },{ "Nur Elci", 29 },{ "Eda Alan", 14 } };   
    Person* p;
    int* iptr = g_max(a, asize(a), sizeof(int), cmp_int);
    printf("max = %d %d indisli eleman\n", *iptr, iptr - a);
    p = g_max(pa, asize(pa), sizeof(Person), cmp_person_by_name);
    printf("max pa (isme gore) %s %d\n", p->name, p->no);
    p = g_max(pa, asize(pa), sizeof(Person), cmp_person_by_no);
    printf("max pa (numaraya gore) %s %d\n", p->name, p->no);
}