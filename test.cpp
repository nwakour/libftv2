#include <gtest/gtest.h>

extern "C" {
	#include "string/ft_string.h"
	#include "vector/ft_vector.h"
}

// TEST(vector, vectorInit)
// {
// 	t_vector vector = vectorInit(sizeof(int), 0);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 0);
// 	ASSERT_TRUE(vectorBegin(&vector) == NULL);
// }

// TEST(vector, vectorPushBack)
// {
// 	t_vector vector = vectorInit(sizeof(int), 0);
// 	int i = 10;
// 	vectorPushBack(&vector, &i);
// 	ASSERT_TRUE(vectorSize(&vector) == 1);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 1);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 10);

// 	i = 20;
// 	vectorPushBack(&vector, &i);
// 	ASSERT_TRUE(vectorSize(&vector) == 2);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 2);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 10);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,1) == 20);
// 	vectorClear(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 2);
// 	vectorFree(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 0);
// 	ASSERT_TRUE(vectorBegin(&vector) == NULL);
// }

// TEST(vector, vectorPushFront)
// {
// 	t_vector vector = vectorInit(sizeof(int), 0);
// 	int i = 10;
// 	vectorPushFront(&vector, &i);
// 	ASSERT_TRUE(vectorSize(&vector) == 1);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 1);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 10);

// 	i = 20;
// 	vectorPushFront(&vector, &i);
// 	ASSERT_TRUE(vectorSize(&vector) == 2);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 2);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 20);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,1) == 10);
// 	vectorClear(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 2);
// 	vectorFree(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 0);
// 	ASSERT_TRUE(vectorBegin(&vector) == NULL);
// }

// TEST(vector, vectorPopBack)
// {
// 	t_vector vector = vectorInit(sizeof(int), 0);
// 	int i = 10;
// 	vectorPushBack(&vector, &i);
// 	i = 20;
// 	vectorPushBack(&vector, &i);
// 	i = 30;
// 	vectorPushBack(&vector, &i);
// 	ASSERT_TRUE(vectorSize(&vector) == 3);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 10);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,1) == 20);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,2) == 30);

// 	vectorPopBack(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 2);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 10);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,1) == 20);

// 	vectorPopBack(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 1);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 10);

// 	vectorPopBack(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(vectorBegin(&vector) == vectorEnd(&vector));
// 	vectorFree(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 0);
// 	ASSERT_TRUE(vectorBegin(&vector) == NULL);
// }

// TEST(vector, vectorPopFront)
// {
// 	t_vector vector = vectorInit(sizeof(int), 0);
// 	int i = 10;
// 	vectorPushBack(&vector, &i);
// 	i = 20;
// 	vectorPushBack(&vector, &i);
// 	i = 30;
// 	vectorPushBack(&vector, &i);
// 	ASSERT_TRUE(vectorSize(&vector) == 3);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 10);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,1) == 20);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,2) == 30);

// 	vectorPopFront(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 2);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 20);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,1) == 30);

// 	vectorPopFront(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 1);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 30);

// 	vectorPopFront(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(vectorBegin(&vector) == vectorEnd(&vector));
// 	vectorFree(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 0);
// 	ASSERT_TRUE(vectorBegin(&vector) == NULL);
// }

// TEST(vector, vectorInsert)
// {
// 	t_vector vector = vectorInit(sizeof(int), 0);
// 	int i = 10;
// 	vectorPushBack(&vector, &i);
// 	i = 20;
// 	vectorPushBack(&vector, &i);
// 	i = 30;
// 	vectorPushBack(&vector, &i);
// 	ASSERT_TRUE(vectorSize(&vector) == 3);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 10);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,1) == 20);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,2) == 30);

// 	i = 40;
// 	vectorInsert(&vector, 1, &i);
// 	ASSERT_TRUE(vectorSize(&vector) == 4);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 10);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,1) == 40);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,2) == 20);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,3) == 30);

// 	i = 50;
// 	vectorInsert(&vector, 0, &i);
// 	ASSERT_TRUE(vectorSize(&vector) == 5);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 8);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 50);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,1) == 10);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,2) == 40);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,3) == 20);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,4) == 30);

// 	i = 60;
// 	vectorInsert(&vector, 5, &i);
// 	ASSERT_TRUE(vectorSize(&vector) == 6);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 8);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 50);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,1) == 10);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,2) == 40);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,3) == 20);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,4) == 30);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,5) == 60);
// 	vectorFree(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 0);
// 	ASSERT_TRUE(vectorBegin(&vector) == NULL);
// }

