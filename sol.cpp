#include <bits/stdc++.h>

using namespace std;

// function for checking if a number contains a digit 7
bool Check(int n) {
	while (n > 0) {
		if (n % 10 == 7) {
			return true;
		}
		n /= 10;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x;
	cin >> x;
	int hh, mm;
	cin >> hh >> mm;
	int cnt = 0;
	while (!Check(hh) && !Check(mm)) {
		// simulate the reverse process until hh or mm has a digit 7
		// calculate the difference of the current minutes and x
		// there will be two (2) cases:
		
		// case 1 - if the difference is less than 0
		// we need to reduce the hour by 1 and reduce the current minutes (starting from 60)
		// depending on the remaining minutes that needs to be subtracted
		// edge case: if the hours is equal to 00:00, then the previous time will be 23:59
		
		// case 2 - if the difference is greater than or equal to 0
		// simply subtract x from the current minutes
		
		// note: keep incrementing the counter until the while-loop terminates
		int diff = mm - x;
		if (diff < 0) {
			hh = (hh == 0 ? 23 : hh - 1);
			mm = 60 - (x - mm);
		} else {
			mm = diff;
		}
		cnt++;
	}
	cout << cnt << '\n';
	return 0;
}
