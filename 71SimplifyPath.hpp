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
		if (!path.size()) return path;
		int i = 1, ep = 1;
		while (i < (int)path.size()){//looking forward till next '/'
			int j = 0;
			while (i + j < (int)path.size() && path[i + j] != '/') j++;
			if (j == 0){
				i++;
			}else if (j == 1 && path[i] == '.'){
				i += 2;
			}
			else if (j == 2 && path[i] == '.' && path[i + 1] == '.'){
				while (ep > 1 && path[ep-- - 1] != '/'); //backtrack, ep moved to last '/' if ep > 1
				i += 3;
			}
			else{
				if(ep!=1)path[ep++] = '/';
				for (int k = 0; k < j; k++){
					path[ep++] = path[i++];
				}
			}
		}
		return path.substr(0, ep);
	}
}; 

class Solution2 {
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