// TEST(vector, vectorInsertIt)
// {
// 	t_vector vector = vectorInit(sizeof(int), 0);
// 	int i = 10;
// 	vectorPushBack(&vector, &i);
// 	i = 20;
// 	vectorPushBack(&vector, &i);
// 	i = 30;
// 	vectorPushBack(&vector, &i);
// 	ASSERT_TRUE(vectorSize(&vector) == 3);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 10);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,1) == 20);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,2) == 30);

// 	i = 40;
// 	vectorInsertIt(&vector, vectorAt(&vector, 1), &i);
// 	ASSERT_TRUE(vectorSize(&vector) == 4);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 10);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,1) == 40);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,2) == 20);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,3) == 30);

// 	i = 50;
// 	vectorInsertIt(&vector, vectorBegin(&vector), &i);
// 	ASSERT_TRUE(vectorSize(&vector) == 5);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 8);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 50);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,1) == 10);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,2) == 40);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,3) == 20);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,4) == 30);

// 	i = 60;
// 	vectorInsertIt(&vector, vectorEnd(&vector), &i);
// 	ASSERT_TRUE(vectorSize(&vector) == 6);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 8);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 50);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,1) == 10);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,2) == 40);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,3) == 20);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,4) == 30);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,5) == 60);
// 	vectorFree(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 0);
// 	ASSERT_TRUE(vectorBegin(&vector) == NULL);
// }

// TEST(vector, vectorErase)
// {
// 	t_vector vector = vectorInit(sizeof(int), 0);
// 	int i = 10;
// 	vectorPushBack(&vector, &i);
// 	i = 20;
// 	vectorPushBack(&vector, &i);
// 	i = 30;
// 	vectorPushBack(&vector, &i);
// 	i = 40;
// 	vectorPushBack(&vector, &i);
// 	i = 50;
// 	vectorPushBack(&vector, &i);
// 	ASSERT_TRUE(vectorSize(&vector) == 5);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 8);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 10);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,1) == 20);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,2) == 30);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,3) == 40);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,4) == 50);

// 	vectorErase(&vector, 1);
// 	ASSERT_TRUE(vectorSize(&vector) == 4);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 8);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 10);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,1) == 30);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,2) == 40);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,3) == 50);

// 	vectorErase(&vector, 0);
// 	ASSERT_TRUE(vectorSize(&vector) == 3);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 8);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 30);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,1) == 40);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,2) == 50);

// 	vectorErase(&vector, 2);
// 	ASSERT_TRUE(vectorSize(&vector) == 2);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 8);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 30);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,1) == 40);

// 	vectorErase(&vector, 1);
// 	ASSERT_TRUE(vectorSize(&vector) == 1);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 8);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 30);

// 	vectorErase(&vector, 0);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 8);
// 	ASSERT_TRUE(vectorBegin(&vector) == vectorEnd(&vector));
// 	vectorFree(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 0);
// 	ASSERT_TRUE(vectorBegin(&vector) == NULL);
// }

// TEST(vector, vectorEraseIt)
// {
// 	t_vector vector = vectorInit(sizeof(int), 0);
// 	int i = 10;
// 	vectorPushBack(&vector, &i);
// 	i = 20;
// 	vectorPushBack(&vector, &i);
// 	i = 30;
// 	vectorPushBack(&vector, &i);
// 	i = 40;
// 	vectorPushBack(&vector, &i);
// 	i = 50;
// 	vectorPushBack(&vector, &i);
// 	ASSERT_TRUE(vectorSize(&vector) == 5);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 8);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 10);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,1) == 20);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,2) == 30);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,3) == 40);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,4) == 50);

// 	vectorEraseIt(&vector, vectorAt(&vector, 1));
// 	ASSERT_TRUE(vectorSize(&vector) == 4);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 8);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 10);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,1) == 30);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,2) == 40);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,3) == 50);

// 	vectorEraseIt(&vector, vectorBegin(&vector));
// 	ASSERT_TRUE(vectorSize(&vector) == 3);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 8);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 30);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,1) == 40);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,2) == 50);

// 	vectorEraseIt(&vector, vectorAt(&vector, vectorSize(&vector) - 1));
// 	ASSERT_TRUE(vectorSize(&vector) == 2);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 8);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 30);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,1) == 40);

