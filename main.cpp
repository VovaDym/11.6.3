#include <iostream>
#include <string>
int n(std::string part)
{
    int digit = 0;
    for(int i = 0; i < part.length(); ++i)
    {
        digit += part[i] -'0';
        digit *= 10;
    }
    return digit / 10;
}

int main() {
    std::string ip;
    std::string part = "";
    std::string part2 = "";
    std::string part3 = "";
    std::string part4 = "";
    std::cout << "Enter the ip address!" << std::endl;
    std::cin >> ip ;
    if(ip[ip.length() - 1] == '.')
    {
        std::cout << "No";
    }
    else
    {
        bool correct = true;
        for (int i = 0; i < ip.length(); ++i)
        {

            if(ip[0] == '.' || (ip[0] == '0' && ip[0 + 1] >= '0')
                || (ip[i] < '0' && ip[i] != '.' )|| ip[i] > '9')
            {
                correct = false;
                break;
            }
            else if (ip[i] >= '0' && ip[i] <= '9')
            {
                part += ip[i];
            }
            else if (ip[i] == '.') {
                break;
            }
        }
        if(!correct  || part.length() > 3 || n(part) > 255)
        {
            std::cout << "No";
        }
        else
        {

            for (int i = part.length() + 1; i < ip.length(); ++i)
            {
                if(ip[part.length() + 1] == '.' || (ip[i] < '0' && ip[i] != '.')
                    || ip[i] > '9'||(ip[part.length() + 1] == '0'
                    && ip[part.length() + 2] >= '0'))
                {
                    correct = false;
                    break;
                }
                else if (ip[i] >= '0' && ip[i] <= '9')
                {
                    part2 += ip[i];
                }
                else if (ip[i] == '.')
                {
                    break;
                }
            }
            if(!correct || part2.length() > 3 || n(part2) > 255)
            {
                std::cout << "No";
            }
            else
            {

                for (int i = part.length() + part2.length()  + 2; i < ip.length(); ++i)
                {
                    if(ip[part.length() + part2.length()  + 2] == '.' || (ip[i] < '0' && ip[i] != '.' )
                        || ip[i] > '9'||(ip[part.length() + part2.length()  + 2] == '0'
                        && ip[part.length() + part2.length()  + 3] >= '0'))
                    {
                        correct = false;
                        break;
                    }
                    else if (ip[i] >= '0' && ip[i] <= '9')
                    {
                        part3 += ip[i];
                    }
                    else if (ip[i] == '.')
                    {
                        break;
                    }
                }
                if (!correct || part3.length() > 3 || n(part3) > 255)
                {
                    std::cout << "No";
                }
                else
                {
                    for (int i = part.length() + part2.length() + part3.length() + 3; i < ip.length(); ++i)
                    {
                        if(ip[part.length() + part2.length() + part3.length() + 3] == '.'
                            || (ip[i] < '0' && ip[i] != '.' )|| ip[i] > '9'
                            ||(ip[part.length() + part2.length() + part3.length() + 3] == '0'
                            && ip[part.length() + part2.length() + part3.length() + 4] >= '0'))
                        {
                            correct = false;
                            break;
                        }
                        else if (ip[i] >= '0' && ip[i] <= '9')
                        {
                            part4 += ip[i];
                        }
                        else if (ip[i] == '.')
                        {
                            break;
                        }
                    }
                    if (!correct || part4.length() > 3 || n(part4) > 255)
                    {
                        std::cout << "No";
                    }
                    else
                    {
                        std::cout << "Yes";
                    }
                }

            }
        }
    }

}





