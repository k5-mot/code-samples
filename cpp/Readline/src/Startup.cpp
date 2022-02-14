#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

int main(int argc, char* argv[])
{
  while (true)
  {
    std::string linebuf;
    std::cout << "Input  : ";
    if (!std::getline(std::cin, linebuf))
    {
      std::cerr << "ERROR: Cannot read line." << std::endl;
      break;
    }
    if (linebuf.c_str()[0] == '\0')
    {
      std::cerr << std::endl;
      std::cerr << "EXIT." << std::endl;
      break;
    }

    std::cout << "Output : " << linebuf << std::endl;
    std::cout << std::endl;
  }
  return EXIT_SUCCESS;
}

