#include <string>
#include "helper.h"

std::string encrypt_caesar (std::string s, int parameter) {
    for (int i = 0; i < s.length(); i++) {
        if ( (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ) {
            if (s[i] + parameter > 'Z' && s[i] == toupper(s[i])) {
                s[i] = (s[i] + parameter - 'Z') +'A' - 1;
            } else if (s[i] + parameter > 'z' && s[i] != toupper(s[i])) {
                s[i] = (s[i] + parameter - 'z') +'a' - 1;
            } else s[i] += parameter;
        }
    }
    return s;
}

std::string decrypt_caesar (std::string s, int parameter) {
    for (int i = 0; i < s.length(); i++) {
        if ( (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ) {
            if (s[i] - parameter < 'A' && s[i] == toupper(s[i]))
                s[i] = 'Z' - ('A' - (s[i] - parameter)) + 1;
            else if (s[i] - parameter < 'a' && s[i] != toupper(s[i]))
                s[i] = 'z' - ('a' - (s[i] - parameter)) + 1;
            else s[i] -= parameter;
        }
    }
    return s;
}
