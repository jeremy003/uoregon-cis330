#ifndef CAESARCIPHER_HPP_
#define CAESARCIPHER_HPP_

class CaesarCipher : public Cipher {
private:
  
public:
  CaesarCipher();
  ~CaesarCipher();

	std::string encrypt( std::string &text ) = 0;
	std::string decrypt( std::string &text ) = 0;

};





#endif
