#include <iostream>
#include <fstream>

#include "ioutils.hpp"
#include "cipher.hpp"
#include "caesar.hpp"

int main(int argc, const char *argv[]) {

  IOUtils io;
  io.openStream(argc, argv);
  std::string input, encrypted, decrypted;
  input = io.readFromStream();
  std::cout << "Original text:" << std::endl << input;

  CaesarCipher caesar;
  encrypted = caesar.encrypt(input);
  std:: cout << "Encrypted text:" << std::endl << encrypted;

  decrypted = caesar.decrypt(input);
  std::cout << "Decrypted text:" << std::endl << decrypted;

  return 0;
}
