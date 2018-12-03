bug note whether right point to end or one past one
string invlidParentheses(string s) {
	int right = -1, nOpen = 0, nClose = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == ')' && !nOpen) continue;
		if (s[i] == '(') ++nOpen;
		else if (s[i] == ')') --nOpen;
		s[++right] = s[i];
	}
	int left = right + 1;
	for (int i = right; i >= 0; --i) {
		if (s[i] == '(' && !nClose) continue;
		if (s[i] == '(') --nClose;
		else if (s[i] == ')') ++nClose;
		s[--left] = s[i];
	}
	return s.substr(left, right - left + 1);
}