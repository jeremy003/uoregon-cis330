#ifndef CAESARCIPHER_HPP_
#define CAESARCIPHER_HPP_

#include "cipher.hpp"

class CaesarCipher : public Cipher {
private:
  int shift = 1;
public:
  CaesarCipher();
  virtual ~CaesarCipher();
	virtual std::string encrypt( std::string &text );
	virtual std::string decrypt( std::string &text );

};


#endif
