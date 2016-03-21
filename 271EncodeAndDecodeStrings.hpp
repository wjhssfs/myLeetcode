// 271 Encode and Decode Strings
// Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

// Machine 1 (sender) has the function:

// string encode(vector<string> strs) {
//   // ... your code
//   return encoded_string;
// }
// Machine 2 (receiver) has the function:
// vector<string> decode(string s) {
//   //... your code
//   return strs;
// }
// So Machine 1 does:

// string encoded_string = encode(strs);
// and Machine 2 does:

// vector<string> strs2 = decode(encoded_string);
// strs2 in Machine 2 should be the same as strs in Machine 1.

// Implement the encode and decode methods.

// Note:
// The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be generalized enough to work on any possible characters.
// Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
// Do not rely on any library method such as eval or serialize methods. You should implement your own encode/decode algorithm.

class Codec {
public:
    
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string output;
        for(auto &str :strs){
            output += to_string(str.size()) + '|';
            output += str;
        }
        return output;
    }
    
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        vector<char> str;
        istringstream ss(s);
        size_t count = 0;
        while(ss >> count){
            char c;
            ss >> c;
            str.resize(count);
            ss.read(str.data(), count);
            result.push_back(string(str.data(), count));
        }
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string output;
        for(auto & str : strs){
            for(auto c : str){
                if(c == '#') output += "##";
                else output += c;
            }
            output += "#1";
        }
        return output;
    }
    
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        string str;
        for(size_t i = 0; i < s.size(); i++){
            if(s[i] == '#') {
                if(i + 1 < s.size() && s[i+1] == '#'){
                    str += '#';
                    ++i;
                }
                else {
                    result.emplace_back(str);
                    str.clear();
                    ++i;
                }
            } else str += s[i];
        }
        return result;
    }
};