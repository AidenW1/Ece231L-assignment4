/*
Assignment 4 ECE231L
Aiden watt

A grocery list of items creatting a custom data type "item list" that holds price sku
category name and its index in a semi array type way

then uses memory allocation to store all the data in a way that is not like java

AI USE:
used claude to translate between java code and C
example: Systeme.out.printf("xyz",a,b,c); and its syntax

Again all the malloc stuff because that just dosent make any sense to someone with dynamic
memory allocation code skills and the ENTIRE free section again with memory allocation
and not understanding any of it really

again more syntaxing transfer from java to c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index);
void free_items(Item *item_list, int size);
double average_price(Item *item_list,  int size);
void print_items(Item *item_list, int size);
//Main takes in command line args and then pulls up that item
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
//item searching for loop
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
//item building method that is also allocating the memmory for each of the items and their chars
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

//I honesly have no idea what this really does but
//ai is telling me it just opens back up the memory of the pc
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
//averages item price pretty simple method of adding then submtting
double average_price(Item *item_list, int size)
{
	double adder = 0;
	for(int i = 0; i < size; i++)
	{
		adder += item_list[i].price;
	}
	return adder/size;
}
//print method also as simple as they come kinda weird with the whole indexing and not creating
//an array with all the item_list in it and just calling the whole datatype and print them formatted
//but I think thats more advanced than this here
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

