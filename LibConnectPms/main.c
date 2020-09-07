#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef __int16 (*DvConnect) (__int16 beep);
typedef int (*Add) (int x, int y);
typedef int (*PassParameter) (char** a, char** b, char** c);

int main()
{
    //libwkhtmltox.dll
    __int16 x = 1234;
    printf("__int16 variable x is %d \n", x);

    HINSTANCE hinstance = LoadLibrary("C:\\C-Projects\\LibConnectPms\\DLLSample.dll");

    printf("hinstance: %d\n", hinstance);

    Add func = (Add)GetProcAddress(hinstance, "Sub");
    PassParameter passFunc = (PassParameter)GetProcAddress(hinstance, "PassParameter");

    printf("obj: %d\n", func);

    if (func)
    {
            int result = func(3,4);
            printf("result: %d\n", result);
    }

    if (passFunc)
    {
            char* a = "parameter1";
            char* b = "parameter2";
            char* c = "parameter3";
            int result = passFunc(&a, &b, &c);
            printf("result: %d\n", result);
            printf("parameters: %s, %s, %s\n", a, b, c);
    }


    printf("finished\n");

    return 0;
}
