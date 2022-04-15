#include <stdio.h>
#include "manager.h"

void printDebug(){
    printf("=>디버깅 모드로 진입하였습니다.\n");
}
void printInfo(){
    printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
}
