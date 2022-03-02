#pragma once
#include <iostream>
#include <string>
#include <limits.h>
#include <list>
#include <vector>
#include "../Solution/Product/NonFoodProduct.h"
#include "../Solution/Product/FoodProduct.h"
#include "../Solution/User/User.h"

class Utility
{

public:
    static bool compareProducts(Product *, Product *);
    static bool groupByName(Product *, Product *);
    static bool sortByID(User *, User *);
    string FindCounty(list<User *> );
};