// 	vectorEraseIt(&vector, vectorAt(&vector, vectorSize(&vector) - 1));
// 	ASSERT_TRUE(vectorSize(&vector) == 1);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 8);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 30);

// 	vectorEraseIt(&vector, vectorBegin(&vector));
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 8);
// 	ASSERT_TRUE(vectorBegin(&vector) == vectorEnd(&vector));
// 	vectorFree(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 0);
// 	ASSERT_TRUE(vectorBegin(&vector) == NULL);
// }

// TEST(vector, vectorEraseRangeIt)
// {
// 	t_vector vector = vectorInit(sizeof(int), 0);
// 	int i = 10;
// 	vectorPushBack(&vector, &i);
// 	i = 20;
// 	vectorPushBack(&vector, &i);
// 	i = 30;
// 	vectorPushBack(&vector, &i);
// 	i = 40;
// 	vectorPushBack(&vector, &i);
// 	i = 50;
// 	vectorPushBack(&vector, &i);
// 	ASSERT_TRUE(vectorSize(&vector) == 5);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 8);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 10);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,1) == 20);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,2) == 30);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,3) == 40);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,4) == 50);

// 	vectorEraseRangeIt(&vector, vectorAt(&vector, 1), vectorAt(&vector, 3));
// 	ASSERT_TRUE(vectorSize(&vector) == 3);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 8);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 10);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,1) == 40);
// 	ASSERT_TRUE(*(int*)vectorAt(&vector,2) == 50);

// 	vectorEraseRangeIt(&vector, vectorBegin(&vector), vectorAt(&vector, 1));
// 	ASSERT_TRUE(vectorSize(&vector) == 2);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 8);
// 	ASSERT_TRUE(*(int*)vectorBegin(&vector) == 40);

// 	vectorEraseRangeIt(&vector, vectorBegin(&vector), vectorEnd(&vector));
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 8);
// 	ASSERT_TRUE(vectorBegin(&vector) == vectorEnd(&vector));
// 	vectorFree(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 0);
// 	ASSERT_TRUE(vectorBegin(&vector) == NULL);
// }

// TEST(vector, vectorInit_with_string)
// {
// 	t_vector vector = vectorInit(sizeof(t_string), _freeString);
// 	ASSERT_TRUE(&vector != NULL);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 0);
// 	ASSERT_TRUE(vectorBegin(&vector) == NULL);
// }


// TEST(vector, vectorPushBack_with_string)
// {
// 	t_vector vector = vectorInit(sizeof(t_string), _freeString);
// 	t_string string = stringNew("Hello");
// 	vectorPushBack(&vector, &string);
// 	string = stringNew("World");
// 	vectorPushBack(&vector, &string);
// 	string = stringNew("!");
// 	vectorPushBack(&vector, &string);
// 	ASSERT_TRUE(vectorSize(&vector) == 3);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorBegin(&vector), "Hello") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 1), "World") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 2), "!") == 0);
// 	vectorClear(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(vectorBegin(&vector) == vectorEnd(&vector));
// 	vectorFree(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 0);
// 	ASSERT_TRUE(vectorBegin(&vector) == NULL);
// }
// TEST(vector, vectorPushFront_with_string)
// {
// 	t_vector vector = vectorInit(sizeof(t_string), _freeString);
// 	t_string string = stringNew("Hello");
// 	vectorPushFront(&vector, &string);
// 	string = stringNew("World");
// 	vectorPushFront(&vector, &string);
// 	string = stringNew("!");
// 	vectorPushFront(&vector, &string);
// 	ASSERT_TRUE(vectorSize(&vector) == 3);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorBegin(&vector), "!") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 1), "World") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 2), "Hello") == 0);
// 	vectorClear(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(vectorBegin(&vector) == vectorEnd(&vector));
// 	vectorFree(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 0);
// 	ASSERT_TRUE(vectorBegin(&vector) == NULL);
// }

