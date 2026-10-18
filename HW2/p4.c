/* CS100 Fall 2026 - HW2 Problem 4: GCC argument descriptor
 *
 * Read GCC-style command-line arguments (argv) and print a description
 * for each of them, in order. No standard input in this problem.
 * Do not rename this file.
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    for (int i=0;i<argc;i++){
        if(strcmp(*(argv+i),"-Wall")==0){
            printf("-Wall: Enable all the warnings about constructions that some users consider questionable, and that are easy to avoid (or modify to prevent the warning).\n");
        }
        else if(strcmp(*(argv+i),"-Wpedantic")==0){
            printf("-Wpedantic: Issue all the warnings demanded by strict ISO C and ISO C++ and reject all programs that use forbidden extensions.\n");
        } 
        else if(strcmp(*(argv+i),"-Wextra")==0){
            printf("-Wextra: Enable some extra warning flags that are not enabled by -Wall.\n");
        } 
        else if(strcmp(*(argv+i),"-Werror")==0){
            printf("-Werror: Make all warnings into errors.\n");
        }            
        else if (strncmp(*(argv+i),"-o",2)==0){
            printf("-o %s: Place the primary output in file %s.\n",*(argv+i+1),*(argv+i+1));
        }
        else if (strncmp(*(argv+i),"-I",2)==0){
            printf("-I %s: Add the directory %s to the list of directories to be searched for header files during preprocessing.\n",*(argv+i+1),*(argv+i+1));
        }
        else if (strncmp(*(argv+i),"-std=",5)==0){
            if (strncmp(*(argv+i)+5,"gnu++",5)==0){
                printf("-std=%s: Set the language standard to GNU dialect of C++%s.\n",*(argv+i)+5,*(argv+i)+10);
            }
            else if (strncmp(*(argv+i)+5,"gnu",3)==0){
                printf("-std=%s: Set the language standard to GNU dialect of C%s.\n",*(argv+i)+5,*(argv+i)+8);
            }
            else if (strncmp(*(argv+i)+5,"c++",3)==0){
                printf("-std=%s: Set the language standard to ISO C++%s.\n",*(argv+i)+5,*(argv+i)+8);
            }
            else{
                printf("-std=%s: Set the language standard to ISO C%s.\n",*(argv+i)+5,*(argv+i)+6);
            }
        }  
        else {
            char *dot = strrchr(*(argv+i), '.');
            if (dot != NULL && strcmp(dot, ".c") == 0) {
                printf("%s: C source code as input file.\n", *(argv+i));
            } 
            else if (dot != NULL && strcmp(dot, ".h") == 0) {
                printf("%s: C/C++ header file as input file.\n", *(argv+i));
            } 
            else if (dot != NULL && (strcmp(dot, ".cpp") == 0 ||
                                       strcmp(dot, ".C")   == 0 ||
                                       strcmp(dot, ".cc")  == 0 ||
                                       strcmp(dot, ".cxx") == 0)) {
                printf("%s: C++ source code as input file.\n", *(argv+i));
            } 
            else if (dot != NULL && (strcmp(dot, ".hpp") == 0 ||
                                       strcmp(dot, ".hxx") == 0)) {
                printf("%s: C++ header file as input file.\n", *(argv+i));
            }
        } 
    }
    (void)argc;
    (void)argv;
    return 0;
}
