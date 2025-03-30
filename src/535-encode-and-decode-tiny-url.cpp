class UrlEncoder {
private:
    std::unordered_map<string, string> saved;
    char convertIntoChar(int asciiSum) {
        while (asciiSum > 128) {
            asciiSum = asciiSum / 2;
        }

        return char(asciiSum);
    }
public:
    std::string encode(std::string url) {
        int pointer = 0;
        int currCharSum = 0;
        std::string encoded;
        while (pointer < url.size()) {
            if (pointer % 3 == 0) {
                char res = convertIntoChar(currCharSum);
                currCharSum = 0;
                encoded += res;
            }
            else {
                currCharSum += url[pointer];
            }

            pointer++;
        }

        if (currCharSum > 0) {
            encoded += convertIntoChar(currCharSum);
        }

        saved[encoded] = url;
        std::cout << encoded << std::endl;
        return encoded;
    }

    std::string decode(std::string url) {
        return saved[url];
    }
};

class Solution {
private:
    UrlEncoder encoder;
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        return encoder.encode(longUrl);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return encoder.decode(shortUrl);
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