// TEST(vector, vectorPopBack_with_string)
// {
// 	t_vector vector = vectorInit(sizeof(t_string), _freeString);
// 	t_string string = stringNew("Hello");
// 	vectorPushBack(&vector, &string);
// 	string = stringNew("World");
// 	vectorPushBack(&vector, &string);
// 	string = stringNew("!");
// 	vectorPushBack(&vector, &string);
// 	ASSERT_TRUE(vectorSize(&vector) == 3);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorBegin(&vector), "Hello") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 1), "World") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 2), "!") == 0);
// 	vectorPopBack(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 2);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorBegin(&vector), "Hello") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 1), "World") == 0);
// 	vectorPopBack(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 1);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorBegin(&vector), "Hello") == 0);
// 	vectorPopBack(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(vectorBegin(&vector) == vectorEnd(&vector));
// 	vectorFree(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 0);
// 	ASSERT_TRUE(vectorBegin(&vector) == NULL);
// }
// TEST(vector, vectorPopFront_with_string)
// {
// 	t_vector vector = vectorInit(sizeof(t_string), _freeString);
// 	t_string string = stringNew("Hello");
// 	vectorPushBack(&vector, &string);
// 	string = stringNew("World");
// 	vectorPushBack(&vector, &string);
// 	string = stringNew("!");
// 	vectorPushBack(&vector, &string);
// 	ASSERT_TRUE(vectorSize(&vector) == 3);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorBegin(&vector), "Hello") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 1), "World") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 2), "!") == 0);
// 	vectorPopFront(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 2);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorBegin(&vector), "World") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 1), "!") == 0);
// 	vectorPopFront(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 1);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorBegin(&vector), "!") == 0);
// 	vectorPopFront(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(vectorBegin(&vector) == vectorEnd(&vector));
// 	vectorFree(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 0);
// 	ASSERT_TRUE(vectorBegin(&vector) == NULL);
// }

// TEST(vector, vectorInsert_with_string)
// {
// 	t_vector vector = vectorInit(sizeof(t_string), _freeString);
// 	t_string string = stringNew("Hello");
// 	vectorPushBack(&vector, &string);
// 	string = stringNew("World");
// 	vectorPushBack(&vector, &string);
// 	string = stringNew("!");
// 	vectorPushBack(&vector, &string);
// 	ASSERT_TRUE(vectorSize(&vector) == 3);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorBegin(&vector), "Hello") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 1), "World") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 2), "!") == 0);
// 	string = stringNew("C");
// 	vectorInsert(&vector, 1, &string);
// 	ASSERT_TRUE(vectorSize(&vector) == 4);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorBegin(&vector), "Hello") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 1), "C") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 2), "World") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 3), "!") == 0);
// 	vectorClear(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(vectorBegin(&vector) == vectorEnd(&vector));
// 	vectorFree(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 0);
// 	ASSERT_TRUE(vectorBegin(&vector) == NULL);
// }

// TEST(vector, vectorInsertIt_with_string)
// {
// 	t_vector vector = vectorInit(sizeof(t_string), _freeString);
// 	t_string string = stringNew("Hello");
// 	vectorPushBack(&vector, &string);
// 	string = stringNew("World");
// 	vectorPushBack(&vector, &string);
// 	string = stringNew("!");
// 	vectorPushBack(&vector, &string);
// 	ASSERT_TRUE(vectorSize(&vector) == 3);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorBegin(&vector), "Hello") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 1), "World") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 2), "!") == 0);
// 	string = stringNew("C");
// 	vectorInsertIt(&vector, vectorAt(&vector, 1), &string);
// 	ASSERT_TRUE(vectorSize(&vector) == 4);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorBegin(&vector), "Hello") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 1), "C") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 2), "World") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 3), "!") == 0);
// 	vectorClear(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(vectorBegin(&vector) == vectorEnd(&vector));
// 	vectorFree(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 0);
// 	ASSERT_TRUE(vectorBegin(&vector) == NULL);
// }

// TEST(vector, vectorErase_with_string)
// {
// 	t_vector vector = vectorInit(sizeof(t_string), _freeString);
// 	t_string string = stringNew("Hello");
// 	vectorPushBack(&vector, &string);
// 	string = stringNew("World");
// 	vectorPushBack(&vector, &string);
// 	string = stringNew("!");
// 	vectorPushBack(&vector, &string);
// 	ASSERT_TRUE(vectorSize(&vector) == 3);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorBegin(&vector), "Hello") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 1), "World") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 2), "!") == 0);
// 	vectorErase(&vector, 1);
// 	ASSERT_TRUE(vectorSize(&vector) == 2);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorBegin(&vector), "Hello") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 1), "!") == 0);
// 	vectorErase(&vector, 0);
// 	ASSERT_TRUE(vectorSize(&vector) == 1);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorBegin(&vector), "!") == 0);
// 	vectorErase(&vector, 0);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(vectorBegin(&vector) == vectorEnd(&vector));
// 	vectorFree(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 0);
// 	ASSERT_TRUE(vectorBegin(&vector) == NULL);
// }

