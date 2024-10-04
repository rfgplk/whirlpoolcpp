#include "../src/whirlpool.hpp"
#include <algorithm>
#include <format>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

int
main(void)
{
  std::string data;

  while ( std::cin >> data ) {
    auto digest = whirlpool(data);
    for ( const auto n : digest ) {
      std::cout << std::hex << std::setfill('0') << std::setw(16) << n;
    }
    std::cout << "  (message)" << std::endl;     // to conform to test output
    break;
  }
  return 0;
}
