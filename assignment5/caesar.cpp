#include "caesar.hpp"
#include "cipher.hpp"

CaesarCipher::CaesarCipher() : Cipher() {

}

CaesarCipher::~CaesarCipher() {

}

std::string CaesarCipher::encrypt( std::string &text ) {
  std::string output = text;
  std::string::size_type len = output.length();
  for (int i = 0; i != len; ++i) {
    if (output[i] >= 'a' && output[i] <= 'z' - shift) {
      output[i] = output[i] + shift;
    } else if (output[i] >= 'A' && output[i] <= 'Z' - shift) {
      output[i] = output[i] + shift;
    } else if (output[i] > 'z' - shift && output[i] <= 'z') {
      output[i] = 'a' + ((output[i] + shift) - 'z');
    } else if (output[i] > 'Z' - shift && output[i] <= 'Z') {
      output[i] = 'A' + ((output[i] + shift) - 'Z');
    }
  }
  return output;
}

std::string CaesarCipher::decrypt( std::string &text ) {
  std::string output = text;
  std::string::size_type len = output.length();
  for (int i = 0; i != len; ++i) {
    if (output[i] >= 'a' + shift && output[i] <= 'z') {
      output[i] = output[i] - shift;
    } else if (output[i] >= 'A' + shift && output[i] <= 'Z') {
      output[i] = output[i] - shift;
    } else if (output[i] > 'a' && output[i] <= 'a' + shift) {
      output[i] = 'z' - (output[i] - shift);
    } else if (output[i] > 'Z' - shift && output[i] <= 'Z') {
      output[i] = 'Z' + (output[i] - shift);
    }
  }
  return output;
}
