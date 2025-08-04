#ifndef STRING_HH
#define STRING_HH

namespace Strings {
  bool equals(const char* string1, const char* string2) {    
      for(int i = 0; i < 4; i++) {
        if(string1[i] != string2[i]) {
          return false;
        }
      }

      return true;
  }

  void clear(char* string) {
    for(int i = 0; i < 4; i++) {
      string[i] = '\0';
    }
  }
};

#endif