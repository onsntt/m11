#include <iostream>
#include <string>
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

std::string octetString (std::string inp, int begin, int end)
{
std::string resultOctet = "";
for (int i = begin; i < end; i++) {
    if (inp[i] >= '0' && inp[i] <= '9') {
      resultOctet += inp[i];
    }

}
if (resultOctet.length() < 1 || resultOctet.length() > 3) return "incorrect";
    else return resultOctet;
}

bool octetOk (std::string inp)
{
int octet = 0;
if (inp.length() == 3) {
    octet = (inp[2] - '0') + ((inp[1] - '0') * 10) + ((inp[0] - '0') * 100);
} else if (inp.length() == 2) {
    octet = (inp[1] - '0') + ((inp[0] - '0') * 10);
} else if (inp.length() == 1) {
    octet = (inp[0] - '0');
} else return 0;
if (octet > 255) return 0;
if (inp != std::to_string(octet)) {
    return 0;
} else return 1;

}
void error() {std::cout << "Incorrect IP address!\n";}
int main() {
std::string whiteList = "0123456789.";   
std::cout << "Enter IP-address! \n";
std::string string;
std::cin >> string;

int firstDot, secondDot, thirdDot = 0;

//std::cout << symbols(string, whiteList) << "\n";
if (!symbols) {
    error();
    abort();
}

firstDot = getIndex(1, string);
secondDot = getIndex(2, string);
thirdDot = getIndex(3, string);

if (firstDot == 0 || secondDot == 0 || thirdDot == 0) {

 error();
 abort();
} 
std::string firstOctet = octetString(string, 0, firstDot);
std::string secondOctet = octetString(string, firstDot, secondDot);
std::string thirdOctet = octetString(string, secondDot, thirdDot);
std::string lastOctet = octetString(string, thirdDot, string.length());

if (firstOctet == "incorrect" || secondOctet == "incorrect" || thirdOctet == "incorrect" || lastOctet == "incorrect") {

 error();
 abort();
}


std::cout << firstDot << " " << secondDot << " " << thirdDot << "\n";

 //std::cout << octetOk(string, 0, firstDot) << " " << octetOk(string, firstDot, secondDot) << " " << octetOk(string, secondDot, thirdDot) << " " << octetOk(string, thirdDot, string.length()) << "\n";
 //std::cout << firstOctet << " " << secondOctet << " " << thirdOctet << " " << lastOctet << "\n";
 //std::cout << octetOk(firstOctet) << " " << octetOk(secondOctet) << " " << octetOk(thirdOctet) << " " << octetOk(lastOctet) << "\n";
 //if ((!symbols) || firstDot == 0 )
 if (!octetOk(firstOctet) || !octetOk(secondOctet) || !octetOk(thirdOctet) || !octetOk(lastOctet)) {
    error();
    abort();
 } else std::cout << "Correct IP address!\n";
}