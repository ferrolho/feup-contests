#include <algorithm>
#include <iostream>

using namespace std;

// Custom types
typedef unsigned int ui;

int main() {
	int cases;
	cin >> cases;

	while (cases--) {
		ui XLL1, YLL1, XUR1, YUR1;
		ui XLL2, YLL2, XUR2, YUR2;

		// input windows
		cin >> XLL1 >> YLL1 >> XUR1 >> YUR1;
		cin >> XLL2 >> YLL2 >> XUR2 >> YUR2;

		if (XUR1 <= XLL2 || XUR2 <= XLL1 || YUR1 <= YLL2 || YUR2 <= YLL1)
			cout << "No Overlap" << endl;
		else
			cout << max(XLL1, XLL2) << " " << max(YLL1, YLL2) << " "
					<< min(XUR1, XUR2) << " " << min(YUR1, YUR2) << endl;

		if (cases > 0)
			cout << endl;
	}

	return 0;
}
