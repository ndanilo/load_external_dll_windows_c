#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>
#include <stdio.h>

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

__declspec(dllexport) int Mul(int a, int b)
{
    return a * b;
}

__declspec(dllexport) int Add(int a, int b)
{
    return a + b;
}

__declspec(dllexport) int Sub(int a, int b)
{
    return a - b;
}

__declspec(dllexport) char* TextFunction(char* text)
{
    return text;
}

__declspec(dllexport) int PassParameter(char** a, char** b, char** c)
{
    printf("function call: test-parameters, receved: %s, %s, %s\n", *a, *b, *c);
    *a = "modified1";
    *b = "modified2";
    *c = "modified3";
    return 0;
}

#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
