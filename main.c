#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index);
void free_items(Item *item_list, int size);
double average_price(Item *item_list,  int size);
void print_items(Item *item_list, int size);

int main(int argc, char *argv[])
{
	int size = 5;

	Item *item_list = malloc(size * sizeof(Item));

	add_item(item_list, 5.00, "19282", "breakfast", "reese's cereal", 0);
	add_item(item_list, 3.95, "79862", "dairy", "milk", 1);
	add_item(item_list, 1.11, "12345", "FOOD", "One-O's", 2);
	add_item(item_list, 2.22, "23456", "foods", "Two-O's", 3);
	add_item(item_list, 3.33, "34567", "fooods", "Three-O's", 4);

	print_items(item_list, size);

	printf("Average Price of items = %f\n", average_price(item_list, size));

	if (argc < 2)
	{
		printf("Wrong input for main\n");
	}else
	{
		int n = 0;

		while( n < size && strcmp(item_list[n].sku, argv[1]) != 0)
		{
			n++;
		}
		if (n < size)
		{
			print_items(&item_list[n], 1);
		}
		else
		{
			printf("item not found\n");
		}
	}

	free_items(item_list, size);
	return 0;
}

void add_item(Item *item_list, double price, char *sku,  char *category, char *name, int index )
{
	item_list[index].price = price;

	item_list[index].sku = malloc(strlen(sku) + 1);
	strcpy(item_list[index].sku, sku);

	item_list[index].category = malloc(strlen(category) + 1);
	strcpy(item_list[index].category, category);

	item_list[index].name = malloc(strlen(name) + 1);
	strcpy(item_list[index].name, name);

}


void free_items(Item *item_list, int size)
{
	for(int i = 0; i < size; i++)
	{
		free(item_list[i].sku);
		free(item_list[i].category);
		free(item_list[i].name);
	}
	free(item_list);
}

double average_price(Item *item_list, int size)
{
	double adder = 0;
	for(int i = 0; i < size; i++)
	{
		adder += item_list[i].price;
	}
	return adder/size;
}

void print_items(Item *item_list, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("###############\n");
		printf("Item name = %s\n", item_list[i].name);
		printf("Item sku = %s\n", item_list[i].sku);
		printf("Item category = %s\n", item_list[i].category);
		printf("Item price = %f\n", item_list[i].price);
	}
		printf("###############\n");
}

