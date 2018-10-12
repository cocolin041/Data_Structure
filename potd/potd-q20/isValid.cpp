#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool isValid(string input) {
    stack<char> st;
		int a = 0;
		int a_count = 0;
		int a_balance = 0;
		int b = 0;
		int b_count = 0;
		int b_balance = 0;
		int c = 0;
		int c_count = 0;
		int c_balance = 0;

		for (int i = 0; i < (int)input.length(); i++) {
			if (input[i] == ']' | input[i] == ')' | input[i] == '}' | input[i] == '[' | input[i] == '(' | input[i] == '{') {
				st.push(input[i]);
			}
		}
		if (st.size() == 0) {
			return true;
		}
		while (st.size() > 0) {
			if (st.top() == ']') {
				a += st.size();
				a_count += 1;
				a_balance += 1;
			}
			if (st.top() == ')') {
				b += st.size();
				b_count += 1;
				b_balance += 1;
			}
			if (st.top() == '}') {
				c += st.size();
				c_count += 1;	
				c_balance += 1;
			}
			if (st.top() == '[') {
				a -= st.size();
				a_count += 1;
				a_balance -= 1;
			}
			if (st.top() == '(') {
				b -= st.size();
				b_count += 1;
				b_balance -= 1;
			}
			if (st.top() == '{') {
				c -= st.size();
				c_count += 1;
				c_balance -= 1;
			}
			if (a_balance < 0 | b_balance < 0 | c_balance < 0) {
				return false;
			}
			st.pop();
		}
		a_count = a_count / 2;
		b_count = b_count / 2;
		c_count = c_count / 2;

		if (a_balance != 0) {
			return false;
		}
		if (b_balance != 0) {
			return false;
		}
		if (c_balance != 0) {
			return false;
		}

		if (a_count== 2 * (a_count / 2)) {  //a has even pair
		  if (a != 2 * (a / 2)) {
				return false;
			}
		} else {                            //a has odd pair
			if (a == 2 * (a / 2)) {
				return false;
			}
		}
		if (b_count== 2 * (b_count / 2)) {  //b has even pair
		  if (b != 2 * (b / 2)) {
				return false;
			}
		} else {														//b has odd pair
			if (b == 2 * (b / 2)) {
				return false;
			}
		}
		if (c_count== 2 * (c_count / 2)) {  //c has even pair
		  if (c != 2 * (c / 2)) {
				return false;
			}
		} else {														//c has odd pair
			if (c == 2 * (c / 2)) {
				return false;
			}
		}
		return true;
}