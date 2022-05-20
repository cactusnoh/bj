long long power(long long a, long long x)
{
  long long ret = 1;

  while(x) {
    if(x & 1) {
      ret *= a;
    }
    a *= a;
    x >>= 1;
  }

  return ret;
}