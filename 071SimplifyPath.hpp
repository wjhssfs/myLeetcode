// 71 Simplify Path 
// Given an absolute path for a file (Unix-style), simplify it.
// 
// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"
// click to show corner cases.
// 
// Corner Cases:
// Did you consider the case where path = "/../"?
// In this case, you should return "/".
// Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
// In this case, you should ignore redundant slashes and return "/home/foo".

class Solution {
public:
    string simplifyPath(string path) {
        string res;
        path += "/";
        size_t pos = path.find_first_of("/"), last = 0;
        while (pos != string::npos)
        {
            string s = path.substr(last, pos - last);
            if (s == "..") 
            {
                if (!res.empty())
                    res.resize(res.find_last_of("/"));
            }
            else if (!s.empty() && s != ".")
            {
                res += "/";
                res += s;
            }
            last = pos + 1;
            pos = path.find_first_of("/", last);
        }
        return res.empty() ? "/" : res;
    }
};
