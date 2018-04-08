#include <iostream>
#include <vector>

//These should be in their own file.

bool is_an_abundant_number(long n)
{
  long sum = 1;
  //We can continue looping untill sqrt(n)
  //Every found divisior is part of a pair expect a sqrt(n) that is a divisor.
  for (long i = 2; i <= n / i; ++i)
  {
    if (n % i == 0) {
      if ((n / i) == i) {
          sum += i;
          break;
      }

      sum += i;
      sum += n/i;
    }

  }
  return n < sum;
}

std::vector< long > find_first_n_abundants(long n)
{
  long counter = 0;
  std::vector< long > result;

  for (long i = 1; counter < n; ++i)
  {
    if (is_an_abundant_number(i)) {
        result.push_back(i);
        ++counter;
    }
  }

  return result;
}

void print_vector(std::vector< long > v)
{
  for (auto b = v.begin(); b != v.end(); ++b)
  {
    std::cout << *b << std::endl;
  }
}

int main(int argc, char* argv[])
{
  if (argc < 2) {
    std::cout << "Too few arguments!" << std::endl;
    return 1;
  }
  else {

    long n = std::stol(argv[1]);

    auto v = find_first_n_abundants(n);

    print_vector(v);

  }

  return 0;
}
