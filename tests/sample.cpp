#include "../src/whirlpool.hpp"
#include <iostream>
#include <string>

int
main(void)
{
  const char *e = "";
  auto digest_empty = whirlpool(e);
  const char *fox = "The quick brown fox jumps over the lazy dog";
  auto digest_fox = whirlpool(fox);
  const char *a = "a";
  auto digest_a = whirlpool(a);
  const char *large
      = "y78q34y78mtvqy78mowtym7oae4ctyy89o,sy,9osey,9ve5h,y95vh,ey8se5vyhhu8o,s,h8os5,h89os,hj89ohj89o,j89o,";
  auto digest_large = whirlpool(large);
  std::cout << std::hex;
  std::cout << "Empty string: " << std::endl;
  for ( const auto n : digest_empty )
    std::cout << n;
  std::cout << std::endl;

  std::cout << std::hex;
  std::cout << "The quick brown fox jumps over the lazy dog: " << std::endl;
  for ( const auto n : digest_fox )
    std::cout << n;
  std::cout << std::endl;

  std::cout << std::hex;
  std::cout << "a: " << std::endl;
  for ( const auto n : digest_a )
    std::cout << n;
  std::cout << std::endl;

  std::cout << "y78q34y78mtvqy78mowtym7oae4ctyy89o,sy,9osey,9ve5h,y95vh,ey8se5vyhhu8o,s,h8os5,h89os,hj89ohj89o,j89o,: "
            << std::endl;
  for ( const auto n : digest_large )
    std::cout << n;
  std::cout << std::endl;

  return 0;
}
