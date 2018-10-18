#include "ADT_linked_list.h"

int main(){
    printf("55555\n");
    
    LIST* list = create_list();

    
    int data[5] = { 1, 6, 3, 2, 15 };

    for(int i = 0; i < sizeof(data)/sizeof(int); i++){
        printf("%d\n", i);
        node_insertion(list, 0, &data[i]);
    }
    
    // node_insertion(list, 0, &data[0]);
    // node_insertion(list, 1, &data[1]);
    // node_insertion(list, 1, &data[3]);

    check_list(list);

    return 0;
}