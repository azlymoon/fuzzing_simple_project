#include "12.7_module.h"
#include <cstdint>
#include <iostream>
#include <sstream>

using namespace std;


extern "C" int LLVMFuzzerTestOneInput(const uint8_t* Data, size_t Size) {

    std::string input_data(reinterpret_cast<const char *>(Data), Size);

    std::istringstream fake_input(input_data);
    std::streambuf *cin_backup = std::cin.rdbuf();
    std::cin.rdbuf(fake_input.rdbuf());

    main_program();

    std::cin.rdbuf(cin_backup);
    return 0;
}