// 588. Design In-Memory File System

// Design an in-memory file system to simulate the following functions:

// ls: Given a path in string format. If it is a file path, return a list that only contains this file's name. If it is a directory path, return the list of file and directory names in this directory. Your output (file and directory names together) should in lexicographic order.

// mkdir: Given a directory path that does not exist, you should make a new directory according to the path. If the middle directories in the path don't exist either, you should create them as well. This function has void return type.

// addContentToFile: Given a file path and file content in string format. If the file doesn't exist, you need to create that file containing given content. If the file already exists, you need to append given content to original content. This function has void return type.

// readContentFromFile: Given a file path, return its content in string format.

// Example:
// Input: 
// ["FileSystem","ls","mkdir","addContentToFile","ls","readContentFromFile"]
// [[],["/"],["/a/b/c"],["/a/b/c/d","hello"],["/"],["/a/b/c/d"]]
// Output:
// [null,[],null,null,["a"],"hello"]
// Explanation:
// filesystem
// Note:
// You can assume all file or directory paths are absolute paths which begin with / and do not end with / except that the path is just "/".
// You can assume that all operations will be passed valid parameters and users will not attempt to retrieve file content or list a directory or file that does not exist.
// You can assume that all directory names and file names only contain lower-case letters, and same names won't exist in the same directory.

class FileSystem {
private:
    struct TrieNode {
        bool isFile;
        string content;
        unordered_map<string, TrieNode *> children;
        TrieNode() : isFile(false) {}
    };

    TrieNode *root;
    
public:
    FileSystem() {
        root = new TrieNode();
    }
    
    vector<string> getStrs(string &path) {
        vector<string> ans;
        int i = 1, j = 1;
        while (j <= path.length()) {
            if (i != j && (j == path.length() || path[j] == '/')) {
                ans.push_back(path.substr(i, j - i));
                i = j + 1;
            }
            ++j;
        }
        return ans;
    }
    
    vector<string> ls(string path) {
        vector<string> strs = getStrs(path);
        TrieNode *curr = root;
        for (string &str : strs)
            curr = curr->children[str];
        
        if (curr->isFile)
            return {strs.back()};
        
        vector<string> ans;
        for (auto &p : curr->children)
            ans.push_back(p.first);
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    void mkdir(string path) {
        vector<string> strs = getStrs(path);
        TrieNode *curr = root;
        for (string &str : strs) {
            if (!curr->children.count(str))
                curr->children[str] = new TrieNode();
            curr = curr->children[str];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        vector<string> strs = getStrs(filePath);
        TrieNode *curr = root;
        for (string &str : strs) {
            if (!curr->children.count(str))
                curr->children[str] = new TrieNode();
            curr = curr->children[str];
        }
        curr->isFile = true;
        curr->content += content;
    }
    
    string readContentFromFile(string filePath) {
        vector<string> strs = getStrs(filePath);
        TrieNode *curr = root;
        for (string &str : strs)
            curr = curr->children[str];
        return curr->content;
    }
};

class FileSystem {
	struct Item {
		virtual vector<string> getList() = 0;
	};
	struct File : Item {
		string name; // redunnant
		string content;

		File(string n) : name(n) {};
		vector<string> getList() { return{ name }; }
	};
	struct Directory : Item {
		string name;
		map<string, Item *> subItems;

		Directory(string n) : name(n) {};
		vector<string> getList() {
			vector<string> res;
			for (auto && i : subItems) res.push_back(i.first);
			return res;
		}
	};

	Directory root;

	Item * getItem(string path) {
		if (path == "/") return &root;
		path += '/';
		int start = 1;
		Directory *cur = &root;
		while (start != path.size()) {
			int end = path.find('/', start);
			string c = path.substr(start, end - start);
			if (cur->subItems.count(c) == 0) cur->subItems[c] = new Directory(c);
			cur = (Directory *)(cur->subItems[c]);
			start = end + 1;
		}
		return cur;
	}

	File * findFile(string filePath) {
		int lastSlash = filePath.rfind('/');
		string parentPath = lastSlash == 0 ? "/" : filePath.substr(0, lastSlash);
		string fileName = filePath.substr(lastSlash + 1);
		Directory *d = (Directory *)getItem(parentPath);
		if (d->subItems.count(fileName) == 0) d->subItems[fileName] = new File(fileName);
		return (File *)d->subItems[fileName];
	}

public:
	FileSystem() :root(""){
	}

	vector<string> ls(string path) {
		Item * i = getItem(path);
		return i->getList();
	}

	void mkdir(string path) {
		getItem(path);
	}

	void addContentToFile(string filePath, string content) {
		File * f = findFile(filePath);
		f->content += content;
	}

	string readContentFromFile(string filePath) {
		return findFile(filePath)->content;
	}
};

/**
* Your FileSystem object will be instantiated and called as such:
* FileSystem obj = new FileSystem();
* vector<string> param_1 = obj.ls(path);
* obj.mkdir(path);
* obj.addContentToFile(filePath,content);
* string param_4 = obj.readContentFromFile(filePath);
*/