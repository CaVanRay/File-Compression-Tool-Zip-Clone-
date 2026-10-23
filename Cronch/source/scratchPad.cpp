/***************************************************************************
*
*      Title: ScratchPad
*
*      Author: Cavan Ray Theiss
*
*      Description: Using this as a place to work on general code before
*      adding it to the specific files
*      
***************************************************************************/

/***************************************************************************
*
*      Open file in binary mode
*      
***************************************************************************/

// input: file name
// output: Vector of bytes

std::vector<std::byte> fileReader(const std::string& fileToOpen){
    
    std::ifstream file(fileToOpen, std::ios::binary | std::ios::ate);
    if(!file) throw std::runtime_error("Cannot open file");

    auto size = file.tellg();
    if (size < 0) throw std::runtime_error("Cannot determine file size");
    file.seekg(0, std::ios::beg);

    std::vector<std::byte> fileInBytes(static_cast<size_t>(size));
    file.read(reinterpret_cast<char*>(fileInBytes.data()), size);
    fileInBytes.resize(file.gcount()); // in case of short read
    
    return fileInBytes;
}

/***************************************************************************
*
*      Count frequencies
*      
***************************************************************************/
// input: vector of bytes
// output: array of frequencies

std::array<size_t, 256> frequencyMappin(const std::vector<std::byte>& fileInBytes){

    std::array<size_t, 256> freq{}; // zero-initialized
    for (auto smolByte : fileInBytes)
        ++freq[static_cast<size_t>(smolByte)];
    return freq;
}

/***************************************************************************
*
*      Structure for each node on the huffman tree
*      
***************************************************************************/

// input: a byte from vector list and a matching int from array
// output: structure that tracks original byte, eventual ID, connections to 
//         other nodes

struct treeNode{

size_t freq; // frequency weight (for building the tree)
std::byte ogNumber; // only needed for leaves, internal nodes don't have an original byte
treeNode* left = nullptr;
treeNode* right = nullptr;

};

/***************************************************************************
*
*      Build tree
*      
***************************************************************************/

// input: the vector list of bytes and the matching array of frequencies
// output: technically void, but it will create a tree of connected nodes

treeNode treeBuilder(const std::vector<std::byte>& fileInBytes, const std::array<size_t, 256>& frequencyMap){
    
}

/***************************************************************************
*
*      Using completed tree create an ID for each byte in the huffman tree
*      
***************************************************************************/

// input: starts from the combined total node 
// output: ID numbers for all bytes in tree

std::vector<uint32_t> nodeIDsetter(treeNode& baseNode){
  
}

/***************************************************************************
*
*      create file for saving compiled data
*      
***************************************************************************/

// input: file name to save as
// output: not required

void createFile(std::string& fileName){
  
}

/***************************************************************************
*
*      Write header to file (already counted frequencies)
*      
***************************************************************************/

// input: frequency map & file name for compressed data
// output: changes saved in file, void output

void writeHeader(std::array<int>& fMap, std::string& fileName){
  
}

/***************************************************************************
*
*      Write original binary data to file but replace each original with 
*      new IDs created with tree
*      
***************************************************************************/

// input: original binary vector list & file name for compressed data
// output: changes saved in file, void output

void writeBodyAsIDs(std::vector<byte>& originalData, std::string& fileName){
  
}

/***************************************************************************
*
*      fill in end with 0's until number of digits is a multiplication of
*      8
*      
***************************************************************************/

// input: file name for compressed data
// output: void output, just checking file size and filling in with 0's

void fillInFile(std::string& fileName){
  
}

/***************************************************************************
*
*      Possibly need to attach a footer, not sure
*      
***************************************************************************/

// input: file name for compressed data
// output: void output, just adding footer

void writeFooter(std::string& fileName){
  
}
