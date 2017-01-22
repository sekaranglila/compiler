#include "mesinkata.h"
#include "mesinkarakter.h"
#include "tbfo.h"
#include "string.h"

boolean isVariabel(char CC)
{
/*Algoritma*/
    if (((CC >= 65) && (CC <= 90)) || ((CC >= 97) && (CC <= 122)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

boolean isConstant(char CC)
{
/*Algoritma*/
    if ((CC >= 48) && (CC <= 57))
    {
        return true;
    }
    else
    {
        return false;
    }
}

boolean isOperatorLogic(char CC)
{
/*Algoritma*/
    if ((CC == '>') || (CC == '<') || (CC == '='))
    {
        return true;
    }
    else
    {
        return false;
    }
}

boolean isOperator(char CC)
{
/*Algoritma*/
    if ((CC == '+') || (CC == '*') || (CC == '-'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

boolean isAssign(Kata K1)
{
/*Kamus Lokal*/
    int i;
    boolean eq;

/*Algoritma*/
    if (K1.TabKata[0] == '(')
    {
        return false;
    }
    else
    {
        i = 0; eq = false;
        while ((i <= K1.Length - 1) && (!eq))
        {
            if (K1.TabKata[i] == '=')
            {
                eq = true;
            }
            else
            {
                i++;
            }
        }
        return eq;
    }
}

void CopyString (Kata K1, Kata *K2)
{
/*Kamus Lokal*/
    int i;

/*Algoritma*/
    i = 0;
    while (i < K1.Length)
    {
        (*K2).TabKata[i] = K1.TabKata[i];
        i++;
    }
    (*K2).Length = K1.Length;
}

void isBegin(Kata K1)
{
/*Kamus Lokal*/
    boolean begin;
    boolean found;

/*Algoritma*/
    if (K1.TabKata[0] == '{')
    {
        if (K1.TabKata[K1.Length - 1] != '}')
        {
            found = false;
            while (!EOP() && (!found))
            {
                if (CKata.TabKata[CKata.Length - 1] == '}')
                {
                    found = true;
                }
                else
                {
                    ADVKATA();
                }
            }
        }
        else
        {
            found = true;
        }
        if ((found == false) && (EOP()))
        {
            printf("   Error : A '}' was expected.\n");
        }
        else
        {
            ADVKATA();
            begin = IsKataSama(BEGIN, CKata);
        }
    }
    else
    {
        begin = IsKataSama(BEGIN, K1);
    }
    if (begin == true)
    {
        begincounter++;
    }
    else
    {
        printf("   Line %d: The program needs a 'begin' to proceed!\n", CountLine);
        CountError++;
    }
    ADVKATA();
    if (!IsKataSama(END, CKata))
    {
        Stat(CKata);
    }
    else
    {
        isEnd(CKata);
    }
}

void isEnd(Kata K1)
{
/*Kamus Lokal*/
    boolean end;

/*Algoritma*/
    end = IsKataSama(END, K1);
    if (end == true)
    {
        endcounter++;
    }
    else
    {
        printf("   Line %d: An 'end' was expected!\n", CountLine);
        CountError++;
    }
    CopyString(CKata, &CKataP);
    if (!EOP())
    {
        ADVKATA();
        if (IsKataSama(ELSE, CKata))
        {
            Else(CKata);
        }
        else
        {
            Stat(CKata);
        }
    }
}

void Do(Kata K1)
{
    docounter++;
    CopyString(CKata, &CKataP);
    ADVKATA();
    Stat(CKata);
}

void While(Kata K1)
{
    whilecounter++;
    if (docounter < whilecounter)
    {
        printf("   Line %d: A 'do' is expected before 'while'!\n", CountLine);
        CountError++;
    }
    CopyString(CKata, &CKataP);
    ADVKATA();
    if (CKata.TabKata[0] != '(')
    {
        printf("   Line %d: A condition is expected after 'while'!\n", CountLine);
        CountError++;
    }
    Cond(CKata);
}

void IfThen(Kata K1)
{
    if (IsKataSama(IF, K1))
    {
        iferror = false;
        CopyString(CKata, &CKataP);
        ADVKATA();
        if (CKata.TabKata[0] != '(')
        {
            printf("   Line %d: A condition is expected after an 'if'! \n", CountLine);
            CountError++;
        }
        Cond(CKata);
    }
}

void Then(Kata K1)
{
    if (IsKataSama(THEN, K1))
    {
        if (iferror != false)
        {
            printf("   Line %d: An 'if' is expected before condition!\n", CountLine);
            CountError++;
        }
        iferror = true;
        CopyString(CKata, &CKataP);
        ADVKATA();
        isBegin(CKata);
    }
}

void Else(Kata K1)
{
    if (iferror == false)
    {
        printf("   Line %d: An 'if' or a 'then' is expected before 'else'!\n", CountLine);
        CountError++;
    }
    iferror = true;
    CopyString(CKata, &CKataP);
    ADVKATA();
    isBegin(CKata);
}

void For(Kata K1)
{
    forerror = false;
    CopyString(CKata, &CKataP);
    ADVKATA();
    if (CKata.TabKata[0] != '(')
    {
        printf("   Line %d: A condition is expected after 'for'!\n", CountLine);
        CountError++;
    }
    CondFor(CKata);
}

void CondFor(Kata K1)
{
    boolean eqf;
    boolean varf;
    boolean constf;
    boolean constff;
    boolean too;
    int i;
    int j;
    int k;
    int m;

    eqf = false; i=0;
    while ((i < CKata.TabKata[CKata.Length-1]) && (!eqf))
    {
        if (CKata.TabKata[i] == '=')
        {
            eqf = true;
        }
        else
        {
            i++;
        }
    }
    if (eqf == true)
    {
        j=0; varf = false;
        while ((j<i) && (!varf))
        {
            if (!isVariabel(CKata.TabKata[j]))
            {
                varf = true;
            }
            else
            {
                j++;
            }
        }
        k = i+1; constf = false;
        while ((k<CKata.Length-1) && (!constf))
        {
            if (!isConstant(CKata.TabKata[k]))
            {
                constf = true;
            }
            else
            {
                k++;
            }
        }
    }
    ADVKATA();
    too = false;
    if (!IsKataSama(TO, CKata))
    {
        too = true;
    }
    ADVKATA();
    constff=false; m=0;
    while ((m<CKata.Length-1) && (!constff))
    {
        if (!isConstant(CKata.TabKata[m]))
        {
            constff = true;
        }
        else
        {
            m++;
        }
    }
    if ((too == true) || (constff == true) || (constf == true) || (varf == true) || (eqf == true))
    {
        printf("    Line %d: Invalid parameter of for-do!\n", CountLine);
        CountError++;
    }
    ADVKATA();
    if (!IsKataSama(DO, CKata))
    {
        printf("   Line %d: Expected a 'do' in 'for' iteration!\n", CountLine);
        CountError++;
    }
    doFor(CKata);
}

void doFor(Kata K1)
{
    CopyString(CKata, &CKataP);
    ADVKATA();
    isBegin(CKata);
}

void input(Kata K1)
{
/*Kamus Lokal*/
    int i;
    boolean notvar;

/*Algoritma*/
    if (K1.TabKata[5] != '(')
    {
        printf("   Line %d: A '(' is expected before 'variable'!\n", CountLine);
        CountError++;
        i = 5; notvar = false;
        while ((i < (K1.Length - 1)) && (!(notvar)))
        {
            if (!(isVariabel(K1.TabKata[i])))
            {
                notvar = true;
            }
            else
            {
                i++;
            }
        }
        if (notvar == true)
        {
            printf("   Line %d: A variable is expected as input!\n", CountLine);
            CountError++;
        }
        if (CKata.TabKata[CKata.Length - 1] != ')')
        {
            printf("   Line %d: A ')' is expected\!n", CountLine);
            CountError++;
        }
    }
    else
    {
        i = 6; notvar = false;
        while ((i < (K1.Length - 1)) && (!(notvar)))
        {
            if (!(isVariabel(K1.TabKata[i])))
            {
                notvar = true;
            }
            else
            {
                i++;
            }
        }
        if (notvar == true)
        {
            printf("   Line %d: A variable is expected as input!\n", CountLine);
            CountError++;
        }
        if (CKata.TabKata[CKata.Length - 1] != ')')
        {
            printf("   Line %d: A ')' was expected!\n", CountLine);
            CountError++;
        }
    }
    ADVKATA();
    Stat(CKata);
}

void output(Kata K1)
{
    int i;
    int j;
    int k;
    boolean opf;
    boolean notvar;
    boolean notop;

    if (K1.TabKata[6] != '(')
    {
        printf("   Line %d: Expected a '(' right after 'output'!\n");
        CountError++;
    }
    else
    {
        i = 6; opf = false;
        while ((i<K1.Length-1) && (!opf))
        {
            if (isOperator(K1.TabKata[i]))
            {
                opf = true;
            }
            else
            {
                i++;
            }
        }
        if (opf == true)
        {
            j=7; notvar= false;
            while ((j<i) && (!notvar))
            {
                if (!isVariabel(K1.TabKata[j]) && !isConstant(K1.TabKata[j]))
                {
                    notvar = true;
                }
                else
                {
                    j++;
                }
            }
            if (notvar == false)
            {
                i++;
                while ((i < K1.Length - 1) && (!notvar))
                {
                    if (!isVariabel(K1.TabKata[i]) && !isConstant(K1.TabKata[i]))
                    {
                        notvar = true;
                    }
                    else
                    {
                        i++;
                    }
                }
            }
        }
        else
        {
            k=7; notop = false;
            while ((k < K1.Length-1) && (!notop))
            {
                if (!isVariabel(K1.TabKata[k]))
                {
                    notop = true;
                }
                else
                {
                    k++;
                }
            }
        }
    }
    if ((K1.TabKata[K1.Length - 1] != ')') || ((notvar==true) || (notop==true)))
    {
        printf("   Line %d: The output parameter is neither a variable or math operation!\n", CountLine);
        CountError++;
    }
    ADVKATA();
    Stat(CKata);
}

void Assign(Kata K1)
{
/*Kamus Lokal*/
    int i, j, k, l ,m;
    boolean eq, notvar, op, nocons;

/*Algoritma*/
    i=0; eq=false;
    while ((i <= K1.Length - 1) && (!eq))
    {
        if (K1.TabKata[i] == '=')
        {
            eq = true;
        }
        else
        {
            i++;
        }
    }
    if (eq == true)
    {
        j = 0; notvar=false;
        while ((j < i) && (!notvar))
        {
            if ((isVariabel(K1.TabKata[j])) == false)
            {
                notvar = true;
            }
            else
            {
                j++;
            }
        }
        if (notvar == false)
        {
            k = i + 1; m = k; op = false;
            while ((k<K1.Length-1) && (!op))
            {
                if (isOperator(K1.TabKata[k]))
                {
                    op = true;
                }
                else
                {
                    k++;
                }
            }
            if (op == true)
            {
                nocons = false;
                while ((m < k) && (!nocons))
                {
                    if (!(isVariabel(K1.TabKata[m])) && !(isConstant(K1.TabKata[m])))
                    {
                        nocons = true;
                    }
                    else
                    {
                        m++;
                    }
                }
                if (nocons == false)
                {
                    l = k + 1;
                    while ((l <= K1.Length - 1) && (!nocons))
                    {
                        if (!(isVariabel(K1.TabKata[l])) && !(isConstant(K1.TabKata[l])))
                        {
                            nocons = true;
                        }
                        else
                        {
                            l++;
                        }
                    }
                }
            }
            else
            {
                m = i + 1; nocons = false;
                while ((m <= K1.Length - 1) && (!nocons))
                {
                    if (!(isVariabel(K1.TabKata[m])) && !(isConstant(K1.TabKata[m])))
                    {
                        nocons = true;
                    }
                    else
                    {
                        m++;
                    }
                }
            }
            if (nocons == true)
            {
                printf("   Line %d: Invalid parameter!\n", CountLine);
                CountError++;
            }
        }
        else
        {
            printf("   Line %d: Invalid parameter!\n", CountLine);
            CountError++;
        }
    }
    else
    {
        printf("   Line %d: Invalid parameter. '=' is expected!\n", CountLine);
        CountError++;
    }
    ADVKATA();
    Stat(CKata);
}

void Cond(Kata K1)
{
    int i, j, k, m, n, o, p;
    boolean noteq;
    boolean notlog;
    boolean notlog1;
    boolean notop;
    boolean notvar; boolean notvar1, notvar2;

    i=1; noteq=false;
    while ((i<K1.Length-1) && (!noteq))
    {
        if (K1.TabKata[K1.Length-1] == '=')
        {
            noteq = true;
        }
        else
        {
            i++;
        }
    }
    if (noteq == true)
    //ada samadengan dan nanti tinggal cek apakah dia benar atau tidak susunan operasi matematikanya.
    {
        Assign(K1);
    }
    else
    //samadengan tidak ditemukan
    {
        //dibawah ini ngecek dia ada operator logic apa tidak
        j=1; notlog=false;
        while ((j<K1.Length-1) && (!notlog))
        {
            if (isOperatorLogic(K1.TabKata[j]) == true)
            {
                notlog=true;
            }
            else
            {
                j++;
            }
        }
        //cek apakah ada operator matematika atau tidak
        k=1; notop=false;
        while ((k<K1.Length-1) && (!notop))
        {
            if (isOperator(K1.TabKata[k]) == true)
            {
                notop=true;
            }
            else
            {
                k++;
            }
        }
        //cek apakah ada operator logic kedua atau tidak
        m=j; notlog1=false;
        while ((m<K1.Length-1) && (!notlog1))
        {
            if (isOperatorLogic(K1.TabKata[m]))
            {
                notlog1=true;
            }
            else
            {
                m++;
            }
        }
        //proses menurut operator logic atau operator matematika yang ada
        if ((notlog1==false) && (notlog==false) && (notop==false))
        //jika tidak ada operator sama sekali maka harus variabel.
        {
            n=1; notvar=false;
            while ((n<K1.Length-1) && (!notvar))
            {
                if (!isVariabel(K1.TabKata[n]))
                {
                    notvar=true;
                }
                else
                {
                    n++;
                }
            }
            if (!notvar)
            {
                printf("   Line %d: A variable is expected for if-then condition!\n", CountLine);
                CountError++;
            }
        }
        else if ((notlog == true) && (notlog1 == false) && (notop))
        //jika operator yang ada hanya operator logic
        {
            o=1; notvar1=false;
            while ((o<j) && (!notvar))
            {
                if (isVariabel(K1.TabKata[o]) || isConstant(K1.TabKata[o]))
                {
                    o++;
                }
                else
                {
                    notvar1 = true;
                }
            }
            p=j+1; notvar2=false;
            while ((p<K1.Length-1) && (!notvar2))
            {
                if (isVariabel(K1.TabKata[p]) || isConstant(K1.TabKata[p]))
                {
                    p++;
                }
                else
                {
                    notvar2 = true;
                }
            }
            if ((notvar1==true) || (notvar2==true))
            {
                printf("   Line %d: Invalid parameter!\n", CountLine);
                CountError++;
            }
        }
    }
    ADVKATA();
    Stat(CKata);
}

void StatError(Kata K1)
{
    if (!EOP())
    {
        ADVKATA();
        Stat(CKata);
    }
}

void Stat(Kata K1)
{
/*Kamus Lokal*/
    boolean found;

/*Algoritma*/
    if(!EOP())
    {
        if (forerror == false)
        {
            forerror = true;
        }
        if (IsKataSama(IF, K1))
        {
            IfThen(K1);
        }
        else if (IsKataSama(THEN, K1))
        {
            Then(K1);
        }
        else if (IsKataSama(FOR, K1))
        {
            For(K1);
        }
        else if (IsKataSama(DO, K1))
        {
            Do(K1);
        }
        else if (IsKataSama(WHILE, K1))
        {
            While(K1);
        }
        else if (IsKataSama(BEGIN, K1))
        {
            printf("   Line %d: A 'begin' is not valid!\n", CountLine);
            CountError++;
            StatError(K1);
        }
        else if (IsKataSamaInput(INPUT, K1))
        {
            input(K1);
        }
        else if (IsKataSamaInput(OUTPUT, K1))
        {
            output(K1);
        }
        else if (IsKataSama(ELSE, K1))
        {
            Else(K1);
        }
        else if (IsKataSama(END, K1))
        {
            isEnd(K1);
        }
        else if (isAssign(K1) == true)
        {
            Assign(K1);
        }
        else if (K1.TabKata[0] == '{')
        {
            if (K1.TabKata[K1.Length - 1] != '}')
            {
                found = false;
                while (!EOP() && (!found))
                {
                    if (CKata.TabKata[CKata.Length - 1] == '}')
                    {
                        found = true;
                    }
                    else
                    {
                        ADVKATA();
                    }
                }
            }
            else
            {
                found = true;
            }
            if ((found == false) && (EOP()))
            {
                printf("   Error : A '}' is expected!\n");
            }
            else
            {
                StatError(K1);
            }
        }
        else
        {
            printf("   Line %d: Unknown variable!\n", CountLine);
            CountError++;
            StatError(K1);
        }
    }
}
