// 13 Roman to Integer 
// Given a roman numeral, convert it to an integer.
// Input is guaranteed to be within the range from 1 to 3999.

// Look back
class Solution {
public:
int romanToInt(string s) {
		int table[256];
		table['I'] = 1;
		table['V'] = 5;
		table['X'] = 10;
		table['L'] = 50;
		table['C'] = 100;
		table['D'] = 500;
		table['M'] = 1000;

		int sum = 0;
		int pre = 0;
		for (int i = 0; i < (int)s.size(); i++){
			pre < table[s[i]] ? sum -= pre : sum += pre;
			pre = table[s[i]];
		}
		sum += pre;
		return sum;
	}
};

// Look ahead
class Solution2 {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman;
        roman['M'] = 1000;
        roman['D'] = 500;
        roman['C'] = 100;
        roman['L'] = 50;
        roman['X'] = 10;
        roman['V'] = 5;
        roman['I'] = 1;

        int res = 0, N = s.size();
        for (int i = 0; i < N; ++i)
        {
            if (i < N-1 && roman[s[i]] < roman[s[i+1]])
                res -= roman[s[i]];
            else
                res += roman[s[i]];
        }
        return res;
    }
};

public int romanToInt(String s) {
     int sum=0;
    if(s.indexOf("IV")!=-1){sum-=2;}
    if(s.indexOf("IX")!=-1){sum-=2;}
    if(s.indexOf("XL")!=-1){sum-=20;}
    if(s.indexOf("XC")!=-1){sum-=20;}
    if(s.indexOf("CD")!=-1){sum-=200;}
    if(s.indexOf("CM")!=-1){sum-=200;}

    char c[]=s.toCharArray();
    int count=0;

   for(;count<=s.length()-1;count++){
       if(c[count]=='M') sum+=1000;
       if(c[count]=='D') sum+=500;
       if(c[count]=='C') sum+=100;
       if(c[count]=='L') sum+=50;
       if(c[count]=='X') sum+=10;
       if(c[count]=='V') sum+=5;
       if(c[count]=='I') sum+=1;

   }

   return sum;

}