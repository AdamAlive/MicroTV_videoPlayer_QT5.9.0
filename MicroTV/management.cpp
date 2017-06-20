#include "Management.h"
using namespace std;
Management::Management(const string & name, const string & passport, const long int & id)

{
    Account::Account(name, passport, id);
}
Management::~Management()
{
}
