#ifndef TBFO_H
#define TBFO_H
#include "mesinkarakter.h"
#include "mesinkata.h"
#include <stdio.h>
#include <string.h>

void CopyString (Kata K1, Kata *K2);
/*Menyalin string kata K1 ke kata K2*/

void isBegin(Kata K1);
/*Memeriksa bagian begin*/

void isEnd(Kata K1);
/*Memeriksa bagian end*/

void Do(Kata K1);
/*Memeriksa bagian do*/

void While(Kata K1);
/*Memeriksa bagian While*/

void IfThen(Kata K1);
/*Memeriksa bagian if then else*/

void Then(Kata K1);
/*Memeriksa bagian then*/

void Else(Kata K1);
/*Memeriksa bagian else*/

void Stat(Kata K1);
/*Memeriksa bagian statements*/

void Cond(Kata K1);
/*Memeriksa kondisi*/

void For(Kata K1);
/*Memeriksa for*/

void CondFor(Kata K1);
/*Memeriksa to pada loop for*/

void doFor(Kata K1);
/*Memeriksa do pada loop for*/

boolean isVariabel(char CC);
/*Memeriksa apakah variabel atau tifak*/

boolean isConstant(char CC);
/*Memeriksa apakah angka atau bukan*/

boolean isOperatorLogic(char CC);
/*Memeriksa apakah operator logic*/

boolean isOperator(char CC);
/*Memeriksa apakah operator*/

boolean isAssign(Kata K1);
/*Mengecek apakah assignment atau tidak*/

#endif
