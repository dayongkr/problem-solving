int trailingZeroes(int n){
  int a = 1;
  int result = 0;
  while (n > a)
  {
    a *= 5;
    result += n / a;
  }
  return result;
}