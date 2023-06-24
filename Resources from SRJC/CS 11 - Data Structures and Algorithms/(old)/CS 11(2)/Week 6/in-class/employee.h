




















employee::employee()
{
  netPay = 0;
}

employee::employee(const string& newName, const string& newSsn)
{
  name = newName;
  ssn = newSsn;
  netPay = 0;
}

void employee::changeName(const string& newName)
{
  name = newName;
}

void employee::changeSsn(const string& newSsn)
{
  ssn = newSsn;
}
