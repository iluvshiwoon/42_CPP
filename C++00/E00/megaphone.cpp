#include <iostream>
#include <string>

int main(int argc, char ** argv)
{
    bool is_empty_input = true;
    bool first_pass = true;

    for (int i = 1; i < argc; i++)
    {
        std::string str = argv[i];

        std::string::size_type start = str.find_first_not_of(" \t\n\r\f\v");

        if (start == std::string::npos)
            continue;
        is_empty_input = false;

        std::string::size_type end = str.find_last_not_of(" \t\n\r\f\v");
        str = str.substr(start, end - start + 1);

        for (std::string::size_type j = 0; j < str.length(); j++)
        {
            if (str[j] >= 'a' && str[j] <= 'z')
                str[j] += 'A' - 'a';
        }
        if (first_pass == true)
            first_pass = false;
        else 
            std::cout << " ";
        std::cout << str;
    }

    if (is_empty_input == true)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
}
