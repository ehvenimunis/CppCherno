#include <stdio.h>

typedef int(*Fptr)(int, int);

static int sum_square(int x, int y)
{
	return x * x + y * y;
}

Fptr func()
{
	//...
	return sum_square;
}

int main()
{
	int a = 10, b = 20;
	int ival = func()(a, b);
	printf("ival = %d\n", ival);
}


/*

Fonksiyon göstericilerine ilişkin kodların kolay yazılması ve okunması amacıyla çoğunlukla fonksiyon göstericisi türlerine typedef bildirimleriyle eş isimler verilir.

İşlevlerin geri dönüş değerleri fonksiyon adresleri olabilir. Bu durumda böyle bir fonksiyona çağrı yapacak bir kod işlevden geri dönüş değeri yoluyla bir fonksiyonun adresini alabilir:

*/

/*

	ival = 500

*/