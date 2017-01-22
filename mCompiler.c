#include "mesinkata.c"
#include "mesinkarakter.c"
#include "tbfo.c"
#include <stdio.h>
#include <string.h>


int main()
{
/*Kamus*/
    int i;
    boolean end;

/*Inisialisasi seluruh variabel*/
    /*Mengisi array kata*/
    BEGIN.TabKata[0] = 'b';
    BEGIN.TabKata[1] = 'e';
    BEGIN.TabKata[2] = 'g';
    BEGIN.TabKata[3] = 'i';
    BEGIN.TabKata[4] = 'n';
    BEGIN.Length = 5;

    END.TabKata[0] = 'e';
    END.TabKata[1] = 'n';
    END.TabKata[2] = 'd';
    END.Length = 3;

    IF.TabKata[0] = 'i';
    IF.TabKata[1] = 'f';
    IF.Length = 2;

    THEN.TabKata[0] = 't';
    THEN.TabKata[1] = 'h';
    THEN.TabKata[2] = 'e';
    THEN.TabKata[3] = 'n';
    THEN.Length = 4;

    ELSE.TabKata[0] = 'e';
    ELSE.TabKata[1] = 'l';
    ELSE.TabKata[2] = 's';
    ELSE.TabKata[3] = 'e';
    ELSE.Length = 4;

    FOR.TabKata[0] = 'f';
    FOR.TabKata[1] = 'o';
    FOR.TabKata[2] = 'r';
    FOR.Length = 3;

    DO.TabKata[0] = 'd';
    DO.TabKata[1] = 'o';
    DO.Length = 2;

    TO.TabKata[0] = 't';
    TO.TabKata[1] = 'o';
    TO.Length = 2;

    WHILE.TabKata[0] = 'w';
    WHILE.TabKata[1] = 'h';
    WHILE.TabKata[2] = 'i';
    WHILE.TabKata[3] = 'l';
    WHILE.TabKata[4] = 'e';
    WHILE.Length = 5;

    INPUT.TabKata[0] = 'i';
    INPUT.TabKata[1] = 'n';
    INPUT.TabKata[2] = 'p';
    INPUT.TabKata[3] = 'u';
    INPUT.TabKata[4] = 't';
    INPUT.Length = 5;

    OUTPUT.TabKata[0] = 'o';
    OUTPUT.TabKata[1] = 'u';
    OUTPUT.TabKata[2] = 't';
    OUTPUT.TabKata[3] = 'p';
    OUTPUT.TabKata[4] = 'u';
    OUTPUT.TabKata[5] = 't';
    OUTPUT.Length = 6;

    /*Inisialisasi variabel integer counter*/
    begincounter =0; endcounter = 0;
    CountError = 0; docounter = 0; ; whilecounter = 0;
    CountLine = 1;

    /*Inisialisasi variabel boolean*/
    iferror = true; forerror = true;

/*Algoritma*/
    /*Header Program / Judul program*/
    printf("---------------------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------------------\n\n\n");
    printf("                                       COMPILER\n\n\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------------------\n\n");
    printf("               Selamat datang di compiler Ukay & Fanda! Compile Start!\n\n");
    printf("---------------------------------------------------------------------------------------\n\n\n");

    /*Pembacaan file eksternal dari awal*/
    STARTKATA();

    /*Memulai proses pemeriksaan*/
    isBegin(CKata);

    /*Pemeriksaan kata terakhir*/
    if (CKata.Length > 0)
    {
        isEnd(CKata);
    }

    /*Pemeriksaan seluruh counter*/
    if (docounter > whilecounter)
    {
        CountError++;
        printf("   Error : The iteration process do-while was not complete. Please check again.\n\n");
    }
    if (begincounter != endcounter)
    {
        CountError++;
        printf("   Error : Unbalanced amount of 'begin' and 'end'. Please check again!\n\n");
    }

    /*Menampilkan jumlah error dan status compilation*/
    printf("   %d error(s)\n", CountError);
    if (CountError == 0)
    {
        printf("   Compilation success!\n\n");
    }
    else if (CountError > 0)
    {
        printf("   Compilation failed!\n\n");
    }

    /*Penutup Compiler*/
    printf("---------------------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------------------\n\n\n");
    printf("                  Terima Kasih Telah Menggunakan Compiler Kami!\n\n\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------------------\n\n\n");

    //Then, Else, doFor gak pake ngecek begin. isBegin ditambahin komentar
    return 0;
}
