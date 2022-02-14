#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

int main(int argc, char* argv[])
{
  // Get filename.
  std::string filename;
  if (1 < argc)
  {
    filename = argv[1];
  }
  else
  {
    std::cerr << "ERROR: Cannot read arguments." << std::endl;
    std::exit(EXIT_FAILURE);
  }

  // Open input file stream.
  std::ifstream ifs(filename);
  if (!ifs)
  {
    std::cerr << "ERROR: Cannot open input file stream." << std::endl;
    std::exit(EXIT_FAILURE);
  }

  // Read each one line in file.
  int wordCount = 0;
  std::vector<std::string> linebufs;
  while (!ifs.eof())
  {
    // Read each one line.
    std::string linebuf;
    if (!std::getline(ifs, linebuf))
    {
      //std::cerr << "ERROR: Cannot read line." << std::endl;
      break;
    }

    // Read one word.
    std::stringstream ss(linebuf);
    std::string wordbuf;
    ss >> wordbuf;
    wordCount += wordbuf.size();

    // Add line buffer.
    linebufs.push_back(wordbuf);
  }

  // Display.
  std::cout << std::endl;
  std::cout << "Display all text in file." << std::endl;
  std::cout << "    Line Count: " << linebufs.size() << std::endl;
  std::cout << "    Word Count: " << wordCount << std::endl;
  std::cout << "------------------------- Start -------------------------" << std::endl;
  for (size_t i = 0; i < linebufs.size(); ++i)
  {
    std::cout << std::setprecision(3) << i;
    std::cout << ": ";
    std::cout << linebufs[i] << std::endl;
  }
  std::cout << "-------------------------- End --------------------------" << std::endl;

  // Close input file stream.
  ifs.close();

  return EXIT_SUCCESS;
}
