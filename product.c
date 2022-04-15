#include <stdio.h>
#include <string.h>
#include "product.h"
int loadData(Product*p){
    int i=0;
    FILE*file=NULL;
    file=fopen("product.txt","r");
    if(file==NULL){
        printf("=>파일에서 불러올 자료가 없습니다.\n");
        return 0;
    }
    while(!feof(file)){
        char line[1024];
        fgets(line, 1024, file);
        sscanf(line,"%[^\n,],%[^\n,],%[^\n,],%[^\n,],%d,%d",
        p[i].name,
        p[i].wonsan,
        p[i].info,
        p[i].weight,
        &p[i].price,
        &p[i].ship);
        i++;
    }
    fclose(file);
    printf("=> 파일에서 데이터를 불러왔습니다.\n");

    return i-1;
}
int addProduct(Product *p){//제품 추가
    printf("제품명을 입력하여 주세요 ");
    scanf("\n%[^\n]", p->name);
    printf("제품의 원산지를 입력하여 주세요 ");
    scanf("\n%[^\n]", p->wonsan);
    printf("제품의 소개를 입력하여 주세요 ");
    scanf("\n%[^\n]", p->info);
    printf("제품의 무게를 입력하여 주세요 ");
    scanf("%s", p->weight);
    printf("제품의 가격을 입력하여 주세요 ");
    scanf("%d", &p->price);
    printf("제품의 배송방법을 입력하여 주세요 (1: 새벽배송/ 2: 택배배송) ");
    scanf("%d", &p->ship);
    return 0;
}
int selectMenu(){
    int menu;
    printf("\n*** 과일등록 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 파일저장\n");
    printf("6. 이름검색\n");
    printf("7. 정보검색\n");
    printf("8. 원산지검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}
void readProduct(Product p){
    char shipment[20];
    if(p.ship==1){
        strcpy(shipment,"새벽배송");
    }
    else if(p.ship==2){
        strcpy(shipment,"택배배송");
    }
    
    printf("[%s] /%s /%s /%s /%d /%s\n", p.wonsan,p.name, p.weight, p.info, p.price, shipment);
}
void listProduct(Product *p, int count){
    printf("\n상품정보\n");
    printf("================================\n");
    printf("번호 원산지  품명  무게  소개  가격  배송방식\n");
    for(int i=0;i<count;i++){
        if(p[i].ship==-1){
            continue;
        }
        printf("%2d ", i+1);
        readProduct(p[i]);
    }
    printf("\n");
   
}
int updateProduct(Product *p){
    printf("***제품수정***\n");
    printf("제품명을 입력하여 주세요");
    scanf("\n%[^\n]", p->name);
    printf("제품의 원산지를 입력하여 주세요");
    scanf("\n%[^\n]", p->wonsan);
    printf("제품의 소개를 입력하여 주세요");
    scanf("\n%[^\n]", p->info);
    printf("제품의 무게를 입력하여 주세요");
    scanf("%s", p->weight);
    printf("제품의 가격을 입력하여 주세요");
    scanf("%d", &p->price);
    printf("제품의 배송방법을 입력하여 주세요 (1: 새벽배송/ 2: 택배배송) ");
    scanf("%d", &p->ship);
    return 0;
}
int deleteProduct(Product *p){
    p->ship=-1;
    return 1;
}
int selectDataNo(Product *p, int count){
    int no;
    listProduct(p, count);//리스트 보여주기
    while(1){
        printf("번호는 (취소: 0)? ");
        scanf("%d", &no);
        if(no<0||no>count){
            printf("잘못된 번호입니다.\n");
            continue;
        }
        else{
            break;
        }
    }
    
    return no;
}
void findByName(Product*p, int index){
    int found=0;
    char name[60];

    
    printf("검색할 상품이름은? ");
    scanf("%s", name);
    printf("\n상품정보\n");
    printf("================================\n");
    printf("번호 원산지  품명  무게  소개  가격  배송방식\n");
    for(int i=0;i<index;i++){
        //printf("%d번째 %s\n",i,s[i]->name);
        if(p[i].ship==-1){
            continue;   
        }
        
        if(strstr(p[i].name, name)!=NULL){
            //printf("%s",s[i]->name);
            found++;
            char shipment[20];
            if(p[i].ship==1){
                strcpy(shipment,"새벽배송");
            }
            else if(p[i].ship==2){
                strcpy(shipment,"택배배송");
            }
            printf("[%s] /%s /%s /%s /%d /%s\n", p[i].wonsan,p[i].name, p[i].weight, p[i].info, p[i].price, shipment);
            
        }
    }
    
    if(found==0){
        printf("검색된 데이터 없음!\n");
    }
}
void findByInfo(Product*p, int index){
    int found=0;
    char inf[60];

    
    printf("검색할 상품이름은? ");
    scanf("%s", inf);
    printf("\n상품정보\n");
    printf("================================\n");
    printf("번호 원산지  품명  무게  소개  가격  배송방식\n");
    for(int i=0;i<index;i++){
        //printf("%d번째 %s\n",i,s[i]->name);
        if(p[i].ship==-1){
            continue;   
        }
        
        if(strstr(p[i].info, inf)!=NULL){
            //printf("%s",s[i]->name);
            found++;
            char shipment[20];
            if(p[i].ship==1){
                strcpy(shipment,"새벽배송");
            }
            else if(p[i].ship==2){
                strcpy(shipment,"택배배송");
            }
            printf("[%s] /%s /%s /%s /%d /%s\n", p[i].wonsan,p[i].name, p[i].weight, p[i].info, p[i].price, shipment);
            
        }
    }
    
    if(found==0){
        printf("검색된 데이터 없음!\n");
    }
}
void findByWonsanji(Product*p, int index){
    int found=0;
    char won[60];

    
    printf("검색할 상품이름은? ");
    scanf("%s", won);
    printf("\n상품정보\n");
    printf("================================\n");
    printf("번호 원산지  품명  무게  소개  가격  배송방식\n");
    for(int i=0;i<index;i++){
        //printf("%d번째 %s\n",i,s[i]->name);
        if(p[i].ship==-1){
            continue;   
        }
        
        if(strstr(p[i].wonsan, won)!=NULL){
            //printf("%s",s[i]->name);
            found++;
            char shipment[20];
            if(p[i].ship==1){
                strcpy(shipment,"새벽배송");
            }
            else if(p[i].ship==2){
                strcpy(shipment,"택배배송");
            }
            printf("[%s] /%s /%s /%s /%d /%s\n", p[i].wonsan,p[i].name, p[i].weight, p[i].info, p[i].price, shipment);
            
        }
    }
    
    if(found==0){
        printf("검색된 데이터 없음!\n");
    }
}

void saveProduct(Product*p, int count){
    FILE *file;
    file=fopen("product.txt", "wt");
    for(int i=0;i<count;i++){
        if(p[i].ship==-1){
            continue;
        }
        
        fprintf(file,"%s,%s,%s,%s,%d,%d\n",
        p[i].name,
        p[i].wonsan,
        p[i].info,
        p[i].weight,
        p[i].price,
        p[i].ship);
    }
    fclose(file);
    printf("=>파일에 데이터를 저장하였습니다.!\n");
}