// TEST(vector, vectorEraseIt_with_string)
// {
// 	t_vector vector = vectorInit(sizeof(t_string), _freeString);
// 	t_string string = stringNew("Hello");
// 	vectorPushBack(&vector, &string);
// 	string = stringNew("World");
// 	vectorPushBack(&vector, &string);
// 	string = stringNew("!");
// 	vectorPushBack(&vector, &string);
// 	ASSERT_TRUE(vectorSize(&vector) == 3);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorBegin(&vector), "Hello") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 1), "World") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 2), "!") == 0);
// 	vectorEraseIt(&vector, vectorAt(&vector, 1));
// 	ASSERT_TRUE(vectorSize(&vector) == 2);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorBegin(&vector), "Hello") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 1), "!") == 0);
// 	vectorEraseIt(&vector, vectorBegin(&vector));
// 	ASSERT_TRUE(vectorSize(&vector) == 1);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorBegin(&vector), "!") == 0);
// 	vectorEraseIt(&vector, vectorBegin(&vector));
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(vectorBegin(&vector) == vectorEnd(&vector));
// 	vectorFree(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 0);
// 	ASSERT_TRUE(vectorBegin(&vector) == NULL);
// }

// TEST(vector, vectorEraseRangeIt_with_string)
// {
// 	t_vector vector = vectorInit(sizeof(t_string), _freeString);
// 	t_string string = stringNew("Hello");
// 	vectorPushBack(&vector, &string);
// 	string = stringNew("World");
// 	vectorPushBack(&vector, &string);
// 	string = stringNew("!");
// 	vectorPushBack(&vector, &string);
// 	ASSERT_TRUE(vectorSize(&vector) == 3);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorBegin(&vector), "Hello") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 1), "World") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 2), "!") == 0);
// 	vectorEraseRangeIt(&vector, vectorAt(&vector, 1), vectorAt(&vector, 2));
// 	ASSERT_TRUE(vectorSize(&vector) == 2);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorBegin(&vector), "Hello") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 1), "!") == 0);
// 	vectorEraseRangeIt(&vector, vectorBegin(&vector), vectorAt(&vector, 2));
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(vectorBegin(&vector) == vectorEnd(&vector));
// 	vectorFree(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 0);
// 	ASSERT_TRUE(vectorBegin(&vector) == NULL);
// }
// TEST(vector, vectorFind_with_string)
// {
// 	t_vector vector = vectorInit(sizeof(t_string), _freeString);
// 	t_string string = stringNew("Hello");
// 	vectorPushBack(&vector, &string);
// 	string = stringNew("World");
// 	vectorPushBack(&vector, &string);
// 	string = stringNew("!");
// 	vectorPushBack(&vector, &string);
// 	ASSERT_TRUE(vectorSize(&vector) == 3);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 4);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorBegin(&vector), "Hello") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 1), "World") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorAt(&vector, 2), "!") == 0);
// 	ASSERT_TRUE(vectorFind(&vector, "adgadsgad", _findCString) == vectorEnd(&vector));
// 	ASSERT_TRUE(stringComCString((t_string*)vectorFind(&vector, "Hello", _findCString), "Hello") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorFind(&vector, "World", _findCString), "World") == 0);
// 	ASSERT_TRUE(stringComCString((t_string*)vectorFind(&vector, "!", _findCString), "!") == 0);
// 	string = stringNew("Hello");
// 	ASSERT_TRUE(stringComCString((t_string*)vectorFind(&vector, &string, _findString), "Hello") == 0);
// 	stringFree(&string);
// 	string = stringNew("World");
// 	ASSERT_TRUE(stringComCString((t_string*)vectorFind(&vector, &string, _findString), "World") == 0);
// 	stringFree(&string);
// 	string = stringNew("!");
// 	ASSERT_TRUE(stringComCString((t_string*)vectorFind(&vector, &string, _findString), "!") == 0);
// 	stringFree(&string);
// 	vectorFree(&vector);
// 	ASSERT_TRUE(vectorSize(&vector) == 0);
// 	ASSERT_TRUE(vectorCapacity(&vector) == 0);
// 	ASSERT_TRUE(vectorBegin(&vector) == NULL);
// }
int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}