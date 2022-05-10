#include <iostream>
#include <fstream>
#include <map>
#include <string>

using std::cout; using std::ofstream;
using std::endl; using std::string;
using std::fstream;

int main()
{
    string filename2("tmp2.txt");
    fstream outfile;

    outfile.open(filename2, std::ios_base::out);

    std::ifstream ifs("in.txt");
    std::string s;
    std::map<std::string, int> map;
    std::string text;

    while (ifs >> s)
        ++map[s];

    typedef std::map<std::string, int>::const_iterator iter;
    for (iter it = map.begin(); it != map.end(); ++it) {
        std::cout << "le nombre d'occurence du mot " << it->first << " est " << it->second << std::endl;
        std::string s = std::to_string(it->second);
        text = "le nombre d'occurence du mot " + it->first + "est " + s + '\r';

        if (!outfile.is_open()) {
            cout << "failed to open " << filename2 << '\n';
        }
        else {
            outfile.write(text.data(), text.size());

        }
    }

   
    


    return 0;
}