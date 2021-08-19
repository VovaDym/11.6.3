#include <iostream>
#include <string>
int n(std::string part)
{
    int number = 0;
    for(int i = 0; i < part.length(); ++i)
    {
        int digit = part[i] -'0';
        number = number * 10 + digit;
    }
    return number;
}
bool correct (std::string part)
{
    bool correct;
    for (int i = 0; i < part.length(); ++i)
    {
        if( part[0] == '.'|| part.length() > 3
        || (part[0] == '0' && part[0 + 1] >= '0')
        || (part[i] < '0' && part[i] != '.' ) || part[i] > '9')
        {
            correct = false;
        }
        else if (part[i] >= '0' && part[i] <= '9')
        {
            correct = true;
        }
    }
    return correct;
}
int main()
{
    std::string ip;
    std::cout << "Enter the ip address!" << std::endl;
    std::cin >> ip ;
    if(ip[0] == '.' || ip[ip.length() - 1] == '.' )
    {
        std::cout << "No";
    }
    else
    {
        int pos = 0;
        int pos2 = 0;
        int pos3 = 0;
        int dot = 0;
        bool points = false;
        for (int i = 0;i < ip.length();i++)
        {
            if ( ip[i] == '.' && ip[i + 1] == '.')
            {
                points = true;
                break;
            }
            else if(dot == 0 && ip[i] == '.')
            {
                pos += i;
                ++dot;
            }
            else if (dot == 1 && ip[i] == '.')
            {
                pos2 += i;
                ++dot;
            }
            else if (dot == 2 && ip[i] == '.')
            {
                pos3 += i;
                ++dot;
            }
        }
        if (!points)
        {
            std::string part = ip.substr(0,pos);
            std::string part2 = ip.substr(pos + 1,pos2 - (pos + 1));
            std::string part3 = ip.substr(pos2 + 1,pos3 - (pos2 +1));
            std::string part4 = ip.substr(pos3 + 1,ip.length() - (pos3 +1));
            if(n(part) <= 255 &&correct(part) && n(part2) <= 255  && correct(part2)
            && n(part3) <= 255 && correct(part3) && n(part4) <= 255 && correct(part4))
            {
                std::cout << "Yes";
            }
            else
            {
                std::cout << "No";
            }
        }
        else
        {
            std::cout << "No";
        }
    }
}
