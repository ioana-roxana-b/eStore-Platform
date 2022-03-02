#include "utility.h"
bool Utility::compareProducts(Product *prod1, Product *prod2)
{
    NonFoodProduct *prod11 = dynamic_cast<NonFoodProduct *>(prod1);
    NonFoodProduct *prod22 = dynamic_cast<NonFoodProduct *>(prod2);
    if ((*prod11).getPrice() < (*prod22).getPrice())
    {
        return true;
    }
    if ((*prod11).getPrice() > (*prod22).getPrice())
    {
        return false;
    }
    return false;
}
bool Utility::groupByName(Product *prod1, Product *prod2)
{
    if ((*prod1).getName() != (*prod2).getName())
    {
        if ((*prod1).getName() < (*prod2).getName())
        {
            return true;
        }
        if ((*prod1).getName() > (*prod2).getName())
        {
            return false;
        }
    }
    if ((*prod1).getName() == (*prod2).getName())
    {
        FoodProduct *prod11 = dynamic_cast<FoodProduct *>(prod1);
        FoodProduct *prod22 = dynamic_cast<FoodProduct *>(prod2);
        if ((*prod11).getCountryOfOrigin() == (*prod22).getCountryOfOrigin())
        {
            if ((*prod11).getLeiPerKg() < (*prod22).getLeiPerKg())
            {
                return true;
            }
            if ((*prod11).getLeiPerKg() > (*prod22).getLeiPerKg())
            {
                return false;
            }
        }
        if ((*prod11).getCountryOfOrigin() != (*prod22).getCountryOfOrigin())
        {
            if ((*prod11).getCountryOfOrigin() < (*prod22).getCountryOfOrigin())
            {
                return true;
            }
            if ((*prod11).getCountryOfOrigin() > (*prod22).getCountryOfOrigin())
            {
                return false;
            }
        }
    }
    return false;
}
bool Utility::sortByID(User *u1, User *u2)
{
    if ((*u1).getUserID() < (*u2).getUserID())
    {
        return true;
    }
    if ((*u1).getUserID() > (*u2).getUserID())
    {
        return false;
    }
    return false;
}
string Utility::FindCounty(list<User *> u)
{
    string *a, jud;
    int n = 0, nr_ap, max = 0;
    list<User *>::iterator it;
    for (it = u.begin(); it != u.end(); it++)
    {
        n++;
    }
    a = new string[n];
    int x = 0;
    for (it = u.begin(); it != u.end(); it++)
    {
        a[x] = ((*it)->getDeliveryData().getCounty());
        x++;
    }
    for (int i = 1; i < x; i++)
    {
        nr_ap = 1;
        for (int j = i + 1; j <= x; j++)
            if (a[i] == a[j])
                nr_ap++;
        if (nr_ap > max)
            max = nr_ap;
    }
    for (int i = 1; i < x; i++)
    {
        nr_ap = 1;
        for (int j = i + 1; j <= x; j++)
            if (a[i] == a[j])
                nr_ap++;
        if (nr_ap == max)
        {
            jud = a[i];
        }
    }
    delete []a;
    return jud;
}