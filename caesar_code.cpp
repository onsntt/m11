#include <iostream>
char code(char c, int k)
{
    if (c >= 'a' && c <= 'z')
    {
        c = 'a' + ((c - 'a' + k) % 26);
    }
    else if (c >= 'A' && c <= 'Z')
    {
        c = 'A' + ((c - 'A' + k) % 26);
    }
    else if (c >= '0' && c <= '9')
    {
        c = '0' + ((c - '0' + k) % 10);
    }
    else if (c == ' ')
    {
        c = ' ';
    }
    //std::cout << c << "\n";
    return c;
}
int main()
{
    std::cout << "Enter your string!\n";
    std::string str;
    getline(std::cin, str); // this warning is bad, but I can't prevent it
    std::cout << "Enter your Key !\n";
    int key;
    std::cin >> key;
    std::string result = "";
    for (int i = 0; i < str.length(); i++)
    {
        result += code(str[i], key);
    }
    std::cout << result;
}