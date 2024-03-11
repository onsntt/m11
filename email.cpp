#include <iostream>
//first part format checking:
std::string firstPart (std::string string)
{
    std::string firstPartResult = "";
    int i = 0;
    if (string[0] == '@' || string[0] == '.')
    {
        return "incorrect";
    }
    else
    {
        for (i = 0; i < 63; i++) {
            
            firstPartResult += string[i];
            if (string[i] == '@') {
                break;
            }
            else if (string[i] == '.' && string[i - 1] == '.') {
                return "incorrect";
               
            }
        }
        if (string[i] != '@' || string[i - 1] == '.')
        {
            return "incorrect";
        }
        else
            return firstPartResult;
    }
}
//second part format checking:
std::string secondPart(std::string string, int secondPartBegin)
{
    std::string secondPartResult = "";
    
    int i =0;
    int dotCount = 0;
    if (string[secondPartBegin] == '.') {
        return "incorrect";
    } else {
    for (i = secondPartBegin; i < string.length(); i++) {
        
        secondPartResult += string[i];
        if (string[i] == '@')
        {
            return "incorrect";
            
        }
        else if (string[i] == '.' && string[i - 1] == '.')
        {
            return "incorrect";
        }
        else if (string[i] == '.')
        {
            dotCount += 1;
        }
        else if (i > 126)
        {
            return "incorrect";
            
        }
    }
          if (string[i - 1] == '.' || dotCount == 0) {
              return "incorrect";
              
          } else
              return secondPartResult;
}
}
//whitelist:
bool partCorrect(std::string inp, std::string whiteList)
{
  
for (int i = 0; i < inp.length(); ) {
    bool equal = false;
    for (int j = 0; j < whiteList.length();) {
        if (inp[i] == whiteList[j]) {
          equal = true;  
          break;
        } else {
            j++;
          }
          
    }
    if (equal == false){
        return false;
    }
    i++;
}
return true;


}
void error() {std::cout << "Incorrect email address!\n";}
int main(){

std::string input;
std::cout << "Enter email address!\n";
getline(std::cin, input); //what shold I do to prevent this warning?
std::string sub1 = "";
std::string sub2 = "";
std::string whiteListFirst = "!#$%&'*+-/=?^_`{|}~abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.@";
std::string whiteListSecond = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.-";

sub1 = firstPart(input);
int secondPartBegin = sub1.length();
sub2 = secondPart(input, secondPartBegin);
if (sub1 == "incorrect" || sub2 == "incorrect")  error();
else if (!partCorrect(sub2, whiteListSecond)) error();
else if (!partCorrect(sub1, whiteListFirst)) error();
else std::cout << "Correct email address!\n";

}

