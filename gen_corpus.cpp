#include <fstream>
#include <string>
#include <vector>

void create_corpus_file(const std::string &filename, int K, const std::string &text) {
    std::ofstream file(filename, std::ios::binary);
    char k_byte = static_cast<char>(K);
    file.write(text.c_str(), text.size());
    file.write(&k_byte, sizeof(k_byte));
    file.close();
}


int main() {
    std::vector<std::string> texts = {"hello", "abcabc", "xyzxyzxyz", "nope", "aisfgs", "akjdhas", "NVMCXBYUJGEYUF"};

    for (size_t i = 0; i < texts.size(); ++i) {
        std::string filename = "corpus/corpus_" + std::to_string(i) + ".txt";
        create_corpus_file(filename, rand(), texts[i]);
    }

    return 0;
}
