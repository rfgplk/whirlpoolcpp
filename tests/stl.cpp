#include "../src/whirlpool.hpp"
#include <iostream>
#include <string>
#include <vector>
int
main(void)
{
  std::string helloworld = "Hello World";
  auto digest_helloworld = whirlpool(helloworld);
  for ( const auto n : digest_helloworld )
    std::cout << std::hex << n;
  std::cout << std::endl;
  std::vector<float> vecf(2500, 4574.2f);

  auto digest_vecf = whirlpool(vecf);
  for ( const auto n : digest_vecf )
    std::cout << std::hex << n;
  std::cout << std::endl;
  for ( auto &n : vecf )
    n *= n;

  digest_vecf = whirlpool(vecf);
  for ( const auto n : digest_vecf )
    std::cout << std::hex << n;
  std::cout << std::endl;
  return 0;
}
