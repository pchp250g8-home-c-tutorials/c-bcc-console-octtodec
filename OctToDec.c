#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <tchar.h>

int _tmain(int argc, _TCHAR* argv[]) 
{
    const unsigned int nMaxOctDigits = (unsigned int)(ceil(log2(UINT32_MAX) / 3));
    long long nOctPower = 1L;
    long long nDecNum = 0L;
    char szLine1[256], szLine2[256];
    size_t nStrLen1, nStrLen2;
    bool bIsRightString = false;
    system("cls");
    printf("Input an octal number\r\n");
    scanf("%[^\n]", szLine1);
    sscanf(szLine1, "%[0-7]", szLine2);
    nStrLen1 = strlen(szLine1);
    nStrLen2 = strlen(szLine2);
    bIsRightString = (nStrLen1 <= nMaxOctDigits) && (nStrLen1 == nStrLen2);
    if (!bIsRightString)
    {
        printf("Wrong octal number format!!!\r\n");
        getchar();
        getc(stdin);
        return 0;
    }
    for (unsigned int i = 0; i < nStrLen1; i++)
    {
        unsigned int nOctDigit = szLine1[nStrLen1 - 1 - i] - '0';
        nDecNum += (nOctDigit * nOctPower);
        nOctPower *= 8;
    }
    printf
    (
    	"The decimal equivalent of the octal number %s is %lld\r\n",
        szLine1, nDecNum
    );
    getchar();
    getc(stdin);
    return 0;
}
