#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>


// comparator written with support of chatgpt
// research more info on comparators
class CompareIPAddresses {

    public:
    
    bool operator()(const std::string& lhs, const std::string& rhs) const {
        // split ip adress on octets
        std::vector<int> lhsOctets = splitIP(lhs);
        std::vector<int> rhsOctets = splitIP(rhs);

        // compare every octet
        for (size_t i = 0; i < lhsOctets.size(); ++i) {
            if (lhsOctets[i] != rhsOctets[i]) {
                return lhsOctets[i] > rhsOctets[i];
            }
        }
        // if all octets are equal, then ip adress is equal
        return false;
    }

private:
    // method to split ip adress into octets
        std::vector<int> splitIP(const std::string& ipAddress) const{
        std::vector<int> octets;
        std::istringstream iss(ipAddress);
        std::string octet;
            while (std::getline(iss, octet, '.')) {
                octets.push_back(std::stoi(octet));
            }
        return octets;
    }
};

int main(){

    // IP_Adress t
    // t.ReadAdress(1,1,1,1); 

try{
    std::ifstream file("ip_filter.tsv");
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open the file!");
        return 1;
    }

    //using set with custom comparator to create an ordered set with reverse order
    std::set<std::string, CompareIPAddresses> ip_list;

    std::string line;
        while (std::getline(file, line)) {
            line.erase(line.find_first_of('\t'), line.npos);
            //std::cout << line << std::endl;
            ip_list.emplace(line);
        }

    file.close();

    for (auto i : ip_list)
    {
        std::cout << i << '\n';
    }
    

}


catch(const std::runtime_error &e)
{
    std::cerr << e.what() << std::endl;
}

return 0;

}