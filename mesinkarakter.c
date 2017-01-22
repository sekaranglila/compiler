/*
*	NIM/Nama	:
*	Nama file	:
*	Topik		:
*	Tanggal		:
*	Deskripsi 	:
*/

#include "mesinkarakter.h"

extern void START()
/* 	I.S. sembarang
	F.S. CC adalah karakter pertama pita (stdin)
		 Bila Kondisi EOP terpenuhi, nyalakan EOP
*/
{
	fprogram = fopen("data.txt", "r");
	ADV();
}

extern void ADV()
/*	I.S. CC!=mark
	F.S. CC adalah karakter berikutnya yang dapat diakuisisi
		 contoh untuk pita "IF", bila CC menunjuk 'I', maka CC berikutnya adalah 'F'
		 Bila Kondisi EOP terpenuhi, nyalakan EOP
*/
{
	//ALGORITMA
    CC = fgetc(fprogram);
    if (EOP() == true)
    {
        fclose(fprogram);
    }
}

extern boolean EOP()
/*	true jika CC==mark */
{
	return (CC == EOF);
}
