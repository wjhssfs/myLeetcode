// 9 Palindrome Number 
// Determine whether an integer is a palindrome. Do this without extra space.
// You could also try reversing an integer. However, if you have solved the problem "Reverse Integer",
// you know that the reversed integer might overflow. How would you handle such case?
class Solution {
public:
    bool isPalindrome(int x) {
	    if(x < 0) return false;
		int div = 1;
		while(x/div >=10) div *=10;

		while(x>0)
		{
			int l = x/div;
			int r = x%10;
			if(l!=r) return false;
			x = (x%div)/10;
			div/=100;
		}
		return true;
    }
};


public boolean isPalindrome(int x) {
    if (x<0 || (x!=0 && x%10==0)) return false;
    int rev = 0;
    while (x>rev){
        rev = rev*10 + x%10;
        x = x/10;
    }
    return (x==rev || x==rev/10);
}