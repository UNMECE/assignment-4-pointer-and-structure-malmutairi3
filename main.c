#include "item.h"

 

void add_item(Item *itemList, double price, char *sku, char *category, char *name, int index)
{
    itemList[index].price = price;

    int sku_length = strlen(sku);
    itemList[index].sku = (char *)malloc(sku_length + 1);
    strcpy(itemList[index].sku, sku);

    int name_length = strlen(name);
    itemList[index].name = (char *)malloc(name_length + 1);
    strcpy(itemList[index].name, name);

    int category_length = strlen(category);
    itemList[index].category = (char *)malloc(category_length + 1);
    strcpy(itemList[index].category, category);
}

void free_items(Item *itemList, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        free(itemList[i].sku);
        free(itemList[i].name);
        free(itemList[i].category);
    }
    free(itemList);
}

double average_price(Item *itemList, int size)
{
    double sum = 0.0;
    int i;
    for (i = 0; i < size; i++)
    {
        sum += itemList[i].price;
    }
    double avg = sum / size;
    return avg;
}

void print_items(Item *itemList, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf(" ###############\n");
        printf("Item name = %s\n", itemList[i].name);
        printf("Item SKU = %s\n", itemList[i].sku);
        printf("Item category = %s\n", itemList[i].category);
        printf("Item price = %.2f\n", itemList[i].price);
    }
    printf("###############\n");
}

void find_item(Item *itemList, int size, char *sku)
{
    int i = 0;
    while (i < size && strcmp(itemList[i].sku, sku) != 0)
    {
        i++;
    }

    if (i < size)
    {
        printf ("###############\n");
        printf("Item found:\n");
        printf("item name = %s\n", itemList[i].name);
        printf("Item SKU = %s\n", itemList[i].sku);
        printf("Item category = %s\n", itemList[i].category);
        printf("Item Price = %.2f\n", itemList[i].price);
        printf("###############\n");
    }
    else
    {
        printf("Item not Found\n");
    }
}

int main(int argc, char *argv[])
{
    // step 1
    Item *itemList = (Item *)malloc(5 * sizeof(Item));

    add_item(itemList,  5.00, "19282", "breakfast", "reese's cereal", 0);
    add_item(itemList, 3.95, "79862", "dairy", "milk", 1);
    add_item(itemList, 2.50, "12345", "snack", "chips", 2);
    add_item(itemList, 8.75, "54321", "beverage", "coffee", 3);
    add_item(itemList, 11.10,  "67890", "fruit", "banana", 4);

    if (argc == 2)
    {
        find_item(itemList, 5, argv[1]);
    }
    else{
        print_items(itemList, 5);

    double avg = average_price(itemList, 5);
    printf("Average price of items = %.2f\n", avg);

    }
    

    

    free_items(itemList, 5);

    return 0;
}
