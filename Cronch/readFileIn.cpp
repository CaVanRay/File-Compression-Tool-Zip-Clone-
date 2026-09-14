#include <fstream>
#include <vector>
#include <cstdint>

std::vector<uint8_t> read_binary_file(const std::string& filename){

  // Open file in binary mode
  std::ifstream file(filename, std::ios::binary | std::ios::ate);

  if (!file.is_open()){
    
  }
  
}
