#include "QuerySolver.h"

using namespace std;

/* NU MODIFICATI */
QuerySolver::QuerySolver()
{
  server = Server::GetInstance();
}

/* NU MODIFICATI */
QuerySolver::~QuerySolver()
{
  if (server != nullptr)
  {
    server = nullptr;
  }
}

list<Product *> QuerySolver::Query_3a()
{
  list<Product *> p, nou;
  p = server->getProductsList();
  list<Product *>::iterator it;
  for (it = p.begin(); it != p.end(); it++)
  {
    if ((*it)->getProductType() == "redus" && (*it)->getCategory() == "espressor")
      nou.push_back(*it);
  }
  return nou;
  //throw("undefined");
}

list<User *> QuerySolver::Query_3b()
{
  list<User *> p, nou;
  p = server->getUsersList();
  list<User *>::iterator it;
  for (it = p.begin(); it != p.end(); it++)
  {
    if ((*it)->getUserType() == "nonPremium")
    {
      BasicUser *it2 = dynamic_cast<BasicUser *>(*it);
      if (it2 != NULL)
      {
        if ((*it2).getTransportCost() <= 11.5)
          nou.push_back(*it);
      }
    }
  }
  return nou;
  //throw("undefined");
}

list<Product *> QuerySolver::Query_3c()
{
  list<Product *> p, nou;
  p = server->getProductsList();
  list<Product *>::iterator it;
  for (it = p.begin(); it != p.end(); it++)
  {
    if ((*it)->getProductType() == "resigilat")
    {
      ReturnedProduct *it2 = dynamic_cast<ReturnedProduct *>(*it);
      if (it2 != NULL)
      {
        if ((*it2).getReason() == "lipsa_accesorii")
        {
          nou.push_back(*it);
        }
      }
    }
  }
  nou.sort(Utility::compareProducts);
  return nou;
  //throw("undefined");
}

list<Product *> QuerySolver::Query_3d()
{
  list<Product *> p, nou;
  p = server->getProductsList();
  list<Product *>::iterator it;
  for (it = p.begin(); it != p.end(); it++)
  {
    if ((*it)->getProductType() == "alimentar")
    {
      nou.push_back(*it);
    }
  }
  nou.sort(Utility::groupByName);
  return nou;
  //throw("undefined");
}

list<User *> QuerySolver::Query_3e()
{
  Utility obj;
  string jud;
  list<User *> p, nou;
  p = server->getUsersList();
  list<User *>::iterator it;
  jud = obj.FindCounty(p);
  for (it = p.begin(); it != p.end(); it++)
  {
    if ((*it)->getBillingData().getCounty() == jud && (*it)->getDeliveryData().getCounty() == jud)
      if ((*it)->getBillingData().getBlock() == "-" && (*it)->getDeliveryData().getBlock() == "-" && (*it)->getBillingData().getApartment() == 0 && (*it)->getDeliveryData().getApartment() == 0)
      {
        nou.push_back(*it);
      }
  }
  nou.sort(Utility::sortByID);
  return nou;
  //throw("undefined");
}
list<User *> QuerySolver::Query_3f()
{
  list<User *> u, nou;
  u = server->getUsersList();
  list<User *>::iterator iu;
  list<Product *> p;
  p = server->getProductsList();
  list<Product *>::iterator ip;
  vector<int> v;
  vector<int>::iterator i;
  for (ip = p.begin(); ip != p.end(); ip++)
  {
    if ((*ip)->getCategory() == "telefon" || (*ip)->getCategory() == "imprimanta")
    {
      v.push_back((*ip)->getId());
    }
  }

  for (iu = u.begin(); iu != u.end(); ++iu)
  {
    if ((*iu)->getUserType() == "premium")
    {
      PremiumUser *it2 = dynamic_cast<PremiumUser *>(*iu);
      for (i = v.begin(); i != v.end(); i++)
      {
        if ((*it2).getDiscounts().find(*i) != (*it2).getDiscounts().end())
        {
          nou.push_back(*iu);
          break;
        }
      }
    }
  }
  return nou;
  //throw("undefined");
}
