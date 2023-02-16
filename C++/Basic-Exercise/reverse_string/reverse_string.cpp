#include "reverse_string.h"
#include <string>
using namespace std;
namespace reverse_string{
  
    string reverse_string(string str){
        string reverse;
        for(int i=str.length()-1; i >= 0; i--){
            reverse.push_back(str[i]);
        }
        return reverse;
    }
}