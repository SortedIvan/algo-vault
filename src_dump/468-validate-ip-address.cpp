class Solution {
public:
    string validIPAddress(string queryIP) {
        std::size_t checkIpv4 = queryIP.find('.');
        std::size_t checkIpv6 = queryIP.find(':');

        if (checkIpv4 != std::string::npos) {

            bool res = tryValidateIpv4(queryIP);

            if (res) {
                return "IPv4";
            }
        }

        if (checkIpv6 != std::string::npos) {
            bool res = tryValidateIpv6(queryIP);

            if (res) {
                return "IPv6";
            }
        }


        return "Neither";

    }

    bool tryValidateIpv6(string ip) {
        string tmp; 
        stringstream ss(ip);
        vector<string> ipParts;

        if (ip[ip.size() - 1] == ':') {
            return false;
        }

        while(getline(ss, tmp, ':')){
            ipParts.push_back(tmp);
        }

        if (ipParts.size() != 8) {
            return false;
        }

        for (string ipPart : ipParts) {
            if (ipPart.size() == 0) {
                return false;
            }

            if (ipPart.size() > 4) {
                return false;
            }

            for (int k = 0; k < ipPart.size(); k++) {
                if (ipPart[k] >= 48 && ipPart[k] <= 57) {

                } else if (ipPart[k] >= 97 && ipPart[k] <= 102) {

                } else if (ipPart[k] >= 65 && ipPart[k] <= 70) {

                } else {
                    return false;
                }
            }
        }

        return true;
    }

    bool tryValidateIpv4(string ip) {
        string tmp; 
        stringstream ss(ip);
        vector<string> ipParts;

        if (ip[ip.size() - 1] == '.') {
            return false;
        }
       

        while(getline(ss, tmp, '.')){
            ipParts.push_back(tmp);
        }

        if (ipParts.size() != 4) {
            return false;
        }
    
        for (string ipPart : ipParts) {
            std::string number = "";
            if (ipPart.size() == 0) {
                return false;
            }

            if (ipPart.size() > 3) {
                return false;
            }

            bool zeroWasFound = false;

            //48 - 57
            for (int i = 0; i < ipPart.size(); ++i) {
                if (ipPart[i] >= 48 && ipPart[i] <= 57) {
                    if (zeroWasFound) {
                        return false;
                    }
              
                    if (ipPart[i] == '0' && i == 0) {
                        zeroWasFound = true;
                    }

                    number += ipPart[i];
                    int converted = std::stoi(number);
                    
                    if (converted > 255) {
                        return false;
                    }
                    
                } else {
                    return false;
                }
            }
        }

        return true;
    }

    
};
