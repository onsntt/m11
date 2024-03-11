#include <iostream>
bool symbols(std::string inp, std::string whiteList)
{
    if (inp.length() < 7 || inp.length() > 15) return false;
    for (int i = 0; i < inp.length();)
    {
        bool equal = false;
        for (int j = 0; j < whiteList.length();)
        {
            if (inp[i] == whiteList[j])
            {
                equal = true;
                break;
            }
            else
            {
                j++;
            }
        }
        if (equal == false)
        {
            return false;
        }
        i++;
    }
    return true;
}
int getIndex(int number, std::string inp)
{
   int i = 0; 
   int dotNumber = 0;
   int first = 0;
   int second = 0;
   int third = 0;
   while (i < inp.length()) {
    if (inp[i] == '.' && dotNumber == 0) {
       first = i;
       dotNumber += 1;
       i++;
    }
    else if (inp[i] == '.' && dotNumber == 1) {
        second = i;
        dotNumber += 1;
        i++;
    }
    else if (inp[i] == '.' && dotNumber == 2) {
        third = i;
        dotNumber += 1;
        i++;
    }
    else if (inp[i] == '.' && dotNumber == 3) {
        return 0;
    }
    else i++;    
   }
   if (number == 1) return first;
   else if (number == 2) return second;
   else if (number == 3) return third;
   else return 0;
   
}

std::string octetOk (std::string inp, int begin, int end)
{
std::string resultOctet = "";
for (int i = begin; i < end; i++) {
    if (inp[i] >= '0' && inp[i] <= '9') {
      resultOctet += inp[i];
    }

}
return resultOctet;
}
int main() {
std::string whiteList = "0123456789.";   
std::cout << "Enter IP-address! \n";
std::string string;
std::cin >> string;
int firstDot, secondDot, thirdDot = 0;

std::cout << symbols(string, whiteList) << "\n";
firstDot = getIndex(1, string);
secondDot = getIndex(2, string);
thirdDot = getIndex(3, string);

//std::cout << getIndex(1, string) << " " << getIndex(2, string) << " " << getIndex(3, string) << "\n";
std::cout << octetOk(string, 0, firstDot) << " " << octetOk(string, firstDot, secondDot) << " " << octetOk(string, secondDot, thirdDot) << " " << octetOk(string, thirdDot, string.length()) << "\n";
}