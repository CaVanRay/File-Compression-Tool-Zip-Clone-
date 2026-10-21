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

    std::array<size_t, 256> freq{};
  
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

byte ogNumber;
uint32_t newID;
treeBranch* top;
treeBranch* bottom;

};

/***************************************************************************
*
*      Stucture for each limb on the huffman tree? not sure I'll need this
*      
***************************************************************************/

// input: will be created using the previously created treeNodes
// output: structure that tracks whether path is left or right

struct treeBranch{

bool isLeft;
treeNode* top;
treeNode* bottom;

};

/***************************************************************************
*
*      Using completed tree create an ID for each byte in the huffman tree
*      
***************************************************************************/

// input: treeNode 
// output: ID number

uint32_t nodeIDsetter(treeNode& ){
  
}

/***************************************************************************
*
*      create file for saving compiled data
*      
***************************************************************************/

// input: not required, file will persist for future writing
// output: not required

void createFile(){
  
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

void fillInFile(){
  
}

/***************************************************************************
*
*      Possibly need to attach a footer, not sure
*      
***************************************************************************/

// input: file name for compressed data
// output: void output, just adding footer

void writeFooter(){
  
}
