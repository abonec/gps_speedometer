char *doubleToChar(double var, int width, int prec)
{
  char str_temp[6];
  return dtostrf(var, width, prec, str_temp);
}
