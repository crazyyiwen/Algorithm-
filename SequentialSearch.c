#include <stdio.h>
#include <stdlib.h>
#define keyType int

typedef struct{
    
    keyType key;
}ElemType;

typedef struct{
    
    ElemType *elem;
    int length;
}SSTable;

void Create(SSTable **st, int length){
    
    (*st) = (SSTable *)malloc(sizeof(SSTable));
    (*st)->length = length;
    (*st)->elem = (ElemType *)malloc((length + 1)*sizeof(ElemType));
    printf("input element: \n");
    for(int i=1; i<=length; i++){
        
        scanf("%d", &((*st)->elem[i].key));
    }
}

int SearchSeq(SSTable *st, keyType key){
    
    st->elem[0].key = key;
    int i = st->length;
    while(st->elem[i].key != key){
        i--;
    }
    return i;
}

int main()
{
    int key;
    int location;
    SSTable *st;
    Create(&st, 6);
    getchar();
    printf("please key word to search\n");
    scanf("%d", &key);
    location = SearchSeq(st, key);
    if(location == 0){
        printf("success\n");
    }
    else{
        printf("failed\n");
    }

    return 0;
}
