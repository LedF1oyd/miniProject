typedef struct{
    char name[20];
    char wonsan[20];
    char info[200];
    char weight[20];
    int price;
    int ship;
} Product;
int loadData(Product*p);//真 真
int addProduct(Product *p);//真 真
int selectMenu();//真 真
void readProduct(Product p);//listProduct真 真 真 真
void listProduct(Product *p, int count);//真 真� 真
int updateProduct(Product *p);//真� 真 真
int deleteProduct(Product *p);//真 真
int selectDataNo(Product *p, int count);//真� 真� 真� 真� 真
void findByName(Product*p, int index);//真真 真 真
void findByInfo(Product*p, int index);//真真 真 真
void findByWonsanji(Product*p, int index);//真� 真真 真 真
void saveProduct(Product*p, int count);//真� 真真 真
