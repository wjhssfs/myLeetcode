totalTax
double totalTax(vector<pair<double, double>>& brackets, double income) {
	sort(begin(brackets), end(brackets));
	double total = 0.0;
	for (int i = 0; i < brackets.size(); ++i) {
		if (i == brackets.size() - 1 || income < brackets[i + 1].first) {
			total += (income - brackets[i].first) * brackets[i].second;
			return total;
		}
		total += (brackets[i + 1].first - brackets[i].first) * brackets[i].second;
	}
	return 0.0;
}