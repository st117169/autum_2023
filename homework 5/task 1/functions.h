#pragma once

#include <iostream>


 //1 - Вывести массив 

void print(int* a, int n);

//2 - Добавить элемент в массив

void add(int* a, int n, int c);

//3 - Удалить элемент из массива

void del1(int* a, int n, int c);
void del2(int* a, int n, int c);

//4 - Отсортировать массив по возрастанию(любым способом)

bool sort_1(int a, int b);

//5 - Развернуть массив

void turn(int* a, int n);

//6 - Поменять местами первый максимальный и последний минимальный элемент массива

void change(int* a, int n);

//7 - Удалить из массива все дубликаты

void del_cop(int* a, int n);

//8 - Добавить в массив n случайных элементов(n вводится с клавиатуры)

void add_rand(int* a, int n);
