#include <stdio.h>
#include <string.h>
#include "product.h"
#include "manager.h"

int main(void){
    Product plist[100];
    int index=0;
    int count = 0, menu;
    index=count;
#ifdef DEBUG
        printDebug();
        printInfo();
    #endif

    count=loadData(plist);
    while (1){
        //printf("count=%d, index=%d\n",count, index);
        menu = selectMenu();
        if (menu == 0) break;//메뉴 종료
        if (menu == 1){//점수 조회
            if(count==0){
                printf("*입력된 데이터가 없습니다.*\n");
                continue;
            }
            else{
                listProduct(plist, index);
                continue;
            }
           
            
        }
        else if (menu == 2){//점수 추가
            count+= addProduct(&plist[index++]);
            
            printf("=> 추가됨!\n");
            
        }
        else if (menu == 3){//수정
            
            if(count==0){
                printf("*수정할 데이터가 없습니다.*\n");
                continue;
            }
            
            int no = selectDataNo(plist, index);
            if(no==0){
                printf("=> 취소됨!\n");
                continue;
            }
            updateProduct(&plist[no-1]);
           
            printf("=>수정됨!\n");
            
            
        }
        else if (menu == 4){
            if(count==0){
                printf("*삭제할 데이터가 없습니다.*\n");
            }
            else{
            
                int no =selectDataNo(plist, index);
                if(no==0){
                    printf("=> 취소됨!\n");
                    continue;
                }
                int deleteok;
                printf("정말로 삭제하시겠습니까?(삭제: 1) ");
                scanf("%d", &deleteok);
                if(deleteok==1){
                    if(deleteProduct(&plist[no-1])){
                        count--;
                    }
                    printf("=> 삭제됨!\n");

                }
                else{
                    printf("=> 취소됨!\n");
                    continue;
                }
                
            }
        }
        else if (menu == 5){
            saveProduct(plist, index);
        }
        else if (menu == 6){
            findByName(plist,index);
        }
        else if (menu == 7){
            findByInfo(plist,index);
        }
        else if (menu == 8){
            findByWonsanji(plist,index);
        }
        else{
            printf("잘못된 번호입니다.\n");
        }
    }
    printf("종료됨!\n");
    return 0;
}
